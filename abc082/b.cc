#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)

string s, t;
string ans = "";

int main() {
  cin >> s >> t;

  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), greater<char>());
  if (s < t) {
    ans = "Yes";
  } else {
    ans = "No";
  }

  cout << ans << endl;
  return 0;
}
