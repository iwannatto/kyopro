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
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

// const int kMaxN;

int N, K;
int ans = 0;

int Pow(int a, int b) {
  int r = 1;
  REP(i, b) { r *= a; }
  return r;
}

signed main() {
  cin >> N >> K;

  if (K%2 == 0) {
    int a = N/K;
    int b = (N+(K/2))/K;
    ans = Pow(a, 3) + Pow(b, 3);
  } else {
    ans = Pow(N/K, 3);
  }

  cout << ans << endl;
  return 0;
}
