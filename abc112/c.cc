#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
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

const int kMaxN = 100;

int N;
int x[kMaxN], y[kMaxN], h[kMaxN];
int ans = 0;

void Swap(int a[], int i, int j) {
  int tmp = a[i];
  a[i] = a[j];
  a[j] = tmp;
}

signed main() {
  cin >> N;
  REP(i, N) { cin >> x[i] >> y[i] >> h[i]; }

  int idx = 0;
  while (h[idx] == 0) { ++idx; }
  Swap(x, 0, idx);
  Swap(y, 0, idx);
  Swap(h, 0, idx);

  int Cx, Cy, H;
  FOR(i, 0, 100) {
    FOR(j, 0, 100) {
      Cx = i; Cy = j;
      H = h[0] + ABS(x[0]-Cx) + ABS(y[0]-Cy);
      bool f = true;
      REP(k, N-1) {
        // cout << h[1+k] << endl;
        // cout << H-ABS(x[1+k]-Cx)-ABS(y[1+k]-Cy) << endl;
        if (h[1+k] != MAX(H-ABS(x[1+k]-Cx)-ABS(y[1+k]-Cy), 0)) {
          f = false;
          break;
        }
      }
      if (f) { goto r;}
    }
  }

r:
  cout << Cx << " " << Cy << " " << H << endl;
  return 0;
}
