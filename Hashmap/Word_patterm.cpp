#include<iostream>
#include<unordered_map>
#include<sstream>
#include<vector>
using namespace std;

bool iswordpattern(string pattern, string s)
{
    istringstream istr(s);
    vector<string> words;
    string w;
    while(istr >> w)
    {
        words.push_back(w);
    }
    if(pattern.length() != words.size())
        return false;
    
    unordered_map<char, string> chartoW;
    unordered_map<string, char> wordtoC;

    for(int i = 0; i < pattern.size(); i++)
    {
        char c = pattern[i];
        string wd = words[i];
        if(chartoW.count(c) && chartoW[c] != wd)
            return false;
        else
            chartoW[c] = wd;
        
        if(wordtoC.count(wd) && wordtoC[wd] != c)
            return false;
        else
            wordtoC[wd] = c;
    }

    return true;
}

int main()
{
    string pattern = "abba";
    string s = "dog cat cat dog";
    if(iswordpattern(pattern, s))
        cout << "True" << "\n";
    else
        cout << "False" << "\n";
    return 0;
}