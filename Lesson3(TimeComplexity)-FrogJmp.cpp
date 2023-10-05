// 1. FrogJmp.

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
