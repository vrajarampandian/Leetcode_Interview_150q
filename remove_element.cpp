#include<iostream>
#include<vector>
#include<algorithm> // For std::remove
using namespace std;

class solution
{
    public:
    int removeelement(vector<int> &nums, int v)
    {
        // Your commented approach:
        // The following approach is problematic because modifying a container
        // (like nums) while iterating over it can lead to undefined behavior.
        // Specifically, after calling erase, the iterator becomes invalid,
        // and continuing to use it can cause issues.
        //
        // for (auto it = nums.begin(); it != nums.end(); it++)
        // {
        //     if(v == *it)
        //         nums.erase(it); // This invalidates the iterator
        // }

        // Correct approach:
        // We use the erase-remove idiom to avoid iterator invalidation issues.
        // 1. std::remove shifts all elements not equal to 'v' to the front of the vector
        //    and returns an iterator pointing to the new logical end of the vector.
        // 2. nums.erase removes the "garbage" values left at the end of the vector.
        //nums.erase(remove(nums.begin(), nums.end(), v), nums.end());

        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != v)
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};

int main()
{
    // Initialize a vector with some integers
    vector<int> nums = {1, 2, 3, 5, 4, 3, 4, 3};

    // Create an instance of the 'solution' class
    solution s1;

    // Call the removeelement function to remove all occurrences of the value 4
    cout << "Nums size " << nums.size() << "\n"; 
    int nsize = s1.removeelement(nums, 4);

    // Print the modified vector after removing the value 4
    for (auto it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << " "; // Output each element of the vector
    }
    cout << "\n";
    cout << "New size " << nsize << "\n";
    for(int i =0; i< nsize; i++)
    {
        cout << nums[i] << " ";
    }

    return 0; // Indicate successful program termination
}