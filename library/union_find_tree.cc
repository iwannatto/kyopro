// UnionFindTree requirements

#define REP(i, n) for (int i = 0; i < n; ++i)
#include <iostream>
#include <vector>
using namespace std;

// UnionFindTree begin

class UnionFindTree {
 public:
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

 private:
  int size_;
  vector<int> parent_, rank_;
};

// UnionFindTree end

int main() {
  UnionFindTree u(10);
  u.Unite(2, 3);
  u.Unite(2, 6);
  u.Unite(7, 9);
  REP(i, 10) {
    cout << i << " " << u.Find(i) << endl;
  }
  return 0;
}
