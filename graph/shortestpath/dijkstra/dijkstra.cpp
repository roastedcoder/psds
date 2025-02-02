#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<int> dijkstra(int n, vector<vector<pii> > &graph, int src) {
  priority_queue <pii, vector<pii>, greater<pii> > q;
  vector<int> dist(n, INT_MAX);

  dist[src] = 0;
  q.push(make_pair(0, src));
  while(q.size()) {
    int node = q.top().second;
    int nodeWt = q.top().first;
    q.pop();

    if(dist[node] < nodeWt) continue;
    for(auto x: graph[node]) {
      int child = x.first;
      int childWt = x.second;
      if(nodeWt + childWt < dist[child]) {
        dist[child] = min(dist[child], nodeWt + childWt);
        q.push(make_pair(dist[child], child));
      }
    }
  }
  return dist;
}

int main() {
  int n = 5;
  vector<vector<pii> > adj(n);
  // node -> {child, wt}
  adj[0].push_back(make_pair(1, 2));
  adj[0].push_back(make_pair(2, 4));
  adj[1].push_back(make_pair(2, 1));
  adj[1].push_back(make_pair(3, 7));
  adj[2].push_back(make_pair(3, 3));
  adj[3].push_back(make_pair(4, 1));

  int src = 0;
  vector<int> dist = dijkstra(n, adj, src);
  for(int i = 0; i<dist.size(); i++) {
    cout << i << " " << dist[i] << endl;
  }
}
