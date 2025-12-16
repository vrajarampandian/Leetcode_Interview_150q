#include<iostream>
#include<string>
using namespace std;

bool random_note(const string &random, const string &magazine)
{
    int freq[26] = {0};

    for(char c : magazine)
    {
        freq[c - 'a']++;
    }

    for(char c : random)
    {
        if(--freq[c-'a'] < 0)
            return false;
    }
    return true;
}

int main()
{
    string r = "aa";
    string m = "aab";
    if(random_note(r,m))
        cout << "TRUE" << "\n";
    else
        cout << "FALSE" << "\n";
    return 0;
}