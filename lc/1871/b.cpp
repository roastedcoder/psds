// bfs Accepted O(n)
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1] != '0') return false;

        queue <int> q;
        q.push(0);
        int currMax = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(node == n-1) return true;

            int right = max(node + minJump, currMax);
            int left = min(node + maxJump, n - 1);

            for(int curr = right; curr <= left; curr++) {
                if(s[curr] == '0') q.push(curr);
            }
            currMax = min(n, node + maxJump + 1);
        }
        return false;
    }
};