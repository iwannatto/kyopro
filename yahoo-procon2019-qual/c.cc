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
#define POW_10_9 1000000000
#define INF (numeric_limits<int>::max()/2)
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

int K, A, B;

int Ans() {
  if (B - A <= 2) {
    return 1 + K;
  }
  return 1 + (A - 1) + ((K - (A - 1))/2)*(B - A) + ((K - (A - 1))%2);
}

signed main() {
  cin >> K >> A >> B;

  int ans = Ans();

  cout << ans << endl;
  return 0;
}
