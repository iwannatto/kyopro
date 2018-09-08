#include <algorithm>
#include <bitset>
#include <cmath>
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

const int kMaxN = 100;

int N;
string W[kMaxN];
string ans;

string Ans() {
  set<string> s;
  s.insert(W[0]);
  FOR(i, 1, N-1) {
    if (W[i-1].back() == W[i].front() && s.insert(W[i]).second) {
      continue;
    }
    return "No";
  }
  return "Yes";
}

signed main() {
  cin >> N;
  REP(i, N) { cin >> W[i]; }

  ans = Ans();

  cout << ans << endl;
  return 0;
}
