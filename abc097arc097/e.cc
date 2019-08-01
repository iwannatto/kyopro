#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
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

int N;
vector<pair<char, int>> ca;
int ans = 0;

class C {
public:
  size_t operator()(const pair<char, int>& p) const {
    return p.first*11113 + p.second;
  }
};

unordered_map<pair<char, int>, int, C> h;
int cntw[kMaxN*2+1][kMaxN];
int cntb[kMaxN*2+1][kMaxN];
int dp[kMaxN+1][kMaxN+1];

int Cost(char c, int i, int j) {
  if (c == 'W') {
    int ni = h[make_pair(c,i)];
    if (i != 0) { i -= cntw[ni][i-1]; }
    if (j != 0) { j -= cntb[ni][j-1]; }
    return i+j;
  } else {
    int ni = h[make_pair(c,j)];
    if (i != 0) { i -= cntw[ni][i-1]; }
    if (j != 0) { j -= cntb[ni][j-1]; }
    return i+j;
  }
}

signed main() {
  cin >> N;
  REP(i, 2*N) {
    char c; int a;
    cin >> c >> a;
    pair<char, int> p = make_pair(c,a-1);
    ca.push_back(p);
    h[p] = i;
  }

  REP(j, N) {
    cntw[0][j] = 0;
    cntb[0][j] = 0;
  }
  REP(i, 2*N) {
    REP(j, N) {
      cntw[i+1][j] = cntw[i][j];
      if (ca[i].first == 'W' && ca[i].second <= j) { cntw[i+1][j]++; }
      cntb[i+1][j] = cntb[i][j];
      if (ca[i].first == 'B' && ca[i].second <= j) { cntb[i+1][j]++; }
    }
  }

  dp[0][0] = 0;
  REP(i, N+1) {
    REP(j, N+1) {
      if (i == 0 && j == 0) { continue; }
      if (i == 0) {
        dp[i][j] = dp[i][j-1] + Cost('B', i, j-1);
      } else if (j == 0) {
        dp[i][j] = dp[i-1][j] + Cost('W', i-1, j);
      } else {
        dp[i][j] = MIN(
          dp[i][j-1] + Cost('B', i, j-1),
          dp[i-1][j] + Cost('W', i-1, j));
      }
    }
  }
  ans = dp[N][N];

  cout << ans << endl;
  return 0;
}
