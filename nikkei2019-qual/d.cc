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
#define INF (numeric_limits<int>::max()/2)
#define int long long

typedef pair<int, int> Pair;

// ---
const int AnLim = POW_10_5;
int N, M, A[AnLim], B[AnLim];
vector<int> P[AnLim];
int root, dist[AnLim];

void Sub(int i) {
  if (dist[i] != INF) { return; }
  if (P[i].size() == 1) {
    Sub(P[i][0]);
    dist[i] = dist[P[i][0]] + 1;
    return;
  }
  REP(j, P[i].size()) { Sub(P[i][j]); }
  int aj = 0;
  FOR(j, 1, P[i].size() - 1) {
    if (dist[P[i][j]] > dist[P[i][aj]]) { aj = j; }
  }
  dist[i] = dist[P[i][aj]] + 1;
  P[i] = {P[i][aj]};
  return;
}

void Ans() {
  REP(i, N-1+M) {
    P[B[i]].push_back(A[i]);
  }

  REP(i, N) {
    if (P[i].size() == 0) {
      P[i].push_back(-1);
      root = i;
      break;
    }
  }

  REP(i, N) { dist[i] = INF; }
  dist[root] = 0;
  REP(i, N) { Sub(i); }

  REP(i, N) {
    P[i][0]++;
  }

  return;
}

signed main() {
  cin >> N >> M;
  REP(i, N-1+M) { cin >> A[i] >> B[i]; }
  REP(i, N-1+M) { A[i]--; B[i]--; }

  Ans();

  REP(i, N) {
    cout << P[i][0] << endl;
  }
  return 0;
}
