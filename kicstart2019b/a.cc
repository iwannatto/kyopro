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

signed main() {
  int T;
  cin >> T;

  FOR(caseno, 1, T) {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> table[26];
    REP(i, 26) {
      table[i].resize(N);
      table[i][0] = 0;

      REP(j, S.length()) {
        if (j != 0) {
          table[i][j] = table[i][j-1];
        }
        if (i == S[j] - 'A') { table[i][j] += 1; }
      }
    }

    int cnt = 0;
    REP(q, Q) {
      int L, R;
      cin >> L >> R;

      bool odd = false;
      bool ok = true;
      REP(i, 26) {
        int n = table[i][R-1];
        if (L != 1) { n -= table[i][L-2]; }
        if (n % 2 == 1) {
          if (odd) {
            ok = false;
            break;
          } else {
            odd = true;
          }
        }
      }

      if (ok) { cnt += 1; }
    }

    cout << "Case #" << caseno << ": " << cnt << endl;
  }

  return 0;
}
