#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
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
#define LL_INF (numeric_limits<long long>::max()/2)
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

const int kMaxH = 500;
const int kMaxW = 500;

int H, W;
int a[kMaxH][kMaxW];
vector<Pair> ans;

int Next(int ij) {
  int x = ij/W, y = ij%W;
  if (x%2 == 0) {
    if (y+1 < W) { return ij+1; }
    return ij+W;
  } else {
    if (y-1 >= 0) { return ij-1; }
    return ij+W;
  }
}

signed main() {
  cin >> H >> W;
  REP(i, H) { REP(j, W) { cin >> a[i][j]; } }

  int ij = 0;
  bool f = false;
  while (true) {
    while (true) {
      int i = ij/W, j = ij%W;
      // cout << "a " << i << " " << j << endl;
      if (a[i][j]%2 == 1) {
        break;
      } else {
        ij = Next(ij);
        if (ij >= H*W) {
          f = true;
          break;
        }
      }
    }
    if (f) { break; }
    int ij2 = Next(ij);
    if (ij2 >= H*W) { break; }
    vector<Pair> v;

    while (true) {
      int i = ij2/W, j = ij2%W;
      // cout << "b " << i << " " << j << endl;
      if (a[i][j]%2 == 1) {
        v.push_back(Pair(ij, ij2));
        REP(i, v.size()) { ans.push_back(v[i]); }
        ij = Next(ij2);
        if (ij >= H*W) { f = true; }
        break;
      } else {
        v.push_back(Pair(ij, ij2));
        ij = ij2;
        ij2 = Next(ij2);
        if (ij2 >= H*W) {
          f = true;
          break;
        }
      }
    }
    if (f) { break; }
  }

  cout << ans.size() << endl;
  REP(i, ans.size()) {
    int yy = ans[i].first/W + 1, xx = ans[i].first%W + 1;
    int y = ans[i].second/W + 1, x = ans[i].second%W + 1;
    cout << yy << " " << xx << " " << y << " " << x << endl;
  }
  return 0;
}
