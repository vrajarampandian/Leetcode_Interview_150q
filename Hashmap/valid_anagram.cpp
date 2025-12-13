#include<iostream>
#include<string>
using namespace std;

bool isAnagram(const string &s, const string &t)
{
    if(s.length() != t.length())
        return false;
    
    int feq[256] = {0};

    for(int i = 0; i < s.size(); i++)
    {
        feq[s[i]]++;
        feq[t[i]]--;
    }
    for(int i = 0; i < 256; i++)
    {
        if(feq[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    string s = "raja";
    string t = "aahr";

    if(isAnagram(s, t))
        cout << "True  " << "\n";
    else
        cout << "False " << "\n";

    return 0;
}