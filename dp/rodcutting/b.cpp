#include <bits/stdc++.h>
using namespace std;

// dp: n^2, n

int solve(vector<int> &a, int n, vector<int> &dp) {
  if(n == 0) return 0;

  if(dp[n] != -1) return dp[n];

  int mx = 0;
  for(int i = 1; i<=n; i++) {
    mx = max(mx, a[i-1] + solve(a, n-i, dp));
  }
  return dp[n] = mx;
}

int main() {
  int n; cin>> n;
  vector<int> a(n);
  for(int i = 0; i<n; i++) cin>>a[i];

  vector<int> dp(n+1, -1);
  cout << solve(a, n, dp) << endl;
}
/*
TC: 1
Input:
  size:
  price:

8
1 5 8 9 10 17 17 20

Output: 22
*/

/*
TC: 2
Input:
  size:
  price:

8
3 5 8 9 10 17 17 20

Output: 24
*/

/*
TC: 3
Input:
  size:
  price:

8
1 10 3 1 3 1 5 9

Output: 40
*/