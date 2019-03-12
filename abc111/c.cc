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

void P2(int a, int b) {
  cout << a << " " << b << endl;
  return;
}

const int kMaxN = 200000;

int n;
int v[kMaxN];
int ans = 0;

signed main() {
  cin >> n;
  REP(i, n) { cin >> v[i]; }

  unordered_map<int, int> h1, h2;
  REP(i, n/2) {
    h1[v[2*i]]++; h2[v[2*i+1]]++;
  }
  int maxn1[2], maxn2[2];
  int maxc1[2] = {0, 0}, maxc2[2] = {0, 0};
  for (auto it = h1.begin(); it != h1.end(); ++it) {
    if (it->second > maxc1[0]) {
      maxn1[1] = maxn1[0]; maxc1[1] = maxc1[0];
      maxn1[0] = it->first; maxc1[0] = it->second;
    } else if (it->second > maxc1[1]) {
      maxn1[1] = it->first; maxc1[1] = it->second;
    }
  }
  for (auto it = h2.begin(); it != h2.end(); ++it) {
    if (it->second > maxc2[0]) {
      maxn2[1] = maxn2[0]; maxc2[1] = maxc2[0];
      maxn2[0] = it->first; maxc2[0] = it->second;
    } else if (it->second > maxc2[1]) {
      maxn2[1] = it->first; maxc2[1] = it->second;
    }
  }
  // P2(maxn1[0], maxc1[0]);
  // P2(maxn1[1], maxc1[1]);

  if (maxn1[0] != maxn2[0]) {
    ans = n/2 - maxc1[0] + n/2 - maxc2[0];
  } else {
    ans = MIN(n/2 - maxc1[1] + n/2 - maxc2[0], n/2 - maxc1[0] + n/2 - maxc2[1]);
  }

  cout << ans << endl;
  return 0;
}
