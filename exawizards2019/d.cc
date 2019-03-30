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
#define MOD 1000000007
#define INF (numeric_limits<int>::max()/2)
#define int long long

typedef pair<int, int> Pair;
typedef unordered_map<int, int> Hash;

// ---
const int Nlim = 200, Xlim = POW_10_5;
int N, X;
int S[Nlim];
int dp[Xlim+1][Nlim+1];

int Ans(int x, int i) {
  if (dp[x][i] != -1) { return dp[x][i]; }
  if (i == N-1) { dp[x][i] = x % S[N-1]; return x % S[N-1]; }

  int ans = 0;
  ans += Ans(x % S[i], i+1);
  ans %= MOD;

  ans += Ans(x, i+1) * (N - (i + 1));
  ans %= MOD;

  dp[x][i] = ans; return ans;
}

signed main() {
  cin >> N >> X;
  REP(i, N) { cin >> S[i]; }

  sort(S, S+N, greater<int>());
  REP(i, Xlim+1) {
    REP(j, Nlim+1) {
      dp[i][j] = -1;
    }
  }
  auto ans = Ans(X, 0);

  cout << ans << endl;
  return 0;
}
