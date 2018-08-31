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
#define NINTH_POWER_OF_TEN 1000000000
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

const int kMaxN = 999;

int N, M;
int ans = 0;

bool checked[1000*1000];

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
    if (checked[v]) { return 0; }
    checked[v] = true;
    int x = v/1000, y = v%1000;
    if (0 < x && x <= N && 0 < y && y <= M) { ++ans; }
    REP(i, es[v].size()) {
      Edge& e = es[v][i];
      if (!checked[e.to]) { Dfs(e.to); }
    }
    return 0;
  }
};

// AdjacencyListGraph end

int Rev(int x) {
  int a = x/100;
  int b = x/10 - 10*a;
  int c = x - 100*a - 10*b;
  if (a == 0) {
    if (b == 0) {
      return c;
    } else {
      return 10*c + b;
    }
  } else {
    return 100*c + 10*b + a;
  }
}

Pair Op(int x, int y) {
  if (x < y) {
    x = Rev(x);
  } else {
    y = Rev(y);
  }
  if (x < y) {
    y = y-x;
  } else {
    x = x-y;
  }
  Pair p(x,y);
  return p;
}

signed main() {
  cin >> N >> M;

  AdjacencyListGraph g(1000*1000);
  FOR(i, 1, 999) {
    FOR(j, 1, 999) {
      Pair r = Op(i, j);
      int ii = r.first;
      int jj = r.second;
      g.AddEdge(ii*1000+jj, i*1000+j, 1);
    }
  }
  FOR(j, 1, 999) { g.Dfs(0*1000+j); }
  FOR(i, 1, 999) { g.Dfs(i*1000+0); }
  ans = N*M - ans;

  cout << ans << endl;
  return 0;
}
