#include<iostream>
#include<string>
using namespace std;

int strstr(const string& haystack, const string&  needle)
{
    int hlen = haystack.size();
    int nlen = needle.size();

    if(nlen == 0)
        return 0;
    
    if(nlen > hlen)
        return - 1;
    
    
    for(int i = 0; i <=hlen-nlen; i++)
    {
        if(haystack.substr(i , nlen) == needle)
            return i;
    }

    return -1;
}

int main()
{
    string haystack ="appybuthappy";
    string needle = "happy";
    cout << strstr (haystack, needle);
    return 0;
}