#include<iostream>
#include<vector>
using namespace std;

class solution
{
    public:
    int removeduplicate(vector<int> &nums)
    {
        if(nums.size() <=2)
            return nums.size();
        int k = 1;
        int n = 1;
        for(int i = 1;i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
            {
                n++;
            }
            else
            {
                n = 1;
            }
            if(n <=2)
            {
                nums[k] = nums[i];
                k++;
            }
        }
        nums.resize(k);
        return k;
    }
};

int main()
{
    vector<int> nums = {1,1,2,3,3,3,4};
    solution s;
    cout << s.removeduplicate(nums) << "\n";
    return 0;
}