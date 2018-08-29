// Bit requirements
#include <vector>
using namespace std;

// Bit begin

class Bit {
 public:
  vector<int> bit;

  Bit(int n) : bit(n) {}

  int Sum(int i) {
    int s = 0;
    while (i > 0) {
      s += bit[i];
      int last_bit = i & (-i);
      i -= last_bit;
    }
    return s;
  }

  void Add(int i, int x) {
    while (i <= bit.size()) {
      bit[i] += x;
      int last_bit = i & (-i);
      i += last_bit;
    }
    return;
  }
};

// Bit end

// Bit testcode
#include <iostream>
int main() {
  int a[] = {3,1,4,2};
  int ans = 0;
  Bit b(4);
  for (int i = 0; i < 4; ++i) {
    ans += i - b.Sum(a[i]);
    b.Add(a[i], 1);
  }
  cout << ans << endl;

  return 0;
}
