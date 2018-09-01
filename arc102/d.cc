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

const int kMaxM = 60;

int L;
int N, M;
int u[kMaxM], v[kMaxM], w[kMaxM];

int Pow(int a, int b) {
  int r = 1;
  REP(i, b) { r *= a; }
  return r;
}

signed main() {
  cin >> L;

  int n = 0;
  int L2 = L;
  while (L2 != 1) {
    L2 /= 2;
    ++n;
  }

  N = n+1;

  M = 0;
  int tmpw = 1;
  REP(i, n) {
    u[2*i] = i; v[2*i] = i+1; w[2*i] = tmpw;
    u[2*i+1] = i; v[2*i+1] = i+1; w[2*i+1] = 0;
    tmpw *= 2;
    M += 2;
  }
  int ii = 2*n;
  L -= tmpw;
  int tmpb = tmpw/2;
  REP(i, n) {
    if (L/tmpb == 1) {
      u[ii] = n-(i+1); v[ii] = n; w[ii] = tmpw;
      ++ii; ++M;
      tmpw += tmpb;
    }
    L %= tmpb;
    tmpb /= 2;
  }

  cout << N << " " << M << endl;
  REP(i, M) { cout << u[i]+1 << " " << v[i]+1 << " " << w[i] << endl; }
  return 0;
}
