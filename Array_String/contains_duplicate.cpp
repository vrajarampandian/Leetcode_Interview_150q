#include<iostream>
#include<vector>
#include<set>
using namespace std;

// Check if array contains any duplicate element.
// Time complexity: O(n) on average (set operations are O(log n) for std::set -> overall O(n log n);
//                  if using unordered_set, average O(n) with O(n) extra space).
// Space complexity: O(n) additional space for the set.
int main()
{
    vector<int> nums = {1,2,3,1};

    // Use a set to track seen elements
    set<int> hashset;

    for (int i = 0; i < nums.size(); i++)
    {
        // If element already in set, we found a duplicate
        auto it = hashset.find(nums[i]);
        if (it != hashset.end())
        {
            cout << "Found duplicate\n";
            break;
        }

        // Mark element as seen
        hashset.insert(nums[i]);
    }
}