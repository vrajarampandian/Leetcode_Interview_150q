#include<iostream>
#include<unordered_map>
#include<stack>
using namespace std;

// Validate parentheses using a stack.
// - Push opening brackets onto the stack.
// - For a closing bracket, check top of stack matches the corresponding opening.
// - If mismatch or stack empty when expecting an opening, return false.
// - At end, stack must be empty for the string to be valid.
bool isvalid_parenrheses(string s)
{
    stack<char> st;

    // Map closing -> opening for quick match checks
    unordered_map<char, char> mp = {
      {')', '('},
      {'}', '{'},
      {']', '['}   // fixed mapping: ']' -> '[' (was incorrect in original)
    };

    for(char c : s)
    {
        // If it's an opening bracket, push it
        if(c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            // For a closing bracket: stack must be non-empty and top must match
            if(st.empty() || st.top() != mp[c])
                return false;
            st.pop();
        }
    }

    // Valid if all openings have been closed
    return st.empty();
}

int main()
{
    string str = "(()}";
    bool bvalid = isvalid_parenrheses(str);
    if(bvalid)
        cout << "valid" << "\n";
    else
        cout << "in valid" << "\n";
    return 0;
}