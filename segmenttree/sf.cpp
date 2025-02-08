#include <bits/stdc++.h>
using namespace std;

// Simplest form
class SegmentTree { // Range sum query
  vector<int> tree;
  vector<int> a;
  int n;

  /*
    ss -> segment start
    se -> segment end
    si -> segment index
    qs -> query start
    qe -> query end
    qi -> query index
  */

  void build(int si, int ss, int se) {
    if(ss == se) {
      tree[si] = a[ss];
      return;
    }
    int m = ss + (se - ss) / 2;
    build(si * 2, ss, m);
    build(si * 2 + 1, m + 1, se);

    tree[si] = tree[si * 2] + tree[si * 2 + 1];
  }

  int queryUtil(int si, int ss, int se, int qs, int qe) {
    if(ss > qe || se < qs) return 0; // outside
    if(ss >= qs && se <= qe) return tree[si];

    int m = ss + (se - ss) / 2;
    return queryUtil(si * 2, ss, m, qs, qe) + queryUtil(si * 2 + 1, m + 1, se, qs, qe);
  }

  void updateUtil(int qi, int si, int ss, int se) {
    if(ss == se) {
      tree[si] = a[qi];
      return;
    }

    int m = ss + (se - ss) / 2;
    if(qi <= m) {
      updateUtil(qi, si * 2, ss, m);
    } else {
      updateUtil(qi, si * 2 + 1, m + 1, se);
    }

    tree[si] = tree[si * 2] + tree[si * 2 + 1];
  }

  public:
  SegmentTree(int n, vector<int> a) {
    this->n = n;
    tree.resize(4*n);
    this->a = a;
    build(1, 0, n-1);
  }

  int query(int l, int r) {
    return queryUtil(1, 0, n-1, l, r);
  }

  void update(int i, int val) {
    a[i] = val;
    updateUtil(i, 1, 0, n-1);
  }

  void print() {
    for(auto x: tree) cout << x << " ";
    cout << endl;
  }
};
int main() {
  cout << "Hello world" << endl;

  vector<int> a;
  int n = 5;
  for(int i = 0; i<n; i++) a.push_back(i+1);


  SegmentTree st(n, a);
  st.print();
  // a -> 1 2 3 4 5
  cout << st.query(1, 4) << endl; // 14
  cout << st.query(0, 4) << endl; // 15
  cout << st.query(2, 4) << endl; // 12

  st.update(4, 6);
  // a -> 1 2 3 4 6
  st.print();
  cout << st.query(1, 4) << endl; // 15
  cout << st.query(0, 4) << endl; // 16
  cout << st.query(2, 4) << endl; // 13

  st.update(1, 4);
  // a -> 1 4 3 4 6
  st.print();
  cout << st.query(1, 4) << endl; // 17
  cout << st.query(0, 4) << endl; // 18
  cout << st.query(2, 4) << endl; // 13
}

/*
Advanced Problems:
- Finding the maximum and the number of times it appears

- Find the number of zeros in a given range, and additionally find the index of the k-th zero using a second function.

- For a given value x we have to quickly find smallest index i such that the sum of the first i elements of the array  
  a[] is greater or equal to x (assuming that the array a[] only contains non-negative values).

- for a given value x and a range a[l...r] find the smallest i in the range a[l...r] , such that a[i] is greater than x.

- Finding subsegments with the maximal sum

- We want to answer queries of the following form: for three given numbers (l, r, x) we have to find the minimal number
  in the segment a[l...r] which is greater than or equal to x. (with/without modification queries.)

*/