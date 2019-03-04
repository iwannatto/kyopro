// header

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

// header

// code

const int Nlim = POW_10_5;
int N, K, A[Nlim];

int Ans() {
  int cnt[40] = {};
  REP(i, 40) {
    REP(j, N) {
      cnt[i] += (A[j] >> i) & 1;
    }
  }

  int ans = 0;

  int ans2 = 0;
  REP(i, 40) {
    if (((K + 1) >> i) & 1) {
      ans2 += (N - cnt[i]) * (1ll << i);
    } else {
      ans2 += cnt[i] * (1ll << i);
    }
  }

  REP(i, 40) {
    if (((K + 1) >> i) & 1) {
      ans2 = ans2 - ((N - cnt[i]) * (1ll << i)) + (cnt[i] * (1ll << i));
      ans = MAX(ans, ans2);
    }
    ans2 = ans2 - (cnt[i] * (1ll << i)) + (MAX(N - cnt[i], cnt[i]) * (1ll << i));
  }

  return ans;
}

signed main() {
  cin >> N >> K;
  REP(i, N) { cin >> A[i]; }

  auto ans = Ans();

  cout << ans << endl;
  return 0;
}

// code
