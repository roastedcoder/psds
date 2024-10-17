// recursive brute force
class Solution {
    int jump_util(vector <int> &nums, int curr) {
        if(curr >= nums.size() - 1) return 0;
        int min_jumps = 100001;
        for(int i = 0; i < nums[curr]; i++) {
        // get the min_jump from each reachable step recursively it will reach to last step.
            min_jumps = min(min_jumps, 1 + jump_util(nums, curr + i + 1));
        }
        return min_jumps;
    }
public:
    int jump(vector<int>& nums) {
        return jump_util(nums, 0);
    }
};