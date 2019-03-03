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
#define POW_10_9 1000000000
#define INF (numeric_limits<int>::max()/2)
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

const int costs[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int N, M;
int A[9];
string ans;

// 数、桁数
int dp[10001];

signed main() {
  cin >> N >> M;
  REP(i, M) { cin >> A[i]; }

  sort(A, A+M, greater<int>());
  FOR(i, 1, N) {
    REP(j, M) {
      int k = i - costs[A[j]];
      if (k >= 0) { dp[i] = MAX(dp[i], dp[k]+1); }
    }
    if (dp[i] == 0) { dp[i] = -INF; }
  }

  int i = N;
  REP(j, M) {
    int k = i-costs[A[j]];
    while (k >= 0 && dp[i] == dp[k]+1) {
      ans.push_back('0'+A[j]);
      i -= costs[A[j]];
      k = i-costs[A[j]];
    }
  }

  cout << ans << endl;

  return 0;
}
