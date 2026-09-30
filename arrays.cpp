//485. Max Consecutive Ones-Single pass with running counter-Amazon, Google
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int high=0;
        int res=0;
        int count=0;

        for(int high=0;high<n;high++){
            if(nums[high]==1){
                count++;
                res=max(res,count);
                
            }
            else
                count=0;;
            
            



        }
    return res;    
    }    
    
};


//2511. Maximum Enemy Forts That Can Be Captured
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int count = 0;
        int res = 0;
        int prev = 0;

        for(int i = 0; i < forts.size(); i++) {

            if(forts[i] == 0) {
                count++;
            }
            else {
                if(prev != 0 && prev != forts[i]) {
                    res = max(res, count);
                }

                prev = forts[i];
                count = 0;
            }
        }

        return res;
    }
};

// # 2511. Maximum Enemy Forts That Can Be Captured

// ## Problem

// Given an array `forts`:

// * `1` = our fort
// * `-1` = enemy fort
// * `0` = empty position

// We can capture enemy forts when there are only `0`s between two forts of **opposite types**.

// ### Example

// ```cpp
// [1, 0, 0, 0, -1]
// ```

// The `1` and `-1` are opposite forts, and there are three `0`s between them.

// Therefore:

// ```text
// Answer = 3
// ```

// ---

// # Main Idea

// We scan the array from left to right.

// We need to keep track of 3 things:

// ```cpp
// count → number of consecutive 0s
// prev  → previous non-zero fort
// res   → maximum number of 0s that can be captured
// ```

// The important pattern is:

// ```text
// previous fort
//       ↓
// 1  0  0  0  -1
//    └──────┘
//       ↓
//    count = 3
// ```

// If the previous fort and current fort are different:

// ```cpp
// prev != forts[i]
// ```

// then the zeros between them can be captured.

// ---

// # Code

// ```cpp
// class Solution {
// public:
//     int captureForts(vector<int>& forts) {
//         int count = 0;
//         int res = 0;
//         int prev = 0;

//         for(int i = 0; i < forts.size(); i++) {

//             if(forts[i] == 0) {
//                 count++;
//             }
//             else {
//                 if(prev != 0 && prev != forts[i]) {
//                     res = max(res, count);
//                 }

//                 prev = forts[i];
//                 count = 0;
//             }
//         }

//         return res;
//     }
// };
// ```

// ---

// # Variable Explanation

// ## 1. `count`

// ```cpp
// int count = 0;
// ```

// `count` stores the number of `0`s between two non-zero forts.

// Example:

// ```text
// [1, 0, 0, 0, -1]
//    ↑  ↑  ↑
// ```

// When we encounter the three zeros:

// ```text
// count = 1
// count = 2
// count = 3
// ```

// So:

// ```text
// count = current number of consecutive zeros
// ```

// ---

// ## 2. `res`

// ```cpp
// int res = 0;
// ```

// `res` stores the **maximum number of forts captured so far**.

// We use:

// ```cpp
// res = max(res, count);
// ```

// because there can be multiple groups.

// Example:

// ```text
// [1, 0, -1, 0, 0, 1]
// ```

// First group:

// ```text
// 1 0 -1
//   ↑
// count = 1
// ```

// Second group:

// ```text
// -1 0 0 1
//    ↑ ↑
// count = 2
// ```

// The answer should be `2`.

// Therefore we need `res` to remember the largest group.

// ---

// ## 3. `prev`

// ```cpp
// int prev = 0;
// ```

// `prev` stores the **previous non-zero fort**.

// It can be:

// ```text
// 1
// ```

// or:

// ```text
// -1
// ```

// Initially:

// ```cpp
// prev = 0;
// ```

// because we haven't encountered any fort yet.

// ---

// # Step-by-Step Code Explanation

// ## Step 1 — Traverse the array

// ```cpp
// for(int i = 0; i < forts.size(); i++)
// ```

// We check every element from left to right.

// ---

// # Step 2 — If current element is `0`

// ```cpp
// if(forts[i] == 0) {
//     count++;
// }
// ```

// A `0` means there is an empty position between forts.

// So increase `count`.

// Example:

// ```text
// [1, 0, 0, 0, -1]
// ```

// After processing:

// ```text
// 0 → count = 1
// 0 → count = 2
// 0 → count = 3
// ```

// ---

// # Step 3 — If current element is NOT `0`

// ```cpp
// else {
// ```

// This means:

// ```cpp
// forts[i] == 1
// ```

// or:

// ```cpp
// forts[i] == -1
// ```

// So we have reached a fort.

// Now we need to check whether the zeros before it can be captured.

// ---

// # Step 4 — Check if the two forts are opposite

// ```cpp
// if(prev != 0 && prev != forts[i])
// ```

// This contains two conditions.

// ## Condition 1

// ```cpp
// prev != 0
// ```

// This checks whether a previous fort actually exists.

// Initially:

// ```text
// prev = 0
// ```

// When we encounter the first fort, there is no previous fort.

// Therefore we cannot capture anything yet.

// ---

// ## Condition 2

// ```cpp
// prev != forts[i]
// ```

// This checks whether the previous fort and current fort are different.

// Valid:

// ```text
// 1 ... -1
// ```

// because:

// ```text
// 1 != -1
// ```

// Also valid:

// ```text
// -1 ... 1
// ```

// because:

// ```text
// -1 != 1
// ```

// Invalid:

// ```text
// 1 ... 1
// ```

// because:

// ```text
// 1 == 1
// ```

// Invalid:

// ```text
// -1 ... -1
// ```

// because:

// ```text
// -1 == -1
// ```

// So the condition:

// ```cpp
// prev != forts[i]
// ```

// means:

// > The two forts must be opposite types.

// ---

// # Step 5 — Update the maximum

// ```cpp
// res = max(res, count);
// ```

// If the two forts are opposite, the zeros between them can be captured.

// Example:

// ```text
// [1, 0, 0, 0, -1]
// ```

// At `-1`:

// ```text
// prev = 1
// count = 3
// forts[i] = -1
// ```

// Since:

// ```text
// 1 != -1
// ```

// we can capture the three zeros.

// Therefore:

// ```cpp
// res = max(0, 3);
// ```

// Result:

// ```text
// res = 3
// ```

// ---

// # Step 6 — Update `prev`

// ```cpp
// prev = forts[i];
// ```

// After processing the current fort, it becomes the previous fort for future elements.

// Example:

// ```text
// [1, 0, 0, -1, 0, 1]
// ```

// When we reach `1`:

// ```text
// prev = 1
// ```

// Then we encounter:

// ```text
// 0 0
// ```

// Then reach:

// ```text
// -1
// ```

// Now:

// ```text
// prev = 1
// current = -1
// ```

// After processing `-1`:

// ```cpp
// prev = -1;
// ```

// So `-1` becomes the previous fort for the next part of the array.

// ---

// # Step 7 — Reset `count`

// ```cpp
// count = 0;
// ```

// We've reached a non-zero fort, so the previous sequence of zeros has ended.

// We reset `count` so that we can start counting a new sequence of zeros.

// Example:

// ```text
// [1, 0, 0, -1, 0, 0, 1]
// ```

// First:

// ```text
// 1 0 0 -1
//   ↑ ↑
// count = 2
// ```

// After reaching `-1`:

// ```cpp
// count = 0;
// ```

// Then:

// ```text
// -1 0 0 1
//    ↑ ↑
// count = 2
// ```

// Now we count the new zeros separately.

// ---

// # Dry Run

// Consider:

// ```cpp
// forts = [1, 0, 0, 0, -1]
// ```

// Initial:

// ```text
// count = 0
// res = 0
// prev = 0
// ```

// ### `i = 0`

// ```text
// forts[0] = 1
// ```

// Not zero → `else`.

// Check:

// ```text
// prev != 0
// 0 != 0 → false
// ```

// So nothing happens.

// Then:

// ```text
// prev = 1
// count = 0
// ```

// ---

// ### `i = 1`

// ```text
// forts[1] = 0
// ```

// Therefore:

// ```text
// count = 1
// ```

// ---

// ### `i = 2`

// ```text
// forts[2] = 0
// ```

// Therefore:

// ```text
// count = 2
// ```

// ---

// ### `i = 3`

// ```text
// forts[3] = 0
// ```

// Therefore:

// ```text
// count = 3
// ```

// ---

// ### `i = 4`

// ```text
// forts[4] = -1
// ```

// Not zero.

// Check:

// ```text
// prev != 0
// 1 != 0 → true

// prev != forts[i]
// 1 != -1 → true
// ```

// Both are true.

// Therefore:

// ```cpp
// res = max(0, 3);
// ```

// So:

// ```text
// res = 3
// ```

// Then:

// ```cpp
// prev = -1;
// count = 0;
// ```

// Finally:

// ```cpp
// return res;
// ```

// Answer:

// ```text
// 3
// ```

// ---

// # Another Example

// ```cpp
// forts = [1, 0, 1]
// ```

// There is:

// ```text
// 1 0 1
// ```

// The forts are the **same type**.

// So:

// ```text
// prev = 1
// current = 1
// ```

// Therefore:

// ```cpp
// prev != forts[i]
// ```

// is false.

// We cannot capture the `0`.

// Answer:

// ```text
// 0
// ```

// ---

// # Important Pattern

// This problem uses a simple **one-pass traversal**.

// We don't need nested loops.

// Instead, remember:

// ```text
// prev  → previous non-zero value
// count → zeros after prev
// res   → maximum valid count
// ```

// Visualize it as:

// ```text
// prev        current
//  ↓             ↓
//  1   0  0  0  -1
//      └──────┘
//        count
// ```

// When:

// ```cpp
// prev != 0 && prev != forts[i]
// ```

// we have:

// ```text
// opposite fort → zeros → opposite fort
// ```

// so:

// ```cpp
// res = max(res, count);
// ```

// ---

// # Why We Don't Use `low` and `high`

// Initially, you were trying to solve this using:

// ```cpp
// i
// j
// k
// ```

// and nested loops.

// But that's unnecessary.

// We only need to remember the **previous non-zero fort**, so one traversal is enough.

// Instead of searching:

// ```text
// fort → search for next fort → count zeros
// ```

// we simply keep:

// ```text
// previous fort
// +
// current zero count
// ```

// while scanning.

// ---

// # Complexity

// We traverse the array only once.

// ### Time Complexity

// ```text
// O(n)
// ```

// where `n = forts.size()`.

// ### Space Complexity

// ```text
// O(1)
// ```

// because we only use:

// ```cpp
// count
// res
// prev
// ```

// and no extra array.

// ---

// # Final Code

// ```cpp
// class Solution {
// public:
//     int captureForts(vector<int>& forts) {
//         int count = 0;
//         int res = 0;
//         int prev = 0;

//         for(int i = 0; i < forts.size(); i++) {

//             if(forts[i] == 0) {
//                 count++;
//             }
//             else {
//                 if(prev != 0 && prev != forts[i]) {
//                     res = max(res, count);
//                 }

//                 prev = forts[i];
//                 count = 0;
//             }
//         }

//         return res;
//     }
// };
// ```

// ## One-line memory trick

// ```text
// Count 0s → remember previous fort → if opposite, update maximum.
// ```

//1295. find even number of digits in a array

class Solution {
public:
    /**
     * Counts the number of integers that contain an even number of digits.
     *
     * Approach:
     * - Traverse through each number in the array.
     * - Count the number of digits using repeated integer division by 10.
     * - If the digit count is even, increment the result.
     *
     * Example:
     * nums = [12, 345, 2, 6, 7896]
     *
     * 12   -> 2 digits  -> Even  -> Count
     * 345  -> 3 digits  -> Odd
     * 2    -> 1 digit   -> Odd
     * 6    -> 1 digit   -> Odd
     * 7896 -> 4 digits  -> Even  -> Count
     *
     * Result = 2
     *
     * Time Complexity: O(n * d)
     *   - n = number of elements in nums
     *   - d = number of digits in each number
     *
     * Space Complexity: O(1)
     *   - Only a constant amount of extra space is used.
     *
     * @param nums Vector of integers.
     * @return Number of integers having an even number of digits.
     */
    int findNumbers(vector<int>& nums) {

        int count = 0;

        // Traverse through every number in the array
        for (int i = 0; i < nums.size(); i++) {

            int n = nums[i];
            int digits = 0;

            // Count the number of digits in the current number
            while (n > 0) {
                n = n / 10;
                digits++;
            }

            // Check if the number of digits is even
            if (digits % 2 == 0) {
                count++;
            }
        }

        return count;
    }
};




//1480. running sum of an array
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=1; i<n ;i++){
            nums[i] = nums[i]+nums[i-1];
        }
    return nums ;   
    }
};


//414.Third maximum number 


#include <vector>
#include <climits>

class Solution {
public:
    // Finds 3rd distinct max, or overall max if < 3 distinct exist.
    // Time: O(n), Space: O(1).
    int thirdMax(std::vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int n : nums) {
            // Ignore duplicates
            if (n == first || n == second || n == third) continue;

            if (n > first) {
                third = second;
                second = first;
                first = n;
            } else if (n > second) {
                third = second;
                second = n;
            } else if (n > third) {
                third = n;
            }
        }

        // If third maximum was never updated, return overall maximum
        return (third == LLONG_MIN) ? first : third;
    }
};
