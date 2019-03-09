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

// const int kMaxN;

string S;
string ans;

string Ans() {
  if (S.length() < 26) {
    REP(i, 26) {
      if (S.find('a'+i) == string::npos) {
        S.push_back('a'+i);
        return S;
      }
    }
  } else {
    if (S == "zyxwvutsrqponmlkjihgfedcba") { return "-1"; }

    priority_queue<char, vector<char>, greater<char>> q;
    char m = 'a'-1;
    while (true) {
      char lst = S[S.length()-1];
      q.push(lst);
      m = MAX(m, lst);
      S.pop_back();

      if (S[S.length()-1] < m) {
        while (true) {
          if (S[S.length()-1] < q.top()) {
            S[S.length()-1] = q.top();
            return S;
          } else {
            q.pop();
          }
        }
      }
    }
  }
  return "-1";
}

signed main() {
  cin >> S;

  ans = Ans();

  cout << ans << endl;
  return 0;
}
