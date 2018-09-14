#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)

// const int kMaxN;

int a, b;
int ans = 0;

int main() {
  cin >> a >> b;

  if ((a%2 == 1 && b%2 == 0) || (a%2 == 0 && b%2 == 1)) {
    ans = (a+b)/2 + 1;
  } else {
    ans = (a+b)/2;
  }

  cout << ans << endl;
  return 0;
}
