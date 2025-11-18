#include<iostream>
#include<vector>
using namespace std;

/*
 Binary Search: find target in sorted array and return its index, or -1 if not found.
 
 Approach:
  - Maintain left (l) and right (r) pointers bounding the search space.
  - Compute midpoint m and compare nums[m] with target.
  - If nums[m] > target, search left half (r = m - 1).
  - If nums[m] < target, search right half (l = m + 1).
  - If nums[m] == target, return m immediately.
  - If l > r, target not found; return -1.
 
 Time complexity: O(log n) where n = nums.size() (search space halves each iteration).
 Space complexity: O(1) extra space (only pointers used).
*/
int search(vector<int> nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    
    while (l <= r)
    {
        // Compute midpoint safely to avoid integer overflow.
        // Formula: m = l + ((r - l) / 2)
        // Why not just m = (l + r) / 2?
        //   - If l and r are large, l + r may overflow int range.
        //   - This formula computes the same result without overflow:
        //     m = l + ((r - l) / 2) = l + (r - l) / 2 = (2*l + r - l) / 2 = (l + r) / 2
        //   - Example: l = 2000000000, r = 2000000001
        //     - (l + r) / 2 would overflow and give wrong result.
        //     - l + ((r - l) / 2) = 2000000000 + 1/2 = 2000000000 (safe).
        int m = l + ((r - l) / 2);

        if (nums[m] > target)
        {
            // Target is in left half; search there
            r = m - 1;
        }
        else if (nums[m] < target)
        {
            // Target is in right half; search there
            l = m + 1;
        }
        else
        {
            // Found target at index m
            return m;
        }
    }
    
    // Target not found in the array
    return -1;
}

int main()
{
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    cout << search(nums, 9) << "\n"; // Output: 4 (index of 9)
    return 0;
}