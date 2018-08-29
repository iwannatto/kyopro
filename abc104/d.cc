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

string S;
int ans = 0;

int dp[kMaxN+1][4];

signed main() {
  cin >> S;
  int n = S.length();

  dp[0][0] = 1;
  REP(i, n) {
    if (S[i] == '?') {
      REP(j, 4) { dp[i+1][j] += 3*dp[i][j]; }
      REP(j, 3) { dp[i+1][j+1] += dp[i][j]; }
    } else {
      REP(j, 4) { dp[i+1][j] += dp[i][j]; }
      if (S[i] == 'A') {
        dp[i+1][1] += dp[i][0];
      } else if (S[i] == 'B') {
        dp[i+1][2] += dp[i][1];
      } else {
        dp[i+1][3] += dp[i][2];
      }
    }
    REP(j, 4) { dp[i+1][j] %= NINTH_POWER_OF_TEN+7; }
  }
  ans = dp[n][3];

  cout << ans << endl;
  return 0;
}
