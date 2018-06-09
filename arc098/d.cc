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

const int kMaxN = 2*100000;

int N, A[kMaxN];
int ans = 0;

int l, r;
int sum, xor_;

signed main() {
  cin >> N;
  REP(i, N) { cin >> A[i]; }

  r = 0;
  REP(i, N) {
    l = i;
    while ((r < N) && (sum+A[r] == (xor_^A[r]))) {
      sum += A[r];
      xor_ ^= A[r];
      ++r;
    }
    ans += r-l;
    sum -= A[l];
    xor_ ^= A[l];
  }

  cout << ans << endl;
  return 0;
}
