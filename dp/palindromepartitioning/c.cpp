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

void preComputePalindrome(string &s, vector<vector<bool> > &isPal) {
  int n = s.length();
  for(int len = 1; len <= n; len++) {  // iterate over each length
    for(int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;
      if(s[i] == s[j] && (len <= 2 || isPal[i+1][j-1])) {
        isPal[i][j] = true;
      }
    }
  }
}

int solve(string &s, int i, int j, vector<vector<int> > &dp, vector<vector<bool> > &isPal) {
  if(i >= j) return 0;

  if(isPal[i][j]) return dp[i][j] = 0;
  // if(isPalindrome(s, i, j)) return 0; // this would also work since we anyways loop through i to j

  if(dp[i][j] != -1) return dp[i][j];

  int res = s.length();
  for(int k = i; k<j; k++) {
    // lets assume there are p partition possible and if current prefix [i, k] is palindrome
    // then we partition at k and there will be p-1 partition in next substring [k+1, j]
    // we do not need to solve for both the current partition
    if(isPal[i][k]) {
      res = min(res, solve(s, k+1, j, dp, isPal) + 1);
    }
  }
  return dp[i][j] = res;
}

int main() {
  string s; cin>>s;
  int n = s.length();
  vector<vector<int> > dp(n+1, vector<int> (n+1, -1));
  vector<vector<bool> > isPal(n, vector<bool> (n, false));
  preComputePalindrome(s, isPal);

  cout << solve(s, 0, n-1, dp, isPal) << endl;
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