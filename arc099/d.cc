#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
using namespace std;

#define ABS(a) (((a) >= 0) ? (a) : -(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

// const int kMaxN;

int K;
int ans = 0;

int S(int n) {
  int s = 0;
  while (n != 0) {
    s += n%10;
    n /= 10;
  }
  return s;
}

int F(int n) {
  int fn, base = 1;
  double ratio = 1000000000000000;
  while (base <= n*10) {
    int x = (n/base + 1)*base - 1;
    double nr = (double)x/S(x);
    if (nr < ratio) {
      ratio = nr;
      fn = x;
    }
    base *= 10;
  }
  return fn;
}

signed main() {
  cin >> K;

  int n = 0;
  while (K--) {
    n = F(n+1);
    cout << n << endl;
  }
  return 0;
}
