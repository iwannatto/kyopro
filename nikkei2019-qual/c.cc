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
const int Nlim = POW_10_5;
int N;
Pair AB[Nlim];

int Ans() {
  sort(AB, AB+N, [](auto &left, auto &right) {
    return left.first + left.second > right.first + right.second;
  });
  int ans = 0;
  REP(i, N) {
    if (i%2 == 0) {
      ans += AB[i].first;
    } else {
      ans -= AB[i].second;
    }
  }
  return ans;
}

signed main() {
  cin >> N;
  REP(i, N) { cin >> AB[i].first >> AB[i].second; }

  auto ans = Ans();

  cout << ans << endl;
  return 0;
}
