// Primes requirements
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#include <vector>
using namespace std;


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

// Primes testcode
#include <iostream>
signed main() {
  Primes p(100);
  REP(i, p.nthp.size()) {
    cout << p.nthp[i] << endl;
  }
  return 0;
}
