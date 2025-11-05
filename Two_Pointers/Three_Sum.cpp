/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] where nums[i] + nums[j] + nums[k] == 0, and the indices i, j and k are all distinct.

The output should not contain any duplicate triplets. You may return the output and the triplets in any order.

Example 1:

Input: nums = [-1,0,1,2,-1,-4]

Output: [[-1,-1,2],[-1,0,1]]
*/

/*
 Given an integer array nums, return all unique triplets [nums[i], nums[j], nums[k]]
 such that nums[i] + nums[j] + nums[k] == 0.

 Approach:
 1. Sort the array to allow two-pointer scanning and easy duplicate skipping.
 2. For each index i (as the first element), use two pointers l and r to find pairs
    where nums[i] + nums[l] + nums[r] == 0.
 3. Skip duplicates for i, l and r to ensure unique triplets.

 Time complexity: O(n^2) where n = nums.size() (outer loop * two-pointer scan).
 Space complexity: O(1) extra space (excluding output).
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int>> threesum(vector<int> &nums)
{
    // Sort to use two-pointer technique and to make duplicate handling simple
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    // Iterate each number as the first element of the triplet
    for (int i = 0; i < nums.size(); i++)
    {
        // If current number is > 0, no triplet can sum to zero (array is sorted)
        if (nums[i] > 0)
            break;

        // Skip duplicate values for the first element to avoid duplicate triplets
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int l = i + 1;                 // left pointer (next element after i)
        int r = (int)nums.size() - 1;  // right pointer (end of array)

        // Two-pointer scan for pairs that make sum zero with nums[i]
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum > 0)
            {
                // Sum too large: move right pointer left to decrease sum
                r--;
            }
            else if (sum < 0)
            {
                // Sum too small: move left pointer right to increase sum
                l++;
            }
            else
            {
                // Found a valid triplet
                result.push_back({nums[i], nums[l], nums[r]});

                // Move both pointers to continue searching for other pairs
                l++;
                r--;

                // Skip duplicates for the left pointer
                while (l < r && nums[l] == nums[l - 1])
                {
                    l++;
                }

                // Skip duplicates for the right pointer
                while (l < r && nums[r] == nums[r + 1])
                {
                    r--;
                }
            }
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> re = threesum(nums);

    // Print each triplet on its own line
    for (const auto &row : re)
    {
        for (int v : row)
        {
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}
