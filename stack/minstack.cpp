#include<iostream>
#include<stack>
#include<algorithm> // for std::min
using namespace std;

/*
 MinStack supports push, pop, top and retrieving the minimum element in O(1) time.
 Implementation idea:
 - Maintain two stacks:
   1. s: stores all values in normal stack order.
   2. min_stack: stores the current minimum at each depth (min up to that point).
 - On push(val): push value to s and push min(val, current_min) to min_stack.
 - On pop(): pop both s and min_stack.
 - top() reads s.top(); getmin() reads min_stack.top().
 Time complexity: O(1) per operation.
 Space complexity: O(n) extra space for min_stack (proportional to number of pushes).
*/
class MinStack
{
    private:
    stack<int> s;          // main stack of values
    stack<int> min_stack;  // parallel stack storing current minimum at each position
    public:
    // Pushes value onto the stack and updates min_stack with current minimum.
    void push(int val)
    {
        s.push(val);
        // If min_stack is empty use val, otherwise push the smaller of val and current min.
        val = min(val, min_stack.empty() ? val : min_stack.top());
        min_stack.push(val);
    }

    // Return top element of the stack.
    // Precondition: stack is not empty.
    int top()
    {
        return s.top();
    }

    // Pop top element from the stack and update min_stack accordingly.
    // Precondition: stack is not empty.
    void pop()
    {
        s.pop();
        min_stack.pop();
    }

    // Return current minimum element (at the top of min_stack).
    // Precondition: stack is not empty.
    int getmin()
    {
        return min_stack.top();
    }
};

int main()
{
    MinStack m;
    m.push(-2);
    m.push(0);
    m.push(-3);

    cout << "Minimum Value: "<<m.getmin() << "\n";
    m.pop();
    cout << "Top value: "<<m.top() << "\n";
    cout << "Minimum value: "<<m.getmin() << "\n";
    return 0;
}