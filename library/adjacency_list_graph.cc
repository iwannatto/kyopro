// AdjacencyListGraph requirements
#define REP(i, n) for (int i = 0; i < n; ++i)
#define NINTH_POWER_OF_TEN 1000000000
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> Pair;


// AdjacencyListGraph begin

class AdjacencyListGraph {
 public:
  class Edge {
   public:
    int to, cost;
    Edge(int to, int cost) : to(to), cost(cost) {}
  };

  int n;
  vector<vector<Edge>> es;
  vector<int> ds;
  AdjacencyListGraph(int n) :
  n(n), es(n), ds(n, NINTH_POWER_OF_TEN) {}

  void AddEdge(int from, int to, int cost) {
    Edge e(to, cost);
    es[from].push_back(e);
    return;
  }

  int Dfs(int v) {
    // something
    REP(i, es[v].size()) {
      Edge& e = es[v][i];
      // something
      Dfs(e.to);
    }
    // something
    return 0;
  }

  void Dijkstra(int s) {
    ds[s] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;

    q.push(Pair(0, s));
    while (!q.empty()) {
      Pair p = q.top(); q.pop();
      int d = p.first, v = p.second;
      if (ds[v] < d) { continue; }

      REP(i, es[v].size()) {
        Edge e = es[v][i];
        int nd = ds[v] + e.cost;
        if (nd < ds[e.to]) {
          ds[e.to] = nd;
          q.push(Pair(nd, e.to));
        }
      }
    }
  }
};

// AdjacencyListGraph end

// AdjacencyListGraph testcode
int main() {
  return 0;
}
