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
typedef unordered_map<int, int> Hash;

// ---
const int Nlim = POW_10_5;
int N, K;
Pair dt[Nlim];

int Ans() {
  sort(dt, dt+N);
  // REP(i, N) {
  //   cout << dt[i].first << " " << dt[i].second << endl;
  // }
  int ans = 0;
  Hash kind;
  FOR(i, N-K, N-1) {
    ans += dt[i].first;
    ++kind[dt[i].second];
  }
  ans += (kind.size() * kind.size());
  int ans2 = ans;
  int i = N-K;
  RFOR(j, N-K-1, 0) {
    if (kind.find(dt[j].second) == kind.end()) {
      // cout << i << " " << j << " " << endl;
      while(i < N && kind[dt[i].second] <= 1) { ++i; }
      if (i == N) { return ans; }
      ans2 -= dt[i].first;
      --kind[dt[i].second];
      ++i;
      // cout << kind.size() << endl;
      ans2 -= (kind.size() * kind.size());
      ans2 += dt[j].first;
      ++kind[dt[j].second];
      // cout << kind.size() << endl;
      ans2 += (kind.size() * kind.size());
      ans = MAX(ans, ans2);
    }
  }
  return ans;
}

signed main() {
  cin >> N >> K;
  REP(i, N) { cin >> dt[i].second >> dt[i].first; }

  auto ans = Ans();

  cout << ans << endl;
  return 0;
}
