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

// const int kMaxN;

string S;
int K;
char ans;

signed main() {
  cin >> S;
  cin >> K;

  REP(i, S.length()) {
    if (S[i] != '1') {
      ans = S[i];
      break;
    }
    if (i+1 == K) {
      ans = S[i];
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
