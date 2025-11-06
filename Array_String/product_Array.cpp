/*
Given an integer array nums, return an array output where output[i] is the product of all the elements of nums except nums[i].

Each product is guaranteed to fit in a 32-bit integer.

Follow-up: Could you solve it in O(n)
O(n) time without using the division operation?

Example 1:

Input: nums = [1,2,4,6]

Output: [48,24,12,8]

Given an integer array nums, return an array result where result[i] is the
product of all the elements of nums except nums[i].

Approach (no division, O(n) time, O(1) extra space excluding output):
 1. First pass (left-to-right): compute prefix products and store in result.
    result[i] will hold product of all elements to the left of i.
 2. Second pass (right-to-left): maintain a running postfix product and
    multiply it into result[i] to incorporate products of elements to the right.
    Update postfix by multiplying by nums[i] as we move left.
 This uses O(n) time and O(1) extra space (postfix variable), output vector
uses O(n) space.

Edge cases:
 - If nums is empty return empty result.
 - Works for zeros naturally (prefix/postfix handle zeros correctly).
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> product_Array(vector<int> &nums)
{
    int n = (int)nums.size();
    if (n == 0) return {};

    // result[i] will hold the product of all elements to the left of i
    vector<int> result(n, 1);

    // Build prefix products: result[i] = nums[0] * nums[1] * ... * nums[i-1]
    for (int i = 1; i < n; i++)
    {
        result[i] = result[i - 1] * nums[i - 1];
    }

    // postfix holds product of elements to the right of current index
    int postfix = 1;
    // Multiply each result[i] by postfix (product of elements to the right)
    for (int i = n - 1; i >= 0; i--)
    {
        result[i] *= postfix;
        postfix *= nums[i]; // update postfix to include nums[i] for next iteration
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 4, 6};

    // Expected output: [48, 24, 12, 8]
    vector<int> r = product_Array(nums);

    for (auto v : r)
    {
        cout << v << " ";
    }
    cout << "\n";
    return 0;
}