// UFT requirements
#define REP(i, n) for (int i = 0; i < n; ++i)
#include <vector>
using namespace std;

// UFT begin
class UFT {
public:
  // nは全体の要素数、size[x]はxが根のとき木の要素数
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

// UFT testcode
#include <iostream>
int main() {
  UFT u(10);
  u.Unite(2, 3);
  u.Unite(2, 6);
  u.Unite(7, 9);
  REP(i, 10) {
    std::cout << i << " " << u.Find(i) << std::endl;
  }
  return 0;
}
