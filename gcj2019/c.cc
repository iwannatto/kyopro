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
#define MOD 1000000007
#define INF (numeric_limits<int>::max()/2)
#define int long long

typedef pair<int, int> Pair;
typedef unordered_map<int, int> Hash;

// ---
int Gcd(int a, int b) {
  if (b > a) { return Gcd(b, a); }
  if (b == 0) { return a; }
  return Gcd(b, a%b);
}

signed main() {
  int n;
  cin >> n;
  FOR(i, 1, n) {
    int N, L;
    cin >> N >> L;
    int C[L];
    REP(j, L) { cin >> C[j]; }

    int P[L+1];
    set<int> primes;
    int k;
    for (k = 0; C[k] == C[k+1]; ++k) { ; }
    int b = Gcd(C[k], C[k+1]);
    int a = C[k]/b;
    for (int j = k; j >= 0; --j) {
      P[j] = a;
      --j;
      if (j >= 0) { P[j] = b; }
    }
    primes.insert(a);
    FOR(j, k, L-1) {
      a = C[j]/a;
      P[j+1] = a;
      primes.insert(a);
    }

    unordered_map<int, char> t;
    set<int>::iterator it = primes.begin();
    for (char c = 'A'; c <= 'Z'; ++c) {
      t[*it] = c;
      ++it;
    }

    string Pstr;
    REP(j, L+1) {
      Pstr.push_back(t[P[j]]);
    }

    cout << "Case #" << i << ": " << Pstr << endl;
  }

  return 0;
}
