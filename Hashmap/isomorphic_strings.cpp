#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isomorphicstring(const string &s, const string &t)
{
    vector<int> sstr(256, -1), tstr(256, -1);

    for(int i = 0; i<s.size(); i++)
    {
        if(sstr[s[i]] != tstr[t[i]])
            return false;

        sstr[s[i]] = i;
        tstr[t[i]] = i;
    }
    return true;
}

int main()
{
    string s = "foo";
    string t = "bar";
    if(isomorphicstring(s, t))
        cout << "True" << "\n";
    else
        cout << "False" << "\n";
    return 0;
}