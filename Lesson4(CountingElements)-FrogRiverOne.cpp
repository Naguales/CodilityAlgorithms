// 1. FrogRiverOne.

/**
 * A small frog wants to get to the other side of a river.
 * The frog is initially located on one bank of the river (position 0) and wants to get to the opposite bank (position X + 1).
 * Leaves fall from a tree onto the surface of the river.
 * 
 * You are given an array A consisting of N integers representing the falling leaves.
 * A[K] represents the position where one leaf falls at time K, measured in seconds.
 * 
 * The goal is to find the earliest time when the frog can jump to the other side of the river.
 * The frog can cross only when leaves appear at every position across the river from 1 to X
 * (that is, we want to find the earliest moment when all the positions from 1 to X are covered by leaves).
 * You may assume that the speed of the current in the river is negligibly small,
 * i.e. the leaves do not change their positions once they fall in the river.
 * 
 * Write a function:
 *      class Solution { public int solution(int X, int[] A); }
 * that, given a non-empty array A consisting of N integers and integer X,
 * returns the earliest time when the frog can jump to the other side of the river.
 * If the frog is never able to jump to the other side of the river, the function should return −1.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N and X are integers within the range [1..100,000];
 *       • each element of array A is an integer within the range [1..X].
 */

#include <vector>

int frogRiverOne(int X, std::vector<int>& A)
{
    std::vector<bool> leafPositions(X, false);
    int jumpCount = 0;
    const int length = (int)A.size();

    for (int sec = 0; sec < length; ++sec) {
        int pos = A[sec];
        // If the leaf position is greater than X, skip it.
        if (pos > X) {
            continue;
        }
        
        // If this leaf position has not been encountered before, mark it as encountered.
        if (!leafPositions[pos - 1]) {
            leafPositions[pos - 1] = true;
            // If the frog has covered all positions from 1 to X, return the current second.
            if (++jumpCount == X) {
                return sec;
            }
        }
    }

    return -1;
}
