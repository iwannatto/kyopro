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

const int kMaxS = 5000;

string s;
int K;
string ans;

signed main() {
  cin >> s;
  cin >> K;

  vector<string> ss;
  REP(i, s.length()) {
    REP(j, K) {
      if (i+j < s.length()) { ss.push_back(s.substr(i, j+1)); }
    }
  }
  sort(ss.begin(), ss.end());
  auto r = unique(ss.begin(), ss.end());
  ans = ss[K-1];

  cout << ans << endl;
  return 0;
}
