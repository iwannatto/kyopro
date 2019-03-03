// FlowAdjacencyListGraph requirements
#include <vector>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define LL_INF (numeric_limits<long long>::max()/2)
#define int long long

// FlowAdjacencyListGraph begin

class FlowAdjacencyListGraph {
 public:
  class Edge {
   public:
    // revは、g[e.to][e.rev]がfrom→toの逆辺になるようなrev。
    // つまり、あっちのリストで何番目に逆辺があるか。
    int to, cap, rev;
    Edge(int to, int cap, int rev) : to(to), cost(cost), rev(rev) {}
  };

  int n;
  vector<vector<Edge>> es;
  vector<bool> used;
  AdjacencyListGraph(int n) : n(n), es(n), used(n, false) {}

  void AddEdge(int from, int to, int cap) {
    es[from].push_back(Edge(to, cap, es[to].size()));
    es[to].push_back(Edge(from, 0, es[from].size()-1));
    return;
  }

  int Dfs(int s, int t, int f) {
    if (s == t) { return f; }

    used[s] = true;
    REP(i, es[s].size()) {
      Edge e = es[s][i];
      if (!used[e.to] && e.cap > 0) {
        int d = Dfs(e.to, t, MIN(f, e.cap));
        if (d > 0) {
          e.cap -= d;
          es[e.to][e.rev] += d;
          return d;
        }
      }
    }
    return 0;
  }

  int FordFulkerson(int s, int t) {
    int flow = 0, f = 1;
    while (f > 0) {
      REP(i, n) { used[i] = false; }
      int f = Dfs(s, t, LL_INF);
      flow += f;
    }
    return flow;
  }
};

// AdjacencyListGraph end

// AdjacencyListGraph testcode
int main() {
  return 0;
}
