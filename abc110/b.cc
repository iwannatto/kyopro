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

const int kMaxN = 100;
const int kMaxM = 100;

int N, M, X, Y;
string ans;

int x[kMaxN], y[kMaxM];

signed main() {
  cin >> N >> M >> X >> Y;
  REP(i, N) { cin >> x[i]; }
  REP(i, M) { cin >> y[i]; }

  sort(x, x+N);
  sort(y, y+M);
  ans = "War";
  FOR(i, X+1, Y) {
    if (x[N-1] < i && i <= y[0]) {
      ans = "No War";
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
