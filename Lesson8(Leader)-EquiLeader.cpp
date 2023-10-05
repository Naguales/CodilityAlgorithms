// 2. EquiLeader.

/**
 * A non-empty array A consisting of N integers is given.
 * The leader of this array is the value that occurs in more than half of the elements of A.
 * 
 * An equi leader is an index S such that 0 ≤ S < N − 1
 * and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.
 * 
 * For example, given array A such that:
 *       A[0] = 4 A[1] = 3 A[2] = 4 A[3] = 4 A[4] = 4 A[5] = 2
 * we can find two equi leaders:
 *       • 0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
 *       • 2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
 * 
 * The goal is to count the number of equi leaders.
 * 
 * Write a function:
 *       class Solution { public int solution(int[] A); }
 * that, given a non-empty array A consisting of N integers, returns the number of equi leaders.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [1..100,000];
 *       • each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
 */

#include <vector>
#include <stack>
#include <unordered_map>

int equiLeader(std::vector<int>& A)
{
    std::stack<int> auxStack;   // A stack to track candidate elements.
    
    // Identify the dominator in the entire sequence;
    // if there is no dominator, equi-leaders cannot exist.
    
    // If the sequence has a leader, removing different-value element pairs
    // won't change the remaining sequence's leader.
    for (int i : A) {
        if (auxStack.empty()) {
            auxStack.push(i);
        } else {
            if (auxStack.top() == i) {
                auxStack.push(i);
            } else {
                auxStack.pop();
            }
        }
    }

    if (auxStack.empty()) {
        return 0;
    }

    int candidate = auxStack.top(),
        length = (int)A.size(),
        dominatorCount = 0;
    
    // Count the occurrences of the dominator candidate element and store them in a map.
    std::unordered_map<int, int> dominatorMap;
    for (int i = 0; i < length; ++i) {
        if (A[i] == candidate) {
            dominatorMap[i] = ++dominatorCount;
        }
    }

    int equiLeaders = 0;
    if (dominatorCount > length / 2) {
        int lastCandidateOccurrenceIndex = 0,
            runningDominatorCount = 0;  // Holds the dominator count within the left subsequence.
        
        // Determine the presence of an equi-leader pair at each index within the given sequence.
        for (int i = 0; i < length - 1; ++i) {
            if (A[i] == candidate) {
                lastCandidateOccurrenceIndex = i;
                runningDominatorCount = dominatorMap[i];
            } else if (dominatorMap.count(lastCandidateOccurrenceIndex)) {
                runningDominatorCount = dominatorMap[lastCandidateOccurrenceIndex];
            }

            // Verify the fulfillment of equi-leader conditions in both the left and right subsequences.
            if (runningDominatorCount > (i + 1) / 2
                && (dominatorCount - runningDominatorCount) > (length - (i + 1)) / 2) {
                equiLeaders++;
            }
        }
    }

    return equiLeaders;
}
