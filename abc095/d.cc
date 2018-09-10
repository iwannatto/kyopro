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

const int kMaxN = 100000;

int N, C;
int x[kMaxN], v[kMaxN];
int ans = 0;

int a[kMaxN], ma[kMaxN], b[kMaxN], mb[kMaxN];

signed main() {
  cin >> N >> C;
  REP(i, N) { cin >> x[i] >> v[i]; }

  a[0] = v[0]-x[0];
  ma[0] = MAX(0, a[0]);
  FOR(i, 1, N-1) {
    a[i] = a[i-1] + v[i]-(x[i]-x[i-1]);
    ma[i] = MAX(ma[i-1], a[i]);
  }
  b[N-1] = v[N-1]-(C-x[N-1]);
  mb[N-1] = MAX(0, b[N-1]);
  RFOR(i, N-2, 0) {
    b[i] = b[i+1] + v[i]-(x[i+1]-x[i]);
    mb[i] = MAX(mb[i+1], b[i]);
  }

  RFOR(i, N-1, 0) {
    int t = b[i];
    if (i != 0) { t = MAX(t, b[i]-(C-x[i])+ma[i-1]); }
    ans = MAX(ans, t);
  }
  FOR(i, 0, N-1) {
    int t = a[i];
    if (i != N-1) { t = MAX(t, a[i]-x[i]+mb[i+1]); }
    ans = MAX(ans, t);
  }

  cout << ans << endl;
  return 0;
}
