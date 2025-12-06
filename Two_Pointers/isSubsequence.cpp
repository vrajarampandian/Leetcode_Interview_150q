#include<iostream>
using namespace std;


bool isSubsequence(const string &st1, const string &str2)
{
    int i = 0;
    int j = 0;

    while( i < st1.size() && j < str2.size())
    {
        if(st1[i] == str2[j])
        {
            i++;
        }
        j++;
    }
    return i == st1.size();
}
int main()
{
    string str1 = "abc";
    string str2 = "ahcbgd";
    if(isSubsequence(str1, str2))
        cout << "True" << "\n";
    else
        cout << "False" << "\n";
    return 0;
}