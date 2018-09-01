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

const int kMaxN = 1000;

int N, M;
int x[kMaxN], y[kMaxN], z[kMaxN];
int ans = 0;

signed main() {
  cin >> N >> M;
  REP(i, N) { cin >> x[i] >> y[i] >> z[i]; }

  REP(i, 2) {
    REP(j, 2) {
      REP(k, 2) {
        vector<int> v(N);
        REP(l, N) {
          v[l] = ((1-2*i)*x[l]) + ((1-2*j)*y[l]) + ((1-2*k)*z[l]);
        }
        sort(v.begin(), v.end(), greater<int>());
        int s = 0;
        REP(l, M) { s += v[l]; }
        ans = MAX(ans, s);
      }
    }
  }

  cout << ans << endl;
  return 0;
}
