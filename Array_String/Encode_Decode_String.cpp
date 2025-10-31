#include<iostream>
#include<vector>
#include<string>
using namespace std;

string encode(vector<string> &str)
{
    string result = "";
    for(const string &s :str)
    {
        // prefix each string with its length and a separator '#'
        result += to_string(s.size()) + "#" + s;
    }
    return result;
}

vector<string> decode(string s)
{
    vector<string> result;
    int i = 0;
    while (i < s.size())
    {
        // find separator '#' after the length prefix
        int j = i;
        while(s[j] != '#')
        {
            j++;
        }

        // substring [i, j) contains the length in decimal
        // stoi converts the substring to an int.
        // Note about stoi:
        //  - Converts string to integer (e.g., "12" -> 12).
        //  - May throw std::invalid_argument if no conversion can be performed.
        //  - May throw std::out_of_range if the value is outside int range.
        // In this encoded format the input is trusted, so stoi should succeed.
        int l = stoi(s.substr(i, j-i));

        // move to the start of the actual string and extract l chars
        i = j + 1;
        j = i + l;
        result.push_back(s.substr(i, l));
        i = j;
    }

    return result;    
}

int main()
{
    vector<string> input = {"neet","code","love","you"};
    string encode_output = encode(input);

    vector<string> decode_output = decode(encode_output);

    for(auto s : decode_output)
    {
        cout << s << " ";
    }
    return 0;
}