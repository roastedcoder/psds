// O(1) space DP
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // jump left for next step
        int jumps_forwarded = nums[0];
        for(int i = 1; i < n; i++) {
            // reduce the prev jump left to reach curr step. if that is negative return false.
            // currently jumps_forwarded - 1 steps left to forward from past
            if(jumps_forwarded - 1 < 0) return false;
            jumps_forwarded = max(jumps_forwarded - 1, nums[i]);
        }
        return true;
    }
};