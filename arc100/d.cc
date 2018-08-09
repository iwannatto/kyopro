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

#define ABS(a) (((a) >= 0) ? (a) : -(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

const int kMaxN = 2*100000;

int N;
int A[kMaxN];
int ans = 1000000000;

signed main() {
  cin >> N;
  REP(i, N) { cin >> A[i]; }
  REP(i, N-1) { A[i+1] += A[i]; }

  int a = 1;
  int c = 3;
  REP(i, N-3) {
    int b = i+2;
    while (a+1 < b) {
      if (ABS(A[a-1] - (A[b-1]-A[a-1])) >= ABS(A[a] - (A[b-1]-A[a]))) {
        ++a;
      } else {
        break;
      }
    }
    while (c+1 < N) {
      // printf("%lld %lld %lld %lld\n", a, b, c, N);
      if (ABS((A[c-1]-A[b-1]) - (A[N-1]-A[c-1]))
        >= ABS((A[c]-A[b-1]) - (A[N-1]-A[c]))) {
          ++c;
      } else {
        break;
      }
    }
    int max = MAX(A[a-1],
      MAX(A[b-1]-A[a-1], MAX(A[c-1]-A[b-1], A[N-1]-A[c-1])));
    int min = MIN(A[a-1],
      MIN(A[b-1]-A[a-1], MIN(A[c-1]-A[b-1], A[N-1]-A[c-1])));
    ans = MIN(ans, max-min);
  }

  cout << ans << endl;
  return 0;
}
