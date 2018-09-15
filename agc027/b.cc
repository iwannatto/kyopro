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

const int kMaxN = 200000;

int N, X;
int x[kMaxN];
int ans = 0;

void P3(int a, int b, int c) {
  cout << a << " " << b << " " << c << endl;
  return;
}

int Sim(vector<int> v) {
  int r = 0;
  int k = 0;
  r += x[v.size()-1];
  ++k;
  // P3(0, r, k);
  RFOR(i, v.size()-2, 0) {
    r += (x[v[i+1]]-x[v[i]]) * (k+1)*(k+1);
    ++k;
    // P3(1, r, k);
  }
  r += v[0] * (k+1)*(k+1);
  r += X;
  return r;
}

signed main() {
  cin >> N >> X;
  REP(i, N) { cin >> x[i]; }

  int ri = 0;
  RFOR(i, N-1, 0) {
    if (i < ri) { break; }
    vector<int> v = {i};
    int tmp = Sim(v);

    FOR(rj, ri, i-1) {
      vector<int> v2 = {rj};
      int tmp2 = Sim(v2);

      vector<int> v3;
      FOR(j, ri, rj) { v3.push_back(j); }
      v3.push_back(i);
      int tmp3 = Sim(v3);

      // P3(tmp, tmp2, tmp3);

      if (tmp+tmp2 < tmp3) {
        ri = rj;
        tmp = tmp+tmp2;
        break;
      } else {
        tmp = tmp3;
        if (rj == i-1) { ri = rj; }
      }
    }
    ans += tmp;
  }

  ans += N*X;

  cout << ans << endl;
  return 0;
}
