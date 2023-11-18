#include <stdio.h>
#include "../helper/helper.h"

/**
 * @brief Adds two n-bit binary integers.
 * @param A The first n-bit binary integer represented as an array of bits.
 * @param B The second n-bit binary integer represented as an array of bits.
 * @param length The number of bits in binary integers.
 * @param C Output sum of the two n-bit binary integers represented as an array of bits, expected to be of length n + 1 for carry.
 * @details Time Complexity: O(n)
 * @details Input: A and B two n-bit binary integers represented as arrays of bits (A = {a1, a2, ..., an} and B = {b1, b2, ..., bn}), where any an or bn are either 0 or 1.
 * @details Output: n-bit binary integer C = {c1, c2, ..., cn} represented as an array of bits, where any cn is either 0 or 1.
 * @details Loop Invariant: At the start of each iteration of the for loop, the array C[0..i] contains the i least significant bits of the sum of the two n-bit binary integers A[0..n-1] and B[0..n-1].
 * @details Initialization: i = 0 and therefor the array C[0..i] contains the 0 least significant bits of the sum of the two n-bit binary integers A[0..n-1] and B[0..n-1].
 * @details Maintenance: Each iteration of the loop adds the i-th least significant bits of the two n-bit binary integers A[0..n-1] and B[0..n-1] and stores the result in C[i]. The carry is stored in carry.
 * @details Termination: The loop terminates when i == length. If the loop terminates, the array C[0..i] contains the i least significant bits of the sum of the two n-bit binary integers A[0..n-1] and B[0..n-1].
 */
void add_binary_integers(const int *A, const int *B, int length, int *C) {

	// ADD-BINARY-INTEGERS(A,B,n):
	// for i = 0 to n - 1
	//   C[i] = 0
	// carry = 0
	// for i = n - 1 downto 0
	//   C[i+1] = (A[i] + B[i] + carry) % 2
	//     if A[i] + B[i] + carry > 1
	//       carry = 1
	//     else
	//       carry = 0
	// C[0] = carry

	// Initialize C to 0.
	for (int i = 0; i < length; i++) {
		C[i] = 0;
	}

	int carry = 0;

	// Add the bits.
	for (int i = length - 1; i >= 0; i--) {
		// Use modulo 2 to get the least significant bit and use i+1 to get the correct index (leave the first index for the carry).
		C[i + 1] = (A[i] + B[i] + carry) % 2;
		if (A[i] + B[i] + carry > 1) {
			carry = 1;
		} else {
			carry = 0;
		}
	}

	// Set the first index to the carry.
	C[0] = carry;
}

int main() {
	// The arrays to use.

	// int A[] = {1, 1, 1, 1};
	// int B[] = {1, 1, 1, 1};
	// int C[5]; // +1 for carry
	// expected = 15 + 15;

	// int A[] = {1, 1, 1, 1, 1, 1, 1, 1};
	// int B[] = {1, 1, 1, 1, 1, 1, 1, 1};
	// int C[9]; // +1 for carry
	// expected = 511 + 511;

	int A[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int B[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int C[17]; // +1 for carry
	int expected = 65535 + 65535;

	// Number of elements in the array.
	int length = sizeof(A) / sizeof(int);

	print_arr(A, length, -1, "A  ");
	print_arr(B, length, -1, "B  ");

	add_binary_integers(A, B, length, C);

	print_arr(C, length + 1, -1, "C");

	int acc = 0;
	for (int i = 0; i < length + 1; i++) {
		acc += C[i] * (1 << (length - i));
	}
	printf_s("\nResult (dec): %d", acc);

	if (acc == expected) {
		printf_s("\nResult (dec) is correct!");
	} else {
		printf_s("\nResult (dec) is incorrect!");
	}

	return 0;
}
