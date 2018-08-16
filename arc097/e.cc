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
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

const int kMaxN = 2000;

int N;
vector<pair<char, int> ca;
int ans = 0;

int cnt[kMaxN*2+1][kMaxN]
int dp[kMaxN+1][kMaxN+1];

int Cost(char c, int i, int j) {
  if (c == 'W') {

  }
}

signed main() {
  cin >> N;
  REP(i, 2*N) {
    char c; int a;
    cin >> c >> a;
    ca.push_back(make_pair(c,a-1));
  }



  dp[0][0] = 0;
  REP(i, N+1) {
    REP(j, N+1) {
      if (i == 0 && j == 0) { continue; }
      if (i == 0) {
        dp[i][j] = dp[i][j-1] + Cost('W', i, j);
      } else if (j == 0) {
        dp[i][j] = dp[i-1][j] + Cost('B', i, j);
      } else {
        dp[i][j] = MIN(
          dp[i][j-1] + Cost('W', i, j),
          dp[i][j] = dp[i-1][j] + Cost('B', i, j));
      }
    }
  }
  ans = dp[N][N];

  cout << ans << endl;
  return 0;
}
