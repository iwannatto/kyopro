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

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;

ll Q, H, S, D, N;
ll ans = 0;

int main() {
  cin >> Q >> H >> S >> D;
  cin >> N;

  ll l = min(4*Q, min(2*H, S));
  ll l2 = min(2*l, D);

  ans += l2 * (N/2);
  ans += l * (N%2);

  cout << ans << endl;
  return 0;
}
