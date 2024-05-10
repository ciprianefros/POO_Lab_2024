#include <iostream>
#include <cstdio>

template<typename K, typename V>
class Map {

    private:
        struct Entry {
            K key;
            V value;
        };

        Entry* entries;
        int capacity;
        int size;

        void resize() {
            int new_capacity = capacity * 2;
            Entry* new_entries = new Entry[new_capacity];
            for (int i = 0; i < size; ++i) {
                new_entries[i] = entries[i];
            }
            delete[] entries;
            entries = new_entries;
            capacity = new_capacity;
            delete[] new_entries;
        }

        int findIndex(const K& key) const {
            for (int i = 0; i < size; ++i) {
                if (entries[i].key == key) {
                    return i;
                }
            }
            return -1;
        }

    public:
        Map() : size(0), capacity(10) {
            entries = new Entry[capacity];
        }

        ~Map() {
            delete[] entries;
            size = NULL;
            capacity = NULL;
        }

        V& operator[](const K& key) {
            int index = findIndex(key);
            if (index == -1) {
                if (size == capacity) {
                    resize();
                }
                entries[size].key = key;
                return entries[size++].value;
            }
            return entries[index].value;
        }

        void Set(const K& key, const V& value) {
            (*this)[key] = value;
        }

        bool Get(const K& key, V& value) const {
            int index = findIndex(key);
            if (index != -1) {
                value = entries[index].value;
                return true;
            }
            return false;
        }

        int Count() const {
            return size;
        }

        void Clear() {
            delete[] entries;
            entries = new Entry[capacity];
            size = 0;

        }

        bool Delete(const K& key) {
            int index = findIndex(key);
            if (index == -1) return false;
            entries[index] = entries[--size];
            return true;
        }

        bool Includes(const Map<K, V>& map) const {
            for (int i = 0; i < map.size; i++) {
                if (findIndex(map.entries[i].key) == -1) {
                    return false;
                }
            }
            return true;
        }

        struct Iterator {
            const Map& map;
            int index;

            bool operator!=(const Iterator& other) const {
                return index != other.index;
            }

            Iterator& operator++() {
                index++;
                return *this;
            }

            auto operator*() const {
                return std::make_tuple(map.entries[index].key, map.entries[index].value, index);
            }
        };

        Iterator begin() const {
            return Iterator{ *this, 0 };
        }

        Iterator end() const {
            return Iterator{ *this, size };
        }
};