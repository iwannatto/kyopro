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
#define INF (numeric_limits<int>::max()/2)
#define int long long

typedef pair<int, int> Pair;

// ---
int N;
string S;

int Ans() {
  unordered_map<char, int> h;
  REP(i, N) { h[S[i]] += 1; }

  int ans = 1;
  for (auto it = h.begin(); it != h.end(); ++it) {
    ans = ans * (it->second + 1) % (POW_10_9 + 7);
  }
  return ans - 1;
}

signed main() {
  cin >> N;
  cin >> S;

  auto ans = Ans();

  cout << ans << endl;
  return 0;
}
