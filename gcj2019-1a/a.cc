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
int R, C, table[5][5];
vector<Pair> v;

bool Bfs(int n, int pre_i, int pre_j) {
  if (n + 1 > R * C) { return true; }
  n += 1;

  REP(i, R) {
    REP(j, C) {
      if (table[i][j] == 0 && i != pre_i && j != pre_j && i + j != pre_i + pre_j && i - j != pre_i - pre_j) {
        table[i][j] = n;
        v.push_back(make_pair(i + 1, j + 1));
        if (Bfs(n, i, j)) { return true; }
        table[i][j] = 0;
        v.pop_back();
      }
    }
  }

  return false;
}

signed main() {
  int T;
  cin >> T;

  FOR(caseno, 1, T) {
    cin >> R >> C;

    REP(i, R) { REP(j, C) { table[i][j] = 0; } }
    v.clear();
    cout << "Case #" << caseno << ": ";
    if (Bfs(0, 5, 10)) {
      cout << "POSSIBLE" << endl;
      REP(i, v.size()) {
        cout << v[i].first << " " << v[i].second << endl;
      }
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
  }

  return 0;
}
