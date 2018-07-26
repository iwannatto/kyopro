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

const int kMaxN = 2000;

int N, K, Q;
int A[kMaxN];
int ans = 1000000000;

signed main() {
  cin >> N >> K >> Q;
  REP(i, N) { cin >> A[i]; }

  REP(i, N) {
    int Y = A[i];

    vector<int> v;
    int j = 0;
    while (j < N) {
      vector<int> v2;
      while (j < N && A[j] >= Y) { v2.push_back(A[j]); ++j; }
      sort(v2.begin(), v2.end());
      REP(k, (int)v2.size() - K + 1) { v.push_back(v2[k]); }
      ++j;
    }

    sort(v.begin(), v.end());
    if (v.size() >= Q) { ans = min(ans, v[Q-1]-Y); }
  }

  cout << ans << endl;
  return 0;
}
