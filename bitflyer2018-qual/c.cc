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

const int kMaxN = 100000;

int N, D;
int X[kMaxN];
int ans = 0;

signed main() {
  cin >> N >> D;
  REP(i, N) { cin >> X[i]; }

  int lb[N], ub[N];
  lb[0] = 0;
  ub[0] = 0;
  REP(i, N) {
    if (i != 0) { lb[i] = lb[i-1]; }
    while (lb[i] < N && X[lb[i]] <= X[i]+D) { lb[i]++; }
  }
  REP(j, N) {
    if (j != 0) { ub[j] = ub[j-1]; }
    while (ub[j] < N && X[ub[j]] <= X[j]+D) { ub[j]++; }
  }

  // FOR(i, 0, N-3) {
  //   FOR(j, i+1, N-2) {
  //     if (X[i]+D < X[j]) { break; }
  //     // cout << i << " " << j << " " << lb[i] << " " << ub[j] << endl;
  //     ans += ub[j]-lb[i];
  //   }
  // }

  REP(i, N) {
    ans -= lb[i]*(lb[i] - (i+1));
  }

  int jcnt[N+1];
  REP(i, N+1) { jcnt[i] = 0; }
  REP(i, N) {
    ++jcnt[i+1];
    --jcnt[lb[i]];
  }
  REP(i, N) {
    jcnt[i+1] += jcnt[i];
  }
  REP(i, N) {
    ans += jcnt[i]*ub[i];
  }

  cout << ans << endl;
  return 0;
}
