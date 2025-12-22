#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverse_words(const string &s)
{
    stack<string>str;
    string temp = "";

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] != ' ')
        {
            temp += s[i];
        }
        else
        {
            str.push(temp);
            temp = "";
        }
    }
    if(temp.size() > 0)
        str.push(temp);
    
    string result = "";
    while(!str.empty())
    {
        result += str.top();
        if(str.size() >1)
            result += ' ';
        str.pop();
    }

    return result;
}

int main()
{
    string s = "the sky is blue";
    cout << reverse_words(s) << "\n";
    return 0;
}