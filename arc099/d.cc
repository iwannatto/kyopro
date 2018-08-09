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

int K;
int ans = 0;

signed main() {
  cin >> K;

  REP(i, 9) {
    if (K-- > 0) { cout << i+1 << endl; }
  }
  int i = 19;
  while (K-- > 0) {
    cout << i << endl;
    i = i*10 + 9;
  }
  return 0;
}
