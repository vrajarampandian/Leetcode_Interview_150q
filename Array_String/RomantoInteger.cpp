#include<iostream>
#include<unordered_map>
using namespace std;

int romanToInt(string s) {
        unordered_map<char, int> v = {
            {'I', 1},{'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500},
            {'M', 1000}
        };

        int r = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(i + 1 < s.size() && v[s[i]] < v[s[i+1]])
            {
                r -= v[s[i]];
            }
            else
            {
                r += v[s[i]];
            }
        }
        return r;
    }

    int main()
    {
        string s = "III";
        cout << romanToInt(s) << "\n";
        return 0;
    }