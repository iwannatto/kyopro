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

int N, M;
Pair P[kMaxN];
int ans = 0;

signed main() {
  cin >> N >> M;
  REP(i, M) { cin >> P[i].second >> P[i].first; }

  sort(P, P+M);

  int x = -1;
  REP(i, M) {
    int a = P[i].second;
    int b = P[i].first;
    // cout << a << " " << b << " " << x << " " << ans << endl;
    if (a <= x) {
      continue;
    } else {
      x = b - 1;
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}
