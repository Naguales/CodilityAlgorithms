// 1. BinaryGap.

/**
 * A binary gap within a positive integer N is any maximal sequence of consecutive zeros
 * that is surrounded by ones at both ends in the binary representation of N.
 * 
 * Write a function:
 *      class Solution { public int solution(int N); }
 * that, given a positive integer N, returns the length of its longest binary gap.
 * The function should return 0 if N doesn't contain a binary gap.
 * 
 * Write an efficient algorithm for the following assumptions:
 *      • N is an integer within the range [1..2,147,483,647].
 */ 

#include <algorithm>

int binaryGap(int N)
{
    int lastOne = 32,
        answer = 0;

    // Iterate through each bit of N from the least significant bit to the most significant bit.    
    for (int i = 0; i < 32; ++i) {
        // Check if the current bit is set (equal to 1).
        if (N & (1 << i)) {
            // Calculate the length of the binary gap between the current set bit and the previous set bit.
            answer = std::max(answer, i - lastOne - 1);
            lastOne = i;
        }
    }
    
    return answer;
}
