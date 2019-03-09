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

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;

ll N;
int ans = 0;

int DigitSum(ll n) {
  int r = 0;
  while (n > 0) {
    r += n%10;
    n /= 10;
  }
  return r;
}

int main() {
  cin >> N;

  int i = 0;
  ll j = 1;
  while (N >= j) {
    if (i == 0) {
      ans = DigitSum(N);
    } else {
      ll n = (N/j)*j-j + j-1;
      ans = max(ans, DigitSum(n));
    }
    // cout << i << " " << j << " " << ans << endl;
    ++i;
    j *= 10;
  }

  cout << ans << endl;
  return 0;
}
