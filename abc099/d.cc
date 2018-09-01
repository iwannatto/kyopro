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

const int kMaxN = 500;
const int kMaxC = 30;

int N, C;
int D[kMaxC][kMaxC];
int c[kMaxN][kMaxN];
int ans = NINTH_POWER_OF_TEN;

int cost[3][kMaxC];

signed main() {
  cin >> N >> C;
  REP(i, C) { REP(j, C) { cin >> D[i][j]; }}
  REP(i, N) {
    REP(j, N) {
      int cc;
      cin >> cc;
      c[i][j] = cc-1;
    }
  }

  REP(i, N) {
    REP(j, N) {
      REP(k, C) {
        cost[(i+j)%3][k] += D[c[i][j]][k];
      }
    }
  }

  REP(i, C) {
    REP(j, C-1) {
      REP(k, C-2) {
        ans = MIN(
          ans,
          cost[0][i] + cost[1][(i+j+1)%C] + cost[2][(i+(j+k+1)%(C-1)+1)%C]
        );
      }
    }
  }

  cout << ans << endl;
  return 0;
}
