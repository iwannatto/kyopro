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

int N;

// Primes begin
class Primes {
 public:
  int n;
  vector<int> nthp;
  vector<bool> isp;

  Primes(int n) : n(n), nthp(), isp(n+1) {
    FOR(i, 0, 1) { isp[i] = false; }
    FOR(i, 2, n) { isp[i] = true; }
    FOR(i, 2, n) {
      if (isp[i]) {
        nthp.push_back(i);
        for (int j = i+i; j <= n; j += i) { isp[j] = false; }
      }
    }
  }
};
// Primes end


signed main() {
  cin >> N;
  Primes p(55555);

  int c = 0;
  for (int i = 2; c < N; ++i) {
    if (p.isp[i] && i%5 == 1) {
      if (c != 0) { cout << " "; }
      cout << i;
      ++c;
    }
  }
  cout << endl;

  return 0;
}
