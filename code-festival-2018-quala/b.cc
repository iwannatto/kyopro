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
const int kMaxM = 100;

int N, M, A, B;
int L[kMaxM], R[kMaxM];
int ans = 0;

bool is_a[kMaxN+1];

signed main() {
  cin >> N >> M >> A >> B;
  REP(i, M) { cin >> L[i] >> R[i]; }

  REP(i, M) {
    FOR(j, L[i], R[i]) { is_a[j] = true; }
  }

  FOR(i, 1, N) {
    if (is_a[i]) {
      ans += A;
    } else if (A > B) {
      ans += A;
    } else {
      ans += B;
    }
  }

  cout << ans << endl;
  return 0;
}
