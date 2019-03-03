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

// const int kMaxN;

string s;
int ans = 0;

signed main() {
  cin >> s;
  int n = s.length();

  if (s[0] != '1' || s[n-1] != '0') {
    cout << -1 << endl;
    return 0;
  }
  REP(i, (n-1)/2) {
    if (s[i] != s[n-2-i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  vector<int> u, v;
  int ti = 1;
  int nflag = 0;
  FOR(si, 0, (n-1+1)/2 - 1) {
    if (s[si] == '1') {
      u.push_back(ti);
      v.push_back(++ti);
    } else {
      if (n-(si+1) < nflag) { continue; }
      int oldti = ti;
      REP(i, n-(si+1)) {
        u.push_back(oldti);
        v.push_back(++ti);
      }
      nflag = n-(si+1);
    }
    if (ti > n) {
      cout << -1 << endl;
      return 0;
    }
  }
  while (ti != n) {
    u.push_back(ti);
    v.push_back(++ti);
  }

  REP(i, n-1) {
    cout << u[i] << " " << v[i] << endl;
  }
  return 0;
}
