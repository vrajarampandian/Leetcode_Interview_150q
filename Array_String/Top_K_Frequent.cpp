#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

// Return the k most frequent elements from nums.
// Approach:
// 1. Count frequency of each value using unordered_map.
// 2. Move (frequency, value) pairs into a vector.
// 3. Sort pairs by frequency descending and take first k values.
//
// Time complexity: O(n + m log m) where n = nums.size(), m = number of distinct values.
//   - counting: O(n) average
//   - building pairs: O(m)
//   - sorting pairs: O(m log m)
// Space complexity: O(m) for the map and pairs (m = distinct values)
vector<int> getTop_k_Frequent(vector<int> &nums, int k)
{
    unordered_map<int, int> count; // value -> frequency

    // Count frequencies
    for(auto i : nums)
    {
        count[i]++;
    }

    // Move (frequency, value) into a vector so we can sort by frequency
    vector<pair<int,int>> arr;
    for(const auto &p : count)
    {
        // store as (freq, value) to sort by first element easily
        arr.push_back({p.second, p.first});
    }

    // Sort by frequency descending. pair compares first then second;
    // rbegin/rend with default comparator sorts by first descending.
    sort(arr.rbegin(), arr.rend());

    // Collect top-k values
    vector<int> result;
    for(int i = 0; i < k && i < (int)arr.size(); i++)
    {
        result.push_back(arr[i].second);
    }
    return result;
}

int main()
{
    // Example usage
    vector<int> nums = {1,2,2,3,3,3};
    int k = 2;

    vector<int> r = getTop_k_Frequent(nums, k);

    // Print result
    for(auto i : r)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}