#include <bits/stdc++.h>
using namespace std;

// recursion: k ^ n;

int solve(int n, int k) {
  if(n <= 0 || k <= 0) return 0;

  if(n == 1) return k;

  if(k == 1) return 1;

  int res = k+1;
  for(int i = 1; i <= k; i++) {
    // move to lower floor with 1 less eggs
    int breaks = solve(n-1, i-1);

    // move to total-current number of floors
    int not_breaks = solve(n, k-i);

    // minimize the maximum of all possibilities
    res = min(res, 1 + max(breaks, not_breaks));
  }
  return res;
}

int main() {
  // n -> eggs, k -> floors
  int n, k; cin >> n >> k;

  // vector<vector<int> > dp = vector<vector<int> >(n+1, vector<int>(k+1, -1));
  cout << solve(n, k) << endl;
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