// 1. AbsDistinct

/**
 * A non-empty array A consisting of N numbers is given.
 * The array is sorted in non-decreasing order.
 * The absolute distinct count of this array
 * is the number of distinct absolute values among the elements of the array.
 * 
 * For example, consider array A such that:
 *       A[0] = -5 A[1] = -3 A[2] = -1 A[3] = 0 A[4] = 3 A[5] = 6
 * The absolute distinct count of this array is 5,
 * because there are 5 distinct absolute values among the elements of this array, namely 0, 1, 3, 5 and 6.
 * 
 * Write a function:
 *       class Solution { public int solution(int[] A); }
 * that, given a non-empty array A consisting of N numbers, returns absolute distinct count of array A.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [1..100,000];
 *       • each element of array A is an integer within the range [−2,147,483,648..2,147,483,647];
 *       • array A is sorted in non-decreasing order.
 */

#include <vector>
#include <algorithm>

int absDistinct(std::vector<int>& A)
{
    int absDistinctCount = 0,
        head = 0,
        tail = (int)A.size() - 1;
    
    while (head <= tail) {
        // Move the head and tail pointers towards each other.
        while (head < tail && A[head] == A[head + 1]) {
            head++;
        }
        while (head < tail && A[tail] == A[tail - 1]) {
            tail--;
        }

        // Check for distinct absolute values.
        long absHead = std::abs((long)A[head]),
             absTail = std::abs((long)A[tail]);
        if (absHead == absTail) {
            head++;
            tail--;
        } else if (absHead < absTail) {
            tail--;
        } else {
            head++;
        }

        absDistinctCount++;
    }

    return absDistinctCount;
}
