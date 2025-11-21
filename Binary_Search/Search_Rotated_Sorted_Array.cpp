#include<vector>
#include<iostream>
using namespace std;

/*
 Search target in a rotated sorted array and return its index, or -1 if not found.
 Approach:
  - Use modified binary search. At each step determine which half is sorted:
    - If nums[l] <= nums[m], left half [l..m] is sorted.
    - Otherwise right half [m..r] is sorted.
  - Decide which half may contain target and move l/r accordingly.
 Time complexity: O(log n) on average.
 Space complexity: O(1).
*/
int search(vector<int>& nums, int target)
{
    int l = 0;
    int r = (int)nums.size() - 1;

    while (l <= r)
    {
        // safe midpoint to avoid overflow
        int m = l + (r - l) / 2;

        if (target == nums[m])
            return m;

        // If left half [l..m] is sorted
        if (nums[l] <= nums[m])
        {
            // Target in left sorted half?
            if (target >= nums[l] && target < nums[m])
                r = m - 1;   // search left
            else
                l = m + 1;   // search right
        }
        else
        {
            // Right half [m..r] must be sorted
            // Target in right sorted half?
            if (target > nums[m] && target <= nums[r])
                l = m + 1;   // search right
            else
                r = m - 1;   // search left
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    int t = 0;
    cout << search(nums, t) << "\n";
    return 0;
}