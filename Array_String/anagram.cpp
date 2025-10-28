/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:
1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/

#include<iostream>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;

/*
 Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 Approach used below: frequency counting via unordered_map (works for general characters).
 - Build frequency map for s, then decrement using t.
 - If any count goes negative or a char in t is missing, not an anagram.

 Time complexity: O(n) where n = s.length() (single pass to build map, single pass to verify).
 Space complexity: O(k) where k = number of distinct characters in s (unordered_map overhead).
 Note: if input is guaranteed lowercase English letters, use int freq[26] for O(1) space.
*/
bool isAnagram(string s, string t)
{
    if(s.length() != t.length())
        return false;

    unordered_map<char, int> m;
    for(char c : s)
    {
        m[c]++;
    }

    for(char c : t)
    {
        auto it = m.find(c);
        if(it == m.end() || --(it->second) < 0)
            return false;
    }
    return true;
    
    // Alternative: fixed-size byte-frequency (works when treating inputs as bytes)
    // Time: O(n), Space: O(1) (256 counters)
    /*int freq[256] = {0};
    for(int i = 0; i < s.length(); i++)
    {
        freq[(unsigned char)s[i]]++;
        freq[(unsigned char)t[i]]--;
    }

    for(int i = 0; i < 256; i++)
    {
        if(freq[i] != 0)
            return false;
    }

    return true;*/

    // Alternative: sorting (simple, but slower)
    // Time: O(n log n), Space: O(1) or O(n) depending on sort implementation
    
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    for(int i = 0; i< s.length(); i++)
    {
        if(s[i] != t[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s = "anagram";
    string t = "nagaram";

    if(isAnagram(s, t))
    {
        cout << "True" << "\n";
    } 
    else
    {
        cout << "False" << "\n";
    }
    return 0;
}