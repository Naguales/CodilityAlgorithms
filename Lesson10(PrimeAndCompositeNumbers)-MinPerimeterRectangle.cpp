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
