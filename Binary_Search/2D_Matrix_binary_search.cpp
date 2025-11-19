#include<iostream>
#include<vector>
using namespace std;

/*
 Search a value in a 2D matrix where:
  - Integers in each row are sorted left to right.
  - The first integer of each row is greater than the last integer of the previous row.
 
 We treat the 2D matrix as a flattened sorted 1D array of length ROW * COLUM:
   index (0..ROW*COLUM-1) -> row = index / COLUM, col = index % COLUM
 Use standard binary search on that virtual 1D array.

 Time complexity: O(log(ROW * COLUM)) = O(log N) where N = total elements.
 Space complexity: O(1).
*/
bool search2DMatrix(vector<vector<int>> matrix, int target)
{
    if (matrix.empty() || matrix[0].empty()) return false; // handle empty input

    int ROW = matrix.size();
    int COLUM = matrix[0].size();

    // search space in flattened indices
    int l = 0;
    int r = ROW * COLUM - 1;

    while (l <= r)
    {
        // safe midpoint to avoid overflow: m = l + (r - l) / 2
        int m = l + ((r - l) / 2);

        // map flattened index back to 2D coordinates
        int row = m / COLUM;
        int col = m % COLUM;

        int val = matrix[row][col];

        if (target > val)
        {
            // target is in the right half of the virtual array
            l = m + 1;
        }
        else if (target < val)
        {
            // target is in the left half of the virtual array
            r = m - 1;
        }
        else
        {
            // found the target
            return true;
        }
    }
    return false; // not found
}

int main()
{
    vector<vector<int>> matric = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 15;
    if (search2DMatrix(matric, target))
        cout << "True, Found the Number\n";
    else
        cout << "False, Number is not Found\n";
    return 0;
}