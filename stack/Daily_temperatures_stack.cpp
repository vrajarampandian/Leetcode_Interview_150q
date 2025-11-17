#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*
 Given an array of daily temperatures, return an array answer where answer[i]
 is the number of days you have to wait after day i to get a warmer temperature.
 
 Approach (monotonic stack):
  - Maintain a stack of (temperature, index) pairs in decreasing order.
  - For each day, pop all temperatures smaller than current (found their warmer day).
  - Compute the difference: current_index - popped_index.
  - Push current temperature and index onto stack.
 
 Time complexity: O(n) (each element pushed/popped once).
 Space complexity: O(n) for the stack in worst case.
*/
vector<int> getDailytemperatures(vector<int> temperatures)
{
    vector<int> result(temperatures.size(), 0); // initialize all to 0 (no warmer day found yet)
    stack<pair<int, int>> s;                    // stack of (temperature, index)

    for(int i = 0; i < temperatures.size(); i++)
    {
        int t = temperatures[i];
        
        // Pop all temperatures smaller than current temperature.
        // These days have found their warmer day (current day i).
        while (!s.empty() && t > s.top().first)
        {
            auto [prev_temp, prev_idx] = s.top();
            s.pop();
            // Days until warmer temperature = current index - previous index
            result[prev_idx] = i - prev_idx;
        }
        
        // Push current temperature and index onto the stack.
        s.push({t, i});
    }

    // result[i] remains 0 if no warmer temperature found after day i.
    return result;
}

int main()
{
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> r = getDailytemperatures(temperatures);
    
    // Print the result (days until warmer temperature for each day).
    for(auto i : r)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}