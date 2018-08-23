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

// const int kMaxN;

int N;
int ans = 0;

signed main() {
  cin >> N;

  REP(i, N) {
    if ((i+1)%2 == 1) {
      int y = 0;
      REP(j, i+1) {
        if ((i+1)%(j+1) == 0) { ++y; }
      }
      if (y == 8) { ++ans; }
    }
  }

  cout << ans << endl;
  return 0;
}
