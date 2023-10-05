// 4. MissingInteger.

/**
 *  Write a function:
 *       class Solution { public int solution(int[] A); }
 *  that, given an array A of N integers,
 *  returns the smallest positive integer (greater than 0) that does not occur in A.
 * 
 *  For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
 * 
 *  Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [1..100,000];
 *       • each element of array A is an integer within the range [−1,000,000..1,000,000].
 */

#include <vector>
#include <algorithm>

int missingInteger(std::vector<int>& A)
{
    int min = 1;
    
    // Sort the array A in ascending order.
    std::sort(std::begin(A), std::end(A));
    for (int i : A) {
        if (i == min) {
            min++;
        } else if (i > min) {
            return min;
        }
    }

    return min;
}