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

const int Alim = 100000;
const int sLim = 10000000000;

int A, B, Q;
int s[Alim+1], t[Alim+1], x[Alim];
int ans;

int st[Alim*2][2];

void Ans(int x) {
  if (x <= st[0][0]) {
    ans = ABS(st[0][0] - x) + st[0][1];
    return;
  }
  int i = 0, j = A+B;
  while (i+1 != j) {
    int k = (i+j) / 2;
    if (st[k][0] <= x) {
      i = k;
    } else {
      j = k;
    }
  }
  if (i == A+B-1) {
    ans = ABS(st[i][0]-x) + st[i][1];
    return;
  } else {
    ans = MIN(ABS(st[i][0]-x)+st[i][1], ABS(st[i+1][0]-x)+st[i+1][1]);
    return;
  }
}

signed main() {
  cin >> A >> B >> Q;
  REP(i, A) { cin >> s[i]; }
  REP(i, B) { cin >> t[i]; }
  REP(i, Q) { cin >> x[i]; }
  s[A] = sLim*3;
  t[B] = sLim*3;

  int i = 0, j = 0;
  while (i < A || j < B) {
    if (s[i] < t[j]) {
      st[i+j][0] = s[i];
      if (j-1 >= 0) {
        st[i+j][1] = MIN(ABS(t[j]-s[i]), ABS(t[j-1]-s[i]));
      } else {
        st[i+j][1] = ABS(t[j]-s[i]);
      }
      ++i;
    } else {
      st[i+j][0] = t[j];
      if (i-1 >= 0) {
        st[i+j][1] = MIN(ABS(s[i]-t[j]), ABS(s[i-1]-t[j]));
      } else {
        st[i+j][1] = ABS(s[i]-t[j]);
      }
      ++j;
    }
  }

  REP(i, Q) {
    Ans(x[i]);
    cout << ans << endl;
  }

  return 0;
}
