// dp with O(n) space
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n, 0);
        // jump left for next step
        dp[0] = nums[0];
        for(int i = 1; i < n; i++) {
            // reduce the prev jump left to reach curr step. if that is negative return false.
            // currently dp[i-1] - 1 steps left to forward from past
            if(dp[i-1] - 1 < 0) return false;
            dp[i] = max(dp[i-1] - 1, nums[i]);
        }
        return true;
    }
};