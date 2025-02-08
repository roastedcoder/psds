#include <bits/stdc++.h>
using namespace std;

class LowestCommonAncestor {
  // Tree nodes to be 1-based
  // treeSize ad liftSize are inclusion on 0th values
  int treeSize, liftSize;
  vector<vector<int> > tree;
  vector<int> depth;
  vector<vector<int> > lift;

  void dfs(int node, int par) {
    lift[node][0] = par;
    for(const auto &child: tree[node]) {
      if(child != par) {
        depth[child] = depth[node] + 1;
        dfs(child, node);
      }
    }
  }

  void buildLift() {
    for(int i = 1; i < liftSize; i++) {
      for(int j = 1; j < treeSize; j++) {
        if(lift[j][i-1] != -1)
          lift[j][i] = lift[lift[j][i-1]][i-1];
      }
    }
  }

  public:
  LowestCommonAncestor(vector<vector<int> > tree, int n, int root) {
    this->tree = tree;
    treeSize = n + 1;
    liftSize = ceil(log2(n)) + 1;
    depth.resize(treeSize, 0);
    lift.resize(treeSize, vector<int>(liftSize, -1));
    dfs(root, -1);
    buildLift();
  }

  int getLca(int x, int y) {
    // let y be deeper;
    if(depth[x] > depth[y]) swap(x, y);

    // lift y to same depth as x
    for(int i = liftSize - 1; i>=0; i--) {
      if(lift[y][i] != -1 && depth[lift[y][i]] >= depth[x]) {
        y = lift[y][i];
      }
    }

    // both x and y were on same branch
    if(x == y) return x;

    for(int i = liftSize - 1; i>=0; i--) {
      // lift when x and y has no common ancestor for current 2^i
      if(lift[x][i] != lift[y][i]) {
        x = lift[x][i];
        y = lift[y][i];
      }
    }
    // only parent can be left in this way so we return parent of x or y
    return lift[x][0];
  }

  void print() {
    for(int i = 1; i < treeSize; i++) {
      cout << "Depth of node " << i << " is " << depth[i] << endl;
    }

    cout << endl;

    for(int i = 1; i < treeSize; i++) {
       cout << i <<": ";
      for(int j = 0; j < liftSize; j++) {
        cout << lift[i][j] << " ";
      }
      cout << endl;
    }
  }
};

int main() {
  int n, e;
  cin >> n >> e;
  int liftSize = ceil(log2(n));
  vector<vector<int> > lca(n+1, vector<int>(liftSize + 1, -1));
  vector<vector<int> > tree(n+1);
  vector<int> depth(n+1, 0);

  for(int i = 0; i<e; i++) {
    int a, b;
    cin>>a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  LowestCommonAncestor lc(tree, n, 1);

  vector<int> res;
  int q; cin >> q;
  while(q--) {
    int x, y;
    cin >> x >> y;
    res.push_back(lc.getLca(x, y));
  }

  for(auto x: res) cout << x <<" ";
  cout << endl;

}

/*
TC: 1

8 7
1 2
1 3
2 5
2 6
5 4
4 8
6 7

5
5 6
3 7
7 8
4 1
2 8


        1
       / \
      2   3
     / \
    5   6
   /     \
  4       7
 /
8

*/
