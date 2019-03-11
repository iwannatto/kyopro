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

string A;
ll ans = 0;

int main() {
  cin >> A;

  ll s = 0;
  char a = 'a';
  REP(i, 26) {
    char c = a+i;
    ll cnt = count(A.begin(), A.end(), c);
    s += cnt*(cnt-1)/2;
  }

  ll n = A.length();
  ans = n*(n-1)/2 - s + 1;

  cout << ans << endl;
  return 0;
}
