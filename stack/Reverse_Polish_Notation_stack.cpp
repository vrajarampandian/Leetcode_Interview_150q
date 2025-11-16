#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

/*
 Evaluate Reverse Polish Notation (RPN) given as a list of tokens.
 Algorithm:
  - Use a stack<int> to store intermediate operand values.
  - For each token:
    - If token is an operator, pop two operands and apply the operator.
    - Otherwise the token is a number: convert with stoi and push onto stack.
  - Final result is at the top of the stack.
 Notes:
  - Division uses C++ integer division semantics (truncates toward zero).
  - Assumes the input is a valid RPN expression.
 Time complexity: O(n) where n = number of tokens (each token processed once).
 Space complexity: O(n) worst-case for the stack (all tokens are numbers).
*/
int getRPN(vector<string> tokens)
{
    stack<int> s;

    for(const string &tok : tokens)
    {
        // If token is an operator, pop two operands and apply the operator.
        if(tok == "+")
        {
            int a  = s.top(); s.pop(); // right operand
            int b = s.top(); s.pop();  // left operand
            s.push(b + a);
        }
        else if(tok == "-")
        {
            int a  = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(b - a);
        }
        else if(tok == "*")
        {
            int a  = s.top(); s.pop();
            int b = s.top(); s.pop();
            s.push(b * a);
        }
        else if(tok == "/")
        {
            int a  = s.top(); s.pop();
            int b = s.top(); s.pop();
            // Integer division: truncates toward zero for positive/negative values.
            s.push(b / a);
        }
        else
        {
            // Token is a number; stoi converts string -> int.
            s.push(stoi(tok));
        }
    }

    // Final result is on top of the stack.
    return s.top();
}

int main()
{
    vector<string> tokens = {"2", "3", "+", "3", "*"};
    cout << getRPN(tokens);
    return 0;
}