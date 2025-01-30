#include <bits/stdc++.h>
using namespace std;

// path compression with rank/size has same TC
class DisjointSet {
  private:
  vector <int> parent, rank;
  public:
  DisjointSet(int size) {
    parent.resize(size);
    rank.resize(size, 1);
    for(int i = 0; i<size; i++) parent[i] = i;
  }

  int find(int x) {
    if(parent[x] == x) return x;
    parent[x] = find(parent[x]);
    return parent[x];
  }

  void unite(int x, int y) {
    int xParent = find(x);
    int yParent = find(y);
    if(xParent != yParent) {
      if(rank[xParent] < rank[yParent]) {
        parent[xParent] = yParent;
      } else if(rank[yParent] < rank[xParent]) {
        parent[yParent] = xParent;
      } else {
        parent[xParent] = yParent;
        rank[yParent]++;
      }
    }
  }

  bool connected(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  cout << "Hello world" << endl;

  DisjointSet ds(10);
  ds.unite(1, 2);
  ds.unite(2, 3);
  ds.unite(4, 5);

  cout << ds.connected(1, 3) << endl;
  cout << ds.connected(1, 4) << endl;

  cout << "Bye world" << endl;
}