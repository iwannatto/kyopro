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

const int kMaxN = 100000;
const int kMaxNN = (kMaxN+1)/2;

int N;
int A[kMaxN];
int ans = 0;

int NN;

int K = NINTH_POWER_OF_TEN + 7;
// int dp[kMaxN+1][kMaxN];
int fact[kMaxN+1];
int n[kMaxN];
//
// int Dp(int n, int i) {
//   cout << n << " " << i << endl;
//   if (dp[n][i] != 1) { return dp[n][i]; }
//
//   int a = 0;
//   FOR(j, 0, i-1) { a = (a + (fact[j] * Dp(n-1-j, i-j-1) % K)) % K ; }
//   a = (a+1) % K;
//   FOR(j, i+1, n-1) { a = (a + (Dp(i, j+1) * fact[n-1-j] % K)) % K; }
//   return a;
// }

void Add(int n, int m, int k) {

}

signed main() {
  cin >> N;
  REP(i, N) { cin >> A[i]; }

  NN = (N+1)/2;

  Add(0, n, n);

  


  // fill((int*)dp, (int*)dp + (kMaxN+1)*kMaxN, -1);
  // dp[1][0] = 1;
  fact[0] = 1;
  FOR(i, 1, N) { fact[i] = i * fact[i-1] % K; }

  FOR(step, 1, N) {

  }

  // REP(i, N) {
  //   ans = (ans + A[i]*Dp(N, i)) % K;
  // }

  cout << ans << endl;
  return 0;
}
