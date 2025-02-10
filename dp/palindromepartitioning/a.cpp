#include <bits/stdc++.h>
using namespace std;

// recursion: 2^n

bool isPalindrome(string &s, int i, int j) {
  while(i <= j) {
    if(s[i] != s[j]) return false;
    i++, j--;
  }
  return true;
}

int solve(string &s, int i, int j) {
  if(i > j) return 0;

  if(isPalindrome(s, i, j)) return 0;

  int res = s.length();
  for(int k = i; k<j; k++) {
    res = min(res, solve(s, i, k) + solve(s, k+1, j) + 1);
  }
  return res;
}

int main() {
  string s; cin>>s;
  int n = s.length();

  cout << solve(s, 0, n-1) << endl;
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