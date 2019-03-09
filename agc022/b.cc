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

const int kMaxN = 20000;

int N;
vector<int> S;

int d[10] = {2, 3, 4, 5, 6, 8, 9, 10, 12, 14};

void Ans() {
  if (N == 3) {
    vector<int> S2 = {2, 5, 63};
    S = S2;
    return;
  }

  S.push_back(2);
  S.push_back(3);
  S.push_back(5);
  S.push_back(20);
  N -= 4;
  int base = 30;
  while (N >= 21) {
    S.push_back(base);
    REP(i, 10) {
      S.push_back(base+d[i]);
      S.push_back(base+30-d[i]);
    }
    base += 30;
    N -= 21;
  }
  if (N%2 == 1) {
    S.push_back(base);
    --N;
  }
  REP(i, N/2) {
    S.push_back(base+d[i]);
    S.push_back(base+30-d[i]);
  }
  return;
}

signed main() {
  cin >> N;
  S.reserve(kMaxN);

  Ans();

  REP(i, S.size()-1) { cout << S[i] << " "; }
  cout << S[S.size()-1] << endl;
  return 0;
}
