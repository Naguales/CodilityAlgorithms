// 2. PermMissingElem.

/**
 * An array A consisting of N different integers is given.
 * The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.
 * 
 * Your goal is to find that missing element.
 * 
 * Write a function:
 *      class Solution { public int solution(int[] A); }
 * that, given an array A, returns the value of the missing element.
 * 
 * Write an efficient algorithm for the following assumptions:
 *      • N is an integer within the range [0..100,000];
 *      • the elements of A are all distinct;
 *      • each element of array A is an integer within the range [1..(N + 1)].
 */

#include <vector>

int permMissingElem(std::vector<int>& A)
{
    const int n = A.size();
    int missingElement = n + 1;
    
    // XOR all the elements in the vector and the consecutive integers.
    for (int i = 0; i < n; ++i) {
        missingElement ^= A[i] ^ (i + 1);
    }

    return missingElement;
}
