// 3. MaxDoubleSliceSum.

/**
 * A non-empty array A consisting of N integers is given.
 * A triplet (X, Y, Z), such that 0 ≤ X < Y < Z < N, is called a double slice.
 * The sum of double slice (X, Y, Z) is the total of
 * A[X + 1] + A[X + 2] + ... + A[Y − 1] + A[Y + 1] + A[Y + 2] + ... + A[Z − 1].
 * 
 * For example, array A such that:
 *       A[0] = 3 A[1] = 2 A[2] = 6 A[3] = -1 A[4] = 4 A[5] = 5 A[6] = -1 A[7] = 2
 * contains the following example double slices:
 *       • double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
 *       • double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 − 1 = 16,
 *       • double slice (3, 4, 5), sum is 0.
 * 
 * The goal is to find the maximal sum of any double slice.
 * 
 * Write a function:
 *       class Solution { public int solution(int[] A); }
 * that, given a non-empty array A consisting of N integers,
 * returns the maximal sum of any double slice.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [3..100,000];
 *       • each element of array A is an integer within the range [−10,000..10,000].
 */

#include <vector>
#include <algorithm>

int maxDoubleSliceSum(std::vector<int>& A)
{
    int N = (int)A.size();
    if (N < 3) {
        return 0;
    }

    std::vector<int> forwardLocalMaxSlices(N, 0),
                     backwardLocalMaxSlices(N, 0);
    
    // Calculate the maximum local slices ending at each position from left to right.
    // Start at i=1 as a slice cannot originate from index 0.
    for (int i = 1; i < N - 1; ++i) {
        forwardLocalMaxSlices[i] = std::max(forwardLocalMaxSlices[i - 1] + A[i], 0);
    }

    // Calculate the maximum local slices starting at each position from right to left.
    // Start from i = length - 2 as a slice cannot end at index length - 1.
    for (int i = N - 2; i > 0; --i) {
        backwardLocalMaxSlices[i] = std::max(backwardLocalMaxSlices[i + 1] + A[i], 0);
    }

    // To determine the absolute maximum, Calculate the maximum sum of two non-overlapping subarrays 
    // by summing the subarray that ends before a specific index with the subarray that starts after that index.
    int maxDoubleSliceSum = 0;
    for (int i = 1; i < N - 1; ++i) {
        maxDoubleSliceSum = std::max(maxDoubleSliceSum,
            forwardLocalMaxSlices[i - 1] + backwardLocalMaxSlices[i + 1]);
    }

    return maxDoubleSliceSum;
}
