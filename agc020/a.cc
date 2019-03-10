#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)

const int kMaxN = 100;

int n, a, b;
string ans;

int main() {
  cin >> n >> a >> b;

  if ((a-b)%2 == 0) {
    ans = "Alice";
  } else {
    ans = "Borys";
  }

  cout << ans << endl;
  return 0;
}
