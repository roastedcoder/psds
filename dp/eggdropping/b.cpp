#include <bits/stdc++.h>
using namespace std;

// memoization: n * k * k, n * k

int solve(int n, int k, vector<vector<int> > &dp) {
  if(n <= 0 || k <= 0) return 0;

  if(dp[n][k] != -1) return dp[n][k];

  if(n == 1) return dp[n][k] = k;

  if(k == 1) return dp[n][k] = 1;


  int res = k+1;
  for(int i = 1; i <= k; i++) {
    // move to lower floor with 1 less eggs
    int breaks = solve(n-1, i-1, dp);

    // move to total-current number of floors
    int not_breaks = solve(n, k-i, dp);

    // minimize the maximum of all possibilities
    res = min(res, 1 + max(breaks, not_breaks));
  }
  return dp[n][k] = res;
}

int main() {
  // n -> eggs, k -> floors
  int n, k; cin >> n >> k;

  vector<vector<int> > dp(n+1, vector<int>(k+1, -1));
  cout << solve(n, k, dp) << endl;
}

/*
TC: 1
I: 1 2
O: 2

TC: 2
I: 10 5
O: 3

TC: 3
I: 2 10
O: 4

*/