#include <bits/stdc++.h>
using namespace std;

// dp: n^2, n^2

int solve(vector<int> &a, vector<int> &wt, int n, int cap, vector<vector<int> > &dp) {
  if(n <= 0 || cap <= 0) return 0;

  if(dp[n][cap] != -1) return dp[n][cap];

  // we can choose current item's weight is more than total capacity
  if(wt[n-1] > cap) {
    return dp[n][cap] = solve(a, wt, n-1, cap, dp);
  }

  // choose the current item reduce the total capacity by items weight
  int choose = solve(a, wt, n-1, cap-wt[n-1], dp) + a[n-1];

  // not choose and proceed with next item (n-1)
  int notChoose = solve(a, wt, n-1, cap, dp);

  return dp[n][cap] = max(choose, notChoose);
}

int main() {
  int cap, n; cin>> cap >> n;
  vector<int> a(n), wt(n);
  for(int i = 0; i<n; i++) cin>>a[i];
  for(int i = 0; i<n; i++) cin>>wt[i];

  vector<vector<int> > dp(n+1, vector<int> (cap + 1, -1));

  cout << solve(a, wt, n, cap, dp) << endl;
}
/*
TC: 1
Input:

capacity size
values
weight

4 3
1 2 3
4 5 1 

Output: 3
*/

/*
TC: 2
Input:

capacity size
values
weight

3 3
1 2 3
4 5 6 

Output: 0
*/

/*
TC: 3
Input:

capacity size
values
weight

5 4
10 40 30 50
5 4 6 3

Output: 50
*/