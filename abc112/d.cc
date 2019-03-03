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

// const int kMaxN;

int N, M;
int ans = 0;

map<int, int> PrimeFactor(int n) {
  map<int, int> prime_factor;
  for (int i = 2; i*i <= n; ++i) {
    while (n%i == 0) {
      ++prime_factor[i];
      n /= i;
    }
  }
  if (n != 1) { prime_factor[n] = 1; }
  return prime_factor;
}

void Bfs(map<int, int>& pf, map<int, int>::iterator& it, int n) {
  if (it == pf.end()) {
    if (n >= N) {
      ans = MAX(ans, M/n);
    }
    return;
  }

  int nn = 1;
  FOR(i, 0, it->second) {
    ++it;
    Bfs(pf, it, n*nn);
    --it;
    nn *= it->first;
  }
  return;
}

signed main() {
  cin >> N >> M;
  map<int, int> pf = PrimeFactor(M);

  map<int, int>::iterator it = pf.begin();
  Bfs(pf, it, 1);

  cout << ans << endl;
  return 0;
}
