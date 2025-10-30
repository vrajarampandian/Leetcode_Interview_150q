#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

// Group anagrams by using a 26-length frequency signature as the map key.
// Time: O(N * L) where N = number of strings, L = average string length.
// Space: O(N * L) for stored groups (plus map overhead).
vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> result;

    for(const auto &s : strs)
    {
        // Count frequency of each lowercase letter in the string
        vector<int> count(26, 0);
        for(char c : s)
        {
            count[c - 'a']++;
        }

        // Build a compact key from counts, e.g. "1,0,2,0,..."
        string key = to_string(count[0]);
        for(int i = 1; i < 26; i++)
        {
            key += "," + to_string(count[i]);
        }

        // Group strings with the same key together
        result[key].push_back(s);
    }

    // Move grouped anagrams into the result vector
    vector<vector<string>> r;
    for(const auto &p : result)
    {
        r.push_back(p.second);
    }

    return r;
}

int main()
{
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = groupAnagrams(strs);

    // Print grouped anagrams: each group on its own line
    for(const auto &grp : result)
    {
        cout << "[";
        for(int i = 0; i < grp.size(); i++)
        {
            cout << '"' << grp[i] << '"';
            if(i + 1 < grp.size())
                cout << ", ";
        }
        cout << "]\n";
    }
    return 0;
}