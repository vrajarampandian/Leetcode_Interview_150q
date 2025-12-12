/*Given an integer array nums and an integer k, 
return true if there are two distinct indices i and j in the array 
such that nums[i] == nums[j] and abs(i - j) <= k.*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool containsNearbyDuplicate(const vector<int> &nums, int k)
{
    unordered_set<int> s;
    int l = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(i - l > k)
        {
            s.erase(nums[l]);
            l += 1;
        }

        if(s.find(nums[i]) != s.end())
        {
            return true;
        }
        s.insert(nums[i]);

    }
    return false;
}

int main()
{
    vector<int> v = {1,2,3,1,2,3};
    if(containsNearbyDuplicate(v, 2))
        cout << "True" << "\n";
    else
        cout << "False" << "\n";
    return 0;
}