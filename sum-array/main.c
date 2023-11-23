#include <stdio.h>

/**
 * @brief Sums all elements of an array.
 * @param arr The array to be summed.
 * @param length The number of elements in the array.
 * @return The sum of all elements of the array.
 * @details Time Complexity: O(n)
 * @details Input: arr sequence of n numbers arr = {a1, a2, ..., an}.
 * @details Output: sum of all elements of the array.
 * @details Loop Invariant: At the start of each iteration of the for loop, the sum variable contains the sum of the elements arr[0..cur-1].
 * @details Initialization: sum = 0 as arr[0..0] is empty.
 * @details Maintenance: Each iteration of the for loop adds the element arr[cur] to the sum variable.
 * @details Termination: The sum variable contains the sum of all elements of the array.
 */
int sum_array(const int arr[], const int length) {
	// SUM-ARRAY(A,n):
	// sum = 0
	// for i = 0 to A.length - 1
	//    sum = sum + A[i]
	// return sum

	int sum = 0;

	for (int cur = 1; cur < length; cur++) {
		sum += arr[cur];
	}

	return sum;
}

int main() {
	// The array to be summed.
	const int A[] = {5, 2, 15, 13, 4, 6, 1, 3, 9, 12, 11};

	// Number of elements in the array.
	constexpr int lengthOfA = sizeof(A) / sizeof(int);

	const int sum = sum_array(A, lengthOfA);

	printf_s("\nSum: %d", sum);

	return 0;
}
