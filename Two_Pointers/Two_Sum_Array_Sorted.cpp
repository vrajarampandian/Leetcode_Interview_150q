/*
Given an array of integers numbers that is sorted in non-decreasing order.

Return the indices (1-indexed) of two numbers, [index1, index2], such that they add up to a given target number target and index1 < index2.
There will always be exactly one valid solution.
Your solution must use O(1) additional space.

Approach: two-pointer scan from both ends (works because array is sorted).
Time complexity: O(n)
Space complexity: O(1)
*/

#include<vector>
#include<iostream>
using namespace std;

// Find two indices (1-indexed) whose values sum to target.
// Use two pointers l (left) and r (right) and move inward depending on sum.
vector<int> twoSum(vector<int> &nums, int target)
{
    int l = 0;
    int r = (int)nums.size() - 1;

    while (l < r)
    {
        int sum = nums[l] + nums[r];

        if (sum > target)
        {
            // Sum too large: decrease right pointer to reduce sum
            r--;
        }
        else if (sum < target)
        {
            // Sum too small: increase left pointer to increase sum
            l++;
        }
        else
        {
            // Found the pair; return 1-indexed positions as required
            return {l + 1, r + 1};
        }
    }

    // Problem guarantees a solution; return empty vector as fallback
    return {};
}

int main()
{
    // Example usage
    vector<int> nums = {2, 7, 11, 15};
    int target = 18;

    // Compute result
    vector<int> result = twoSum(nums, target);

    // Print resulting indices
    for (auto idx : result)
    {
        cout << idx << " ";
    }
    cout << "\n";
    return 0;
}