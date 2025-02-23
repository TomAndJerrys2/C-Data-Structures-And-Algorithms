// Basic implementation of a Queue data Structure
#include <iostream>
#include <memory>

// Main Queue Class
class Queue {
	private:
		int* qArr; // Queue Array
		int front; // Front-most element index
		int size; // current size
		int capacity; // maximum size

	public:
		// Default constructor
		Queue(size_t size) {
			capacity = (int)size;
			size = 0;
			qArr = (int*) malloc(sizeof(capacity * sizeof(int)));
		}

		void deleteQueue() {
			free(qArr);
		}

		// enqueue an element 
		void enqueue(int element) {
			if (size == capacity) { return; }
			qArr[size] = element;
			size++;

			std::cout << "[!] Added item Successfully!" << "\n";
		}

		// Dequeue an element
		void dequeue() {
			if (size == 0) { return; }
			for (int i = 1; i < size; i++) {
				qArr[i - 1] = qArr[i];
			}

			size--;
		}

		// Get Front-most Element
		int peek() {
			if (size == 0) { return -1; }
			return qArr[front];
		}

		// Display the Queue
		void displayQueue() {
			for (int i = front; i < size; i++) {
				std::cout << qArr[i] << "\n";
			}
		}

		// Memory Cleanup
		~Queue() {
			deleteQueue();
		}
};

int main() {
	Queue* myQueue = new Queue(10);
	myQueue->enqueue(1);
	myQueue->enqueue(2);
	myQueue->enqueue(3);
	myQueue->displayQueue();
}
