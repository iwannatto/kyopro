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

string s;
int x, y;
string ans;

bool dpx[16001], dpy[16001];

signed main() {
  cin >> s;
  cin >> x >> y;

  dpx[0+8000] = true; dpy[0+8000] = true;

  int i = 0;
  bool state_init = true;
  bool state_x = true;
  while (i < s.length()) {
    int c = 0;
    while (i < s.length() && s[i] == 'F') {
      ++i;
      ++c;
    }

    if (state_x) {
      bool dpx2[16001];
      REP(j, 16001) {
        dpx2[j] = false;
        if (j-c >= 0) { dpx2[j] |= dpx[j-c]; }
        if (j+c < 16001 && !state_init) { dpx2[j] |= dpx[j+c]; }
      }
      REP(j, 16001) { dpx[j] = dpx2[j]; }
      state_init = false;
    } else {
      bool dpy2[16001];
      REP(j, 16001) {
        dpy2[j] = false;
        if (j-c >= 0) { dpy2[j] |= dpy[j-c]; }
        if (j+c < 16001) { dpy2[j] |= dpy[j+c]; }
      }
      REP(j, 16001) { dpy[j] = dpy2[j]; }
    }
    ++i;
    state_x = !state_x;

    // cout << state_x << endl;
    //
    // FOR(j, -5, 5) { cout << dpx[j+8000] << " "; }
    // cout << endl;
    // FOR(j, -5, 5) { cout << dpy[j+8000] << " "; }
    // cout << endl;
  }


  if (dpx[x+8000] && dpy[y+8000]) {
    ans = "Yes";
  } else {
    ans = "No";
  }

  cout << ans << endl;
  return 0;
}
