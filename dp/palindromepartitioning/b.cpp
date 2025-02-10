#include <bits/stdc++.h>
using namespace std;

// dp: n^2, n^2

bool isPalindrome(string &s, int i, int j) {
  while(i <= j) {
    if(s[i] != s[j]) return false;
    i++, j--;
  }
  return true;
}

int solve(string &s, int i, int j, vector<vector<int> > &dp) {
  if(i > j) return 0;

  if(isPalindrome(s, i, j)) return 0;

  if(dp[i][j] != -1) return dp[i][j];

  int res = s.length();
  for(int k = i; k<j; k++) {
    res = min(res, solve(s, i, k, dp) + solve(s, k+1, j, dp) + 1);
  }
  return dp[i][j] = res;
}

int main() {
  string s; cin>>s;
  int n = s.length();
  vector<vector<int> > dp(n+1, vector<int> (n+1, -1));

  cout << solve(s, 0, n-1, dp) << endl;
}
/*
TC: 1
Input: ababbbabbababa
Output: 3

"a", "babbbab", "b", "ababa"
*/

/*
TC: 2
Input: aaabba
Output: 1

"aa", "abba"
*/

/*
TC: 3
Input: aaa
Output: 0
*/