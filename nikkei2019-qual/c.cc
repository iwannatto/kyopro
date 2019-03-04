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

int Ans() {
  vector<int> C[N];
  vector<int> P[N];
  REP(i, N-1+M) {
    C[A[i]].push_back(B[i]);
    P[B[i]].push_back(A[i]);
  }

  int root;
  REP(i, N) {
    if (P[i].size() == 0) {
      root = i;
      break;
    }
  }

  int T[N] = {};
  T[root] = 0;
  queue<int> q;
  q.push(root);
  for (int i = root; !q.empty(); i = q.front()) {
    q.pop();
    
  }
}

signed main() {
  cin >> N >> M;
  REP(i, N-1+M) { cin >> A[i] >> B[i]; }
  REP(i, N-1+M) { A[i]--; B[i]--; }

  auto ans = Ans();

  cout << ans << endl;
  return 0;
}
