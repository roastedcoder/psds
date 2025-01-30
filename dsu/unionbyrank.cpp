#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
  private:
  // rank represents depth of a tree and not size
  vector <int> parent, rank;
  public:
  DisjointSet(int size) {
    parent.resize(size);
    rank.resize(size, 1);
    for(int i = 0; i < size; i++) parent[i] = i;
  }

  int find(int x) {
    if(parent[x] == x) return x;
    return find(parent[x]);
  }

  void unite(int x, int y) {
    int xParent = find(x);
    int yParent = find(y);
    if(xParent != yParent) {
      if(rank[xParent] > rank[yParent]) {
        parent[yParent] = xParent;
      } else if(rank[yParent] > rank[xParent]) {
        parent[xParent] = yParent;
      } else {
        parent[xParent] = yParent;
        rank[yParent] += 1;
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

  cout << ds.connected(1, 2)<<endl;
  cout << ds.connected(1, 4)<<endl;
  
  cout << "Bye world" << endl;
}