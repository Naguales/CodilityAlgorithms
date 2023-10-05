// Lesson 1
// Iterations
// -------------------------------------------------

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

// Lesson 2
// Arrays
// -------------------------------------------------

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

// 2. OddOccurrencesInArray.

/**
 * A non-empty array A consisting of N integers is given.
 * The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value,
 * except for one element that is left unpaired.
 * 
 * For example, in array A such that:
 *      A[0] = 9  A[1] = 3  A[2] = 9 A[3] = 3  A[4] = 9  A[5] = 7 A[6] = 9
 *      • the elements at indexes 0 and 2 have value 9,
 *      • the elements at indexes 1 and 3 have value 3,
 *      • the elements at indexes 4 and 6 have value 9,
 *      • the element at index 5 has value 7 and is unpaired.
 * 
 * Write a function:
 *      class Solution { public int solution(int[] A); }
 * that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.
 * 
 * Write an efficient algorithm for the following assumptions:
 *      • N is an odd integer within the range [1..1,000,000];
 *      • each element of array A is an integer within the range [1..1,000,000,000];
 *      • all but one of the values in A occur an even number of times.
 */

#include <vector>

int oddOccurrencesInArray(std::vector<int>& A)
{
    int unpairedElement = 0;

    for (int num : A) {
        // Perform bitwise XOR operation with the current element
        // XOR operation cancels out paired elements and keeps the unpaired element.
        unpairedElement ^= num;
    }

    return unpairedElement;
}

// Lesson 3
// Time Complexity
// -------------------------------------------------

/**
 * A small frog wants to get to the other side of the road.
 * The frog is currently located at position X and wants to get to a position greater than or equal to Y.
 * The small frog always jumps a fixed distance, D.
 * 
 * Count the minimal number of jumps that the small frog must perform to reach its target.
 * 
 * Write a function:
 *      class Solution { public int solution(int X, int Y, int D); }
 * that, given three integers X, Y and D,
 * returns the minimal number of jumps from position X to a position equal to or greater than Y.
 * 
 * Write an efficient algorithm for the following assumptions:
 *      • X, Y and D are integers within the range [1..1,000,000,000];
 *      • X ≤ Y.
 */

#include <cmath>

int frogJmp(int X, int Y, int D)
{
    // Divide the distance to be covered (Y - X) by the distance of each jump (D).
    // Use std::ceil to round up the result to the nearest integer.
    // This ensures that the frog reaches or surpasses the target position.
    return std::ceil((Y - X) / (double)D);
}

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

// 3. TapeEquilibrium.

/**
 * A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.
 * 
 * Any integer P, such that 0 < P < N, splits this tape into two non-empty parts:
 *      A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].
 * 
 * The difference between the two parts is the value of:
 *      |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|
 * 
 * In other words, it is the absolute difference between the sum of the first part and the sum of the second part.
 * 
 * Write a function:
 *      class Solution { public int solution(int[] A); }
 * that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.
 * 
 * Write an efficient algorithm for the following assumptions:
 *      • N is an integer within the range [2..100,000];
 *      • each element of array A is an integer within the range [−1,000..1,000].
 */

#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>

int tapeEquilibrium(std::vector<int>& A)
{
    int minDifference = std::numeric_limits<int>::max(),
        length = (int)A.size(),
        sumLeftPart = 0,
        sumRightPart = 0,
        totalSum = std::accumulate(std::begin(A), std::end(A), 0);
    
    for (int i = 0; i < length - 1; ++i) {
        sumLeftPart += A[i];
        sumRightPart = totalSum - sumLeftPart;
        minDifference = std::min(minDifference, std::abs(sumLeftPart - sumRightPart));
    }

    return minDifference;
}

// Lesson 4
// Counting Elements
// -------------------------------------------------

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

// 2. PermCheck.

/**
 * A non-empty array A consisting of N integers is given.
 * A permutation is a sequence containing each element from 1 to N once, and only once.
 * 
 * For example, array A such that:
 *       A[0] = 4 A[1] = 1 A[2] = 3 A[3] = 2
 * is a permutation, but array A such that:
 *       A[0] = 4 A[1] = 1 A[2] = 3
 * is not a permutation, because value 2 is missing.
 * 
 * The goal is to check whether array A is a permutation.
 * 
 * Write a function:
 *       class Solution { public int solution(int[] A); }
 * that, given an array A, returns 1 if array A is a permutation and 0 if it is not.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [1..100,000];
 *       • each element of array A is an integer within the range [1..1,000,000,000].
 */

#include <vector>

int permCheck(std::vector<int>& A)
{
    int N = (int)A.size(),
        result = 0;

    for (int i = 0; i < N; ++i) {
        // Perform an XOR operation on the expected values from 1 to N and the values in the array A.
        // XOR (^) is used to check if all values from 1 to N are present in A only once.
        result ^= (i + 1) ^ A[i];
    }

    return !result;
}

// 3. MaxCounters.

/**
 *  You are given N counters, initially set to 0, and you have two possible operations on them:
 *       • increase(X) − counter X is increased by 1,
 *       • max counter − all counters are set to the maximum value of any counter.
 *
 * A non-empty array A of M integers is given. This array represents consecutive operations:
 *       • if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
 *       • if A[K] = N + 1 then operation K is max counter.
 * 
 * For example, given integer N = 5 and array A such that:
 *       A[0] = 3
 *       A[1] = 4
 *       A[2] = 4
 *       A[3] = 6
 *       A[4] = 1
 *       A[5] = 4
 *       A[6] = 4
 * 
 *  the values of the counters after each consecutive operation will be:
 *       (0, 0, 1, 0, 0)
 *       (0, 0, 1, 1, 0)
 *       (0, 0, 1, 2, 0)
 *       (2, 2, 2, 2, 2)
 *       (3, 2, 2, 2, 2)
 *       (3, 2, 2, 3, 2)
 *       (3, 2, 2, 4, 2)
 * 
 *  The goal is to calculate the value of every counter after all operations.
 * 
 *  Write a function:
 *       class Solution { public int[] solution(int N, int[] A); }
 *  that, given an integer N and a non-empty array A consisting of M integers,
 *  returns a sequence of integers representing the values of the counters.
 *  Result array should be returned as an array of integers.
 * 
 *  Write an efficient algorithm for the following assumptions:
 *       • N and M are integers within the range [1..100,000];
 *       • each element of array A is an integer within the range [1..N + 1].
 */

#include <vector>
#include <algorithm>

std::vector<int> maxCounters(int N, std::vector<int>& A)
{
    std::vector<int> result(N, 0);
    int max = 0, curMax = 0;    // Keep track of the maximum value and current maximum.

    for (int i : A) {
        if (i > N) {
            // If the value in A is greater than N, it means it's a "max counter" operation.
            // Set the 'max' variable to the current maximum value of counters.
            max = curMax;
        } else {
            // If the value in A is in the range [1, N], it's an "increase(X)" operation.
            // Update the value in the 'result' vector accordingly.
            result[i - 1] = result[i - 1] < max ? max + 1 : ++result[i - 1];
            curMax = std::max(curMax, result[i - 1]);
        }
    }

    // After processing all operations, some counters may still be less than 'max'.
    // Transform the 'result' vector to ensure that all counters have a minimum value of 'max'.
    std::transform(std::cbegin(result), std::cend(result), std::begin(result), [max](int i) {
        return i < max ? max : i;
    });

    return result;
}

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

// Lesson 5
// Prefix Sums
// -------------------------------------------------

// 1. PassingCars.

/**
 * A non-empty array A consisting of N integers is given.
 * The consecutive elements of array A represent consecutive cars on a road.
 * Array A contains only 0s and/or 1s:
 *       • 0 represents a car traveling east,
 *       • 1 represents a car traveling west.
 * 
 *  The goal is to count passing cars.
 *  We say that a pair of cars (P, Q), where 0 ≤ P < Q < N,
 *  is passing when P is traveling to the east and Q is traveling to the west.
 * 
 *  For example, consider array A such that:
 *       A[0] = 0 A[1] = 1 A[2] = 0 A[3] = 1 A[4] = 1
 * 
 *  We have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4).
 * 
 *  Write a function:
 *       class Solution { public int solution(int[] A); }
 *  that, given a non-empty array A of N integers,
 *  returns the number of pairs of passing cars.
 * 
 *  The function should return −1 if the number of pairs of passing cars exceeds 1,000,000,000.
 * 
 *  Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [1..100,000];
 *       • each element of array A is an integer that can have one of the following values: 0, 1.
 */

#include <vector>

int passingCars(std::vector<int>& A)
{
    int carsTravelingEast = 0,
        carPasses = 0;
    
    for (int i : A) {
        if (!i) {
            carsTravelingEast++;
        } else if (i == 1) {
            carPasses += carsTravelingEast;
            if (carPasses > 1000000000) {
                return -1;
            }
        }
    }

    return carPasses;
}

// 2. CountDiv.

/**
 * Write a function:
 *       class Solution { public int solution(int A, int B, int K); }
 * that, given three integers A, B and K,
 * returns the number of integers within the range [A..B] that are divisible by K, i.e.:
 *       { i : A ≤ i ≤ B, i mod K = 0 }
 * 
 * For example, for A = 6, B = 11 and K = 2, your function should return 3,
 * because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • A and B are integers within the range [0..2,000,000,000];
 *       • K is an integer within the range [1..2,000,000,000];
 *       • A ≤ B.
 */

int countDiv(int A, int B, int K)
{
    if (A % K) {
        // If A is not divisible by K, increment A to the next multiple of K.
        A += (K - A % K);
    }

    // Reduce B to the largest multiple of K not exceeding B.
    B -= B % K;

    // Divide the range size by K and add 1 to account for the first multiple.
    return (B - A) / K + 1;
}

// Lesson 6
// Sorting
// -------------------------------------------------

// 1. Distinct.

/**
 * Write a function:
 *       class Solution { public int solution(int[] A); }
 * that, given an array A consisting of N integers,
 * returns the number of distinct values in array A.
 * 
 * For example, given array A consisting of six elements such that:
 *       A[0] = 2    A[1] = 1    A[2] = 1
 *       A[3] = 2    A[4] = 3    A[5] = 1
 * the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [0..100,000];
 *       • each element of array A is an integer within the range [−1,000,000..1,000,000].
 */

#include <vector>
#include <unordered_set>

int distinct(std::vector<int>& A)
{
    return (int)std::unordered_set<int>(std::begin(A), std::end(A)).size();
}

// 2. MaxProductOfThree.

/**
 * A non-empty array A consisting of N integers is given.
 * The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).
 * 
 * For example, array A such that:
 *       A[0] = -3 A[1] = 1 A[2] = 2 A[3] = -2 A[4] = 5 A[5] = 6
 * 
 * contains the following example triplets:
 *       • (0, 1, 2), product is −3 * 1 * 2 = −6
 *       • (1, 2, 4), product is 1 * 2 * 5 = 10
 *       • (2, 4, 5), product is 2 * 5 * 6 = 60
 * 
 * Your goal is to find the maximal product of any triplet.
 * 
 * Write a function:
 *       class Solution { public int solution(int[] A); }
 * that, given a non-empty array A,
 * returns the value of the maximal product of any triplet.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [3..100,000];
 *       • each element of array A is an integer within the range [−1,000..1,000].
 */

#include <vector>
#include <algorithm>

int maxProductOfThree(std::vector<int>& A)
{
    int n = (int)A.size();
    if (n < 3) {
        return 0;
    }

    // Sort the input vector in ascending order.
    std::sort(std::begin(A), std::end(A));

    // The maximum product of the 3 elements in a sorted vector can take on one of 4 values:
    // 1. Multiplying the first 3 elements.
    // 2. Multiplying the last 3 elements (which may signify the highest positive values).
    // 3. Multiplying the first element with the last 2 elements.
    // 4. Multiplying the first 2 elements with the last element
    //    (accounting for the potential scenario of 2 first large negative values becoming positive when multiplied
    //     and also multiplied with the last positive value).
    int tripletProduct1 = A[0] * A[1] * A[2],
        tripletProduct2 = A[n - 1] * A[n - 2] * A[n - 3],
        tripletProduct3 = A[0] * A[n - 1] * A[n - 2],
        tripletProduct4 = A[0] * A[1] * A[n - 1];

    return std::max(std::max(tripletProduct1, tripletProduct2),
        std::max(tripletProduct3, tripletProduct4));
}

// 3. Triangle.

/**
 * An array A consisting of N integers is given.
 * A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:
 *       • A[P] + A[Q] > A[R],
 *       • A[Q] + A[R] > A[P],
 *       • A[R] + A[P] > A[Q].
 * 
 * For example, consider array A such that:
 *       A[0] = 10    A[1] = 2    A[2] = 5
 *       A[3] = 1     A[4] = 8    A[5] = 20
 * Triplet (0, 2, 4) is triangular.
 * 
 * Write a function:
 *       class Solution { public int solution(int[] A); }
 * that, given an array A consisting of N integers,
 * returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [0..100,000];
 *       • each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
 */

#include <vector>
#include <algorithm>

int triangle(std::vector<int>& A)
{
    const unsigned int N = A.size();
    if (N < 3) {
        return 0;
    }

    std::vector<long> ordered(std::begin(A), std::end(A));

    // Sort the 'ordered' vector in ascending order.
    std::sort(std::begin(ordered), std::end(ordered));
    for (unsigned int i = 0; i < N - 2; ++i) {
        // Check if the current elements satisfy the triangular triplet conditions.
        if (ordered[i] + ordered[i + 1] > ordered[i + 2]) {
            return 1;
        }
    }

    return 0;
}

// Lesson 7
// Stacks and Queues
// -------------------------------------------------

// 1. Brackets.

/**
 * A string S consisting of N characters is considered to be properly nested
 * if any of the following conditions is true:
 *       • S is empty;
 *       • S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
 *       • S has the form "VW" where V and W are properly nested strings.
 * 
 * For example, the string "{[()()]}" is properly nested but "([)()]" is not.
 * 
 * Write a function:
 *       class Solution { public int solution(String S); }
 * that, given a string S consisting of N characters,
 * returns 1 if S is properly nested and 0 otherwise.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [0..200,000];
 *       • string S is made only of the following characters: '(', '{', '[', ']', '}' and/or ')'.
 */

#include <string>
#include <stack>

int brackets(std::string& S)
{
    std::stack<char> brackets;  // A stack to store opening brackets.

    for (char c : S) {
        if (c == '(' || c == '{' || c == '[') {
            // If the character is an opening bracket, push it onto the stack.
            brackets.push(c);
        } else {
            // If the character is a closing bracket, check if it matches the top of the stack.
            if (brackets.empty() || (brackets.top() == '(' && c != ')')
                || (brackets.top() == '{' && c != '}')
                || (brackets.top() == '[' && c != ']')) {
                return 0;    
            }
            // Pop the top from the stack when an appropriate closing bracket is found.
            brackets.pop();
        }
    }
    
    return brackets.empty();
}

// 3. Nesting.

/**
 * A string S consisting of N characters is called properly nested if:
 *       • S is empty;
 *       • S has the form "(U)" where U is a properly nested string;
 *       • S has the form "VW" where V and W are properly nested strings.
 * 
 * For example, string "(()(())())" is properly nested but string "())" isn't.
 * 
 * Write a function:
 *       class Solution { public int solution(String S); }
 * that, given a string S consisting of N characters,
 * returns 1 if string S is properly nested and 0 otherwise.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [0..1,000,000];
 *       • string S is made only of the characters '(' and/or ')'.
 */

#include <string>
#include <stack>

int nesting(std::string& S)
{
    std::stack<char> brackets;  // A stack to store opening brackets.
    
    for (char c : S) {
        // If the character is an opening bracket, push it onto the stack.
        if (c == '(') {
            brackets.push(c);
        } else {
            // If the character is a closing bracket, check if it matches the top of the stack.
            if (brackets.empty() || (brackets.top() == '(' && c != ')')) {
                return 0;    
            }
            // Pop the top from the stack when a closing bracket is encountered.
            brackets.pop();
        }
    }

    return brackets.empty();
}

// Lesson 8
// Leader
// -------------------------------------------------

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

// Lesson 9
// Maximum slice problem
// -------------------------------------------------

// 1. MaxProfit.

/**
 * An array A consisting of N integers is given.
 * It contains daily prices of a stock share for a period of N consecutive days.
 * If a single share was bought on day P and sold on day Q, where 0 ≤ P ≤ Q < N,
 * then the profit of such transaction is equal to A[Q] − A[P], provided that A[Q] ≥ A[P].
 * Otherwise, the transaction brings loss of A[P] − A[Q].
 * 
 * For example, consider the following array A consisting of six elements such that:
 *       A[0] = 23171 A[1] = 21011 A[2] = 21123 A[3] = 21366 A[4] = 21013 A[5] = 21367
 * 
 * If a share was bought on day 0 and sold on day 2,
 * a loss of 2048 would occur because A[2] − A[0] = 21123 − 23171 = −2048.
 * If a share was bought on day 4 and sold on day 5,
 * a profit of 354 would occur because A[5] − A[4] = 21367 − 21013 = 354.
 * Maximum possible profit was 356.
 * It would occur if a share was bought on day 1 and sold on day 5.
 * 
 * Write a function,
 *       class Solution { public int solution(int[] A); }
 * that, given an array A consisting of N integers containing daily prices
 * of a stock share for a period of N consecutive days,
 * returns the maximum possible profit from one transaction during this period.
 * The function should return 0 if it was impossible to gain any profit.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [0..400,000];
 *       • each element of array A is an integer within the range [0..200,000].
 */

#include <vector>
#include <limits>
#include <algorithm>

int maxProfit(std::vector<int>& A)
{
    int minPrice = std::numeric_limits<int>::max(),
        maxProfit = 0;
    
    for (int price : A) {
        // Update the minimum price seen so far.
        minPrice = std::min(minPrice, price);
        
        // Update the maximum profit if a better profit is found.
        maxProfit = std::max(maxProfit, price - minPrice);
    }

    return maxProfit;
}

// 2. MaxSliceSum.

/**
 * A non-empty array A consisting of N integers is given.
 * A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A.
 * The sum of a slice (P, Q) is the total of A[P] + A[P+1] + ... + A[Q].
 * 
 * Write a function:
 *       class Solution { public int solution(int[] A); }
 * that, given an array A consisting of N integers, returns the maximum sum of any slice of A.
 * 
 * For example, given array A such that:
 *       A[0] = 3  A[1] = 2  A[2] = -6 A[3] = 4  A[4] = 0
 * the function should return 5 because:
 *       • (3, 4) is a slice of A that has sum 4,
 *       • (2, 2) is a slice of A that has sum −6,
 *       • (0, 1) is a slice of A that has sum 5,
 *       • no other slice of A has sum greater than (0, 1).
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [1..1,000,000];
 *       • each element of array A is an integer within the range [−1,000,000..1,000,000];
 *       • the result will be an integer within the range [−2,147,483,648..2,147,483,647].
 */

#include <vector>
#include <algorithm>

int maxSliceSum(std::vector<int>& A)
{
    int maxSum = A[0],
        sum = A[0],
        N = (int)A.size();
    
    // Uses the Kadane's algorithm to iterate through the vector
    // and update the maximum sum at each step.

    // The approach involves comparing the sum of the current element
    // and the sum of preceding elements to the current element to identify local maxima, 
    // with the overall maximum being the highest found. 
    for (int i = 1; i < N; ++i) {
        sum = std::max(A[i], sum + A[i]);
        maxSum = std::max(sum, maxSum);
    }

    return maxSum;
}

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

// Lesson 10
// Prime and composite numbers
// -------------------------------------------------

// 1. CountFactors.

/**
 * A positive integer D is a factor of a positive integer N if there exists an integer M such that N = D * M.
 * 
 * For example, 6 is a factor of 24, because M = 4 satisfies the above condition (24 = 6 * 4).
 * 
 * Write a function:
 *       class Solution { public int solution(int N); }
 * that, given a positive integer N, returns the number of its factors.
 * 
 * For example, given N = 24, the function should return 8, because 24 has 8 factors,
 * namely 1, 2, 3, 4, 6, 8, 12, 24. There are no other factors of 24.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [1..2,147,483,647].
 */

#include <cmath>

int countFactors(int N)
{
    int countFactors = 0,
        squareRootN = (int)std::sqrt(N);
    if (std::pow(squareRootN, 2) != N) {
        squareRootN++;  // Round up for non-perfect squares.
    } else {
        countFactors++; // Perfect squares possess an extra factor.
    }

    // More precisely, if number a is a divisor of N, then N/a is also a divisor.
    for (int i = 1; i < squareRootN; ++i) {
        if (!(N % i)) {
            countFactors += 2;
        }
    }

    return countFactors;
}

// 2. MinPerimeterRectangle.

/**
 * An integer N is given, representing the area of some rectangle.
 * The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).
 * The goal is to find the minimal perimeter of any rectangle whose area equals N.
 * The sides of this rectangle should be only integers.
 * 
 * For example, given integer N = 30, rectangles of area 30 are:
 *       • (1, 30), with a perimeter of 62,
 *       • (2, 15), with a perimeter of 34,
 *       • (3, 10), with a perimeter of 26,
 *       • (5, 6), with a perimeter of 22.
 * 
 * Write a function:
 *       class Solution { public int solution(int N); }
 * that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.
 * 
 * For example, given an integer N = 30, the function should return 22, as explained above.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N is an integer within the range [1..1,000,000,000].
 */

#include <cmath>
#include <limits>
#include <algorithm>

int minPerimeterRectangle(int N)
{
    int squareRootN = (int)std::sqrt(N),
        side = 0,
        perimeter = 0,
        minPerimeter = std::numeric_limits<int>::max();
    
    if (std::pow(squareRootN, 2) != N) {
        squareRootN++;  // Round up for all non-perfect squares.
    } else {
        // Calculate and set the minimum perimeter since the loop won't reach a perfect square root.
        minPerimeter = 2 * (squareRootN + squareRootN);
    }

    for (int i = 1; i < squareRootN; ++i) {
        if (!(N % i)) {
            side = N / i;
            perimeter = 2 * (side + i);
            minPerimeter = std::min(perimeter, minPerimeter);
        }
    }

    return minPerimeter;
}

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

// Lesson 12
// Euclidean algorithm
// -------------------------------------------------

// 1. ChocolatesByNumbers.

/**
 * Two positive integers N and M are given.
 * Integer N represents the number of chocolates arranged in a circle, numbered from 0 to N − 1.
 * 
 * You start to eat the chocolates. After eating a chocolate you leave only a wrapper.
 * You begin with eating chocolate number 0.
 * Then you omit the next M − 1 chocolates or wrappers on the circle, and eat the following one.
 * More precisely, if you ate chocolate number X,
 * then you will next eat the chocolate with number (X + M) modulo N (remainder of division).
 * You stop eating when you encounter an empty wrapper.
 * 
 * For example, given integers N = 10 and M = 4.
 * You will eat the following chocolates: 0, 4, 8, 2, 6.
 * 
 * The goal is to count the number of chocolates that you will eat, following the above rules.
 * 
 * Write a function:
 *       class Solution { public int solution(int N, int M); }
 * that, given two positive integers N and M, returns the number of chocolates that you will eat.
 * 
 * Write an efficient algorithm for the following assumptions:
 *       • N and M are integers within the range [1..1,000,000,000].
 */

int gcdByDivision(int A, int B)
{
    // Base case: if B divides A evenly, then B is the GCD.
    if (A % B == 0) {
        return B;
    } else {
        // Recursive case: call gcdByDivision with B and A modulo B.
        return gcdByDivision(B, A % B);
    }
}

int chocolatesByNumbers(int N, int M)
{
    // Calculate the greatest common divisor (GCD) using the gcdByDivision function.
    int gcd = gcdByDivision(N, M);
        
    // Calculate the result by dividing N by the GCD.
    return N / gcd;
}

// Lesson 15
// Caterpillar method
// -------------------------------------------------

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
