#include <stdio.h>

/**
 * @brief Searches for a given value in an array.
 * @param arr The array to use for searching.
 * @param length The number of elements in the array.
 * @return The index of the first occurrence of the value in the array or -1 if the value is not found.
 * @details Time Complexity: O(n)
 * @details Input: arr sequence of n numbers arr = {a1, a2, ..., an} and a value v.
 * @details Output: index of the first occurrence of the value in the array or -1 if the value is not found.
 * @details Loop Invariant: At the start of each iteration of the for loop, there is no index k < cur such that arr[k] == v.
 * @details Initialization: cur = 0 and therefor there is no index k < cur such that arr[k] == v.
 * @details Maintenance: Each iteration of the loop checks if the current element is equal to v. If it is, the index is returned.
 * @details Termination: The loop terminates when cur == length. If the loop terminates, there is no index k < cur such that arr[k] == v.
 */
int linear_search(const int arr[], int length, int v) {

	// LINEAR-SEARCH(A,n,v):
	// for i = 0 to A.length - 1
	//   if A[i] == v
	//     return i
	// return -1

	for (int cur = 0; cur < length; cur++) {
		if (arr[cur] == v) {
			return cur;
		}
	}

	return -1;
}

int main() {
	// The array to use.
	int A[] = {5, 2, 15, 13, 4, 6, 1, 3, 9, 12, 11};

	// Number of elements in the array.
	int lengthOfA = sizeof(A) / sizeof(int);

	int indexExisting = linear_search(A, lengthOfA, 9);
	printf_s("\nIndex of 9: %d", indexExisting);

	int indexNonExisting = linear_search(A, lengthOfA, 99);
	printf_s("\nIndex of 99: %d", indexNonExisting);

	return 0;
}
