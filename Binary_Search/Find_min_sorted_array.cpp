#include<iostream>
#include<vector>
using namespace std;

/*
 Find the minimum element in a rotated sorted array.
 
 A rotated sorted array is a sorted array rotated at some unknown pivot.
 Example: [3,4,5,1,2] is [1,2,3,4,5] rotated at pivot index 2.
 
 Approach (binary search):
  - The array has two sorted portions: left portion and right portion.
  - The minimum is always at the start of the right (unsorted) portion.
  - Compare nums[m] with nums[r]:
    - If nums[m] < nums[r]: minimum is in left half (including m), move r = m.
    - If nums[m] > nums[r]: minimum is in right half (after m), move l = m + 1.
    - If nums[m] == nums[r]: cannot determine; would need l++ (rare edge case).
  - When l == r, we've found the minimum.
 
 Time complexity: O(log n) average (binary search), O(n) worst-case (duplicates).
 Space complexity: O(1).
*/
int get_min_sorted_array(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;

    // Continue until pointers converge to the minimum element
    while(l < r)
    {
        // Safe midpoint calculation to avoid overflow
        int m = l + ((r - l) / 2);

        // Compare middle with right pointer to decide which half has the minimum
        if(nums[m] < nums[r])
        {
            // Minimum is in left half (including m)
            // Set r = m to include m in the search space
            r = m;
        }
        else
        {
            // Minimum is in right half (after m)
            // Set l = m + 1 to exclude m (we know nums[m] > nums[r])
            l = m + 1;
        }
    }

    // When l == r, we've found the minimum element
    return nums[l];
}

int main()
{
    vector<int> nums = {3, 4, 5, 0, 1, 2};
    cout << "Minimum element: " << get_min_sorted_array(nums) << "\n";
    // Output: 0
    return 0;
}