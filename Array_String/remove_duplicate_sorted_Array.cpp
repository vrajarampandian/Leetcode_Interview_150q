#include<iostream>
#include<vector>

using namespace std;

class solution
{
    public:
    // Return the number of unique values and modify the array in place
    int removeduplicates(vector<int> &nums)
    {
        if (nums.empty()) return 0; // Handle empty vector case

        int k = 1; // Pointer for the position of the next unique element

        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); i++)
        {
            // If the current element is different from the previous unique element
            if (nums[i] != nums[k - 1])
            {
                nums[k] = nums[i]; // Place the unique element at position 'k'
                k++; // Increment the position for the next unique element
            }
        }

        nums.resize(k);
        return k; // Return the count of unique elements
    }
};

int main()
{
    solution s;
    // Sorted array
    vector<int> nums = {1, 2, 3, 3, 5, 5, 6, 6, 6};

    // Call the function and get the count of unique elements
    int unique_count = s.removeduplicates(nums);

    // Print the modified array up to the unique count
    cout << "Modified array: ";
    for (int i = 0; i < unique_count; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    // Print the count of unique elements
    cout << "Number of unique elements: " << unique_count << endl;

    return 0;
}