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

const int kMaxN = 3*100000;

int N;
string S;
int ans = kMaxN;

// w_count[i] = [0, i]までに存在する'W'の数
// e_count[i] = [i, N-1]までに存在する'E'の数
int w_count[kMaxN], e_count[kMaxN];

signed main() {
  cin >> N;
  cin >> S;

  w_count[0] = (S[0] == 'W') ? 1 : 0;
  e_count[N-1] = (S[N-1] == 'E') ? 1 : 0;
  FOR(i, 1, N) {
    w_count[i] = w_count[i-1];
    if (S[i] == 'W') { w_count[i] += 1; }
    e_count[N-1-i] = e_count[N-1-(i-1)];
    if (S[N-1-i] == 'E') { e_count[N-1-i] += 1; }
  }

  REP(i, N) {
    if (i == 0) {
      ans = MIN(ans, e_count[i+1]);
    } else if (i == N-1) {
      ans = MIN(ans, w_count[i-1]);
    } else {
      ans = MIN(ans, w_count[i-1]+e_count[i+1]);
    }
  }

  cout << ans << endl;
  return 0;
}
