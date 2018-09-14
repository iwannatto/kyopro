#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)

const int kMaxN = 100000;

int n;
int a[kMaxN];
int ans = 0;

int main() {
  cin >> n;
  REP(i, n) { cin >> a[i]; }

  sort(a, a+n);
  int i = 0;
  while (i < n) {
    int ai = a[i];
    int ai_cnt = 0;
    for (int j = 0; a[i+j] == ai && i+j < n; ++j) { ++ai_cnt; }
    if (ai_cnt < ai) {
      ans += ai_cnt;
    } else if (ai_cnt == ai) {
      ;
    } else {
      ans += ai_cnt - ai;
    }
    i += ai_cnt;
  }

  cout << ans << endl;
  return 0;
}
