# Basic Implementations
Written in a mixture of C and C++ - I really wanted to learn how these work and learn the lowest
and most fundamental ideas. I tried to use a mixture of C/C++ so I could A) Use Classes and
other proficiencies to make it slighly easier and B) Use C type programming to ensure I understood
how dynamic allocation, reallocation and deletion worked in memory so my data structures could be more fluid.

# Implementations
- Basic Stack
- Basic Queue
- Basic LinkedList
- Basic Doubly-LinkedList
- Basic Circularly-LinkedList
- Basic Dictionary
- Hash Maps, Sets and Tables

# Stack - [Linear Data Structures]
a Stack, being a Last-In First-Out data structure, is a commonly used data structure in computer science that is useful for storing data in.
It has common operations such as `push()` to add an item to the stack. `pop()` to delete the top-most item from the stack and return it. Among
those two read/write functions there are numerous common methods such as `peek()` and `isFull()`, `isEmpty()`.

# Queue - [Linear Data Structures]
a Queue, being a First-in First-Out data structure, is also commonly used in everyday applications. Such as Queue control for a ticketing system
or used for managing customers or food-product expiry dates. It operates by having an `enqueue()` function to add items to the queue and a
`dequeue()` function to remove the first element in the Queue. Like stack and many other data structures it has surrounding methods to aptly
modify, update and read the data.

# Linked List - [Linear Data Structures]
a Linked List is a data structure by which each Node in the list points to the next Nodes memory address. Linked list usually have a Head and
Tail node and offer sufficient access-time for data. Nodes hold information and the address of the next node. This means Nodes can dynamically
be inserted and deleted at any point in the Linked List, making it a very versitile data structure. 
There are also three different types of LinkedList:
- Singularly Linked List (this example)
- Doubly Linked List (holds data to point to the element before AND after it in the list)
- Circularly Linked List (The Tail node points to the Head nodes address)

# Doubly Linked List
Inherits the same functionality and basis as a Linked list - with the exception that each node
holds not only the next Nodes address but also the previous Nodes address. i.e.
```c++
struct Node {
  int data; // the data you want the node to hold
  Node* next, prev;
  Node(int _data) {
    data = _data;
    prev = next = nullptr;
  }
}
```
With this difference, it gives the programmer optional traversal (start at the head or tail)

# Hash Table - Dictionary/Hash Map
A Hash table is a data structure that passes Key-value pairs into a hash function and stores them
appropriately. This makes indexing and searching for an item constant time if you know the index or
linear time if you search through the HashMap

# Trees

# Graphs
