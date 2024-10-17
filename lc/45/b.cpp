// memoized recursive dp for solution `a`
class Solution {
    int jump_util(vector <int> &nums, int curr, vector <int> &dp) {
        if(curr >= nums.size() - 1) return 0;

        if(dp[curr] != 100001) return dp[curr];

        for(int i = 0; i < nums[curr]; i++) {
            dp[curr] = min(dp[curr], 1 + jump_util(nums, curr + i + 1, dp));
        }
        return dp[curr];
    }
public:
    int jump(vector<int>& nums) {
        vector <int> dp(nums.size(), 100001);
        return jump_util(nums, 0, dp);
    }
};