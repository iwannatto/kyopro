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
// 変えた
#define NINTH_POWER_OF_TEN 1000000000000000
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

const int kMaxK = 100000;

int N, M, K;
string d;
int ans = 0;

int t[kMaxK*2+1][4];

// Grid begin

class Grid {
 public:
  int n, m;
  vector<string> g;
  int dx[4], dy[4];
  vector<int> ds;
  Grid(int n, int m) :
  n(n), m(m), g(n), ds(n*m, NINTH_POWER_OF_TEN) {
    // D, L, U, R
    int tdx[4] = {1, 0, -1, 0};
    int tdy[4] = {0, -1, 0, 1};
    REP(i, 4) { dx[i] = tdx[i]; dy[i] = tdy[i]; }
  }

  bool Valid(int x, int y) {
    bool xv = (0 <= x && x < n);
    bool yv = (0 <= y && y < m);
    return xv && yv && g[x][y] != '#';
  }

  int Cost(int x, int y, int i) {
    int k = ds[x*m+y]%K;
    return t[k][i] + 1;
  }

  void Dijkstra(int sx, int sy) {
    ds[sx*m+sy] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;

    q.push(Pair(0, sx*m+sy));
    while (!q.empty()) {
      // cout << "b" << endl;
      Pair p = q.top(); q.pop();
      int d = p.first;
      int x = p.second/m, y = p.second%m;
      // cout << d << " " << x << " " << y << " " << endl;
      if (ds[x*m+y] < d) { continue; }

      // cout << "c" << endl;
      REP(i, 4) {
        // cout << "d" << endl;
        int nx = x+dx[i], ny = y+dy[i];
        if (Valid(nx, ny)) {
          // cout << "e" << endl;
          int nd = ds[x*m+y] + Cost(x, y, i);
          // cout << "f" << endl;
          if (nd < ds[nx*m+ny]) {
            ds[nx*m+ny] = nd;
            q.push(Pair(nd, nx*m+ny));
          }
        }
      }
    }
    return;
  }
};

// Grid end

signed main() {
  cin >> N >> M >> K;
  cin >> d;
  Grid g(N, M);
  REP(i, N) { cin >> g.g[i]; }

  int sx, sy, gx, gy;
  REP(i, N) {
    REP(j, M) {
      if (g.g[i][j] == 'S') {
        sx = i; sy = j;
      } else if (g.g[i][j] == 'G') {
        gx = i; gy = j;
      }
    }
  }

  d += d;
  REP(i, 2*K+1) {
    REP(j, 4) {
      t[i][j] = NINTH_POWER_OF_TEN;
    }
  }
  RFOR(i, 2*K-1, 0) {
    char c[4] = {'D', 'L', 'U', 'R'};
    REP(di, 4) {
      if (d[i] == c[di]) {
        t[i][di] = 0;
      } else {
        t[i][di] = t[i+1][di]+1;
      }
    }
  }

  g.Dijkstra(sx, sy);
  ans = g.ds[gx*M+gy];
  if (ans >= NINTH_POWER_OF_TEN) { ans = -1; }

  cout << ans << endl;
  return 0;
}
