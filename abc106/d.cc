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
using namespace std;

#define ABS(a) (((a) >= 0) ? (a) : -(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

const int kMaxN = 500;
const int kMaxM = 200000;
const int kMaxQ = 100000;

int N, M, Q;
int L[kMaxM], R[kMaxM];
int p[kMaxQ], q[kMaxQ];

int t[kMaxN+1][kMaxN+2];

signed main() {
  cin >> N >> M >> Q;
  REP(i, M) { cin >> L[i] >> R[i]; }
  REP(i, Q) { cin >> p[i] >> q[i]; }

  REP(i, M) {
    t[L[i]][R[i]] += 1;
  }
  REP(i, N) {
    REP(j, N-1) {
      t[i+1][j+2] += t[i+1][j+1];
    }
  }

  REP(i, Q) {
    int ans = 0;
    FOR(j, p[i], q[i]) {
      ans += t[j][q[i]];
    }
    cout << ans << endl;
  }
  return 0;
}
