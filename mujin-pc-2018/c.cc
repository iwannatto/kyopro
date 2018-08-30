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

const int kMaxN = 2000;
const int kMaxM = 2000;

int N, M;
string s[kMaxN];
int ans = 0;

// (i,j) -> (i,j+1)
int LtoR[kMaxN][kMaxM+1];
// (i,j) -> (i,j)
int RtoL[kMaxN][kMaxM+1];
// (i,j) -> (i+1,j)
int UtoD[kMaxN+1][kMaxM];
// (i,j) -> (i,j)
int DtoU[kMaxN+2][kMaxM+2];

signed main() {
  cin >> N >> M;
  REP(i, N) { cin >> s[i]; }

  REP(i, N) {
    REP(j, M) {
      if (s[i][j] == '.') {
        LtoR[i][j+1] = LtoR[i][j] + 1;
      } else {
        LtoR[i][j+1] = 0;
      }
    }
    RFOR(j, M-1, 0) {
      if (s[i][j] == '.') {
        RtoL[i][j] = RtoL[i][j+1] + 1;
      } else {
        RtoL[i][j] = 0;
      }
    }
  }
  REP(j, M) {
    REP(i, N) {
      if (s[i][j] == '.') {
        UtoD[i+1][j] = UtoD[i][j] + 1;
      } else {
        UtoD[i+1][j] = 0;
      }
    }
    RFOR(i, N-1, 0) {
      if (s[i][j] == '.') {
        DtoU[i][j] = DtoU[i+1][j] + 1;
      } else {
        DtoU[i][j] = 0;
      }
    }
  }

  REP(i, N) {
    REP(j, M) {
      if (s[i][j] == '#') { continue; }

      int l = LtoR[i][j];
      int r = RtoL[i][j+1];
      int u = UtoD[i][j];
      int d = DtoU[i+1][j];
      // cout << i << " " << j << " ";
      // cout << l << " " << r << " ";
      // cout << u << " " << d << " " << endl;
      ans += l*d + d*r + r*u + u*l;
    }
  }

  cout << ans << endl;
  return 0;
}
