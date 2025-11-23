#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

/*
 Find the length of the longest substring without repeating characters.
 
 Approach (sliding window):
  - Use two pointers (l, r) to maintain a window of characters.
  - Use an unordered_set to track characters in the current window.
  - Expand window by moving r pointer to the right.
  - If a duplicate is found, shrink window from left (move l) until duplicate is removed.
  - Track the maximum window size encountered.
 
 Time complexity: O(n) where n = substr.size() (each character visited at most twice).
 Space complexity: O(min(n, charset_size)) for the set (at most unique characters).
*/
int getLongestSubString(const string &substr)
{
    int result = 0;              // maximum length found so far
    int l = 0;                   // left pointer of sliding window
    unordered_set<char> cSet;    // characters in current window

    // Expand window by moving right pointer
    for(int r = 0; r < substr.size(); r++)
    {
        // If character at r is already in the window, we have a duplicate
        if(cSet.find(substr[r]) != cSet.end())
        {
            // Shrink window from left until the duplicate is removed
            cSet.erase(substr[l]);
            l++;
        }

        // Add current character to the window
        cSet.insert(substr[r]);

        // Update maximum length: current window size = r - l + 1
        result = max(result, r - l + 1);
    }

    return result;
}

int main()
{
    string substr = "abcabcbb";
    
    // Expected output: 3 (substring "abc")
    cout << "Longest substring without repeating characters: " 
         << getLongestSubString(substr) << "\n";
    
    return 0;
}