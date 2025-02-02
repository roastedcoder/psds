#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int u, v, wt;
};

void bellmanFord(int n, int m, vector<Edge> edges, int src) {
  vector<int> dist(n, INT_MAX);
  dist[src] = 0;
  for(int i = 0; i<n-1; i++) {
    for(auto e: edges) {
      if(dist[e.u] != INT_MAX) {
        dist[e.v] = min(dist[e.v], dist[e.u] + e.wt);
      }
    }
  }

  for(auto x: dist) cout << x << " ";
  cout << endl;
}

void bellmanFordOptimized(int n, int m, vector<Edge> edges, int src) {
  // unrestricted to n-1 iterations

  vector<int> dist(n, INT_MAX);
  dist[src] = 0;
  for(;;) {
    bool any = false;
    for(auto e: edges) {
      if(dist[e.u] != INT_MAX) {
        if(dist[e.v] > dist[e.u] + e.wt) {
          dist[e.v] = min(dist[e.v], dist[e.u] + e.wt);
          // relaxation found
          any = true;
        }
      }
    }
    // if no relaxation found no need to iterate further
    if(!any) break;
  }

  for(auto x: dist) cout << x << " ";
  cout << endl;
}

int main() {
  int n = 5, m = 8;
  vector<Edge> edges;
  Edge e1 = {0, 1, -1};
  Edge e2 = {0, 2, 4};
  Edge e3 = {1, 2, 3};
  Edge e4 = {1, 3, 2};
  Edge e5 = {1, 4, 2};
  Edge e6 = {3, 2, 5};
  Edge e7 = {3, 1, 1};
  Edge e8 = {4, 3, -3};
  edges.push_back(e1);
  edges.push_back(e2);
  edges.push_back(e3);
  edges.push_back(e4);
  edges.push_back(e5);
  edges.push_back(e6);
  edges.push_back(e7);
  edges.push_back(e8);

  bellmanFord(n, m, edges, 0);
  bellmanFordOptimized(n, m, edges, 0);
}