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

const int kMaxNM = 100000;

int N, M;
string S, T;
int ans = 0;

int g, l, sn, tn;

int Gcd(int a, int b) {
  if (b == 0) { return a; }
  return Gcd(b, a%b);
}

int Ans() {
  REP(i, g) {
    if (S[sn*i] != T[tn*i]) { return -1; }
  }
  return l;
}

signed main() {
  cin >> N >> M;
  cin >> S;
  cin >> T;

  g = Gcd(N, M);
  l = (N/g) * (M/g) * g;

  sn = N/g;
  tn = M/g;

  ans = Ans();

  cout << ans << endl;
  return 0;
}
