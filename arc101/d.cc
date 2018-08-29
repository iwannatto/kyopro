#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <iterator>
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
#define NINTH_POWER_OF_TEN 1000000000
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

const int kMaxN = 100000;

int N;
int A[kMaxN];
int ans = 0;

signed main() {
  cin >> N;
  REP(i, N) { cin >> A[i]; }

  vector<int> v;
  REP(i, N) {
    v.push_back(A[i]);

    unordered_map<int, int> le, lo, re, ro;
    int s = 0;
    RFOR(j, i-1, 0) {
      if (A[j] <= A[i]) {
        --s;
      } else {
        ++s;
      }
      if ((i-j)%2 == 0) {
        ++le[s];
      } else {
        ++lo[s];
      }
    }
    FOR(j, i+1, N-1) {
      if (A[i] <= A[j]) {
        ++s;
      } else {
        --s;
      }
      if ((j-i)%2 == 0) {
        ++re[s];
      } else {
        ++ro[s];
      }
    }

    for (auto it = lo.begin(); it != lo.end(); ++it) {
      int x = it->first;
      int n = it->second;
      if (x > 0) {
        REP(k, n*ro[-x]) { v.push_back(A[i]); }
        REP(k, n*re[-(x+1)]) { v.push_back(A[i]); }
      } else {
        REP(k, n*ro[-x]) { v.push_back(A[i]); }
        REP(k, n*re[-x-1]) { v.push_back(A[i]); }
      }
    }
    for (auto it = le.begin(); it != le.end(); ++it) {
      int x = it->first;
      int n = it->second;
      
    }
  }

  cout << ans << endl;
  return 0;
}
