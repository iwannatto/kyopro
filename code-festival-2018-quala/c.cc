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

const int kMaxN = 50;
const int kMaxK = NINTH_POWER_OF_TEN;
const int kM = NINTH_POWER_OF_TEN+7;

int N, K;
int A[kMaxN];
int ans = 0;

int dp[kMaxN][kMaxK];

signed main() {
  cin >> N >> K;
  REP(i, N) { cin >> A[i]; }

  REP(i, N) {
    int c = 0;
    while (A[i] != 0) { A[i] /= 2; ++c; }
    A[i] = c;
  }

  

  cout << ans << endl;
  return 0;
}
