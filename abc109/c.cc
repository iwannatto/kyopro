#include <algorithm>
#include <bitset>
#include <cmath>
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

const int kMaxN = 100000;

int N, X;
int x[kMaxN];
int ans = 1;

int Pow(int a, int b) {
  int r = 1;
  REP(i, b) { r *= a; }
  return r;
}

signed main() {
  cin >> N >> X;
  REP(i, N) { cin >> x[i]; }

  REP(i, N) { x[i] = ABS(x[i]-X); }

  map<int, int> pf;
  int n = x[0];
  for (int i = 2; i*i <= n; ++i) {
    // cout << n << " " << i << endl;
    while (n%i == 0) {
      // cout << "hey" << endl;
      ++pf[i];
      n /= i;
    }
  }
  if (n != 1) { ++pf[n]; }

  FOR(i, 1, N-1) {
    map<int, int> pf2;
    int n = x[i];
    for (int j = 2; j*j <= n; ++j) {
      while (n%j == 0) {
        ++pf2[j];
        n /= j;
      }
    }
    if (n != 1) { ++pf2[n];}

    for (auto it = pf.begin(); it != pf.end(); ++it) {
      int n = it->first;
      // cout << n << " " << it->second << " " << pf2[n] << endl;
      it->second = MIN(it->second, pf2[n]);
    }
  }

  for (auto it = pf.begin(); it != pf.end(); ++it) {
    // cout << it->first << " " << it->second << endl;
    ans *= Pow(it->first, it->second);
  }

  cout << ans << endl;
  return 0;
}
