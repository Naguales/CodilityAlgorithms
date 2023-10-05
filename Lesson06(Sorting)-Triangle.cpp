// 3. Triangle.

/**
 * An array A consisting of N integers is given.
 * A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:
 *       • A[P] + A[Q] > A[R],
 *       • A[Q] + A[R] > A[P],
 *       • A[R] + A[P] > A[Q].
 * 
 * For example, consider array A such that:
 *       A[0] = 10    A[1] = 2    A[2] = 5
 *       A[3] = 1     A[4] = 8    A[5] = 20
 * Triplet (0, 2, 4) is triangular.
 * 
 * Write a function:
 *       class Solution { public int solution(int[] A); }
 * that, given an array A consisting of N integers,
 * returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [0..100,000];
 *       • each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
 */

#include <vector>
#include <algorithm>

int triangle(std::vector<int>& A)
{
    const unsigned int N = A.size();
    if (N < 3) {
        return 0;
    }

    std::vector<long> ordered(std::begin(A), std::end(A));

    // Sort the 'ordered' vector in ascending order.
    std::sort(std::begin(ordered), std::end(ordered));
    for (unsigned int i = 0; i < N - 2; ++i) {
        // Check if the current elements satisfy the triangular triplet conditions.
        if (ordered[i] + ordered[i + 1] > ordered[i + 2]) {
            return 1;
        }
    }

    return 0;
}
