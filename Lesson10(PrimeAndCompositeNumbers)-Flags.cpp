// 3. Flags.

/**
 * A non-empty array A consisting of N integers is given.
 * A peak is an array element which is larger than its neighbours.
 * More precisely, it is an index P such that 0 < P < N − 1 and A[P − 1] < A[P] > A[P + 1].
 * 
 * For example, the following array A:
 *       A[0] = 1 A[1] = 5 A[2] = 3 A[3] = 4 A[4] = 3 A[5] = 4 A[6] = 1 
 *       A[7] = 2 A[8] = 3 A[9] = 4 A[10] = 6 A[11] = 2
 * has exactly four peaks: elements 1, 3, 5 and 10.
 * 
 * You are going on a trip to a range of mountains
 * whose relative heights are represented by array A, as shown in a figure below.
 * You have to choose how many flags you should take with you.
 * The goal is to set the maximum number of flags on the peaks, according to certain rules.
 * 
 *                                Peak 10
 *                                   *
 *                                  / \
 *                                 /   \     
 *     Peak 1                     /     \
 *        *   Peak 3 Peak 5      /       \
 *       / \    *    *          /         \
 *      /   \  / \  / \        /           \
 *     /     \/   \/   \      /             \
 *    /                 \    /
 *   /                   \  /
 *  *                     \/
 * 
 * Flags can only be set on peaks.
 * What's more, if you take K flags, then the distance between any two flags should be greater than or equal to K.
 * The distance between indices P and Q is the absolute value |P − Q|.
 * 
 * For example, given the mountain range represented by array A, above, with N = 12, if you take:
 *       • two flags, you can set them on peaks 1 and 5;
 *       • three flags, you can set them on peaks 1, 5 and 10;
 *       • four flags, you can set only three flags, on peaks 1, 5 and 10.
 * You can therefore set a maximum of three flags in this case.
 * 
 * Write a function:
 *       class Solution { public int solution(int[] A); }
 * that, given a non-empty array A of N integers, returns the maximum number of flags that can be set on the peaks of the array.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [1..400,000];
 *       • each element of array A is an integer within the range [0..1,000,000,000].
 */

#include <vector>
#include <algorithm>
#include <cmath>

int flags(std::vector<int>& A)
{
    int N = (int)A.size();

    // If there are less than 3 elements, it's impossible to place flags.
    if (N < 3) {
        return 0;
    }

    // Detect all peaks and store their positions in the 'peaks' vector.
    std::vector<int> peaks;
    for (int i = 1; i < N - 1; ++i) {
        if (A[i] > std::max(A[i - 1], A[i + 1])) {
            peaks.push_back(i);
            i++; // Skip the next element since it cannot be a peak.
        }
    }

    const int numPeaks = peaks.size();
    if (numPeaks <= 1) {
        return numPeaks;
    }

    // The square root is used because it helps determine the maximum number of flags
    // that can be placed on peaks while maintaining a minimum distance between them.
    const int maxPossibleNumFlags = int(std::sqrt(peaks[numPeaks - 1] - peaks[0])) + 1;
    int maxNumFlags = 0;

    // Check all possible numbers of flags from 2 to the maximum possible.
    for (int flags = 2; flags <= maxPossibleNumFlags; ++flags) {
        int flagsPlaced = 1,
            position = peaks[0];

        for (int i = 1; i < numPeaks; ++i) {
            if (peaks[i] - position >= flags) {
                flagsPlaced++;
                position = peaks[i];
            }

            if (flagsPlaced == flags) {
                maxNumFlags = flags;
                break;
            }
        }

        if (flagsPlaced != flags) {
            break; // No more flags can be placed, so break the loop.
        }
    }

    return maxNumFlags;
}
