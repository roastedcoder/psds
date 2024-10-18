// O(n)
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return 0;
        unordered_map <int, vector <int>> m;
        for(int i = 0; i < n; i ++) {
            m[arr[i]].push_back(i);
        }
        queue <int> q;
        q.push(0);
        vector <bool> visited(n, false);
        int res = 0;
        while(q.size()) {
            int size = q.size();
            while(size--) { // process complete queue increase jump count by 1 before next jump/step
                int curr = q.front();
                q.pop();
                if(curr == n - 1) return res;
                if(curr + 1 < n && !visited[curr + 1]) {
                    q.push(curr + 1);
                    visited[curr + 1] = true;
                }
                if(curr - 1 >= 0 && !visited[curr - 1]) {
                    q.push(curr - 1);
                    visited[curr - 1] = true;
                }
                for(auto x: m[arr[curr]]) {
                    if(!visited[x]) {
                        q.push(x);
                        visited[x] = true;
                    }
                }
                // need to clear since same key via different index can be iterated again 
                // even if that index is visited and not pushed iteration would cost
                m[arr[curr]].clear();
            }
            res += 1;
        }
        return res;
    }
};