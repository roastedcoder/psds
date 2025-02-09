#include <bits/stdc++.h>
using namespace std;

// recursive: 2^n

int solve(vector<int> &a, int n) {
  if(n <= 0) return 0;

  int mx = 0;
  for(int i = 1; i<=n; i++) {
    // maximize each length n revenue by choosing each possible length of rod i
    // and get the remaining length revenue using solve(n-i);
    mx = max(mx, a[i-1] + solve(a, n-i));
  }
  return mx;
}

int main() {
  int n; cin>> n;
  vector<int> a(n);
  for(int i = 0; i<n; i++) cin>>a[i];

  cout << solve(a, n) << endl;
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