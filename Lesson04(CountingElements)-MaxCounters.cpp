// 3. MaxCounters.

/**
 *  You are given N counters, initially set to 0, and you have two possible operations on them:
 *       • increase(X) − counter X is increased by 1,
 *       • max counter − all counters are set to the maximum value of any counter.
 *
 * A non-empty array A of M integers is given. This array represents consecutive operations:
 *       • if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
 *       • if A[K] = N + 1 then operation K is max counter.
 * 
 * For example, given integer N = 5 and array A such that:
 *       A[0] = 3
 *       A[1] = 4
 *       A[2] = 4
 *       A[3] = 6
 *       A[4] = 1
 *       A[5] = 4
 *       A[6] = 4
 * 
 *  the values of the counters after each consecutive operation will be:
 *       (0, 0, 1, 0, 0)
 *       (0, 0, 1, 1, 0)
 *       (0, 0, 1, 2, 0)
 *       (2, 2, 2, 2, 2)
 *       (3, 2, 2, 2, 2)
 *       (3, 2, 2, 3, 2)
 *       (3, 2, 2, 4, 2)
 * 
 *  The goal is to calculate the value of every counter after all operations.
 * 
 *  Write a function:
 *       class Solution { public int[] solution(int N, int[] A); }
 *  that, given an integer N and a non-empty array A consisting of M integers,
 *  returns a sequence of integers representing the values of the counters.
 *  Result array should be returned as an array of integers.
 * 
 *  Write an efficient algorithm for the following assumptions:
 *       • N and M are integers within the range [1..100,000];
 *       • each element of array A is an integer within the range [1..N + 1].
 */

#include <vector>
#include <algorithm>

std::vector<int> maxCounters(int N, std::vector<int>& A)
{
    std::vector<int> result(N, 0);
    int max = 0, curMax = 0;    // Keep track of the maximum value and current maximum.

    for (int i : A) {
        if (i > N) {
            // If the value in A is greater than N, it means it's a "max counter" operation.
            // Set the 'max' variable to the current maximum value of counters.
            max = curMax;
        } else {
            // If the value in A is in the range [1, N], it's an "increase(X)" operation.
            // Update the value in the 'result' vector accordingly.
            result[i - 1] = result[i - 1] < max ? max + 1 : ++result[i - 1];
            curMax = std::max(curMax, result[i - 1]);
        }
    }

    // After processing all operations, some counters may still be less than 'max'.
    // Transform the 'result' vector to ensure that all counters have a minimum value of 'max'.
    std::transform(std::cbegin(result), std::cend(result), std::begin(result), [max](int i) {
        return i < max ? max : i;
    });

    return result;
}
