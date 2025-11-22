#include<iostream>
#include<vector>
using namespace std;

/*
 Find the maximum profit from buying and selling a stock once.
 You must buy before you sell (buy on day i, sell on day j where i < j).
 
 Approach (two-pointer / sliding window):
  - Maintain left pointer (l) for buy price and right pointer (r) for sell price.
  - For each position r, calculate profit if we sell at r (having bought at l).
  - If prices[l] < prices[r], we can make a profit; update maxprofit.
  - If prices[l] >= prices[r], move l to r (new potential buy point).
  - Advance r to check the next sell price.
 
 Time complexity: O(n) where n = prices.size() (single pass with two pointers).
 Space complexity: O(1) extra space.
*/
int getMaximumProfit(const vector<int> &prices)
{
    int maxprofit = 0;        // best profit found so far
    int l = 0;                // left pointer (buy day)
    int r = 1;                // right pointer (sell day)

    while(r < prices.size())
    {
        // If we can make a profit by selling at r (bought at l)
        if(prices[l] < prices[r])
        {
            int profit = prices[r] - prices[l];
            maxprofit = max(maxprofit, profit);
        }
        else
        {
            // prices[l] >= prices[r]: l is not a good buy point
            // Move l to r (r becomes the new potential buy point)
            l = r;
        }
        r++;  // move to next potential sell day
    }

    return maxprofit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    
    // Expected output: 5 (buy at 1, sell at 6)
    cout << "Maximum Profit: " << getMaximumProfit(prices) << "\n";
    return 0;
}