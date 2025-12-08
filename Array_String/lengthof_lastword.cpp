#include<iostream>
#include<string>
using namespace std;

int getlengthlastword(string s)
{
    int l = s.size() - 1;   
    int result = 0;

    for(int i = l; i >=0;i--)
    {
        if(s[i] == ' ')
        {
            if(result != 0)
                break;
            else
                continue;
        }
        else
        {
            result++;
        }
    }
    return result;
}

int main()
{
    string str = "Hi, how are you";
    cout << "Length of last word :" << "\n"; 
    cout << getlengthlastword(str) << "\n";
    return 0;
}