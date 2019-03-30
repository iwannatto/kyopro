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
typedef unordered_map<int, int> Hash;

// ---
const int Qlim = 2 * POW_10_5;
int N, Q;
string s;
char t[Qlim], d[Qlim];

bool LeftHamide(int pos) {
  REP(i, Q) {
    if (t[i] == s[pos]) {
      if (d[i] == 'L') {
        --pos;
        if (pos < 0) { return true; }
      } else {
        ++pos;
        if (pos >= N) { return false; }
      }
    }
  }
  return false;
}

bool RightHamide(int pos) {
  REP(i, Q) {
    if (t[i] == s[pos]) {
      if (d[i] == 'L') {
        --pos;
        if (pos < 0) { return false; }
      } else {
        ++pos;
        if (pos >= N) { return true; }
      }
    }
  }
  return false;
}

int Ans() {
  int ans = N;

  if (LeftHamide(0)) {
    int l = 0, r = N;
    while (l+1 != r) {
      int m = (l + r) / 2;
      if (LeftHamide(m)) {
        l = m;
      } else {
        r = m;
      }
    }
    ans -= l + 1;
  }

  // (l, r]
  if (RightHamide(N-1)) {
    int l = -1, r = N-1;
    while (l != r-1) {
      int m = (l + r) / 2;
      if (RightHamide(m)) {
        r = m;
      } else {
        l = m;
      }
    }
    ans -= N - r;
  }

  return ans;
}

signed main() {
  cin >> N >> Q;
  cin >> s;
  REP(i, Q) { cin >> t[i] >> d[i]; }

  auto ans = Ans();

  cout << ans << endl;
  return 0;
}
