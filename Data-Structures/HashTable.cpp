#include <iostream>
#include <cstring>

struct Node {
	// Key-Value based pairs which are both char pointers "strings"
	char* key;
	char* element;
	struct Node* next;
};

void setNode(struct Node* node, char* key, char* element) {
	// regular pointer assignment;
	node->key = key;
	node->element = element;
	node->next = nullptr; 
	return;
}

typedef struct __hashmap__ {
	int numElements, capacity;
	struct Node** hashArr;
} HashMap;

void initHashMap(HashMap* myHashMap) {
	myHashMap->capacity = 10; // define capacity
	myHashMap->numElements = 0; // number of elements currently
	myHashMap->hashArr = (struct Node**) malloc(sizeof(struct Node*) * myHashMap->capacity);
	return;
}

int hashFunction(HashMap* myHashMap, char* key) {
	int index;
	int sum = 0, factor = 31;

	// for each sub in the key we do modulus calculation to find sum/factors accordingly
	for (int i = 0; i < strlen(key); i++) {
		sum = ((sum % myHashMap->capacity) + (((int) key[i]) * factor) % myHashMap->capacity) % myHashMap->capacity;
		factor = ((factor % INT16_MAX) * (31 % INT16_MAX)) % INT16_MAX;
	}

	index = sum;
	return index;
}

void insert(HashMap* myHashMap, char* key, char* element) {
	int index = hashFunction(myHashMap, key);
	struct Node* currentNode = (struct Node*) malloc(sizeof(struct Node));
	setNode(currentNode, key, element);

	if (myHashMap->hashArr[index] == NULL) {
		myHashMap->hashArr[index] = currentNode;
	} else {
		currentNode->next = myHashMap->hashArr[index];
		myHashMap->hashArr[index] = currentNode;
	}
	return;
}

void deleteKey(HashMap* myHashMap, char* key) {
	int index = hashFunction(myHashMap, key);
	struct Node* prevNode = nullptr;
	struct Node* currentNode = myHashMap->hashArr[index];
	while (currentNode != nullptr) {
		if (strcmp(key, currentNode->key) == 0) {
			myHashMap->hashArr[index] = currentNode->next;

			if (currentNode == myHashMap->hashArr[index]) {
				myHashMap->hashArr[index] = currentNode->next;
			} else {
				prevNode->next = currentNode->next;
			}
			free(currentNode); // fail safe
			break;
		}
		prevNode = currentNode;
		currentNode = currentNode->next;
	}
	return;
}

// Basic implementation of a Hash table to see how hash functions work
