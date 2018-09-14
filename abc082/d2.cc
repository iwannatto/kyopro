#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)

const int kMaxS = 8000;

// waになる理由が全くわからない　ロジックは合っているはずなのだが

string s;
int x, y;
string ans = "";

vector<int> section = {0};
int n = 2*kMaxS + 1;
int dpx[8000][16001];
int dpy[8000][16001];

int main() {
  cin >> s;
  cin >> x >> y;

  int sec_i = 0;
  REP(i, s.length()) {
    if (s[i] == 'F') {
      ++section[sec_i];
    } else {
      section.push_back(0);
      ++sec_i;
    }
  }

  dpx[0][8001] = 1;
  REP(i, (section.size()+1) / 2) {
    REP(j, n) {
      if (j-section[i*2] >= 0) {
        dpx[i+1][j] = dpx[i+1][j] || dpx[i][j-section[i*2]];
      }
      if (j+section[i*2] < n) {
        dpx[i+1][j] = dpx[i+1][j] || dpx[i][j+section[i*2]];
      }
    }
  }

  dpy[0][8001] = 1;
  REP(i, section.size()/2) {
    REP(j, n) {
      if (j-section[i*2 + 1] >= 0) {
        dpy[i+1][j] = dpy[i+1][j] || dpy[i][j-section[i*2 + 1]];
      }
      if (j+section[i*2 + 1] < n) {
        dpy[i+1][j] = dpy[i+1][j] || dpy[i][j+section[i*2 + 1]];
      }
    }
  }

  // REP(i, section.size()-1/2) {
  //   REP(j, n) {
  //     cout << "dpx " << i << " " << j << "  " << dpx[i][j] << endl;
  //   }
  // }

  if (dpx[(section.size()+1) / 2][x+8001] && dpy[section.size()/2][y+8001]) {
    ans = "Yes";
  } else {
    ans = "No";
  }

  cout << ans << endl;
  return 0;
}
