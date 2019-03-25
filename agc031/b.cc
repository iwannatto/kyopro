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
#define POW_10_5 100000
#define POW_10_9 1000000000
#define INF (numeric_limits<int>::max()/2)
#define int long long

typedef pair<int, int> Pair;

// ---
const int Nlim = 2 * POW_10_5;
const int Clim = 2 * POW_10_5 + 1;
const int M = POW_10_9 + 7;
int N;
int C[Nlim];

int Ans() {
  int dp[Nlim];
  int last[Clim];
  fill(last, last+Clim, -1);
  dp[0] = 1;
  last[C[0]] = 0;
  FOR(i, 1, N-1) {
    dp[i] = dp[i-1];
    if (last[C[i]] != -1 && last[C[i]] != i-1) {
      dp[i] = (dp[i] + dp[last[C[i]]]) % M;
    }
    last[C[i]] = i;
  }

  return dp[N-1];
}

signed main() {
  cin >> N;
  REP(i, N) { cin >> C[i]; }

  auto ans = Ans();

  cout << ans << endl;
  return 0;
}
