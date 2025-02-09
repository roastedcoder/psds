#include <bits/stdc++.h>
using namespace std;

// dp: n^2, n^2
// this can be also solved using classic knapsack approach
// store the value for each length
// there are n given values for n possible length

int solve(vector<int> &a, int n, int l, vector<vector<int> > &dp) {
  if(n == 0 || l <= 0) return 0;

  if(dp[n][l] != -1) return dp[n][l];

  if(l >= n) {
    int choose = a[n-1] + solve(a, n, l-n, dp);
    int notchoose = solve(a, n-1, l, dp);

    return dp[n][l] = max(choose, notchoose);

  } else {
    int notchoose = solve(a, n-1, l, dp);
    return dp[n][l] = notchoose;
  }
}

int main() {
  int n; cin>> n;
  vector<int> a(n);
  for(int i = 0; i<n; i++) cin>>a[i];

  vector<vector<int> > dp(n+1, vector<int> (n+1, -1));
  cout << solve(a, n, n, dp) << endl;
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