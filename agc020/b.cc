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

const int kMaxK = 100000;

int K;
int A[kMaxK];
long long int L[kMaxK+1], R[kMaxK+1];

long long int Ceil(long long int a, int b) {
  if (a%b == 0) {
    return a/b;
  } else {
    return a/b + 1;
  }
}

int main() {
  cin >> K;
  REP(i, K) { cin >> A[i]; }

  L[K] = 2;
  R[K] = 2;
  RFOR(i, K, 0) {
    long long int min_multiple_of_A = Ceil(L[i], A[i-1]) * A[i-1];
    if (!(L[i] <= min_multiple_of_A && min_multiple_of_A <= R[i])) {
      L[0] = -1;
      break;
    }

    L[i-1] = min_multiple_of_A;
    R[i-1] = (R[i]/A[i-1]) * A[i-1] + A[i-1] - 1;
  }

  if (L[0] == -1) {
    cout << -1 << endl;
  } else {
    cout << L[0] << " " << R[0] << endl;
  }
  return 0;
}
