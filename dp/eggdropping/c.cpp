#include <bits/stdc++.h>
using namespace std;

// memoization: n * k * log(n), n * k
// binary search over the current number of floors in each recursive call, along with memoization

int solve(int n, int k, vector<vector<int> > &dp) {
  if(n <= 0 || k <= 0) return 0;

  if(dp[n][k] != -1) return dp[n][k];

  if(n == 1) return dp[n][k] = k;

  if(k == 1) return dp[n][k] = 1;

  int l = 1, r = k, res = k + 1;
  while(l <= r) {
    int mid = l + (r - l) / 2;
    int breaks = solve(n-1, mid-1, dp);
    int not_breaks = solve(n, k-mid, dp);

    res = min(res, 1 + max(breaks, not_breaks));

    // breaking scenario is worse
    if(breaks > not_breaks) r = mid - 1;
    // The worst case is dominated by the non-breaking scenario,
    // meaning we can afford to check higher floors.
    else l = mid + 1;
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