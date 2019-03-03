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
#define NINTH_POWER_OF_TEN 1000000000
#define LL_INF (numeric_limits<long long>::max()/2)
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

const int kMaxN = 2*100000;

string S, T;
string ans;

// bool table[26];

signed main() {
  cin >> S;
  cin >> T;

  ans = "Yes";
  FOR(i, 'a', 'z') {
    int c = 0;
    REP(j, S.length()) {
      if (S[j] == i) {
        c = T[j];
        // if (table[c-'a']) {
        //   ans = "No";
        //   goto r;
        // } else {
        //   table[c-'a'] = true;
        // }
        break;
      }
    }

    if (c == 0) { continue; }

    REP(j, S.length()) {
      if ((S[j] == i && T[j] != c) || (S[j] != i && T[j] == c)) {
        ans = "No";
        goto r;
      }
    }
  }

r:
  cout << ans << endl;
  return 0;
}
