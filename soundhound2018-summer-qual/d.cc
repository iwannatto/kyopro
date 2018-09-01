#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ABS(a) (((a) >= 0) ? (a) : -(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
// 変えた(00000000)
#define NINTH_POWER_OF_TEN 100000000000000000
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

const int kMaxM = 100000;

int n, m, s, t;
int u[kMaxM], v[kMaxM], a[kMaxM], b[kMaxM];
int ans = 0;

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


signed main() {
  cin >> n >> m >> s >> t;
  REP(i, m) { cin >> u[i] >> v[i] >> a[i] >> b[i]; }

  AdjacencyListGraph yens(n+1);
  AdjacencyListGraph yent(n+1);
  AdjacencyListGraph snukes(n+1);
  AdjacencyListGraph snuket(n+1);
  REP(i, m) {
    yens.AddEdge(u[i], v[i], a[i]);
    yens.AddEdge(v[i], u[i], a[i]);
    yent.AddEdge(u[i], v[i], a[i]);
    yent.AddEdge(v[i], u[i], a[i]);
    snukes.AddEdge(u[i], v[i], b[i]);
    snukes.AddEdge(v[i], u[i], b[i]);
    snuket.AddEdge(u[i], v[i], b[i]);
    snuket.AddEdge(v[i], u[i], b[i]);
  }
  yens.Dijkstra(s);
  yent.Dijkstra(t);
  snukes.Dijkstra(s);
  snuket.Dijkstra(t);

  Pair ps[n+1];
  ps[0] = Pair(NINTH_POWER_OF_TEN, 0);
  FOR(i, 1, n) {
    int cost = yens.ds[i] + snuket.ds[i];
    ps[i] = Pair(cost, i);
  }
  sort(ps, ps+n+1);

  int pi = 0;
  REP(i, n) {
    Pair p = ps[pi];
    while (p.second <= i) { p = ps[++pi]; }
    cout << 1000000000000000 - p.first << endl;
  }

  return 0;
}
