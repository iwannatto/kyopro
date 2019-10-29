#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ABS(a) (((a) >= 0) ? (a) : -(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define POW_10_5 100000
#define POW_10_9 1000000000
#define MOD 1000000007
#define INF (numeric_limits<int>::max()/2)
#define int long long

typedef pair<int, int> Pair;
typedef unordered_map<int, int> Hash;
// New Elements: Part 1
// ---
int Nlim = 6;

// int Ans() {
//
// }

signed main() {
  cin >> T;
  FOR(caseno, 1, T) {
    int N;
    int C[Nlim], J[Nlim];
    cin >> N;
    REP(i, N) { cin >> C[i] >> J[i]; }
    REP(i, 5) {
      REP(j, 4) {
        REP(k, 3) {
          REP(l, 2) {
            REP(m, 1) {
              int a = i;
              int b = (i+j)%5;
              int c = (i+j+k)%5;
              int d = (i+j+k+l)%5;
              int e = (i+j+k+l+m)%5;
            }
          }
        }
      }
    }
    cout << "Case #" << caseno << ": ";
    cout << ans << endl;
  }


  return 0;
}
