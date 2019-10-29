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
int R, G, B, N;

int Ans() {
  int cnt = 0;
  int r = 0;
  while (r * R <= N) {
    int g = 0;
    int NN = N - (r * R);
    while (g * G <= NN) {
      if (((NN - (g * G)) % B) == 0) { ++cnt; }
      ++g;
    }
    ++r;
  }
  return cnt;
}

signed main() {
  cin >> R >> G >> B >> N;

  auto ans = Ans();

  cout << ans << endl;
  return 0;
}
