#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <utility>
using namespace std;

// 諦めました。いつかやりたい。

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)

string s;
int gx, gy;
int x = 0, y = 0;
string ans = "";

typedef pair<int, int> Pair;
set<Pair> goals;

int main() {
  cin >> s;
  cin >> gx >> gy;
  goals.insert(Pair(gx, gy));

  bool to_x = true;
  REP(i, s.length()) {
    if (s[i] == 'F') {
      if (to_x) { ++x; } else { ++y; }
    } else {
      if (to_x) {
        vector<Pair> goals2(goals.begin(), goals.last());
        REP(j, goals2.size()) {
          if (goals2[j].second < y) {
            goals2[j].second += 2 * (y - goals2[j].second);
          }
        }
        goals = set(goals2.begin(), goals.last());
        set<Pair> goals_cp(goals);
        for (auto goalp = goals_cp.begin(); goalp != goals_cp.end(); goalp++) {
          goals.insert(Pair(
            goalp->first,
            y + 2*(goalp->second - y)));
        }
        to_x = false;
      } else {
        for (auto goalp = goals.begin(); goalp != goals.end(); ++goalp) {
          if (goalp->first < x) {
            (*goalp).first += 2 * (x - goalp->first);
          }
        }
        set<Pair> goals_cp(goals);
        for (auto goalp = goals_cp.begin(); goalp != goals_cp.end(); goalp++) {
          goals.insert(Pair(
            x + 2*(goalp->first - x),
            goalp->second));
        }
        to_x = true;
      }
    }
  }

  bool f = false;
  for (auto goalp = goals.begin(); goalp != goals.end(); ++goalp) {
    if (x == goalp->first && y == goalp->second) {
      f = true;
      break;
    }
  }
  if (f) {
    ans = "Yes";
  } else {
    ans = "No";
  }

  cout << ans << endl;
  return 0;
}
