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
const int Nlim = 10000;
int N;
string s[Nlim];

int Ans() {
  int ab = 0;
  int last_a = 0, first_b = 0, both = 0;
  REP(i, N) {
    auto pos = s[i].find("AB");
    while (pos != string::npos) {
      ++ab;
      pos = s[i].find("AB", pos + 2);
    }
    if (s[i].back() == 'A' && s[i].front() == 'B') {
      ++both;
    } else {
      if (s[i].back() == 'A') { ++last_a; }
      if (s[i].front() == 'B') { ++first_b; }
    }
  }
  if (last_a >= 1 && first_b >= 1) {
    return ab + MIN(last_a, first_b) + both;
  } else {
    if (last_a >= 1 || first_b >= 1) {
      return ab + both;
    } else {
      return ab + MAX(both-1, 0);
    }
  }
}

signed main() {
  cin >> N;
  REP(i, N) { cin >> s[i]; }

  auto ans = Ans();

  cout << ans << endl;
  return 0;
}
