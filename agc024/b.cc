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

const int kMaxN = 200000;

int N;
int P[kMaxN+1];
int ans = LL_INF;

signed main() {
  cin >> N;
  FOR(i, 1, N) { cin >> P[i]; }

  unordered_map<int, int> h;
  int a[N+1], b[N+1];
  FOR(i, 1, N) { a[i] = 0; b[i] = 0; }
  FOR(i, 1, N) { h[P[i]] = i; }
  FOR(i, 1, N) {
    if (P[i] == N) { continue; }
    int ni = h[P[i]+1];
    if (ni > i) { a[ni] = a[i]+1; }
  }
  RFOR(i, N, 1) {
    if (P[i] == 1) { continue; }
    int ni = h[P[i]-1];
    if (ni < i) { b[ni] = b[i]+1; }
  }

  FOR(i, 1, N) {
    ans = MIN(ans, N-1-a[i]-b[i]);
  }

  cout << ans << endl;
  return 0;
}
