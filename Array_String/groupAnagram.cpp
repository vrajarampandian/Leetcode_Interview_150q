#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> result;
    for(const auto &s : strs)
    {
        vector<int> count(26, 0);

        for(char c : s)
        {
            count[c - 'a']++;
        }
        string key = to_string(count[0]);

        for(int i = 1; i < 26; i++)
        {
            key += "," + to_string(count[i]);
        }

        result[key].push_back(s);
    }

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

    for(const auto &grp : result)
    {
        cout << "[";
        for(int i = 0; i < grp.size(); i++)
        {
            cout <<'"'<<grp[i] <<'"';
            if(i + 1 < grp.size())
                cout << ", ";
        }
        cout << "]";
    }
    return 0;
}