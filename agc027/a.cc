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

int N, x;
int a[kMaxN];

int ans = 0;

signed main() {
  cin >> N >> x;
  REP(i, N) { cin >> a[i]; }

  sort(a, a+N);
  REP(i, N) {
    if (x <= 0) { break; }

    if (i != N-1) {
      if (x-a[i] > 0) {
        x -= a[i];
      } else if (x-a[i] == 0) {
        ans = i+1;
        break;
      } else {
        ans = i;
        break;
      }
    } else {
      if (x-a[i] > 0) {
        ans = N-1;
      } else if (x-a[i] == 0) {
        ans = N;
      } else {
        ans = N-1;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
