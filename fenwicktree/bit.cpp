#include <bits/stdc++.h>
using namespace std;
class FenwickTree {
  private:
  vector <int> tree;
  int maxSize;
  public:
  FenwickTree(int size) {
    tree.resize(size+1, 0);
    maxSize = size;
  }

  void update(int i, int val) {
    i += 1;
    while(i <= maxSize) {
      tree[i] += val;
      i += (i & -i);
    }
  }

  int prefixSum(int i) {
    i += 1;
    int res = 0;
    while(i > 0) {
      res += tree[i];
      i -= (i & -i);
    }
    return res;
  }

  int rangeSum(int i, int j) {
    return prefixSum(j) - prefixSum(i-1);
  }
};

int main() {
  cout << "Hello world" << endl;
  int n = 5;
  vector<int> a;
  for(int i = 0; i<5; i++) a.push_back(i+1);
  
  FenwickTree ft(n);
  
  for(int i = 0; i<n; i++) ft.update(i, a[i]);

  cout << ft.prefixSum(3) << endl;
  cout << ft.prefixSum(0) << endl;
  cout << ft.rangeSum(1, 3) << endl;

  cout << "Bye world" << endl;
}
