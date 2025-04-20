
#include<iostream>
#include<vector>
using namespace std;

class solution
{
    public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while( i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else{
                nums1[k--] = nums2[j--];
            }
        }

        while(j >=0)
        {
            nums1[k--] = nums2[j--];
        }
    }
};

int main()
{
    vector<int> nums1 = {1,2,3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    solution s;
    s.merge(nums1, m, nums2, n);
    for(auto it = nums1.begin(); it != nums1.end(); it++)
    {
        cout << *it << " ";
    }
    return 0;
}