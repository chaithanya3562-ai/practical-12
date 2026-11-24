
#include <iostream>
#include <climits>
using namespace std;

int n;
int cost[20][20];
int dp[20][1 << 20];

int tsp(int city, int mask) {

    // All cities visited
    if (mask == (1 << n) - 1) {
        return cost[city][0];
    }

    if (dp[city][mask] != -1) {
        return dp[city][mask];
    }

    int ans = INT_MAX;

    for (int next = 0; next < n; next++) {

        if ((mask & (1 << next)) == 0) {

            int newCost = cost[city][next]
                        + tsp(next, mask | (1 << next));

            if (newCost < ans) {
                ans = newCost;
            }
        }
    }

    return dp[city][mask] = ans;
}

int main() {

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    // Initialize DP table
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }

    // Start from city 0
    int result = tsp(0, 1);

    cout << "Minimum travelling cost: "
         << result;

    return 0;
}
