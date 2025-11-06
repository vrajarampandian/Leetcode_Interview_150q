#include<iostream>
#include<vector>
using namespace std;

/*
 Compute the maximum area of water a container can store given heights.
 Two-pointer approach:
  - Start with pointers at both ends (l, r).
  - Area = (r - l) * min(height[l], height[r]).
  - Move the pointer at the smaller height inward (possible larger area).
 Time: O(n) (each pointer moves at most n steps).
 Space: O(1).
*/
int getContainer_MostWater(vector<int> &heights)
{
    int result = 0;                     // best area found so far
    int l = 0;                          // left pointer
    int r = (int)heights.size() - 1;    // right pointer

    while (l < r)
    {
        // compute area with current pair of lines
        int width = r - l;
        int h = min(heights[l], heights[r]);
        int area = width * h;
        result = max(area, result);

        // move the pointer at the shorter line inward:
        // only this can possibly increase area (wider width lost but taller height possible)
        if (heights[l] < heights[r])
            l++;
        else
            r--;
    }

    return result;
}

int main()
{
    vector<int> heights = {1,7,2,5,4,7,3,6};
    cout << getContainer_MostWater(heights) << " ";
    return 0;
}