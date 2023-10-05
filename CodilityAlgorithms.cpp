#include "CodilityAlgorithms.h"
#include "gtest/gtest.h"

#include <algorithm>

// Lesson 1 (Iterations) - BinaryGap tests.
// -------------------------------------------------

// Test case to check if the function returns the correct binary gap for a positive integer.
TEST(BinaryGapTest, PositiveInteger)
{
    EXPECT_EQ(binaryGap(9), 2);     // Binary representation of 9 is 1001, so the gap is 2.
    EXPECT_EQ(binaryGap(529), 4);   // Binary representation of 529 is 1000010001, so the gap is 4.
    EXPECT_EQ(binaryGap(1041), 5);  // Binary representation of 1041 is 10000010001, so the gap is 5.
}

// Test case to check if the function handles a case where there is no binary gap.
TEST(BinaryGapTest, NoBinaryGap)
{
    EXPECT_EQ(binaryGap(15), 0);  // Binary representation of 15 is 1111, so there's no binary gap.
    EXPECT_EQ(binaryGap(1), 0);   // Binary representation of 1 is 1, so there's no binary gap.
    EXPECT_EQ(binaryGap(7), 0);   // Binary representation of 7 is 111, so there's no binary gap.
}

// Test case to check if the function handles the lower bound of the input range.
TEST(BinaryGapTest, LowerBound)
{
    EXPECT_EQ(binaryGap(1), 0);  // Binary representation of 1 is 1, so there's no binary gap.
}

// Test case to check if the function handles the upper bound of the input range.
TEST(BinaryGapTest, UpperBound) {
    EXPECT_EQ(binaryGap(2147483647), 0);  // Binary representation of the upper bound has no binary gap.
}

// Lesson 2 (Arrays) - CyclicRotation tests.
// -------------------------------------------------

// Test case to check if the function correctly rotates the array to the right by K positions.
TEST(CyclicRotationTest, BasicRotation)
{
    std::vector<int> input1 = { 3, 8, 9, 7, 6 };
    std::vector<int> expected1 = { 6, 3, 8, 9, 7 };
    EXPECT_EQ(cyclicRotation(input1, 1), expected1);

    std::vector<int> input2 = { 1, 2, 3, 4, 5 };
    std::vector<int> expected2 = { 2, 3, 4, 5, 1 };
    EXPECT_EQ(cyclicRotation(input2, 4), expected2);
}

// Test case to check if the function correctly handles an empty input array.
TEST(CyclicRotationTest, EmptyArray)
{
    std::vector<int> empty;
    EXPECT_EQ(cyclicRotation(empty, 3), empty);
}

// Test case to check if the function correctly handles a rotation of zero times.
TEST(CyclicRotationTest, ZeroRotation)
{
    std::vector<int> input = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(cyclicRotation(input, 0), expected);
}

// Test case to check if the function correctly handles a rotation greater than the array size.
TEST(CyclicRotationTest, RotationGreaterThanSize)
{
    std::vector<int> input = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 3, 4, 5, 1, 2 };  // Equivalent to rotating by 8 positions.
    EXPECT_EQ(cyclicRotation(input, 8), expected);
}

// Test case to check if the function correctly handles rotations when K is equal to the array size.
TEST(CyclicRotationTest, RotationEqualToSize)
{
    std::vector<int> input = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };  // No change, as K is equal to the size.
    EXPECT_EQ(cyclicRotation(input, 5), expected);
}

// Lesson 2 (Arrays) - OddOccurrencesInArray tests.
// -------------------------------------------------

// Test case to check if the function correctly finds the unpaired element in the array.
TEST(OddOccurrencesInArrayTest, BasicTest)
{
    std::vector<int> input1 = { 9, 3, 9, 3, 9, 7, 9 };
    EXPECT_EQ(oddOccurrencesInArray(input1), 7);

    std::vector<int> input2 = { 1, 2, 3, 2, 1 };
    EXPECT_EQ(oddOccurrencesInArray(input2), 3);
}

// Test case to check if the function correctly handles an array with a single element.
TEST(OddOccurrencesInArrayTest, SingleElementArray)
{
    std::vector<int> input = { 42 };
    EXPECT_EQ(oddOccurrencesInArray(input), 42);
}

// Test case to check if the function correctly handles large input arrays.
TEST(OddOccurrencesInArrayTest, LargeInput)
{
    std::vector<int> input;
    for (int i = 1; i <= 1000000; ++i) {
        input.push_back(i);
        input.push_back(i);
    }
    input.push_back(999999);  // Add the unpaired element at the end.
    EXPECT_EQ(oddOccurrencesInArray(input), 999999);
}

// Lesson 3 (Time Complexity) - FrogJmp tests.
// -------------------------------------------------

// Test case to check if the function returns the correct minimal number of jumps.
TEST(FrogJmpTest, BasicTest)
{
    EXPECT_EQ(frogJmp(10, 85, 30), 3);  // X = 10, Y = 85, D = 30, minimal jumps = ceil((85 - 10) / 30) = 3.
    EXPECT_EQ(frogJmp(1, 1000000000, 1), 999999999);  // X = 1, Y = 1000000000, D = 1, minimal jumps = ceil((1000000000 - 1) / 1) = 999999999.
}

// Test case to check if the function correctly handles a case where X and Y are equal.
TEST(FrogJmpTest, SamePositions)
{
    EXPECT_EQ(frogJmp(7, 7, 3), 0);  // X = 7, Y = 7, D = 3, no jumps needed (already at the target).
}

// Test case to check if the function correctly handles a case where D is greater than or equal to (Y - X).
TEST(FrogJmpTest, LargeDistance)
{
    EXPECT_EQ(frogJmp(1, 10, 20), 1);  // X = 1, Y = 10, D = 20, minimal jumps = ceil((10 - 1) / 20) = 1.
    EXPECT_EQ(frogJmp(1, 100, 100), 1);  // X = 1, Y = 100, D = 100, minimal jumps = ceil((100 - 1) / 100) = 1.
}

// Lesson 3 (Time Complexity) - PermMissingElem tests.
// -------------------------------------------------

// Test case to check if the function returns the correct missing element.
TEST(PermMissingElemTest, BasicTest)
{
    std::vector<int> input1 = { 2, 3, 1, 5 };
    EXPECT_EQ(permMissingElem(input1), 4);  // The missing element is 4.

    std::vector<int> input2 = { 1, 2, 4, 5 };
    EXPECT_EQ(permMissingElem(input2), 3);  // The missing element is 3.
}

// Test case to check if the function correctly handles an empty input array.
TEST(PermMissingElemTest, EmptyArray)
{
    std::vector<int> empty;
    EXPECT_EQ(permMissingElem(empty), 1);  // The missing element is 1 (smallest possible).
}

// Test case to check if the function correctly handles an array with a single element.
TEST(PermMissingElemTest, SingleElementArray)
{
    std::vector<int> input = { 1 };
    EXPECT_EQ(permMissingElem(input), 2);  // The missing element is 2.
}

// Test case to check if the function correctly handles large input arrays.
TEST(PermMissingElemTest, LargeInput)
{
    std::vector<int> input;
    for (int i = 1; i <= 100000; ++i) {
        input.push_back(i);
    }
    EXPECT_EQ(permMissingElem(input), 100001);  // The missing element is 100001.
}

// Lesson 3 (Time Complexity) - TapeEquilibrium
// -------------------------------------------------

// Test case to check if the function returns the correct minimal difference.
TEST(TapeEquilibriumTest, BasicTest)
{
    std::vector<int> input1 = { 3, 1, 2, 4, 3 };
    EXPECT_EQ(tapeEquilibrium(input1), 1);  // P = 3, |(3 + 1 + 2) - (4 + 3)| = 1.

    std::vector<int> input2 = { 1, 1, 1, 1, 1 };
    EXPECT_EQ(tapeEquilibrium(input2), 1);  // P = 1, |(1 + 1) - (1 + 1 + 1)| = 1.
}

// Test case to check if the function handles negative numbers correctly.
TEST(TapeEquilibriumTest, NegativeNumbers)
{
    std::vector<int> input = { -10, 5, -3, 4, 2 };
    EXPECT_EQ(tapeEquilibrium(input), 6);  // P = 6, |(-10 + 5 - 3 + 4) - 2)| = 6.
}

// Test case to check if the function handles large input arrays.
TEST(TapeEquilibriumTest, LargeInput)
{
    std::vector<int> input;
    for (int i = 1; i <= 100000; ++i) {
        input.push_back(i);
    }
    EXPECT_EQ(tapeEquilibrium(input), 5658);  // P = 5658.
}

// Test case to check if the function returns the correct minimal difference when N is 2.
TEST(TapeEquilibriumTest, NIs2)
{
    std::vector<int> input1 = { 1, 2 };
    EXPECT_EQ(tapeEquilibrium(input1), 1);  // P = 1, |(1) - (2)| = 1.

    std::vector<int> input2 = { 5, 5 };
    EXPECT_EQ(tapeEquilibrium(input2), 0);  // P = 1, |(5) - (5)| = 0.
}

// Test case to check if the function returns the correct minimal difference when all elements are the same.
TEST(TapeEquilibriumTest, AllElementsSame)
{
    std::vector<int> input1 = { 2, 2, 2, 2, 2 };
    EXPECT_EQ(tapeEquilibrium(input1), 2);  // P = 2, |(2 + 2 + 2) - (2 + 2)| = 2.

    std::vector<int> input2 = { -5, -5, -5, -5, -5 };
    EXPECT_EQ(tapeEquilibrium(input2), 5);  // P = 5, |(-5 -5) - (-5 - 5 - 5)| = 5.
}

// Test case to check if the function handles alternating positive and negative numbers.
TEST(TapeEquilibriumTest, AlternatingNumbers)
{
    std::vector<int> input = { -1, 2, -3, 4, -5 };
    EXPECT_EQ(tapeEquilibrium(input), 1);  // P = 2, |(-1 + 2) - (-3 + 4 - 5)| = 1.
}

// Lesson 4 (Counting Elements) - FrogRiverOne
// -------------------------------------------------

// Test when the frog can jump to the other side of the river.
TEST(FrogRiverOneTest, FrogCanJump)
{
    std::vector<int> leaves = { 1, 3, 1, 4, 2, 3, 5, 4 };
    int X = 5;
    int result = frogRiverOne(X, leaves);
    EXPECT_EQ(result, 6); // The frog can jump at time 6.
}

// Test when the frog can never jump to the other side.
TEST(FrogRiverOneTest, FrogCantJump)
{
    std::vector<int> leaves = { 1, 3, 1, 4, 2, 3, 5, 4 };
    int X = 6;
    int result = frogRiverOne(X, leaves);
    EXPECT_EQ(result, -1); // The frog can't jump to the other side.
}

// Test when the frog can jump immediately.
TEST(FrogRiverOneTest, FrogCanJumpImmediately)
{
    std::vector<int> leaves = { 1 };
    int X = 1;
    int result = frogRiverOne(X, leaves);
    EXPECT_EQ(result, 0); // The frog can jump at time 0.
}

// Test when X is 1, and there's only one leaf at position 1.
TEST(FrogRiverOneTest, FrogCanJump_X1)
{
    std::vector<int> leaves = { 1 };
    int X = 1;
    int result = frogRiverOne(X, leaves);
    EXPECT_EQ(result, 0); // The frog can jump at time 0.
}

// Test when X is 1, but there's no leaf at position 1.
TEST(FrogRiverOneTest, FrogCantJump_X1_NoLeaf)
{
    std::vector<int> leaves = { 2, 3, 4 };
    int X = 1;
    int result = frogRiverOne(X, leaves);
    EXPECT_EQ(result, -1); // The frog can't jump to the other side.
}

// Test when X is equal to the length of the array
TEST(FrogRiverOneTest, FrogCanJump_XEqualsLength)
{
    std::vector<int> leaves = { 1, 2, 3, 4, 5 };
    int X = 5;
    int result = frogRiverOne(X, leaves);
    EXPECT_EQ(result, 4); // The frog can jump at time 4.
}

// Test when X is very large (maximum value) and there are leaves at every position.
TEST(FrogRiverOneTest, FrogCanJump_XMaxValue)
{
    int X = 100000;
    std::vector<int> leaves(X);
    for (int i = 0; i < X; ++i) {
        leaves[i] = i + 1; // Leaves at positions 1 to X.
    }
    int result = frogRiverOne(X, leaves);
    EXPECT_EQ(result, X - 1); // The frog can jump at time X - 1.
}

// Test when X is very large (maximum value) but there are missing leaves.
TEST(FrogRiverOneTest, FrogCantJump_XMaxValue_MissingLeaves)
{
    int X = 100000;
    std::vector<int> leaves(X - 1); // Missing one leaf at position X.
    for (int i = 0; i < X - 1; ++i) {
        leaves[i] = i + 1; // Leaves at positions 1 to X-1.
    }
    int result = frogRiverOne(X, leaves);
    EXPECT_EQ(result, -1); // The frog can't jump to the other side.
}

// Lesson 4 (Counting Elements) - PermCheck
// -------------------------------------------------

// Test when array A is a permutation.
TEST(PermCheckTest, ArrayIsPermutation)
{
    std::vector<int> A = { 4, 1, 3, 2 };
    EXPECT_EQ(permCheck(A), 1); // Array A is a permutation.
}

// Test when array A is not a permutation (missing values).
TEST(PermCheckTest, ArrayNotPermutation_MissingValues)
{
    std::vector<int> A = { 4, 1, 3 };
    EXPECT_EQ(permCheck(A), 0); // Array A is not a permutation (missing value 2).
}

// Test when array A is not a permutation (duplicate values).
TEST(PermCheckTest, ArrayNotPermutation_DuplicateValues)
{
    std::vector<int> A = { 4, 1, 3, 2, 2 };
    EXPECT_EQ(permCheck(A), 0); // Array A is not a permutation (duplicate value 2).
}

// Test when array A contains only one element (minimum edge case).
TEST(PermCheckTest, ArrayWithOneElement) {
    std::vector<int> A = { 1 };
    EXPECT_EQ(permCheck(A), 1); // Array A is a permutation with a single element.
}

// Test when array A is not a permutation (out of range values).
TEST(PermCheckTest, ArrayNotPermutation_OutOfRangeValues)
{
    std::vector<int> A = { 4, 1, 3, 2, 6 };
    EXPECT_EQ(permCheck(A), 0); // Array A is not a permutation (value 6 is out of range).
}

// Test when array A is a permutation with values from 1 to N (in ascending order).
TEST(PermCheckTest, ArrayIsPermutation_AscendingOrder)
{
    std::vector<int> A = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(permCheck(A), 1); // Array A is a permutation.
}

// Test when array A is a permutation with values from 1 to N (in descending order).
TEST(PermCheckTest, ArrayIsPermutation_DescendingOrder)
{
    std::vector<int> A = { 5, 4, 3, 2, 1 };
    EXPECT_EQ(permCheck(A), 1); // Array A is a permutation.
}

// Test when array A is a permutation with a large number of elements (N = 100,000).
TEST(PermCheckTest, LargeArrayIsPermutation)
{
    std::vector<int> A(100000);
    for (int i = 0; i < 100000; ++i) {
        A[i] = i + 1; // A is a permutation with values from 1 to 100,000.
    }
    EXPECT_EQ(permCheck(A), 1); // Array A is a permutation.
}

// Lesson 4 (Counting Elements) - MaxCounters
// -------------------------------------------------

// Test when N is 1, and A contains a single max counter operation.
TEST(MaxCountersTest, N1_SingleMaxCounter)
{
    int N = 1;
    std::vector<int> A = { 2 };
    std::vector<int> result = maxCounters(N, A);
    EXPECT_EQ(result, std::vector<int>({ 0 }));
}

// Test when N is 5, and A contains a sequence of operations.
TEST(MaxCountersTest, N5_SequenceOfOperations) {
    int N = 5;
    std::vector<int> A = { 3, 4, 4, 6, 1, 4, 4 };
    std::vector<int> result = maxCounters(N, A);
    EXPECT_EQ(result, std::vector<int>({ 3, 2, 2, 4, 2 }));
}

// Test when N is 3, and A contains only max counter operations.
TEST(MaxCountersTest, N3_MaxCounterOperationsOnly) {
    int N = 3;
    std::vector<int> A = { 4, 4, 4, 4, 4 };
    std::vector<int> result = maxCounters(N, A);
    EXPECT_EQ(result, std::vector<int>({ 0, 0, 0 }));
}

TEST(MaxCountersTest, N1_SingleIncreaseOperation) {
    int N = 1;
    std::vector<int> A = { 1 };
    std::vector<int> result = maxCounters(N, A);
    EXPECT_EQ(result, std::vector<int>({ 1 }));
}

// Test when N is 2, and A contains a sequence of operations.
TEST(MaxCountersTest, N2_SequenceOfOperations)
{
    int N = 2;
    std::vector<int> A = { 1, 2, 1, 2, 1 };
    std::vector<int> result = maxCounters(N, A);
    EXPECT_EQ(result, std::vector<int>({ 3, 2 }));
}

// Test when N is 4, and A contains a sequence of operations with multiple max counter operations.
TEST(MaxCountersTest, N4_SequenceWithMultipleMaxCounterOperations)
{
    int N = 4;
    std::vector<int> A = { 3, 4, 4, 6, 1, 4, 4, 5, 5 };
    std::vector<int> result = maxCounters(N, A);
    EXPECT_EQ(result, std::vector<int>({ 4, 4, 4, 4 }));
}

// Test when N is 3, and A contains alternating increase and max counter operations.
TEST(MaxCountersTest, N3_AlternatingOperations)
{
    int N = 3;
    std::vector<int> A = { 1, 4, 2, 4, 3, 4 };
    std::vector<int> result = maxCounters(N, A);
    EXPECT_EQ(result, std::vector<int>({ 3, 3, 3 }));
}

// Test when N is 100,000, and A contains a large sequence of operations.
TEST(MaxCountersTest, N100000_LargeSequenceOfOperations)
{
    int N = 100000;
    std::vector<int> A(1000000, N + 1);
    std::vector<int> result = maxCounters(N, A);
    EXPECT_TRUE(std::all_of(result.begin(), result.end(), [](int val) { return val == 0; }));
}

// Lesson 4 (Counting Elements) - MissingInteger
// -------------------------------------------------

// Test when A contains positive integers in ascending order.
TEST(MissingIntegerTest, AscendingPositiveIntegers)
{
    std::vector<int> A = { 1, 2, 3, 4, 5 };
    int result = missingInteger(A);
    EXPECT_EQ(result, 6); // The smallest missing positive integer is 6.
}

// Test when A contains positive integers in descending order.
TEST(MissingIntegerTest, DescendingPositiveIntegers)
{
    std::vector<int> A = { 5, 4, 3, 2, 1 };
    int result = missingInteger(A);
    EXPECT_EQ(result, 6); // The smallest missing positive integer is 6.
}

// Test when A contains a mix of positive and negative integers.
TEST(MissingIntegerTest, MixOfPositiveAndNegativeIntegers)
{
    std::vector<int> A = { -1, -3, 6, 4, 1, 2 };
    int result = missingInteger(A);
    EXPECT_EQ(result, 3); // The smallest missing positive integer is 3.
}

// Test when A contains only negative integers.
TEST(MissingIntegerTest, OnlyNegativeIntegers)
{
    std::vector<int> A = { -5, -4, -3, -2, -1 };
    int result = missingInteger(A);
    EXPECT_EQ(result, 1); // The smallest missing positive integer is 1.
}

// Test when A contains a single positive integer.
TEST(MissingIntegerTest, SinglePositiveInteger)
{
    std::vector<int> A = { 42 };
    int result = missingInteger(A);
    EXPECT_EQ(result, 1); // The smallest missing positive integer is 1.
}

// Test when A contains a single negative integer.
TEST(MissingIntegerTest, SingleNegativeInteger)
{
    std::vector<int> A = { -42 };
    int result = missingInteger(A);
    EXPECT_EQ(result, 1); // The smallest missing positive integer is 1.
}

// Test when A contains all positive integers from 1 to N, where N is large (N = 100,000).
TEST(MissingIntegerTest, AllPositiveIntegersUpToLargeN)
{
    int N = 100000;
    std::vector<int> A(N);
    for (int i = 1; i <= N; ++i) {
        A[i - 1] = i;
    }
    int result = missingInteger(A);
    EXPECT_EQ(result, N + 1); // The smallest missing positive integer is N + 1.
}

// Test when A contains all negative integers and zero, where N is large (N = 100,000).
TEST(MissingIntegerTest, AllNegativeIntegersAndZero)
{
    int N = 100000;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = -i;
    }
    int result = missingInteger(A);
    EXPECT_EQ(result, 1); // The smallest missing positive integer is 1.
}

// Test when A contains a large number of random positive and negative integers.
TEST(MissingIntegerTest, LargeNumberOfRandomIntegers)
{
    int N = 100000;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = rand() % 2000000 - 1000000; // Random integers between -1,000,000 and 1,000,000.
    }
    int result = missingInteger(A);
    // Calculate the expected result manually based on the generated random integers.
    std::vector<int> sortedA = A;
    std::sort(sortedA.begin(), sortedA.end());
    int expected = 1;
    for (int i : sortedA) {
        if (i == expected) {
            ++expected;
        }
    }
    EXPECT_EQ(result, expected); // The smallest missing positive integer.
}

// Lesson 5 (Prefix Sums) - PassingCars
// -------------------------------------------------

// Test when A contains no passing cars.
TEST(PassingCarsTest, NoPassingCars)
{
    std::vector<int> A = { 0, 0, 0, 0, 0 };
    EXPECT_EQ(passingCars(A), 0); // No passing cars, so the result should be 0.
}

// Test when A contains only one car traveling east.
TEST(PassingCarsTest, SingleCarTravelingEast)
{
    std::vector<int> A = { 0 };
    EXPECT_EQ(passingCars(A), 0); // Only one car, so there are no passing cars.
}

// Test when A contains only one car traveling west.
TEST(PassingCarsTest, SingleCarTravelingWest)
{
    std::vector<int> A = { 1 };
    EXPECT_EQ(passingCars(A), 0); // Only one car, so there are no passing cars.
}

// Test when A contains multiple passing cars.
TEST(PassingCarsTest, MultiplePassingCars)
{
    std::vector<int> A = { 0, 1, 0, 1, 1 };
    EXPECT_EQ(passingCars(A), 5); // There are five pairs of passing cars.
}

// Test when A contains a large number of cars (maximum limit).
TEST(PassingCarsTest, LargeNumberOfCars)
{
    int N = 100000;
    std::vector<int> A(N, 0);
    EXPECT_EQ(passingCars(A), 0); // No passing cars in a large array of eastbound cars.
}

// Test when A contains a large number of cars, all traveling west (maximum limit).
TEST(PassingCarsTest, LargeNumberOfCarsTravelingWest)
{
    int N = 100000;
    std::vector<int> A(N, 1);
    EXPECT_EQ(passingCars(A), 0); // No passing cars in a large array of westbound cars.
}

// Test when A contains a large number of cars with one car heading westward.
TEST(PassingCarsTest, LargeNumberOfCarsOneCarHeadingWestwardInTheMiddle)
{
    int N = 100000;
    std::vector<int> A(N, 0);
    A[N / 2] = 1; // A single car is heading westward, positioned in the middle.
    EXPECT_EQ(passingCars(A), 50000);
}

// Test when carPasses exceeds 1,000,000,000.
TEST(PassingCarsTest, CarPassesExceedLimit)
{
    int N = 100000;
    std::vector<int> A(N, 0);
    for (int i = 0; i < N; ++i) {
        if (!(i % 2)) {
            A[i] = 1;
        }
    }
    EXPECT_EQ(passingCars(A), -1); // carPasses exceeds the limit, so the result should be -1.
}

// Lesson 5 (Prefix Sums) - CountDiv
// -------------------------------------------------

// Test when A = B and K = 1 (smallest possible inputs with K = 1).
TEST(CountDivTest, AEqualsBAndKOne)
{
    int A = 5, B = 5, K = 1;
    EXPECT_EQ(countDiv(A, B, K), 1); // Only 5 is divisible by 1 within the range [5..5].
}

// Test when A = 6, B = 11, and K = 2.
TEST(CountDivTest, BasicTest)
{
    int A = 6, B = 11, K = 2;
    EXPECT_EQ(countDiv(A, B, K), 3); // There are three numbers divisible by 2 within the range [6..11]: 6, 8, and 10.
}

// Test when A = 0, B = 100, and K = 10.
TEST(CountDivTest, LargeRange)
{
    int A = 0, B = 100, K = 10;
    EXPECT_EQ(countDiv(A, B, K), 11); // There are eleven numbers divisible by 10 within the range [0..100].
}

// Test when A = 0, B = 1,000,000,000, and K = 1,000,000,000 (maximum possible values).
TEST(CountDivTest, LargeValues)
{
    int A = 0, B = 1000000000, K = 1000000000;
    EXPECT_EQ(countDiv(A, B, K), 2); // Only 0 and 1000000000 are divisible by 1000000000 within the range [0..1000000000].
}

// Test when A, B, and K are at their maximum values.
TEST(CountDivTest, MaximumValues)
{
    int A = 2000000000, B = 2000000000, K = 2000000000;
    EXPECT_EQ(countDiv(A, B, K), 1); // Only 2000000000 is divisible by 2000000000 within the range [2000000000..2000000000].
}

// Test with a combination of minimum, maximum, and in-between values.
TEST(CountDivTest, MixedValues)
{
    int A = 1, B = 2000000000, K = 1000000;
    EXPECT_EQ(countDiv(A, B, K), 2000); // There are 2000 numbers divisible by 1000000 within the range [1..2000000000].
}

// Lesson 6 (Sorting) - Distinct
// -------------------------------------------------

// Test when the array is empty (N = 0).
TEST(DistinctTest, EmptyArray)
{
    std::vector<int> A;
    EXPECT_EQ(distinct(A), 0); // The array is empty, so there are no distinct values.
}

// Test when all elements in the array are the same.
TEST(DistinctTest, AllSameElements)
{
    std::vector<int> A = { 2, 2, 2, 2, 2 };
    EXPECT_EQ(distinct(A), 1); // All elements are the same (2), so there is only one distinct value.
}

// Test when the array contains distinct values.
TEST(DistinctTest, DistinctValues)
{
    std::vector<int> A = { 2, 1, 3, 4, 5 };
    EXPECT_EQ(distinct(A), 5); // All elements are distinct, so there are five distinct values.
}

// Test when the array contains negative values.
TEST(DistinctTest, NegativeValues)
{
    std::vector<int> A = { -2, -1, -3, -2, -1 };
    EXPECT_EQ(distinct(A), 3); // There are three distinct values: -2, -1, and -3.
}

// Test when the array contains the maximum number of elements (N = 100,000) with distinct values.
TEST(DistinctTest, LargeNumberOfElementsDistinct)
{
    const int N = 100000;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = i;
    }
    EXPECT_EQ(distinct(A), N); // All elements are distinct, so there should be N distinct values.
}

// Test when the array contains the maximum number of elements (N = 100,000) with the same value.
TEST(DistinctTest, LargeNumberOfElementsSameValue)
{
    const int N = 100000;
    std::vector<int> A(N, 42); // Initialize with the same value (42).
    EXPECT_EQ(distinct(A), 1); // All elements are the same, so there should be only one distinct value.
}

// Test when the array contains a large number of elements (N = 100,000) with a mix of values.
TEST(DistinctTest, LargeNumberOfElementsMixedValues)
{
    const int N = 100000;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = i % 1000; // Repeat values every 1000 elements.
    }
    EXPECT_EQ(distinct(A), 1000); // There are 1000 distinct values repeated in the array.
}

// Lesson 6 (Sorting) - MaxProductOfThree
// -------------------------------------------------

// Test when the array contains only three elements with positive values.
TEST(MaxProductOfThreeTest, ThreePositiveElements)
{
    std::vector<int> A = { 3, 5, 7 };
    EXPECT_EQ(maxProductOfThree(A), 3 * 5 * 7); // The maximum product should be 3 * 5 * 7 = 105.
}

// Test when the array contains a mix of positive and negative values.
TEST(MaxProductOfThreeTest, MixedValues)
{
    std::vector<int> A = { -3, 5, -7, 2, 4 };
    EXPECT_EQ(maxProductOfThree(A), -7 * -3 * 5); // The maximum product should be -7 * -3 * 5 = 105.
}

// Test when the array contains three elements with negative values.
TEST(MaxProductOfThreeTest, ThreeNegativeElements)
{
    std::vector<int> A = { -3, -5, -7 };
    EXPECT_EQ(maxProductOfThree(A), -3 * -5 * -7); // The maximum product should be -3 * -5 * -7 = -105.
}

// Test when the array contains three elements with mixed values.
TEST(MaxProductOfThreeTest, ThreeMixedElements)
{
    std::vector<int> A = { -3, 5, -7 };
    EXPECT_EQ(maxProductOfThree(A), -3 * 5 * -7); // The maximum product should be -3 * 5 * -7 = 105.
}

// Test when the array contains many elements with both positive and negative values.
TEST(MaxProductOfThreeTest, ManyElementsMixedValues)
{
    std::vector<int> A = { -10, -2, 0, 5, 8, -9, -7, 12 };
    EXPECT_EQ(maxProductOfThree(A), -10 * -9 * 12); // The maximum product should be -10 * -9 * 12 = 1080.
}

// Test when N = 3 (minimum value for N) and all elements are positive.
TEST(MaxProductOfThreeTest, ThreePositiveElementsMinN)
{
    std::vector<int> A = { 2, 3, 5 };
    EXPECT_EQ(maxProductOfThree(A), 2 * 3 * 5); // The maximum product should be 2 * 3 * 5 = 30.
}

// Test when N = 3 (minimum value for N) and all elements are negative.
TEST(MaxProductOfThreeTest, ThreeNegativeElementsMinN)
{
    std::vector<int> A = { -2, -3, -5 };
    EXPECT_EQ(maxProductOfThree(A), -2 * -3 * -5); // The maximum product should be -2 * -3 * -5 = -30.
}

// Test when N = 3 (minimum value for N) and elements are mixed.
TEST(MaxProductOfThreeTest, ThreeMixedElementsMinN)
{
    std::vector<int> A = { -2, 3, -5 };
    EXPECT_EQ(maxProductOfThree(A), -2 * 3 * -5); // The maximum product should be -2 * 3 * -5 = 30.
}

// Test when N = 100000 (maximum value for N) and elements are all zeros.
TEST(MaxProductOfThreeTest, AllZeroElementsMaxN)
{
    std::vector<int> A(100000, 0);
    EXPECT_EQ(maxProductOfThree(A), 0); // All elements are zeros, so the maximum product should be 0.
}

// Test when N = 100000 (maximum value for N) and elements are all positive.
TEST(MaxProductOfThreeTest, AllPositiveElementsMaxN)
{
    std::vector<int> A(100000, 5);
    EXPECT_EQ(maxProductOfThree(A), 5 * 5 * 5); // All elements are the same (5), so the maximum product should be 5 * 5 * 5 = 125.
}

// Test when N = 100000 (maximum value for N) and elements are all negative.
TEST(MaxProductOfThreeTest, AllNegativeElementsMaxN)
{
    std::vector<int> A(100000, -5);
    EXPECT_EQ(maxProductOfThree(A), -5 * -5 * -5); // All elements are the same (-5), so the maximum product should be -5 * -5 * -5 = -125.
}

// Lesson 6 (Sorting) - Triangle
// -------------------------------------------------

// Test when the array is empty (N = 0).
TEST(TriangleTest, EmptyArray)
{
    std::vector<int> A;
    EXPECT_EQ(triangle(A), 0); // An empty array cannot form a triangular triplet.
}

// Test when the array contains only two elements (N = 2).
TEST(TriangleTest, TwoElements)
{
    std::vector<int> A = { 5, 10 };
    EXPECT_EQ(triangle(A), 0); // With only two elements, it's impossible to form a triangular triplet.
}

// Test when the array contains three elements that do not form a triangular triplet.
TEST(TriangleTest, NonTriangularTriplet)
{
    std::vector<int> A = { 10, 2, 20 };
    EXPECT_EQ(triangle(A), 0); // The elements 10, 2, and 20 do not form a triangular triplet.
}

// Test when the array contains many elements with a large range of values.
TEST(TriangleTest, LargeRangeValues)
{
    std::vector<int> A = { -2147483648, 0, 2147483647 };
    EXPECT_EQ(triangle(A), 0); // The large range of values doesn't form a triangular triplet.
}

// Test when N = 100000 (maximum value for N) and all elements are zeros.
TEST(TriangleTest, LargeArrayAllZeros)
{
    std::vector<int> A(100000, 0);
    EXPECT_EQ(triangle(A), 0); // With all elements being zeros, it's impossible to form a triangular triplet.
}

// Test when N = 100000 (maximum value for N) and all elements are positive.
TEST(TriangleTest, LargeArrayAllPositive)
{
    std::vector<int> A(100000, 5);
    EXPECT_EQ(triangle(A), 1); // All elements are the same (5), so a triangular triplet exists.
}

// Test when N = 100000 (maximum value for N) and all elements are negative.
TEST(TriangleTest, LargeArrayAllNegative)
{
    std::vector<int> A(100000, -5);
    EXPECT_EQ(triangle(A), 0); // All elements are the same (-5), but it's still impossible to form a triangular triplet.
}

// Test when N = 100000 (maximum value for N) and elements are random.
TEST(TriangleTest, LargeArrayRandomElements)
{
    std::vector<int> A;
    for (int i = 0; i < 100000; ++i) {
        A.push_back(rand() % 1000000 - 500000); // Generate random elements between -500000 and 499999.
    }
    EXPECT_TRUE(triangle(A) == 0 || triangle(A) == 1); // A random array may or may not form a triangular triplet.
}

// Lesson 7 (Stacks and queues) - Brackets
// -------------------------------------------------

// Test when the string is empty.
TEST(BracketsTest, EmptyString)
{
    std::string S = "";
    EXPECT_EQ(brackets(S), 1); // An empty string is considered properly nested.
}

// Test when the string contains a single pair of brackets.
TEST(BracketsTest, SinglePairOfBrackets)
{
    std::string S1 = "{}";
    std::string S2 = "[]";
    std::string S3 = "()";
    EXPECT_EQ(brackets(S1), 1); // Properly nested.
    EXPECT_EQ(brackets(S2), 1); // Properly nested.
    EXPECT_EQ(brackets(S3), 1); // Properly nested.
}

// Test when the string contains multiple pairs of brackets.
TEST(BracketsTest, MultiplePairsOfBrackets)
{
    std::string S1 = "{[()]()}";
    std::string S2 = "[({})]";
    std::string S3 = "{[()]";
    std::string S4 = "{[()]}}";
    EXPECT_EQ(brackets(S1), 1); // Properly nested.
    EXPECT_EQ(brackets(S2), 1); // Properly nested.
    EXPECT_EQ(brackets(S3), 0); // Not properly nested.
    EXPECT_EQ(brackets(S4), 0); // Not properly nested.
}

// Test when the string contains unbalanced brackets.
TEST(BracketsTest, UnbalancedBrackets)
{
    std::string S1 = "{[()]())}";
    std::string S2 = "[(])";
    EXPECT_EQ(brackets(S1), 0); // Not properly nested.
    EXPECT_EQ(brackets(S2), 0); // Not properly nested.
}

// Test when the string contains 200,000 opening and closing brackets.
TEST(BracketsTest, LargeNumberOfBrackets)
{
    std::string S(200000, '('); // Create a string with 200,000 opening brackets.
    S += std::string(200000, ')'); // Append 200,000 closing brackets.

    // The string consists of pairs of brackets, so it's properly nested.
    EXPECT_EQ(brackets(S), 1);
}

// Test when the string contains 200,000 brackets in a non nested pattern.
TEST(BracketsTest, LargeNotNestedBrackets)
{
    std::string S;
    for (int i = 0; i < 100000; ++i) {
        S += "({[";
    }
    for (int i = 0; i < 100000; ++i) {
        S += ")}]";
    }

    EXPECT_EQ(brackets(S), 0);
}

// Test when the string contains 200,000 brackets in a nested pattern.
TEST(BracketsTest, LargeNestedBrackets)
{
    std::string S;
    for (int i = 0; i < 100000; ++i) {
        S += "({[";
    }
    for (int i = 0; i < 100000; ++i) {
        S += "]})";
    }

    EXPECT_EQ(brackets(S), 1);
}

// Lesson 7 (Stacks and queues) - Nesting
// -------------------------------------------------

// Test when the string is empty.
TEST(NestingTest, EmptyString)
{
    std::string S = "";
    EXPECT_EQ(nesting(S), 1); // An empty string is considered properly nested.
}

// Test when the string contains a single pair of brackets.
TEST(NestingTest, SinglePairOfBrackets)
{
    std::string S1 = "()";
    std::string S2 = "(())";
    EXPECT_EQ(nesting(S1), 1); // Properly nested.
    EXPECT_EQ(nesting(S2), 1); // Properly nested.
}

// Test when the string contains multiple pairs of brackets.
TEST(NestingTest, MultiplePairsOfBrackets)
{
    std::string S1 = "((()))";
    std::string S2 = "()()()";
    std::string S3 = "(()(()()))";
    EXPECT_EQ(nesting(S1), 1); // Properly nested.
    EXPECT_EQ(nesting(S2), 1); // Properly nested.
    EXPECT_EQ(nesting(S3), 1); // Properly nested.
}

// Test when the string contains unbalanced brackets.
TEST(NestingTest, UnbalancedBrackets)
{
    std::string S1 = "(()))";
    std::string S2 = "())(";
    EXPECT_EQ(nesting(S1), 0); // Not properly nested.
    EXPECT_EQ(nesting(S2), 0); // Not properly nested.
}

// Test when the string contains 1,000,000 pairs of brackets.
TEST(NestingTest, LargePairsOfBrackets)
{
    std::string S(2000000, '(');
    S += std::string(2000000, ')');
    EXPECT_EQ(nesting(S), 1); // Properly nested.
}

// Test when the string contains 1,000,000 opening brackets followed by 999,999 closing brackets.
TEST(NestingTest, LargeUnbalancedBrackets)
{
    std::string S(1000000, '(');
    S += std::string(999999, ')');
    EXPECT_EQ(nesting(S), 0); // Not properly nested (unbalanced brackets).
}

// Lesson 8 (Leader) - Dominator
// -------------------------------------------------

// Test when the array is empty.
TEST(DominatorTest, EmptyArray)
{
    std::vector<int> A;
    EXPECT_EQ(dominator(A), -1); // Empty array has no dominator.
}

// Test when the array has a dominator.
TEST(DominatorTest, ArrayWithDominator)
{
    std::vector<int> A = { 3, 4, 3, 2, 3, -1, 3, 3 };
    EXPECT_EQ(dominator(A), 0); // Dominator is 3, found at index 0.
}

// Test when the array has no dominator.
TEST(DominatorTest, ArrayWithoutDominator)
{
    std::vector<int> A = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(dominator(A), -1); // No dominator.
}

// Test when the array is large with a dominator.
TEST(DominatorTest, LargeArrayWithDominator)
{
    std::vector<int> A(100000, 1);
    A[99999] = 2; // 2 occurs once, while 1 occurs 99999 times.
    EXPECT_EQ(dominator(A), 0); // Dominator is 1, found at index 0.
}

// Test when the array has a dominator with large numbers.
TEST(DominatorTest, LargeArrayWithDominator2)
{
    std::vector<int> A(100000, 2147483647); // Fill the array with the maximum positive integer.
    A[99999] = 42; // 42 occurs once, while 2147483647 occurs 99999 times.
    EXPECT_EQ(dominator(A), 0); // Dominator is 2147483647, found at index 0.
}

// Test when the array has a dominator with diverse numbers.
TEST(DominatorTest, DiverseArrayWithDominator)
{
    std::vector<int> A = { 7, 1, 1, 3, 4, 1, 5, 1, 1 }; // Diverse array with dominator 1.
    EXPECT_EQ(dominator(A), 1); // Dominator is 1, found at index 1.
}

// Test when the array doesn't have a dominator with diverse large numbers.
TEST(DominatorTest, DiverseLargeNumbersWithoutDominator)
{
    std::vector<int> A = { 2147483647, -2147483647, 0, 2147483647, -2147483647, 2147483647, -2147483647, 0 };
    EXPECT_EQ(dominator(A), -1);
}

// Test when the array has a dominator with a mixture of large and small numbers.
TEST(DominatorTest, MixedLargeAndSmallNumbersWithDominator)
{
    std::vector<int> A = { -1, 3, 7, -2147483647, -2147483647, -2147483647, -2147483647, 2147483647, -2147483647, -2147483647, 1 };
    // Dominator is -2147483647, found at index 3.
    EXPECT_EQ(dominator(A), 3);
}

// Lesson 8 (Leader) - EquiLeader
// -------------------------------------------------

// Test when there are equi leaders in the array.
TEST(EquiLeaderTest, EquiLeaderExist)
{
    std::vector<int> A = { 4, 3, 4, 4, 4, 2 };
    // There are 2 equi leaders in the array.
    EXPECT_EQ(equiLeader(A), 2);
}

// Test when there are equi leaders in the array.
TEST(EquiLeaderTest, EquiLeadersExist2)
{
    std::vector<int> A = { 4, 3, 4, 4, 4, 2, 4, 4, 4 };
    // There are 7 equi leaders in the array.
    EXPECT_EQ(equiLeader(A), 7);
}

// Test when the array contains only one element.
TEST(EquiLeaderTest, SingleElementArray)
{
    std::vector<int> A = { 5 };
    // There are no equi leaders in a single-element array.
    EXPECT_EQ(equiLeader(A), 0);
}

// Test with a large number of elements where equi leaders exist.
TEST(EquiLeaderTest, LargeInputWithEquiLeaders)
{
    const int N = 100000;
    std::vector<int> A(N, 1000000000);
    A[0] = 48;
    A[N - 1] = 77;
    EXPECT_EQ(equiLeader(A), 99995);
}

// Test with a large number of elements where equi leaders exist.
TEST(EquiLeaderTest, LargeInputWithEquiLeaders2)
{
    const int N = 100000;
    std::vector<int> A(N, 48); // All elements are the same.
    EXPECT_EQ(equiLeader(A), 99999);
}

// Test with a large number of elements with large positive and negative values where equi leaders exist.
TEST(EquiLeaderTest, LargeInputWithLargeValuesAndEquiLeaders)
{
    const int N = 100000;
    std::vector<int> A(N, 0);
    // Set equi leaders at the beginning and end.
    A[0] = 1000000000;
    A[N - 1] = -1000000000;
    EXPECT_EQ(equiLeader(A), 99995);
}

// Lesson 9 (Maximum slice problem) - MaxProfit
// -------------------------------------------------

// Test with a simple example where profit is possible.
TEST(MaxProfitTest, SimpleProfit)
{
    std::vector<int> A = { 23171, 21011, 21123, 21366, 21013, 21367 };
    // Maximum profit is obtained by buying on day 1 (price 21011) and selling on day 5 (price 21367).
    EXPECT_EQ(maxProfit(A), 356);
}

// Test with a simple example where no profit is possible.
TEST(MaxProfitTest, NoProfit)
{
    std::vector<int> A = { 9, 8, 7, 6, 5, 4 };
    // No profit can be obtained as the prices are decreasing each day.
    EXPECT_EQ(maxProfit(A), 0);
}

// Test with an empty array.
TEST(MaxProfitTest, EmptyArray)
{
    std::vector<int> A;
    // There are no prices to analyze, so the result should be 0.
    EXPECT_EQ(maxProfit(A), 0);
}

// Test with a large number of elements and large prices.
TEST(MaxProfitTest, LargeInputWithLargePrices)
{
    const int N = 400000;
    std::vector<int> A(N, 100000);
    // Maximum profit can be obtained by buying on day 0 (price 100000) and selling on the last day (price 100000).
    EXPECT_EQ(maxProfit(A), 0);
}

// Test with a simple example where profit is possible.
TEST(MaxProfitTest, SimpleProfit2)
{
    std::vector<int> A = { 100, 200, 150, 250, 300 };
    // Maximum profit is obtained by buying on day 0 (price 100) and selling on day 4 (price 300).
    EXPECT_EQ(maxProfit(A), 200);
}

// Test with a large number of elements where profit is possible.
TEST(MaxProfitTest, LargeInputWithProfit)
{
    const int N = 400000;
    std::vector<int> A(N, 100000);
    // Modify the prices to create an increasing trend.
    for (int i = 0; i < N; ++i) {
        A[i] += i;
    }
    EXPECT_EQ(maxProfit(A), 399999);
}

// Test with a large number of elements and large prices.
TEST(MaxProfitTest, LargeInputWithLargePrices2)
{
    const int N = 400000;
    std::vector<int> A(N, 200000);
    // Maximum profit can be obtained by buying on day 0 (price 200000) and selling on the last day (price 200000).
    EXPECT_EQ(maxProfit(A), 0);
}

// Lesson 9 (Maximum slice problem) - MaxSliceSum
// -------------------------------------------------

// Test with a simple example.
TEST(MaxSliceSumTest, SimpleExample)
{
    std::vector<int> A = { 3, 2, -6, 4, 0 };
    // Maximum sum can be obtained from the slice (0, 1) with a sum of 5.
    EXPECT_EQ(maxSliceSum(A), 5);
}

// Test with a negative slice that should return the maximum single element.
TEST(MaxSliceSumTest, NegativeSlice)
{
    std::vector<int> A = { -1, -2, -3, -4, -5 };
    // The maximum sum is a single element, which is the highest element (-1).
    EXPECT_EQ(maxSliceSum(A), -1);
}

// Test with all negative values, should return the maximum single element.
TEST(MaxSliceSumTest, AllNegativeValues)
{
    std::vector<int> A = { -5, -3, -7, -2, -8 };
    // The maximum sum is a single element, which is the highest element (-2).
    EXPECT_EQ(maxSliceSum(A), -2);
}

// Test with all positive values, should return the sum of all elements.
TEST(MaxSliceSumTest, AllPositiveValues)
{
    std::vector<int> A = { 1, 2, 3, 4, 5 };
    // The maximum sum is the sum of all elements (15).
    EXPECT_EQ(maxSliceSum(A), 15);
}

// Test with a large number of elements and large values.
TEST(MaxSliceSumTest, LargeInputWithLargeValues)
{
    const int N = 1000000;
    std::vector<int> A(N, 1000000);
    EXPECT_EQ(maxSliceSum(A), 2147000000);
}

// Test with a large input size (maximum value for N) with all elements being positive.
TEST(MaxSliceSumTest, LargeInputWithAllPositiveValues)
{
    const int N = 1000000;
    std::vector<int> A(N, 1000000);
    EXPECT_EQ(maxSliceSum(A), 2147000000);
}

// Test with a large input size (maximum value for N) with all elements being negative.
TEST(MaxSliceSumTest, LargeInputWithAllNegativeValues)
{
    const int N = 1000000;
    std::vector<int> A(N, -1000000);
    // The maximum sum is a single element, which is the highest element (-1000000).
    EXPECT_EQ(maxSliceSum(A), -1000000);
}

// Test with a large input size (maximum value for N) with alternating positive and negative values.
TEST(MaxSliceSumTest, LargeInputWithAlternatingValues)
{
    const int N = 1000000;
    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        A[i] = (i % 2 == 0) ? 1000000 : -1000000;
    }
    EXPECT_EQ(maxSliceSum(A), 1000000);
}

// Lesson 9 (Maximum slice problem) - MaxDoubleSliceSum
// --------------------------------------------------------

// Test with a simple case.
TEST(MaxDoubleSliceSumTest, SimpleCase)
{
    std::vector<int> A = { 3, 2, 6, -1, 4, 5, -1, 2 };
    // The maximal sum of any double slice is 17 (double slice (0, 3, 6)).
    EXPECT_EQ(maxDoubleSliceSum(A), 17);
}

TEST(MaxDoubleSliceSumTest, MaxSum1)
{
    std::vector<int> A = { 10, 5, -5, 3, 2, 6 };
    // The maximal sum of any double slice is 5 + 3 + 2 = 10.
    EXPECT_EQ(maxDoubleSliceSum(A), 10);
}

TEST(MaxDoubleSliceSumTest, MaxSum2)
{
    std::vector<int> A = { 6, -1, 4, 5, -1, 2, 10 };
    // The maximal sum of any double slice is 4 + 5 + 2 = 11.
    EXPECT_EQ(maxDoubleSliceSum(A), 11);
}

TEST(MaxDoubleSliceSumTest, MaxSum3)
{
    std::vector<int> A = { 3, 2, 6, -1, 4, 5, -1, 2, 10, -5 };
    // The maximal sum of any double slice is 2 + 6 + 4 + 5 + (-1) + 2 + 10 = 28.
    EXPECT_EQ(maxDoubleSliceSum(A), 28);
}

// Test with negative values.
TEST(MaxDoubleSliceSumTest, NegativeValues)
{
    std::vector<int> A = { -10, -5, -5, -3, -2, -6 };
    // The maximal sum of any double slice is 0.
    EXPECT_EQ(maxDoubleSliceSum(A), 0);
}

// Test with a large number of elements and values.
TEST(MaxDoubleSliceSumTest, LargeInputs)
{
    const int N = 100000;
    std::vector<int> A(N);

    // Fill the vector with large values.
    for (int i = 0; i < N; ++i) {
        // Use alternating large positive and negative values.
        A[i] = (i % 2 == 0) ? 10000 : -10000;
    }

    // The maximal sum of any double slice is 20000.
    EXPECT_EQ(maxDoubleSliceSum(A), 20000);
}

// Test with a large number of elements and large positive values.
TEST(MaxDoubleSliceSumTest, LargePositiveValues)
{
    const int N = 100000;
    std::vector<int> A(N, 10000);  // All elements are set to a large positive value.

    // The maximal sum of any double slice is (N-3) * 10000 because we exclude the first and last elements.
    EXPECT_EQ(maxDoubleSliceSum(A), (N - 3) * 10000);
}

// Lesson 10 (Prime and composite numbers) - CountFactors
// --------------------------------------------------------

TEST(CountFactorsTest, SmallNumbers)
{
    EXPECT_EQ(countFactors(1), 1);  // 1 has only one factor, which is itself.
    EXPECT_EQ(countFactors(2), 2);  // 2 has factors 1 and 2.
    EXPECT_EQ(countFactors(3), 2);  // 3 is a prime number, so it has factors 1 and 3.
    EXPECT_EQ(countFactors(4), 3);  // 4 has factors 1, 2, and 4.
    EXPECT_EQ(countFactors(5), 2);  // 5 is a prime number, so it has factors 1 and 5.
}

TEST(CountFactorsTest, PrimeNumbers)
{
    EXPECT_EQ(countFactors(17), 2);  // 17 is a prime number, so it has factors 1 and 17.
    EXPECT_EQ(countFactors(31), 2);  // 31 is a prime number, so it has factors 1 and 31.
    EXPECT_EQ(countFactors(97), 2);  // 97 is a prime number, so it has factors 1 and 97.
}

TEST(CountFactorsTest, CompositeNumbers)
{
    EXPECT_EQ(countFactors(24), 8);   // Factors of 24: 1, 2, 3, 4, 6, 8, 12, 24.
    EXPECT_EQ(countFactors(60), 12);  // Factors of 60: 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60.
    EXPECT_EQ(countFactors(100), 9);  // Factors of 100: 1, 2, 4, 5, 10, 20, 25, 50, 100.
}

TEST(CountFactorsTest, LargePrimeNumbers)
{
    EXPECT_EQ(countFactors(2147483647), 2);  // 2147483647 is a prime number, so it has factors 1 and itself.
    EXPECT_EQ(countFactors(15485863), 2);    // 15485863 is also a prime number.
    EXPECT_EQ(countFactors(982451653), 2);   // 982451653 is yet another prime number.
}

TEST(CountFactorsTest, LargeCompositeNumbers)
{
    EXPECT_EQ(countFactors(2147483646), 192);   // Factors of 2147483646 include 1, 2, 3, 6, and many more.
    EXPECT_EQ(countFactors(1023456789), 20);    // Factors of 1023456789: 1, 3, 9, 113717421, and others.
    EXPECT_EQ(countFactors(1771561), 7);        // Factors of 1771561: 1, 11, and others.
}

// Lesson 10 (Prime and composite numbers) - MinPerimeterRectangle
// ------------------------------------------------------------------

TEST(MinPerimeterRectangleTest, NonPerfectSquareNumbers)
{
    EXPECT_EQ(minPerimeterRectangle(30), 22);   // Factors: (1, 30), (2, 15), (3, 10), (5, 6)
    EXPECT_EQ(minPerimeterRectangle(36), 24);   // Factors: (1, 36), (2, 18), (3, 12), (4, 9), (6, 6)
    EXPECT_EQ(minPerimeterRectangle(48), 28);   // Factors: (1, 48), (2, 24), (3, 16), (4, 12), (6, 8)
    EXPECT_EQ(minPerimeterRectangle(77), 36);   // Factors: (7, 11)
    EXPECT_EQ(minPerimeterRectangle(100), 40);  // Factors: (1, 100), (2, 50), (4, 25), (5, 20), (10, 10)
}

TEST(MinPerimeterRectangleTest, PerfectSquareNumbers)
{
    EXPECT_EQ(minPerimeterRectangle(1), 4);     // Square with sides (1, 1)
    EXPECT_EQ(minPerimeterRectangle(4), 8);     // Square with sides (2, 2)
    EXPECT_EQ(minPerimeterRectangle(25), 20);   // Square with sides (5, 5)
    EXPECT_EQ(minPerimeterRectangle(144), 48);  // Square with sides (12, 12)
    EXPECT_EQ(minPerimeterRectangle(324), 72);  // Rectangle
}

TEST(MinPerimeterRectangleTest, LargeNumbers)
{
    EXPECT_EQ(minPerimeterRectangle(1000000000), 126500);  // Large number with many factors.
}

// Lesson 10 (Prime and composite numbers) - Flags
// ------------------------------------------------------------------

TEST(FlagsTest, SinglePeak)
{
    std::vector<int> A = { 1, 3, 2, 2, 1, 5, 5, 4, 6, 8, 9 };
    EXPECT_EQ(flags(A), 1);  // Only one peak exists.
}

TEST(FlagsTest, MultiplePeaks)
{
    std::vector<int> A = { 1, 5, 3, 4, 3, 4, 1, 2, 3, 4, 6, 2 };
    EXPECT_EQ(flags(A), 3);  // Peaks at positions 1, 5, and 10.
}

TEST(FlagsTest, NoPeaks)
{
    std::vector<int> A = { 1, 2, 3, 4, 5, 6 };
    EXPECT_EQ(flags(A), 0);  // No peaks exist.
}

TEST(FlagsTest, LargeInput)
{
    std::vector<int> A(400000, 0);
    EXPECT_EQ(flags(A), 0);  // No peaks exist in a flat landscape.

    // Create a landscape with a single peak at the middle.
    A[199999] = 1000000000;
    EXPECT_EQ(flags(A), 1);

    // Create a landscape with peaks.
    for (int i = 0; i < 400000; i += 2) {
        A[i] = 1000000000;
    }
    EXPECT_EQ(flags(A), 632);
}

// Lesson 12 (Euclidean algorithm) - ChocolatesByNumbers
// ------------------------------------------------------------------

TEST(ChocolatesByNumbersTest, TestCases)
{
    // Test case with N = 1 and M = 1.
    // Expected result: You will eat 1 chocolate (0).
    EXPECT_EQ(chocolatesByNumbers(1, 1), 1);

    // Test case with N = 10 and M = 4.
    // Expected result: You will eat 5 chocolates (0, 4, 8, 2, 6).
    EXPECT_EQ(chocolatesByNumbers(10, 4), 5);

    // Test case with N = 12 and M = 3.
    // Expected result: You will eat 4 chocolates (0, 3, 6, 9).
    EXPECT_EQ(chocolatesByNumbers(12, 3), 4);

    // Test case with N = 7 and M = 5.
    // Expected result: You will eat 7 chocolates (0, 5, 3, 1, 6, 4, 2).
    EXPECT_EQ(chocolatesByNumbers(7, 5), 7);

    // Test case with N = 20 and M = 7.
    // Expected result: You will eat 20 chocolates.
    EXPECT_EQ(chocolatesByNumbers(20, 7), 20);

    // Test case with N = 1 and M = 100.
    // Expected result: You will eat 1 chocolate (0).
    EXPECT_EQ(chocolatesByNumbers(1, 100), 1);

    // Test case with N = 1,000,000,000 and M = 1.
    // Expected result: You will eat 1000000000 chocolates.
    EXPECT_EQ(chocolatesByNumbers(1000000000, 1), 1000000000);

    // Test case with N = 1,000,000,000 and M = 500,000,000.
    // Expected result: You will eat 2 chocolates (0, 500000000).
    EXPECT_EQ(chocolatesByNumbers(1000000000, 500000000), 2);

    // Test case with N = 1,000,000,000 and M = 2.
    // Expected result: You will eat 500,000,000 chocolates (0, 2, 4, ..., 999999998).
    EXPECT_EQ(chocolatesByNumbers(1000000000, 2), 500000000);

    // Test case with N = 1000000000 and M = 999999999.
    // Expected result: You will eat 1000000000 chocolates (0, 1, 2, ..., 999999999).
    EXPECT_EQ(chocolatesByNumbers(1000000000, 999999999), 1000000000);
}

// Lesson 15 (Caterpillar method) - AbsDistinct
// ------------------------------------------------------------------

// Test case for the provided example.
TEST(AbsDistinctTest, ProvidedExample)
{
    std::vector<int> A = { -5, -3, -1, 0, 3, 6 };
    EXPECT_EQ(absDistinct(A), 5); // Expected result is 5.
}

// Test case for an array with all positive values.
TEST(AbsDistinctTest, AllPositive)
{
    std::vector<int> A = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(absDistinct(A), 5); // Expected result is 5.
}

// Test case for an array with all negative values.
TEST(AbsDistinctTest, AllNegative)
{
    std::vector<int> A = { -5, -4, -3, -2, -1 };
    EXPECT_EQ(absDistinct(A), 5); // Expected result is 5.
}

// Test case for an array with mixed positive and negative values.
TEST(AbsDistinctTest, MixedValues)
{
    std::vector<int> A = { -5, -3, -1, 0, 1, 3, 5 };
    EXPECT_EQ(absDistinct(A), 4); // Expected result is 4.
}

// Test case for an array with duplicate values.
TEST(AbsDistinctTest, DuplicateValues)
{
    std::vector<int> A = { -3, -3, 0, 1, 1, 1, 5 };
    EXPECT_EQ(absDistinct(A), 4); // Expected result is 4.
}

// Test case for a large array with all positive values.
TEST(AbsDistinctTest, LargeAllPositive)
{
    std::vector<int> A(100000, 1000000); // Create a vector of 100,000 elements with the value 1,000,000.
    EXPECT_EQ(absDistinct(A), 1); // Expected result is 1 (only one distinct absolute value).
}

// Test case for a large array with all negative values.
TEST(AbsDistinctTest, LargeAllNegative)
{
    std::vector<int> A(100000, -1000000); // Create a vector of 100,000 elements with the value -1,000,000.
    EXPECT_EQ(absDistinct(A), 1); // Expected result is 1 (only one distinct absolute value).
}

// Test case for a large array with alternating positive and negative values.
TEST(AbsDistinctTest, LargeAlternatingValues)
{
    std::vector<int> A;
    for (int i = 0; i < 50000; ++i) {
        A.push_back(-i);
        A.push_back(i);
    }
    EXPECT_EQ(absDistinct(A), 99999); // Expected result is 99,999.
}

// Test case for a diverse array with both positive and negative values.
TEST(AbsDistinctTest, DiverseValues)
{
    std::vector<int> A = { -5, -3, -1, 0, 1, 2, 2, 3, 4, 5, 1000000, -1000000 };
    EXPECT_EQ(absDistinct(A), 8); // Expected result is 8.
}

// Test case for a diverse array with a mix of large and small numbers.
TEST(AbsDistinctTest, DiverseLargeAndSmallNumbers)
{
    std::vector<int> A = { -2147483648, -1000000, -100, 0, 100, 1000000, 2147483647 };
    EXPECT_EQ(absDistinct(A), 7); // Expected result is 7.
}

// Test case for a large array with diverse values.
TEST(AbsDistinctTest, LargeDiverseValues)
{
    std::vector<int> A;
    for (int i = -50000; i < 50000; ++i) {
        A.push_back(i);
    }
    EXPECT_EQ(absDistinct(A), 50001); // Expected result is 50,001.
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
