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
const int kP = NINTH_POWER_OF_TEN+7;
const int kMaxN = 100000;

int N, M;
int ans = 1;

map<int, int> PrimeFactor(int n) {
  map<int, int> prime_factor;
  for (int i = 2; i*i <= n; ++i) {
    while (n%i == 0) {
      ++prime_factor[i];
      n /= i;
    }
  }
  if (n != 1) { prime_factor[n] = 1; }
  return prime_factor;
}

int fact[kP];

void FactInit() {
  REP(i, kP) {
    if (i % 100000000 == 0) { cout << i << endl; }
    if (i == 0) { fact[i] = 1; continue; }
    fact[i] = fact[i-1]*i % kP;
  }
  return;
}

int ModFact(int n, int p, int& e) {
  e = 0;
  if (n == 0) { return 1; }

  int res = ModFact(n/p, p, e);
  e += n/p;

  if (n/p % 2 != 0) { return res*(p-fact[n%p]) % p; }
  return res*fact[n%p] % p;
}

int ExtGcd(int a, int b, int& x, int& y) {
  int d = a;
  if (b != 0) {
    d = ExtGcd(b, a%b, y, x);
    y -= (a/b) * x;
  } else {
    x = 1; y = 0;
  }
  return d;
}

int ModInverse(int a, int m) {
  int x, y;
  ExtGcd(a, m, x, y);
  return (m + x%m) % m;
}

int ModComb(int n, int k, int p) {
  // cout << n << " " << k << " " << p << endl;
  if (n < 0 || k < 0 || n < k) { return 0; }

  int e1, e2, e3;
  int a1 = ModFact(n, p, e1), a2 = ModFact(k, p, e2), a3 = ModFact(n-k, p, e3);
  if (e1 > e2+e3) { return 0; }

  return a1*ModInverse(a2*a3 % p, p) % p;
}

int nHr(int n, int r) { return ModComb(n+r-1, r, kP); }

signed main() {
  cin >> N >> M;
  map<int, int> pf = PrimeFactor(M);

  FactInit();

  for (auto it = pf.begin(); it != pf.end(); ++it) {
    ans = (ans * nHr(N, it->second)) % kP;
  }

  cout << ans << endl;
  return 0;
}
