// 1. Dominator.

/**
 * An array A consisting of N integers is given.
 * The dominator of array A is the value that occurs in more than half of the elements of A.
 * 
 * For example, consider array A such that
 *   A[0] = 3    A[1] = 4    A[2] =  3
 *   A[3] = 2    A[4] = 3    A[5] = -1
 *   A[6] = 3    A[7] = 3
 * 
 * The dominator of A is 3 because it occurs in 5 out of 8 elements of A
 * (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.
 * 
 * Write a function:
 *       class Solution { public int solution(int[] A); }
 * that, given an array A consisting of N integers,
 * returns index of any element of array A in which the dominator of A occurs.
 * The function should return −1 if array A does not have a dominator.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [0..100,000];
 *       • each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
 */

#include <vector>
#include <stack>

int dominator(std::vector<int>& A)
{
    std::stack<int> auxStack;   // A stack to track candidate elements.
    
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
        return -1;
    }

    int candidate = auxStack.top(),
        candidateIndex = -1,
        length = (int)A.size(),
        count = 0;
    
    for (int i = 0; i < length; ++i) {
        if (A[i] == candidate) {
            count++;
            if (candidateIndex < 0) {
                candidateIndex = i;
            }
        }
    }

    if (count > length / 2) {
        return candidateIndex;
    }

    return -1;
}
