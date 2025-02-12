#include <bits/stdc++.h>
using namespace std;

// recursion: n * (2 ^ n)

int solve(vector<int> &a, int i, int j) {
  // 2 1 3 is two matrix {2 * 1} & {1 * 3}
  // there are less then 2 matrix to multiply we can not do that
  if(j - i < 2) return 0;

  int res = INT_MAX;
  // consider the result to be middle matrix and use the ends to finalize the result
  for(int k = i + 1; k <= j - 1; k++) {
    res = min(res, solve(a, i, k) + (a[i] * a[k] * a[j]) + solve(a, k, j));
  }
  return res;

}

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for(auto &x: a) cin>>x;

  cout << solve(a, 0, n-1) << endl;
}

/*
TC: 1
I:
4
2 1 3 4
O: 20

TC: 2
I:
2
3 4
O: 0

TC: 3
I:
5
1 2 3 4 3
O: 30

*/