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

typedef long long ll;

const int kMaxK = 100000;
const int kMaxA = 1000000000;

ll K;
int A[kMaxK];
ll ans1, ans2;

ll G(ll n) {
  REP(i, K) { n = (n/A[i])*A[i]; }
  return n;
}

ll BinSearch1(ll i, ll j) {
  while (i+1 != j) {
    ll k = (i+j)/2;
    if (G(k) >= 2) {
      j = k;
    } else {
      i = k;
    }
  }
  return j;
}

ll BinSearch2(ll i, ll j) {
  while (i+1 != j) {
    ll k = (i+j)/2;
    if (G(k) <= 2) {
      i = k;
    } else {
      j = k;
    }
  }
  return i;
}

int main() {
  cin >> K;
  REP(i, K) { cin >> A[i]; }

  ans1 = BinSearch1(0, 3+K*kMaxA);
  ans2 = BinSearch2(0, 3+K*kMaxA);

  if (ans1 > ans2) {
    cout << -1 << endl;
  } else {
    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
