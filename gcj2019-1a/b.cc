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
void Print18(int n) {
  cout << n;
  REP(i, 17) { cout << " " << n; }
  cout << endl;
}

int Read18(int n) {
  int mod = 0;
  int tmp;
  REP(i, 18) {
    cin >> tmp;
    mod += tmp;
  }
  return mod % n;
}

signed main() {
  int T, N, M;
  cin >> T >> N >> M;

  int b[7] = {5, 7, 9, 11, 13, 16, 17};
  int mod[7];
  FOR(caseno, 1, T) {
    REP(i, 7) {
      Print18(b[i]);
      mod[i] = Read18(b[i]);
    }
    REP(i, N - 7) {
      Print18(2);
      int tmp;
      REP(i, 18) { cin >> tmp; }
    }

    FOR(i, 1, M) {
      bool ok = true;
      REP(j, 7) {
        if (i % b[j] != mod[j]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        cout << i << endl;
        break;
      }
    }

    int tmp;
    cin >> tmp;
    if (tmp == -1) {
      cout << "WA" << endl;
      break;
    }
  }

  return 0;
}
