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

// UnionFindTree begin
class UnionFindTree {
 public:
  int size_;
  vector<int> parent_, rank_;

  UnionFindTree() : size_(0), parent_(), rank_() {}
  UnionFindTree(int size) : size_(size), parent_(size), rank_(size, 0) {
    REP(i, size) { parent_[i] = i; }
  }

  int Find(int x) {
   if (parent_[x] == x) {
     return x;
   } else {
     int f = Find(parent_[x]);
     parent_[x] = f;
     return f;
   }
  }
  void Unite(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) { return; }
    if (rank_[x] < rank_[y]) {
      parent_[x] = y;
    } else if (rank_[x] > rank_[y]) {
      parent_[y] = x;
    } else {
      parent_[x] = y;
      rank_[y] += 1;
    }
  }
  bool Same(int x, int y) { return (Find(x) == Find(y)); }

};
// UnionFindTree end

const int kMaxN = 100000;
const int kMaxM = 100000;

int N, M;
int A[kMaxN], B[kMaxN];
int U[kMaxM], V[kMaxM];
int ans = 0;

signed main() {
  cin >> N >> M;
  REP(i, N) { cin >> A[i] >> B[i]; }
  REP(i, M) {
    int u, v;
    cin >> u >> v;
    U[i] = u-1; V[i] = v-1;
  }

  int C[kMaxN];
  REP(i, N) { C[i] = MAX(A[i]-B[i], 0); }
  int es[kMaxM];
  REP(i, M) { es[i] = i; }
  auto comp = [&C](int i, int j) {
    return MAX(C[U[i]], C[V[i]]) < MAX(C[U[j]], C[V[j]]);
  };
  sort(es, es+M, comp);
  // REP(i, M) { cout << U[es[i]] << " " << V[es[i]] << endl; }
  UnionFindTree uft(N);
  int money[kMaxN];
  REP(i, N) { money[i] = C[i] + B[i]; }
  int bsum[kMaxN];
  REP(i, N) { bsum[i] = B[i]; }

  REP(i, M) {
    int u = U[es[i]], v = V[es[i]];
    if (!uft.Same(u, v)) {
      int uu = uft.Find(u), vv = uft.Find(v);
      uft.Unite(u, v);
      int uv = uft.Find(u);
      money[uv] = MIN(
        MAX(money[uu], C[v])+bsum[vv], MAX(money[vv], C[u])+bsum[uu]);
      bsum[uv] = bsum[uu]+bsum[vv];
    }
    // REP(i, N) { cout << money[i] << " "; }
    // cout << endl;
  }
  ans = money[uft.Find(0)];

  cout << ans << endl;
  return 0;
}
