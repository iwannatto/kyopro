#include <algorithm>
#include <bitset>
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

const int kMaxN = 2000;
const int kMaxA = 2000;

int N;
int A[kMaxN+1];
int ans = 0;

int sum = 0;

int main() {
  cin >> N;
  REP(i, N) { cin >> A[i+1]; }

  REP(i, N) { sum += A[i+1]; }
  bitset<kMaxN*kMaxA+1> bs;
  bs[0] = true;
  REP(i, N) {
    bitset<kMaxN*kMaxA+1> bs2 = bs << A[i+1];
    bs = bs | bs2;
  }

  if (sum%2 == 0) {
    ans = sum/2;
  } else {
    ans = sum/2 + 1;
  }
  while (!bs[ans]) { ++ans; }

  cout << ans << endl;
  return 0;
}
