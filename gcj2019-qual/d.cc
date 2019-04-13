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
string Makestr(int n, int d) {
  if (d == 1) {
    string s1(n/2, '0');
    string s2(n/2, '1');
    return s1+s2;
  }
  string s = Makestr(n/2, d-1);
  return s+s;
}

signed main() {
  int T;
  cin >> T;

  FOR(casenum, 1, T) {
    int N, B, F;
    cin >> N >> B >> F;

    string R[10];
    int n = 1024, d = 1;
    REP(i, 10) {
      cout << Makestr(n, d).substr(0, N) << endl;
      cin >> R[i];
      ++d;
    }

    set<int> live;
    REP(i, R[0].length()) {
      string s;
      REP(j, 10) { s.push_back(R[j][i]); }
      live.insert(stoi(s, nullptr, 2));
    }

    bool first = true;
    REP(i, N) {
      if (live.count(i) == 0) {
        if (first) {
          cout << i;
          first = false;
        } else {
          cout << " " << i;
        }
      }
    }
    cout << endl;

    int tmp;
    cin >> tmp;
  }

  return 0;
}
