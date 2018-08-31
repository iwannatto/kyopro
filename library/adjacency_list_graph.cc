// AdjacencyListGraph requirements
#define REP(i, n) for (int i = 0; i < n; ++i)
#include <vector>
using namespace std;

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
  AdjacencyListGraph(int n) : n(n), es(n) {}

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
};

// AdjacencyListGraph end

// AdjacencyListGraph testcode
int main() {
  return 0;
}
