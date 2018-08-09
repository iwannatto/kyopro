// Print requirements
#include <iostream>
#include <vector>
using namespace std;

// Print begin
class Print {
 public:
  static void PrintInt2(int a, int b) {
    cout << a << " " << b << endl;
  }
  template <typename T>
  static void PrintVector(vector<T>& v) {
    for (auto& x : v) { cout << x << endl; }
  }
};
// Print end

// Print testcode
#define REP(i, n) for (int i = 0; i < n; ++i)
int main() {
  int a[5] = {0,1,2,3,4};
  int b[5] = {5,6,7,8,9};
  REP(i, 5) { Print::PrintInt2(a[i], b[i]); }
  vector<int> c = {1,3,5};
  Print::PrintVector(c);
  return 0;
}
