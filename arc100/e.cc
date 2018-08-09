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

const int kMaxN = 18;
const int kMaxK = 262144;

int N;
int A[kMaxK];
int ans = 0;

Pair B[kMaxK];

signed main() {
  cin >> N;
  int K = 1;
  REP(i, N) { K *= 2; }
  REP(i, K) { cin >> A[i]; }
  REP(i, K) {
    B[i].first = A[i];
    B[i].second = 0;
  }

  REP(i, N) {
    REP(j, K) {
      if (j&(1<<i)) {
        int k = j^(1<<i);
        int C[4] = {B[j].first, B[j].second,
          B[k].first, B[k].second};
        sort(C, C+4);
        B[j].first = C[3]; B[j].second = C[2];
      }
    }
  }

  REP(i, K-1) {
    ans = MAX(ans, B[i+1].first + B[i+1].second);
    cout << ans << endl;
  }
  return 0;
}
