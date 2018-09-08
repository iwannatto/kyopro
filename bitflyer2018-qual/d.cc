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
const int kMaxM = 1000;

int H, W;
int N, M;
string A[kMaxN];
int ans = 0;

// 累積和フィールドなので1広げる
int field[kMaxN*2+1 + 1][kMaxM*2+1 + 1];

signed main() {
  cin >> H >> W;
  cin >> N >> M;
  REP(i, N) { cin >> A[i]; }

  int bx = MAX(0, H - 2*N), by = MAX(0, W - 2*M);
  int fh = H-bx+MIN(1, bx), fw = W-by+MIN(1, by);
  // cout << bx << " " << by;
  // cout << fh << " " << fw;
  REP(i, N) {
    REP(j, M) {
      if (A[i][j] == '#') {
        int i2 = fh-N+i, j2 = fw-M+j;
        field[i][j] += 1;
        field[i][j2+1] -= 1;
        field[i2+1][j] -= 1;
        field[i2+1][j2+1] += 1;
      }
    }
  }

  REP(i, fh) { REP(j, fw) { field[i][j+1] += field[i][j]; } }
  REP(j, fw) { REP(i, fh) { field[i+1][j] += field[i][j]; } }

  REP(i, fh) {
    REP(j, fw) {
      if (field[i][j] >= 1) {
        int s = 1;
        if (N <= i && i < fh-N) { s *= bx; }
        if (M <= j && j < fw-M) { s *= by; }
        ans += s;
        // cout << i << " " << j << " " << s << endl;
      }
    }
  }

  cout << ans << endl;
  return 0;
}
