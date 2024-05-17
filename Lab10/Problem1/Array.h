#pragma once
#include <iostream>
#include <exception>
using namespace std;

class exceptie2 : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
    T** List;
    int Current;
    int Size;
public:
    ArrayIterator() : List(nullptr), Current(0), Size(0) {};
    ArrayIterator(T** list, int size, int current = 0) : List(list), Size(size), Current(current) {}
    ArrayIterator& operator++() {
        if (Current < Size)
            Current++;
        return *this;
    }
    ArrayIterator& operator--() {
        if (Current > 0)
            Current--;
        return *this;
    }
    bool operator==(const ArrayIterator<T>& other) const {
        return Current == other.Current;
    }
    bool operator!=(const ArrayIterator<T>& other) const {
        return Current != other.Current;
    }
    T* GetElement() const {
        if (Current < Size)
            return List[Current];
        return nullptr;
    }
    void setSize(int size) {
        Size = size;
    }
    void setList(T** list) {
        List = list;
    }
};

template<class T>
class Array
{
private:
    T** List;
    int Capacity;
    int Size;

    void QuickSort(int left, int right) {
        if (left < right) {
            int pivot = Partition(left, right);
            QuickSort(left, pivot - 1);
            QuickSort(pivot + 1, right);
        }
    }

    int Partition(int left, int right) {
        T* pivot = List[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (*List[j] <= *pivot) {
                i++;
                swap(List[i], List[j]);
            }
        }
        swap(List[i + 1], List[right]);
        return i + 1;
    }

    void QuickSort(int left, int right, int(*compare)(const T&, const T&)) {
        if (left < right) {
            int pivotIndex = Partition(left, right, compare);
            QuickSort(left, pivotIndex - 1, compare);
            QuickSort(pivotIndex + 1, right, compare);
        }
    }

    int Partition(int left, int right, int(*compare)(const T&, const T&)) {
        T* pivot = List[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (compare(*List[j], *pivot) <= 0) {
                i++;
                swap(List[i], List[j]);
            }
        }
        swap(List[i + 1], List[right]);
        return i + 1;
    }

    void QuickSort(int left, int right, Compare* comparator) {
        if (left < right) {
            int pivotIndex = Partition(left, right, comparator);
            QuickSort(left, pivotIndex - 1, comparator);
            QuickSort(pivotIndex + 1, right, comparator);
        }
    }

    int Partition(int left, int right, Compare* comparator) {
        T* pivot = List[right];
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (comparator->CompareElements(List[j], pivot) <= 0) {
                i++;
                swap(List[i], List[j]);
            }
        }
        swap(List[i + 1], List[right]);
        return i + 1;
    }

public:
    Array() : List(nullptr), Capacity(0), Size(0) {}

    ~Array() {
        for (int i = 0; i < Size; i++) {
            delete List[i];
        }
        delete[] List;
    }

    Array(int capacity) : Capacity(capacity), Size(0) {
        List = new T * [Capacity];
    }

    Array(const Array<T>& otherArray) : Capacity(otherArray.Capacity), Size(otherArray.Size) {
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*otherArray.List[i]);
        }
    }

    T& operator[] (int index) {
        if (index < 0 || index >= Size) {
            throw exceptie2();
        }
        return *List[index];
    }

    const Array<T>& operator+=(const T& newElem) {
        if (Size >= Capacity) {
            Capacity = Capacity == 0 ? 1 : Capacity * 2;
            T** newList = new T * [Capacity];
            for (int i = 0; i < Size; i++) {
                newList[i] = List[i];
            }
            delete[] List;
            List = newList;
        }
        List[Size++] = new T(newElem);
        return *this;
    }

    const Array<T>& Insert(int index, const T& newElem) {
        if (index < 0 || index > Size) {
            throw exceptie2();
        }
        if (Size >= Capacity) {
            Capacity = Capacity == 0 ? 1 : Capacity * 2;
            T** newList = new T * [Capacity];
            for (int i = 0; i < Size; i++) {
                newList[i] = List[i];
            }
            delete[] List;
            List = newList;
        }
        for (int i = Size; i > index; i--) {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }

    const Array<T>& Insert(int index, const Array<T>& otherArray) {
        if (index < 0 || index > Size) {
            throw exceptie2();
        }
        while (Size + otherArray.Size > Capacity) {
            Capacity = Capacity == 0 ? 1 : Capacity * 2;
            T** newList = new T * [Capacity];
            for (int i = 0; i < Size; i++) {
                newList[i] = List[i];
            }
            delete[] List;
            List = newList;
        }
        for (int i = Size - 1; i >= index; i--) {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; i++) {
            List[index + i] = new T(*otherArray.List[i]);
        }
        Size += otherArray.Size;
        return *this;
    }

    const Array<T>& Delete(int index) {
        if (index < 0 || index >= Size) {
            throw exceptie2();
        }
        delete List[index];
        for (int i = index; i < Size - 1; i++) {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
    }

    Array<T>& operator=(const Array<T>& otherArray) {
        if (this != &otherArray) {
            for (int i = 0; i < Size; i++) {
                delete List[i];
            }
            delete[] List;
            Capacity = otherArray.Capacity;
            Size = otherArray.Size;
            List = new T * [Capacity];
            for (int i = 0; i < Size; i++) {
                List[i] = new T(*otherArray.List[i]);
            }
        }
        return *this;
    }

    bool operator==(const Array<T>& otherArray) {
        if (this->Size != otherArray.Size || this->Capacity != otherArray.Capacity) {
            return false;
        }
        for (int i = 0; i < this->Size; i++) {
            if (*(this->List[i]) != *(otherArray.List[i])) {
                return false;
            }
        }
        return true;
    }

    void Sort() {
        QuickSort(0, Size - 1);
    }

    void Sort(int(*compare)(const T&, const T&)) {
        QuickSort(0, Size - 1, compare);
    }

    void Sort(Compare* comparator) {
        QuickSort(0, Size - 1, comparator);
    }

    int BinarySearch(const T& elem) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (*List[mid] == elem) {
                return mid;
            }
            else if (*List[mid] < elem) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (compare(*List[mid], elem) == 0) {
                return mid;
            }
            else if (compare(*List[mid], elem) < 0) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int BinarySearch(const T& elem, Compare* comparator) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (comparator->CompareElements((void*)List[mid], (void*)&elem) == 0) {
                return mid;
            }
            else if (comparator->CompareElements((void*)List[mid], (void*)&elem) < 0) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++) {
            if (*List[i] == elem) {
                return i;
            }
        }
        return -1;
    }

    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; i++) {
            if (compare(*List[i], elem) == 0) {
                return i;
            }
        }
        return -1;
    }

    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; i++) {
            if (comparator->CompareElements((void*)List[i], (void*)&elem) == 0) {
                return i;
            }
        }
        return -1;
    }

    int GetSize() const {
        return Size;
    }

    int GetCapacity() const {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(List, Size, 0);
    }

    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(List, Size, Size);
    }
};