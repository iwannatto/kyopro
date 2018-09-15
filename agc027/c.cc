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
#define NINTH_POWER_OF_TEN 1000000000
#define LL_INF (numeric_limits<long long>::max()/2)
#define int long long

typedef long long ll;
typedef pair<int, int> Pair;

const int kMaxN = 200000;
const int kMaxM = 200000;

int N, M;
string s;
int a[kMaxM], b[kMaxM];
string ans;

vector<int> es[kMaxN];
int acnt[kMaxN];
int bcnt[kMaxN];
bool remain[kMaxN];

void Bfs(int i) {
  if (!remain[i]) { return; }
  if (acnt[i] > 0 && bcnt[i] > 0) { return; }

  remain[i] = false;
  REP(j, es[i].size()) {
    if (s[i] == 'A') {
      --acnt[es[i][j]];
    } else {
      --bcnt[es[i][j]];
    }
  }
  REP(j, es[i].size()) {
    Bfs(es[i][j]);
  }
}

signed main() {
  cin >> N >> M;
  cin >> s;
  REP(i, M) { cin >> a[i] >> b[i]; }

  REP(i, M) { --a[i]; --b[i]; }

  REP(i, M) {
    if (a[i] != b[i]) {
      es[a[i]].push_back(b[i]);
      if (s[b[i]] == 'A') {
        ++acnt[a[i]];
      } else {
        ++bcnt[a[i]];
      }
      es[b[i]].push_back(a[i]);
      if (s[a[i]] == 'A') {
        ++acnt[b[i]];
      } else {
        ++bcnt[b[i]];
      }
    } else {
      if (s[a[i]] == 'A') {
        ++acnt[a[i]];
      } else {
        ++bcnt[a[i]];
      }
    }
  }
  REP(i, N) { remain[i] = true; }

  REP(i, N) {
    if (!remain[i]) { continue; }
    Bfs(i);
  }

  ans = "No";
  REP(i, N) {
    if (remain[i]) { ans = "Yes"; break; }
  }

  cout << ans << endl;
  return 0;
}
