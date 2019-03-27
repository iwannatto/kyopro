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
const int Nlim = 100;
int N;
vector<int> b;

vector<int> Ans() {
  vector<int> ans;
  REP(i, N) {
    bool fail = true;
    RFOR(j, b.size() - 1, 0) {
      if (b[j] == j+1 && j+1 <= N-i) {
        b.erase(b.begin() + j);
        ans.push_back(j+1);
        fail = false;
        break;
      }
    }
    if (fail) { return {-1}; }
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

signed main() {
  cin >> N;
  b.resize(N); REP(i, N) { cin >> b[i]; }

  vector<int> ans = Ans();
  REP(i, ans.size()) {
    cout << ans[i] << endl;
  }
  return 0;
}
