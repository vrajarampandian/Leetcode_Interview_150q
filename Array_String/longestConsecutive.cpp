#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;

/*
 Find the length of the longest consecutive elements sequence.
 Approach:
  - Insert all numbers into an unordered_set for O(1) average lookups.
  - For each number that is the potential sequence start (num-1 not present),
    walk forward counting consecutive numbers.
 Time complexity: O(n) average (each number is visited at most twice).
 Space complexity: O(n) for the set.
*/
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> num_set(nums.begin(), nums.end());
    int longest_streak = 0;

    for (int num : num_set)
    {
        // only start counting when 'num' is the beginning of a sequence
        if (num_set.find(num - 1) == num_set.end())
        {
            int current_num = num;
            int current_streak = 1;

            // extend the sequence while the next integer exists in the set
            while (num_set.find(current_num + 1) != num_set.end())
            {
                current_num++;
                current_streak++;
            }

            longest_streak = max(longest_streak, current_streak);
        }
    }

    return longest_streak;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    int result = longestConsecutive(nums);
    cout << result << "\n"; // expected 4 (1,2,3,4)
    return 0;
}
