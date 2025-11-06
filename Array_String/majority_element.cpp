#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution
{
    public:
    int majorityElement2(vector<int>& nums) {
        int candidate = nums[0]; // Initialize the first element as the candidate
        int count = 0; // Counter to track the candidate's frequency

        // Phase 1: Find the majority candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num; // Update the candidate
            }
            count += (num == candidate) ? 1 : -1; // Increment or decrement the count
        }

        // Return the candidate (problem guarantees a majority element exists)
        return candidate;
    }
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int m = 1;
        int r = 0;
        if (nums.size() == 1)
            r = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
            {
                count++;
            }
            if (count > m) 
            {
                m = count;
                count = 0;
                r = nums[i-1];
            }

        }
        return r;
    }
};

int main()
{
    solution s;
    vector<int> nums = {12,52,12,70,12,61,12,12,50,72,82,12,11,25,28,43,40,12,12,53,12,12,98,12,12,92,81,2,12,15,40,12,12,9,12,31,12,12,12,12,77,12,12,50,12,12,12,93,41,92,12,12,12,12,12,12,12,12,12,37,48,14,12,70,82,12,80,12,12,12,12,56,30,12,8,12,50,12,20,12,21,97,12,42,12,10,12,38,73,15,9,11,79,12,12,28,51,12,15,12};
    cout << s.majorityElement2(nums);

}