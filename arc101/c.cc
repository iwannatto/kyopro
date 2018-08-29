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

int N, K;
int A[kMaxN];

int ans = NINTH_POWER_OF_TEN;

signed main() {
  cin >> N >> K;
  REP(i, N) { cin >> A[i]; }

  REP(i, N-K+1) {
    int a = A[i];
    int b = A[i+K-1];
    if (a <= 0 && b <= 0) {
      ans = MIN(ans, -a);
    } else if (a <= 0 && b >= 0) {
      a = ABS(a);
      if (a <= b) {
        ans = MIN(ans, a*2 + b);
      } else {
        ans = MIN(ans, b*2 + a);
      }
    } else {
      ans = MIN(ans, b);
    }
  }

  cout << ans << endl;
  return 0;
}
