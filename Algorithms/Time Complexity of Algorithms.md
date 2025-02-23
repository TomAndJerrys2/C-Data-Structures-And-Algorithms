- **Constant Time:** $O(1)$ *Simple statements, IO Operations*
- **Linear Time:** $O(n)$ *Basic Conditionals/Control-Flow statements, Read/Writing etc (simple recursion too)*
- **Quadratic Time:** $O(n^2)$ *Nested Control-Flow / Loop statements*
- **Polynomial Time / Exponential Time:** $O(n^x)$ *Increasing nested logic or conditionals, O approach's worst-time as x, the power, increases.*
- **Logarithmic Time:** $O(log(n))$*
# Insertion Sort
An *insertion sort* - is a type of simple sorting algorithm that builds the final sorted array one item
at a time by comparisons.

*Pseudo-code:*
```c++
void insertionSort (int myArr[], int n) {
		int i, j, key;
		// inital loop to loop through and compare the values
		for(int i = 1; i < n; i++) {
			key = arr[i] // each element is checked
			j = i - 1 // the previous element
			while(j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;
			}
			arr[j + 1] = key;
		}
}
```

[^1]The best-case Time complexity for an insertion sort is $O(n)$
In the worst-case Time complexity, or $Ω(n)$, for an insertion sort is $O(n^2)$

# Merge Sort
A *Merge sort* is a algorithm that follows the divide-and-conquer approach, in which, it works by dividing the input array into smaller sub-arrays and sorting those and merging them back together to obtain the sorted array.

*Pseudo-code:*
```c++
void mergeSort(int myArr[], const int begin, const int end) {
	// recursive end-case
	if(begin >= end) {
		return;
	}

	auto mid = begin + (end - begin) / 2
	mergeSort(myArr, begin, mid);
	mergeSort(myArr, mid + 1, end);
	merge(myArr, begin, mid, end); 
	// some arbitrary function that combines the sorted sub arrays
}
```

[^2]The Time complexity for a Merge sort in both best-case and worst-case is usually $O(nlog(n))$

# Quick Sort
A Quick sort is a sorting algorithm that also follows the divide-and-conquer method. It picks an element as a pivot and partitions the given around around that picked pivot by placing the pivot in its correct position in the sorted array.

*Pseudo-code:*
```c++
void quickSort(int myArr[], int low, int high) {
	 if(low > high) {
		int Par = partition(myArr. low, high);
		// Will seperatley sort the elements in an arbitrary function
		quickSort(myArr, low, Par - 1);
		quickSort(myArr, Par + 1, high);
	 }
}
```

[^3]The Time Complexity of a Quick sort in best-case is $O(nlog(n))$
The Worst case is $O(n^2)$

# Bubble Sort
A Bubble sort is where we swap adjacent elements until the array is sorted. We do this by usually having a pointer to an element and comparing whether the next element is smaller. If the adjacent element is smaller we swap and keep looping until the array is in order.

*Pseudo-code:*
```c++
void bubbleSort(myArr[], int n) {
	int i, j;
	bool swapped;
	for(i = 0; i < (n - 1); i++) {
		swapped = false;
		for(j = 0; j < (n - i - 1); j++) {
			if(arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		if(!swapped) break;
	}
}
```

[^4]the best-case Time complexity for a Bubble sort is $O(n)$
the worst-case Time Complexity for a Bubble sort is $O(n^2)$

# Linear Search

No explanation needed

*Pseudo-code:*
```c++
int searchArr(int myArr[], int n, int x) {
	int i;
	for(i = 0; i < n; i++) {
		if(arr[i] == x)
			return i;
		return -1;
	}
}
```

[^5]best-case Time complexity for a Linear search is $O(1)$
worst-case Time complexity is $O(n)$

# Binary Search
Binary search is a searching algorithm that is used by repeatedly dividing the search intervals in half. Like starting from half way in a phone book and ripping half the pages where the number is too big or too small. Doing this recursively until you find the right number

*Pseudo-code:*
```c++
int binarySearch(int myArr[], int left, int right, int x) {
	if(right >= left) {
		int mid = left + (right - left) / 2;
		if(myArr[mid] == x) {
			return mid;
		}
		if(arr[mid] >=) {
			return binarySearch(myArr, left, mid - 1, x);
			return binarySearch(myArr, mid + 1, right, x);
		}
	}
}
```

the best-case Time complexity for a binary search is $O(1)$
the worst-case Time complexity is $O(log(n))$

[^1]: Insertion sort time complexity

[^2]: Merge Sort time complexity

[^3]: Quick Sort time complexity

[^4]: Bubble Sort time complexity

[^5]: Linear Search time complexity
