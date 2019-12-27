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
const int Nlim = 1000;
int T;
int N;
string w[Nlim];
bool used[Nlim];
unordered_map<string, int> h;
int ans;

signed main() {
  cin >> T;

  FOR(caseno, 1, T) {
    cin >> N;
    REP(i, N) {
      cin >> w[i];
      used[i] = false;
    }
    ans = 0;

    RFOR(l, 50, 1) {
      h.clear();
      REP(i, N) {
        if (used[i] || w[i].length() < l) { continue; }
        string s = w[i].substr(w[i].length() - l, l);
        auto it = h.find(s);
        if (it != h.end()) {
          int j = it->second;
          if (j == -1) { continue; }
          used[i] = true; used[j] = true;
          it->second = -1;
          ans += 2;
        } else {
          h[s] = i;
        }
      }
    }

    cout << "Case #" << caseno << ": " << ans << endl;
  }

  return 0;
}
