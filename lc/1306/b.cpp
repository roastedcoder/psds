// bfs
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue <int> q;
        vector <bool> visited(n, false);
        q.push(start);
        while(q.size()) {
            int node = q.front();
            q.pop();
            if(node >= n || node < 0) continue;

            if(arr[node] == 0) return true;

            if(!visited[node]) {
                q.push(node + arr[node]);
                q.push(node - arr[node]);
                visited[node] = true;
            }
        }
        return false;
    }
};