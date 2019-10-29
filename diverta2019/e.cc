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
const int Nlim = 5 * POW_10_5;
const int M = POW_10_9 + 7;
int N;
int a[Nlim];

int Sub(int* a, int n, int b) {
  
}

int Ans() {
  int b = a[0];
  int ans = 0;
  REP(i, N) {
    ans = (ans + Sub(a+i+1, N-i-1, b)) % M;
    if (i != N-1) { b ^= a[i+1]; }
  }
  return ans;
}

signed main() {
  cin >> N;
  REP(i, N) { cin >> a[i]; }

  auto ans = Ans();

  cout << ans << endl;
  return 0;
}
