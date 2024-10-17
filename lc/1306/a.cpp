// dfs
class Solution {
    void dfs(vector <int> &a, int start, vector <int> &visited, bool &ans) {
        if(ans == 1) return;

        if(start < 0 || start >= a.size()) return;

        if(visited[start] == 1) return;

        visited[start] = 1;

        if(a[start] == 0) {
            ans = true;
            return;
        }

        solve(a, start + a[start], visited, ans);
        solve(a, start - a[start], visited, ans);
        return;
    }
public:
    bool canReach(vector<int>& arr, int start) {
        vector <int> visited(arr.size(), 0);
        bool ans = false;
        dfs(arr, start, visited, ans);
        return ans;
    }
};