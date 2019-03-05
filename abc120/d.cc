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

// UFT begin
class UFT {
public:
  int n;
  vector<int> parent, rank, size;

  UFT() : n(0), parent(), rank(), size() {}
  UFT(int n) : n(n), parent(n), rank(n, 0), size(n, 1) {
    REP(i, n) { parent[i] = i; }
  }

  int Find(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      int f = Find(parent[x]);
      parent[x] = f;
      return f;
    }
  }
  void Unite(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) { return; }
    if (rank[x] < rank[y]) {
      parent[x] = y;
      size[y] += size[x];
    } else if (rank[x] > rank[y]) {
      parent[y] = x;
      size[x] += size[y];
    } else {
      parent[x] = y;
      size[y] += size[x];
      rank[y] += 1;
    }
  }
  bool Same(int x, int y) { return (Find(x) == Find(y)); }
  int Size(int x) {
    int root = Find(x);
    return size[root];
  }
};
// UFT end

// ---
const int Mlim = POW_10_5;
int N, M, A[Mlim], B[Mlim];

void Ans() {
  int ans[M];
  ans[M-1] = N*(N-1)/2;
  UFT u(N);
  RFOR(i, M-2, 0) {
    if (u.Same(A[i+1], B[i+1])) {
      ans[i] = ans[i+1];
    } else {
      ans[i] = ans[i+1] - (u.Size(A[i+1]) * u.Size(B[i+1]));
      u.Unite(A[i+1], B[i+1]);
    }
  }

  REP(i, M) {
    cout << ans[i] << endl;
  }
}

signed main() {
  cin >> N >> M;
  REP(i, M) { cin >> A[i] >> B[i]; }
  REP(i, M) { --A[i]; --B[i]; }

  Ans();

  // cout << ans << endl;
  return 0;
}
