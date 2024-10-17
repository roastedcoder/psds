// greedy
class Solution {
public:
    int jump(vector<int>& nums) {
        // 2 3 1 1 4
        // i = 0
        // curFarthest = 2
        // currEnd = 2
        // jump = 1

        // i = 1
        // curFarthest = 4
        // currEnd = 2
        // jump = 1

        // i = 2
        // curFarthest = 4
        // currEnd = 4
        // jump = 2

        // currEnd is basically lastFarthest
        // we only jump when we reach lastFarthest
        int jumps = 0, currEnd = 0, currFarthest = 0;
        for(int i = 0; i< nums.size() - 1; i++) {
            currFarthest = max(currFarthest, i + nums[i]);
            if(i == currEnd) {
                jumps += 1;
                currEnd = currFarthest;
            }
        }
        return jumps;
    }
};