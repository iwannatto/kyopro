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

// Bit begin

class Bit {
 public:
  vector<int> bit;

  Bit(int n) : bit(n+1) {}

  int Sum(int i) {
    ++i;
    int s = 0;
    while (i > 0) {
      s += bit[i];
      int last_bit = i & (-i);
      i -= last_bit;
    }
    return s;
  }

  void Add(int i, int x) {
    ++i;
    while (i <= bit.size()) {
      bit[i] += x;
      int last_bit = i & (-i);
      i += last_bit;
    }
    return;
  }
};

// Bit end

const int kMaxN = 100000;

int N;
int A[kMaxN];
int ans = 0;

signed main() {
  cin >> N;
  REP(i, N) { cin >> A[i]; }

  int lb = 1, ub = NINTH_POWER_OF_TEN+1;
  while (ub > lb+1) {
    // cout << lb << " " << ub << endl;
    int x = (ub+lb)/2;

    int a[N];
    REP(i, N) {
      if (A[i] < x) {
        a[i] = -1;
      } else {
        a[i] = 1;
      }
    }

    int S[N+1];
    S[0] = 0;
    REP(i, N) { S[i+1] = S[i] + a[i]; }
    REP(i, N+1) { S[i] += N; }

    int sum = 0;
    Bit b(2*N+1);
    FOR(r, 0, N) {
      sum += b.Sum(S[r]);
      b.Add(S[r], 1);
    }

    if (sum >= (N*(N+1)/2 + 1) / 2) {
      lb = x;
    } else {
      ub = x;
    }
  }
  ans = lb;

  cout << ans << endl;
  return 0;
}
