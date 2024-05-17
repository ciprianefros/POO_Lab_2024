#include <iostream>
#include <string>
#include "Array.h"

class IntCompare : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        int* a = static_cast<int*>(e1);
        int* b = static_cast<int*>(e2);
        return (*a) - (*b);
    }
};

template<class T>
void printArray(Array<T>& arr) {
    for (int i = 0; i < arr.GetSize(); ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    Array<int> arr(100);
    IntCompare intCompare;
    bool running = true;

    while (running) {
        std::cout << "\nArray Operations Menu:\n";
        std::cout << "1. Add Element\n";
        std::cout << "2. Insert Element at Index\n";
        std::cout << "3. Insert Another Array at Index\n";
        std::cout << "4. Delete Element at Index\n";
        std::cout << "5. Sort Array\n";
        std::cout << "6. Binary Search\n";
        std::cout << "7. Find Element\n";
        std::cout << "8. Print Array\n";
        std::cout << "9. Exit\n";
        std::cout << "Choose an option: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Enter element to add: ";
            int elem;
            std::cin >> elem;
            arr += elem;
            break;
        }
        case 2: {
            std::cout << "Enter index to insert at: ";
            int index;
            std::cin >> index;
            std::cout << "Enter element to insert: ";
            int elem;
            std::cin >> elem;
            try {
                arr.Insert(index, elem);
            }
            catch (const exceptie2& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 3: {
            std::cout << "Enter size of array to insert: ";
            int size;
            std::cin >> size;
            Array<int> tempArray(size);
            for (int i = 0; i < size; ++i) {
                std::cout << "Enter element " << i + 1 << ": ";
                int elem;
                std::cin >> elem;
                tempArray += elem;
            }
            std::cout << "Enter index to insert at: ";
            int index;
            std::cin >> index;
            try {
                arr.Insert(index, tempArray);
            }
            catch (const exceptie2& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 4: {
            std::cout << "Enter index to delete: ";
            int index;
            std::cin >> index;
            try {
                arr.Delete(index);
            }
            catch (const exceptie2& e) {
                std::cerr << e.what() << std::endl;
            }
            break;
        }
        case 5: {
            std::cout << "Choose sort type:\n";
            std::cout << "1. Default Sort\n";
            std::cout << "2. Comparator Sort\n";
            int sortChoice;
            std::cin >> sortChoice;
            if (sortChoice == 1) {
                arr.Sort();
            }
            else if (sortChoice == 2) {
                arr.Sort(&intCompare);
            }
            break;
        }
        case 6: {
            std::cout << "Enter element to search for: ";
            int elem;
            std::cin >> elem;
            int result = arr.BinarySearch(elem, &intCompare);
            if (result != -1) {
                std::cout << "Element found at index: " << result << std::endl;
            }
            else {
                std::cout << "Element not found." << std::endl;
            }
            break;
        }
        case 7: {
            std::cout << "Enter element to find: ";
            int elem;
            std::cin >> elem;
            int result = arr.Find(elem, &intCompare);
            if (result != -1) {
                std::cout << "Element found at index: " << result << std::endl;
            }
            else {
                std::cout << "Element not found." << std::endl;
            }
            break;
        }
        case 8: {
            std::cout << "Current Array: ";
            printArray(arr);
            break;
        }
        case 9: {
            running = false;
            break;
        }
        default: {
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }
        }
    }

    return 0;
}