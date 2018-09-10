#include <algorithm>
#include <bitset>
#include <cmath>
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

const int kMaxN = 300;

int N;
string S[kMaxN];
int ans = 0;

void P2(int a, int b) {
  cout << a << " " << b << endl;
  return;
}

signed main() {
  cin >> N;
  REP(i, N) { cin >> S[i]; }

  REP(x, N) {
    FOR(i, 0, N-1) {
      FOR(j, i, N-1) {
        if (S[(i+x)%N][j] != S[(j+x)%N][i]) { goto label; }
      }
    }
    ans += N;
label:
  ;
  }

  cout << ans << endl;
  return 0;
}
