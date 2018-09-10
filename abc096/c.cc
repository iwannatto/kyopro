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

const int kMaxH = 50;

int H, W;
string s[kMaxH];
string ans;

int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

signed main() {
  cin >> H >> W;
  REP(i, H) { cin >> s[i]; }

  ans = "Yes";
  REP(i, H) {
    REP(j, W) {
      if (s[i][j] == '#') {
        bool imp = true;
        REP(k, 4) {
          int ni = i+d[k][0]; int nj = j+d[k][1];
          if (0 <= ni && ni < H && 0 <= nj && nj < W) {
            if (s[ni][nj] == '#') {
              imp = false;
              break;
            }
          }
        }
        if (imp) {
          ans = "No";
          goto r;
        }
      }
    }
  }

r:
  cout << ans << endl;
  return 0;
}
