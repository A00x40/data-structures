public class DynamicArray<T>
{
    private long Capacity { get; set; }
    public long Length { get; private set; }

    private T[] Items;

    public DynamicArray()
    {
        Capacity = 1; Length = 0; Items = new T[1];
    }

    public DynamicArray(long capacity)
    {
        Capacity = capacity; Length = 0; Items = new T[capacity];
    }

    // Using in keywork to avoid coping large structs
    public void Add(in T item)
    {
        if (Length == Capacity)
        {
            Capacity *= 2;
            T[] extendedItems = new T[Capacity];
            Array.Copy(Items, extendedItems, Length);
            Items = extendedItems;
        }

        Items[Length] = item;
        Length++;
    }

    public void Remove()
    {
        if (Length == 0)
        {
            throw new InvalidOperationException("Array is Empty");
        }

        Items[Length - 1] = default!;
        Length--;   
    }

    public T this[long index]
    {
        get
        {
            if (index < 0 || index >= Length)
                throw new ArgumentOutOfRangeException($"Index {index} out of range");

            return Items[index];
        }

        set
        {
            if (index < 0 || index >= Length)
                throw new ArgumentOutOfRangeException($"Index {index} out of range");

            Items[index] = value;
        }
    }

    public DynamicArray<T> Copy()
    {
        DynamicArray<T> newArray = new(Capacity)
        {
            Length = Length,
        };

        Array.Copy(Items, newArray.Items, Length);
        return newArray;
    }

};