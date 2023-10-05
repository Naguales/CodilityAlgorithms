// 1. CyclicRotation.

/**
 * An array A consisting of N integers is given.
 * Rotation of the array means that each element is shifted right by one index,
 * and the last element of the array is moved to the first place.
 * 
 * For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7]
 * (elements are shifted right by one index and 6 is moved to the first place).
 * 
 * The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.
 * 
 * Write a function:
 *      class Solution { public int[] solution(int[] A, int K); }
 * that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.
 * 
 * Assume that:
 *      • N and K are integers within the range [0..100];
 *      • each element of array A is an integer within the range [−1,000..1,000].
 * In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
 */

#include <vector>

std::vector<int> cyclicRotation(std::vector<int>& A, int K)
{
    if (A.empty() || !K) {
        return A;
    }
    
    // Calculate the effective rotation amount.
    K %= A.size();

    // Rotate the vector elements by k positions to the right.
    std::rotate(std::rbegin(A), std::rbegin(A) + K, std::rend(A));

    return A;
}
