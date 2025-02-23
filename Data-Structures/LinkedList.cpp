#include <iostream>

struct Node {
	int data;
	Node* next;
};

class LinkedList {
	Node* head; // Pointer to the head of the linked list

	public:
		// default construcotr - initialize head as nullptr
		LinkedList() : head(nullptr) {}

		// insert a new node at the beginning of the linked list
		void insertHead(int element) {
			Node* currentNode = new Node();
			currentNode->data = element;
			currentNode->next = head;
			head = currentNode;
		}

		// Insert a new node at the end of the linked list
		void insertTail(int element) {
			Node* currentNode = new Node();
			currentNode->data = element;
			currentNode->next = nullptr;

			// If the LinkedList is empty update the head to this node
			if (!head) {
				head = currentNode;
				return;
			}

			Node* tempNode = head;
			while (tempNode->next) {
				tempNode = tempNode->next;
			} 
			
			// Update the last Node to this node
			tempNode->next = currentNode;
		}

		// Insert a New node at a given index in the LinkedList
		void insert(int element, int position) {
			if (position < 1) {
				std::cout << "[!] Position should be Greater than 1" << "\n";
				return;
			}

			if (position == 1) {
				insertHead(element);
				return;
			}

			Node* currentNode = new Node();
			currentNode->data = element;

			// Traverse until the desired position is found
			Node* tempNode = head;
			for (int i = 1; (i < position - 1 && tempNode); ++i) {
				tempNode = tempNode->next;
			}

			// If the position is out of ranger -> error
			if (!tempNode) {
				std::cout << "[!] Position is out of Range" << "\n";
				delete currentNode;
				return;
			}

			currentNode->next = tempNode->next;
			tempNode->next = currentNode;
		}

		// delete Start Node
		void deleteHead() {
			if (!head) {
				std::cout << "[!] LinkedList is Empty\n";
				return;
			}

			Node* tempNode = head;
			head = head->next;
			delete tempNode;
		}

		// delete End Node
		void deleteTail() {
			if (!head) {
				std::cout << "[!] LinkedList is Empty\n";
				return;
			}

			// second fail-safe check for time complexity reasons
			if (!head->next) {
				delete head;
				head = nullptr;
				return;
			}

			// Traverse to second last node
			Node* tempNode = head;
			while (tempNode->next->next) {
				tempNode = tempNode->next;
			}

			// delete last node
			delete tempNode->next;
			tempNode->next = nullptr;
		}
};

// Note: Other arbitrary functions can be implemented such as deletion via a given index or displaying the linked list
// in an informative way. But i thought the main message was there to save my self from going in more
