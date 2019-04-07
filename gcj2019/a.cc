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

// ---
int n;
string N;

signed main() {
  cin >> n;

  FOR(i, 1, n) {
    string N, A, B;
    cin >> N;
    REP(j, N.length()) {
      if (N[j] == '4') {
        A.push_back('3');
        B.push_back('1');
      } else {
        A.push_back(N[j]);
        if (B.length() != 0) {
          B.push_back('0');
        }
      }
    }

    cout << "Case #" << i << ": " << A << " " << B << endl;
  }

  return 0;
}
