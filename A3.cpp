#include <iostream>
#include <algorithm>
using namespace std;

int wt[100], val[100], n, W;
int dp[101][101] = {0};
int best = 0;

// 1. Dynamic Programming
void knapsackDP() {
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i] <= w)
                dp[i][w] = max(val[i] + dp[i - 1][w - wt[i]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    cout << "Maximum value (DP): " << dp[n][W] << endl;
}

// 2. Recursive Branch & Bound / Backtracking
void knapsackBB(int i, int weight, int profit) {
    if (weight > W)
        return;

    if (i == n) {
        best = max(best, profit);
        return;
    }

    // Include next item (i + 1)
    knapsackBB(i + 1, weight + wt[i + 1], profit + val[i + 1]);

    // Exclude next item (i + 1)
    knapsackBB(i + 1, weight, profit);
}

int main() {
    int choice;

    cout << "Enter number of items and capacity: ";
    cin >> n >> W;

    cout << "Enter weight and value of each item:\n";
    for (int i = 1; i <= n; i++)
        cin >> wt[i] >> val[i];

    cout << "\n1. Dynamic Programming";
    cout << "\n2. Branch and Bound";
    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        knapsackDP();
    } 
    else if (choice == 2) {
        best = 0;
        knapsackBB(0, 0, 0);
        cout << "Maximum value (BB): " << best << endl;
    } 
    else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}