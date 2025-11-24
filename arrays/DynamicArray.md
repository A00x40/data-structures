# Dynamic Arrays - Explaination
A **Dynamic Array** is a data structure used to store data
in squential order in the memory

## Key Characteristics
- **Index-based:** Elements are accessed using an **integer index** (0, 1, 2, …). The first element is at index 0, the second at index 1, and so on. Some programming languages, such as Python, also allow **negative integers** for reverse indexing (e.g., -1 refers to the last element).


- **Length** Keeps tracks of stored elements count.
- **Hidden capacity:** Users see the actual number of elements (`Length`), while the array may have extra unused space internally for efficiency.
- **Resizable Capacity** When array length reaches the maximum defined capacity
a new array is defined with double the capacity and copies old values.

## Behaviour / Methods
- **(Add / Append / Push)** 
Adds a new element at the end of the array.  
  When the current length reaches the array's capacity, the capacity is **doubled** automatically, as explained above.

- **(Remove / Delete / Pop)** 
Remove a the element at the end of the array.  
  if **Length** is 0, removal isn't possible

- **Access / Indexing**
Retrieve or modify an element at a valid index.  
    Invalid indices may throw an error.  
    Some languages allow **negative indices** to access elements from the end.

- **Hard (Deep) Copy:**  
Creates a **completely independent** dynamic array object with the same elements and capacity as the original.  
  Modifying the new array does **not affect** the original array.

