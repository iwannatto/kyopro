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

const int kMaxN = 100000;
const int kMaxM = NINTH_POWER_OF_TEN;

int N, M;
int A[kMaxN];
int ans = 0;

int B[kMaxN+1];
unordered_map<int, int> h;

signed main() {
  cin >> N >> M;
  REP(i, N) { cin >> A[i]; }

  B[0] = 0;
  ++h[0];
  REP(i, N) {
    B[i+1] = (B[i]+A[i])%M;
    ++h[B[i+1]];
  }

  for (auto it = h.begin(); it != h.end(); ++it) {
    ans += (it->second-1)*(it->second)/2;
  }

  cout << ans << endl;
  return 0;
}
