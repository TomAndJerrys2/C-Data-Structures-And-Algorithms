#include <iostream>
#include <memory>

template <typename T>
class customUniquePtr {
    private:
        T* ptr = nullptr; // initialize a null pointer of some arbitrary type

        // cleanup any existing data
        void __cleanup__() {
            if (ptr != nullptr) {
                delete ptr;
            }
        }

    public:
        // defined constructors
        customUniquePtr() : ptr(nullptr) {}
        customUniquePtr(T* ptr) : ptr(ptr) {}

        customUniquePtr(const customUniquePtr& ptrObj) = delete; // copy constructed gets deleted
        customUniquePtr& operator=(const customUniquePtr& ptrObj) = delete;

        // Move Constructor
        customUniquePtr(customUniquePtr&& dyingObj) {
            this->ptr = dyingObj.ptr;
            dyingObj.ptr = nullptr; // reference it to NULL
        }
        
        // Move assignment
        void operator=(customUniquePtr&& dyingObj) {
            __cleanup__();

            this->ptr = dyingObj.ptr;
            dyingObj.ptr = nullptr;
        }

        // Dereferencing arrow operator
        T* operator->() { return this->ptr; }

        // Dereferencing ptr
        T& operator*() { return *(this->ptr); }

        // Destructor
        ~customUniquePtr() { __cleanup__(); }
};

template <class T>
class customUniquePtr<T[]> {
    private:
        T* ptr = nullptr;

        void __cleanup__() {
            if (ptr != nullptr) {
                delete[] ptr;
            }
        }

    public: 
        customUniquePtr() : ptr(nullptr) {} // default constructor
        customUniquePtr(T* ptr) : ptr(ptr) {}

        // copy constructor and copy assignment deleted
        customUniquePtr(const customUniquePtr& ptrObj) = delete;
        customUniquePtr& operator=(const customUniquePtr& ptrObj) = delete;

        // Move constructor and Move assignment
        customUniquePtr(customUniquePtr&& dyingObj) {
            __cleanup__(); // cleanup data
            // transfer ownership of memory from dyingObj to this object
            this->ptr = dyingObj.ptr;
            dyingObj.ptr = nullptr;
        }

        void operator=(customUniquePtr&& dyingObj) {
            __cleanup__(); // cleanup data
            // Transfer ownership of memory from dyingObj to this object
            this->ptr = dyingObj.ptr;
            dyingObj.ptr = nullptr;
        }

        T* operator->() { return this->ptr; }

        T& operator*() { return *(this->ptr); }

        T& operator[](int index) {
            if (index < 0) {
                // index exception
                throw(new std::exception("Negative index exception"));
            } return this->ptr[index]; // doesn't check out of bounds
        }

        ~customUniquePtr() { __cleanup__(); } // destructor

};

int main()
{  

    std::cin.get();

    return 0;
}
