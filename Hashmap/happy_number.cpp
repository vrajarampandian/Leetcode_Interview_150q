#include<iostream>
#include<unordered_set>
using namespace std;

int squareofs(int n)
{
    int output = 0;

    while( n > 0)
    {
        int d = n % 10;
        d = d * d;
        output += d ; 
        n = n/10;
    }

    return output;
}


int main()
{
    int n = 19;

    unordered_set<int> s;
    bool flag = false;
    while(s.find(n) == s.end())
    {
        s.insert(n);
        n = squareofs(n);
        if( n == 1)
        {
            cout << "True" << "\n";
            flag = true;
            break;
        }
    }

    if(flag == false)
        cout << "False" << "\n";


    return 0;
}