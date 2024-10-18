// dfs : TLE
// there might be common range for different indices that makes it quadratic.

class Solution {
    void solve(string s, int minJump, int maxJump, vector <int> &dp, int start) {
        if(start == s.length() - 1) {
            dp[start] = 1;
            return;
        }
        if(dp[start] != -1) return;

        int right = start + minJump;
        int left = min(start + maxJump, (int)(s.length() - 1));

        dp[start] = 0;
        for(int j = right; j <= left; j++) {
            if(s[j] == '1') continue;
            solve(s, minJump, maxJump, dp, j);
            if(dp[j] == 1) {
                dp[start] = 1;
            }
        }
        return;
    }
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector <int> dp(s.length(), -1);
        solve(s, minJump, maxJump, dp, 0);
        if(dp[s.length() - 1] == 1) return true;
        return false;
    }
};