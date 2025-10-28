/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
 
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]*/

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
Assume exactly one solution and you may not use the same element twice.
Time complexity: O(n) average, where n = nums.size() (unordered_map lookups are O(1) average).
Space complexity: O(n) for the hash map.
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Return indices of the two numbers that add up to target.
// Uses a hash map to store value -> index while scanning the array.
vector<int> twosum(vector<int> &nums, int target)
{
    unordered_map<int, int> umap; // value -> index

    for (int i = 0; i < nums.size(); i++)
    {
        int diff = target - nums[i];   
        auto it = umap.find(diff);
        if (it != umap.end())
        {
            // Found complement earlier: return pair of indices
            return {it->second, i};
        }
        // Store current value and its index for future complements
        umap[nums[i]] = i;
    }

    // If no solution found (problem guarantees one), return sentinel
    return {-1, -1};
} 

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 18; // example target
    vector<int> result = twosum(nums, target);

    // Print resulting indices (or -1 -1 if not found)
    for (int idx : result)
    {
        cout << idx << " ";
    }
    cout << "\n";
    return 0;
}
