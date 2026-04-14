#include <iostream>
using namespace std;

int main() {

    int W = 8;  // Capacity
    int wt[] = {1, 3, 5, 7};
    int val[] = {2, 4, 7, 10};
    int n = 4;

    int dp[n+1][W+1];

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= W; w++) {

            if(wt[i-1] <= w) {
                dp[i][w] = max(
                    val[i-1] + dp[i-1][w - wt[i-1]],
                    dp[i-1][w]
                );
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout << "Maximum Profit = " << dp[n][W];
}
