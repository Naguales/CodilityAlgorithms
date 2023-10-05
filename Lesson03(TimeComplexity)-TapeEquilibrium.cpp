// 3. TapeEquilibrium.

/**
 * A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.
 * 
 * Any integer P, such that 0 < P < N, splits this tape into two non-empty parts:
 *      A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].
 * 
 * The difference between the two parts is the value of:
 *      |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|
 * 
 * In other words, it is the absolute difference between the sum of the first part and the sum of the second part.
 * 
 * Write a function:
 *      class Solution { public int solution(int[] A); }
 * that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.
 * 
 * Write an efficient algorithm for the following assumptions:
 *      • N is an integer within the range [2..100,000];
 *      • each element of array A is an integer within the range [−1,000..1,000].
 */

#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>

int tapeEquilibrium(std::vector<int>& A)
{
    int minDifference = std::numeric_limits<int>::max(),
        length = (int)A.size(),
        sumLeftPart = 0,
        sumRightPart = 0,
        totalSum = std::accumulate(std::begin(A), std::end(A), 0);
    
    for (int i = 0; i < length - 1; ++i) {
        sumLeftPart += A[i];
        sumRightPart = totalSum - sumLeftPart;
        minDifference = std::min(minDifference, std::abs(sumLeftPart - sumRightPart));
    }

    return minDifference;
}
