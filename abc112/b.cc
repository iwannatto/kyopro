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

int N, T;
int c[kMaxN], t[kMaxN];
// int ans = 0;

signed main() {
  cin >> N >> T;
  REP(i, N) { cin >> c[i] >> t[i]; }

  int mincost = 10000;
  REP(i, N) { if (t[i] <= T) { mincost = MIN(mincost, c[i]); } }

  if (mincost == 10000) {
    cout << "TLE" << endl;
  } else {
    cout << mincost << endl;
  }
  return 0;
}
