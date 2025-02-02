#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

class Dijkstra {
  private:
  int n;
  vector<vector<pii> > graph;
  vector<int> dist;
  vector<int> parent;

  public:
  Dijkstra(vector<vector<pii> > graph) {
    this->graph = graph;
    n = graph.size();
    dist.resize(n, INT_MAX);
    parent.resize(n, -1);
  }

  void run(int src) {
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
        if(dist[child] > childWt + nodeWt) {
          dist[child] = childWt + nodeWt;
          q.push(make_pair(dist[child], child));
          parent[child] = node;
        }
      }
    }
  }

  vector<int> getPath(int node) {
    vector<int> path;
    while(node != -1) {
      path.push_back(node);
      node = parent[node];
    }
    reverse(path.begin(), path.end());
    return path;
  }
};

int main() {
  int n = 5;
  vector<vector<pii> > graph(n);
  graph[0].push_back(make_pair(2, 2));
  graph[0].push_back(make_pair(1, 4));
  graph[1].push_back(make_pair(3, 7));
  graph[1].push_back(make_pair(2, 1));
  graph[2].push_back(make_pair(3, 3));
  graph[3].push_back(make_pair(4, 1));

  Dijkstra dj(graph);
  dj.run(0);
  vector<int> path = dj.getPath(4);
  for(auto x: path) cout << x << " ";
  cout << endl;
}
