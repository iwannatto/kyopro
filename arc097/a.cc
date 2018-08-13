#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
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

int a, b, c, d;
string ans;

signed main() {
  cin >> a >> b >> c >> d;

  if (ABS(a-c) <= d || (ABS(a-b) <= d && ABS(b-c) <= d)) {
    ans = "Yes";
  } else {
    ans = "No";
  }

  cout << ans << endl;
  return 0;
}
