// VeGraph requirements
#define REP(i, n) for (int i = 0; i < n; ++i)
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// union_find_tree.cc

// VeGraph begin
class VeGraphEdge {
 public:
  int u_, v_, cost_;

  VeGraphEdge() : u_(0), v_(0), cost_(0) {}
  VeGraphEdge(int u, int v, int cost) : u_(u), v_(v), cost_(cost) {}

  bool operator< (const VeGraphEdge& e) const {
    return cost_ < e.cost_;
  }
};

class VeGraph {
 public:
   vector<vector<int>> v_;
   vector<VeGraphEdge> e_;
   bool is_directed_;

  VeGraph() : v_(0), e_(0), is_directed_(false) {}
  VeGraph(int v, int e, bool is_directed) :
    v_(v), e_(e), is_directed_(is_directed) {}

  void AddEdgesFromStdin(int e, bool cost) {
    if (cost) {
      REP(i, e) {
        int u, v, c;
        cin >> u >> v >> c;
        e_[i] = VeGraphEdge(u, v, c);
        v_[u].push_back(i);
        if (!is_directed_) { v_[v].push_back(i); }
      }
    } else {
      REP(i, e) {
        int u, v;
        cin >> u >> v;
        e_[i] = VeGraphEdge(u, v, 0);
        v_[u].push_back(i);
        if (!is_directed_) { v_[v].push_back(i); }
      }
    }
    return;
  }

  int Kruskal() {
    sort(e_.begin(), e_.end());
    UnionFindTree u(v_.size());

    int mincost = 0;
    REP(i, e_.size()) {
      VeGraphEdge e = e_[i];
      if (!u.Same(e.u_, e.v_)) {
        mincost += e.cost_;
        u.Unite(e.u_, e.v_);
      }
    }
    return mincost;
  }
};
// VeGraph end

// VeGraph testcode
int main() {
  VeGraph g(7, 9, false);
  g.AddEdgesFromStdin(9, true);
  cout << g.Kruskal() << endl;

  return 0;
}
