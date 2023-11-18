#include <stdio.h>

/**
 * @brief Searches for a given value in an array.
 * @param arr The array to use for searching.
 * @param length The number of elements in the array.
 * @return The index of the first occurrence of the value in the array or -1 if the value is not found.
 * @details Time Complexity: O(n)
 * @details Input: arr sequence of n numbers arr = {a1, a2, ..., an} and a value v.
 * @details Output: index of the first occurrence of the value in the array or -1 if the value is not found.
 * @details Loop Invariant: At the start of each iteration of the for loop, the subarray arr[0..cur-1] does not contain the value v.
 * @details Initialization: cur = 0 as arr[0..0] is empty.
 * @details Maintenance: Each iteration of the for loop checks if the current element is equal to the value v.
 * @details Termination: The subarray arr[0..cur-1] does not contain the value v.
 */
int linear_search(const int arr[], int length, int v) {

	// LINEAR-SEARCH(A,n,v):
	// for i = 0 to A.length - 1
	//   if A[i] == v
	//     return i
	// return -1

	for (int i = 0; i < length; i++) {
		if (arr[i] == v) {
			return i;
		}
	}

	return -1;
}

int main() {
	// The array to be summed.
	int A[] = {5, 2, 15, 13, 4, 6, 1, 3, 9, 12, 11};

	// Number of elements in the array.
	int lengthOfA = sizeof(A) / sizeof(int);

	int indexExisting = linear_search(A, lengthOfA, 9);
	printf_s("\nIndex: %d", indexExisting);

	int indexNonExisting = linear_search(A, lengthOfA, 99);
	printf_s("\nIndex: %d", indexNonExisting);

	return 0;
}
