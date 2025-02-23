Pointers are a type of variable that can store a types memory address

```c++
int num = 5; // some number that stores the value 5
int* ptr = &num; // a pointer that stores the memory address to num
```

# Different types of Pointers

- Null Pointers
- Void Pointers
- Wild Pointers
- Dangling Pointers
- Pointer-to-Pointer (Double Pointer)
- Smart Pointers

# Null Pointer
A **Null Pointer** is just a pointer that is assigned a null memory address:
```c++
int* nullPtr = nullptr;
```
*NOTE: nullptr is preferred over NULL in c++*
# Void Pointer
A **Void Pointer** is a pointer that is declared with the `void` keyword. To use this pointer we must first Type-case the pointer to a useable type

*Type-Casting a Void Pointer:*
```c++
int num = 25;
void* voidPtr = &num;
std::cout << *(int *)voidPtr;
```
```Output
Output: 5
```

# Wild Pointer
A **Wild Pointer** is a pointer that is declared but isn't assigned a memory address of a variable. These pointers are often dangerous and can cause memory/segmentation errors.
```c++
int* ptr; // no value is assigned
```

# Dangling Pointer
A Dangling Pointer is a pointer that points at a deleted variables memory address which is now Free Space. We deallocate memory using the `free()` function.
```c++
int* ptr = (int *)malloc(sizeof(int)); // allocating memory
int num = 50;
ptr = &a;

free(ptr); // now the poiner - points to nothing
```

# Pointer to Pointer
Pointer to Pointer refers to a double pointer where by a pointer stores the memory address of another pointer. Double pointers are generally used to achieve an indirect reference of data via another pointer. These are most useful for dynamic data structures

*Implementation idea:*
```c++
void allocateArray(int**  &ptr, int size) {
    ptr = new int* [size]; // allocate array of pointers
    for (int i = 0; i < size; i++) {
        ptr[i] = new int[size]; // allocate int arr for each pointer
    }

    int value = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            ptr[i][j] = value++;
         }
    }
}

void freeArray(int** &ptr, int size) {
    for (int i = 0; i < size; i++) {
        delete[] ptr[i]; // free each sub-array
    }
    delete[] ptr; // free the top-level of the array
    ptr = nullptr; // safeguard pointer
}

void printArr(int**& ptr, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << ptr[i][j] << " \n";
        }
    }
}

int main()
{  
    int** arr = nullptr;
    int size = 3;

    allocateArray(arr, size);
    printArr(arr, size);
    freeArray(arr, size);

    return 0;
}
```

# Smart Pointers (C++)

**Shared Pointer**:
C++11 Introduces smart pointers, unlike simple pointers it has an associated control block that keeps track of the reference count for the managed object. This is shared across all copies of the `shared_ptr` instance pointing to the same object, ensuring proper memory management and deletion.

```c++
std::shared_ptr<int> sPtr = (new int(10))
std::shared_ptr<int> sPtr2 = sPtr;

std::cout << *sPtr << "\n";
std::cout << *sPtr2 << "\n";
```

```Output
10
10
```

**Unique Pointer**:
Another smart pointer that automatically manages the dynamically allocated resources on the heap. As smart pointers are just wrappers around regular pointers that help prevent widespread bugs.

```c++
std::unique_ptr<int> uPtr(new int(10))
std::cout << *uPtr << "\n";

std::unique_ptr<int> uPtr2 = move(uPtr); // Transferring the ptr
if(!uPtr)
	std::cout << "uPtr is empty"; // as it has been moved
```

```Output
10
uPtr is empty
```

**Weak Pointer:**
To get around circular referencing in shared pointers i.e. A has a shared pointer referencing B and B has a shared pointer referencing A. This is problematic as neither A nor B will ever be deleted and can lead to a memory leak. Weak pointers allow you to create a non-own reference to an object managed by `shared_ptr` without  affecting the reference count or preventing the object from being deleted.
```c++
std::shared_ptr<int> sPtr = std::make_shared<int>(10);
std::weak_ptr<int> weakPtr = sPtr;
```

*Note:* `reset()` Clears the `weak_ptr`
`swap()` Swaps the object managed by `weak_ptr`
`expired()` check if the resource `weak_ptr` points to exists or not
`lock()` if the resource pointed too exists, this function returns a `shared_ptr` with ownership of that resource. if the resource does not exist, it returns a default constructed `shared_ptr`
`use_count()` tells about how many `shared_ptr` owns the resource

And there are many more STL functions to use with these as I am discovering, which makes it great for optimizing memory management