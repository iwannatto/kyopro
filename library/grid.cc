// Grid requirements
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define NINTH_POWER_OF_TEN 1000000000
typedef pair<int, int> Pair;

// Grid begin

class Grid {
 public:
  int n, m;
  vector<string> g;
  int dx[4], dy[4];
  vector<int> ds;
  Grid(int n, int m) : n(n), m(m), g(n), ds(n*m, NINTH_POWER_OF_TEN) {
    int tdx[4] = {1, 0, -1, 0};
    int tdy[4] = {0, -1, 0, 1};
    REP(i, 4) { dx[i] = tdx[i]; dy[i] = tdy[i]; }
  }

  bool Valid(int x, int y) {
    bool xv = (0 <= x && x < n);
    bool yv = (0 <= y && y < m);
    // something?
    return xv && yv;
  }

  int Cost(int x, int y, int dx, int dy) {
    // something
    return 0;
  }

  void Dijkstra(int sx, int sy) {
    ds[sx*m+sy] = 0;
    priority_queue<Pair, vector<Pair>, greater<Pair>> q;

    q.push(Pair(0, sx*m+sy));
    while (!q.empty()) {
      Pair p = q.top(); q.pop();
      int d = p.first;
      int x = p.second/m, y = p.second%m;
      if (ds[x*m+y] < d) { continue; }

      REP(i, 4) {
        int nx = x+dx[i], ny = y+dy[i];
        if (Valid(nx, ny)) {
          int nd = ds[x*m+y] + Cost(x, y, nx, ny);
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

// Grid testcode
int main() {
  return 0;
}
