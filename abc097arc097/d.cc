#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
using namespace std;

#define ABS(a) (((a) >= 0) ? (a) : -(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

// ---
// union_find_tree

const int kMaxN = 100000;

int par[kMaxN];
int treerank[kMaxN];

void Init(int n) {
  REP(i, n) {
    par[i] = i;
    treerank[i] = 0;
  }
}

int Find(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = Find(par[x]);
  }
}

void Unite(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x == y) { return; }
  if (treerank[x] < treerank[y]) {
    par[x] = y;
  } else {
    par[y] = x;
    if (treerank[x] == treerank[y]) { ++treerank[x]; }
  }
  return;
}

bool Same(int x, int y) { return Find(x) == Find(y); }

// union_find_tree
// ---

const int kMaxM = 100000;

int N, M, p[kMaxN], x[kMaxM], y[kMaxM];
int ans = 0;

signed main() {
  cin >> N >> M;
  REP(i, N) { cin >> p[i]; }
  REP(i, M) { cin >> x[i] >> y[i]; }

  Init(N);
  REP(i, M) {
    Unite(x[i]-1, y[i]-1);
  }

  REP(i, N) {
    if (Same(i, p[i]-1)) {
      // cout << Find(i) << " " << Find(p[i]-1) << endl;
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}
