/*
 Given a string s, return true if it is a palindrome, otherwise return false.
 The check is case-insensitive and ignores non-alphanumeric characters.

 Approach:
  - Use two pointers (left and right) to scan the string from both ends.
  - Advance each pointer to the next alphanumeric character.
  - Compare the lowercased characters; if any mismatch, return false.
  - If pointers cross without mismatch, the string is a palindrome.

 Time complexity: O(n) where n = s.length() (each character is visited at most once).
 Space complexity: O(1) extra space.
*/

#include<iostream>
#include<string>
#include<cctype> // for std::tolower
using namespace std;

// Return true if c is an alphanumeric character (A-Z, a-z, 0-9)
bool checkchacters(char c)
{
    return (c >= 'A' && c <= 'Z' ||
            c >= 'a' && c <= 'z' ||
            c >= '0' && c <= '9');
}

// Check if the input string is a valid palindrome under the problem rules
bool isPalindrome(string s)
{
    int l = 0;
    int e = (int)s.size() - 1;

    // Move pointers towards center, skipping non-alphanumeric chars
    while (l < e)
    {
        // advance left pointer until it points to an alphanumeric or crosses right
        while (l < e && !checkchacters(s[l]))
        {
            l++;
        }

        // advance right pointer until it points to an alphanumeric or crosses left
        while (e > l && !checkchacters(s[e]))
        {
            e--;
        }

        // compare case-insensitively; tolower requires casting to unsigned char in
        // general code, but input is ASCII in problem constraints.
        if (tolower((unsigned char)s[l]) != tolower((unsigned char)s[e]))
        {
            return false; // mismatch found
        }

        // move inward after successful match
        l++;
        e--;
    }

    return true; // no mismatches found
}

int main()
{
    string s = "A man, a plan, a canal: Panama";

    if (isPalindrome(s))
    {
        cout << "True" << "\n";
    }
    else
    {
        cout << "False" << "\n";
    }

    return 0;
}