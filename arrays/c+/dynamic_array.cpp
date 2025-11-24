#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class DynamicArray
{
    private: 
        long Capacity;
        T* Items;

    public:
        long Length;

        DynamicArray() : Capacity(1), Length(0)
        {
            Items = new T[1];
        }

        DynamicArray(long capacity) : Capacity(capacity), Length(0)
        {
            Items = new T[capacity];
        }

        DynamicArray(const DynamicArray& arr) : Capacity(arr.Capacity), Length(arr.Length)
        {
            Items = new T[Capacity];
            for (long i = 0; i < Length; i++) Items[i] = arr.Items[i];
        }

        DynamicArray& operator=(const DynamicArray& arr)
        {
            if (this == &arr) return *this;

            delete[]Items;

            Capacity = arr.Capacity;
            Length = arr.Length;
            Items = new T[arr.Capacity];
            for (long i = 0; i < Length; i++) Items[i] = arr.Items[i];

            return *this;
        }



        void Add(const T& item)
        {
            if (Length == Capacity)
            {
                Capacity *= 2;
                T* extendedItems = new T[Capacity];

                for (long i = 0; i < Length; i++) extendedItems[i] = Items[i];

                delete[] Items;
                Items = extendedItems;
            }

            Items[Length] = item;
            Length++;
        }

        void Remove()
        {
            if (Length == 0)
            {
                throw out_of_range("Array is empty");
            }

            Items[Length - 1] = T{};
            Length--;
        }

        T& operator[](long index) 
        {
            if (index < 0 || index >= Length)
                throw out_of_range("Index out of range");

            return Items[index];
        }

        const T& operator[](long index)
        {
            if (index < 0 || index >= Length)
                throw out_of_range("Index out of range");

            return Items[index];
        }

      

        ~DynamicArray()
        {
            delete[] Items;
        }
};

