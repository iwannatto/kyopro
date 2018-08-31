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

const int kMaxN = 200000;

int N, K;
int b[kMaxN];
int ans = 0;

int dp[kMaxN+1], dp2[kMaxN+1];

signed main() {
  cin >> N >> K;
  REP(i, N) { cin >> b[i]; }

  REP(i, N) {
    dp[i+1] = dp[i]+b[i];
    int j = i+1-K;
    if (j >= 0) { dp[i+1] = MAX(dp[i+1], dp2[j]); }
    dp2[i+1] = MAX(dp2[i], dp[i+1]);
  }
  ans = dp[N];

  cout << ans << endl;
  return 0;
}
