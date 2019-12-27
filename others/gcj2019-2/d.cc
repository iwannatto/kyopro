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

// Contransmutation
// ---
const int Mlim = POW_10_5;
int T, M, R[Mlim][2], G[Mlim];

bool active[Mlim];
bool checked[Mlim];
vector<int> rev[Mlim];
int mark[Mlim];
vector<int> sorted;
bool unbounded;
bool cicle[Mlim];
bool kouho[Mlim];

void Visit(int i, int from) {
  if (!active[i]) { return; }
  if (mark[i] == -2) { return; }
  if (mark[i] != -1) {
    if (i != 0) {
      unbounded = true;
      return;
    }
    cicle[0] = true;
    int nnext = from;
    while (nnext != 0) {
      cicle[nnext] = true;
      nnext = mark[nnext];
    }
    if (R[0][0] == from) {
      if (cicle[R[0][1]]) {
        unbounded = true;
        return;
      }
      kouho[R[0][1]] = true;
    } else {
      if (cicle[R[0][0]]) {
        unbounded = true;
        return;
      }
      kouho[R[0][0]] = true;
    }
    int next = from;
    while (next != 0) {
      if (R[next][0] == mark[next]) {
        if (cicle[R[next][1]]) {
          unbounded = true;
          return;
        }
        kouho[R[next][1]] = true;
      } else {
        if (cicle[R[next][0]]) {
          unbounded = true;
          return;
        }
        kouho[R[next][0]] = true;
      }
      next = mark[next];
    }
    return;
  }
  mark[i] = from;
  REP(j, rev[i].size()) {
    int k = rev[i][j];
    if (kouho[k]) {
      unbounded = true;
      return;
    }
    Visit(k, i);
  }
  mark[i] = -2;
  sorted.push_back(i);
}

string Ans() {
  queue<int> q;
  REP(i, M) {
    if (G[i] >= 1) {
      active[i] = true;
      q.push(i);
    }
  }
  while (!q.empty()) {
    int i = q.front(); q.pop();
    if (checked[i]) { continue; }
    int j = R[i][0]; int k = R[i][1];
    active[i] = true; active[k] = true;
    q.push(j); q.push(k);
    checked[i] = true;
  }

  REP(i, M) {
    rev[R[i][0]].push_back(i);
    rev[R[i][1]].push_back(i);
  }
  Visit(0, -3);

  if (unbounded) { return "UNBOUNDED"; }
  if (sorted.size() == 0 || sorted.size() == 1) {
    return to_string(G[0]);
  }
  REP(i, sorted.size()-1) {
    int j = sorted[i];
    int amt = G[j];
    G[j] = 0;
    G[R[j][0]] += amt; G[R[j][0]] %= MOD;
    G[R[j][1]] += amt; G[R[j][1]] %= MOD;
  }

  return to_string(G[0]);
}

signed main() {
  cin >> T;
  FOR(caseno, 1, T) {
    cin >> M;
    REP(i, M) {
      cin >> R[i][0] >> R[i][1];
      --R[i][0]; --R[i][1];
    }
    REP(i, M) { cin >> G[i]; }

    REP(i, M) { active[i] = false; }
    REP(i, M) { checked[i] = false; }
    REP(i, M) { rev[i].clear(); }
    REP(i, M) { mark[i] = -1; }
    sorted.clear();
    unbounded = false;
    REP(i, M) { cicle[i] = false; }
    REP(i, M) { kouho[i] = false; }

    auto ans = Ans();

    cout << "Case #" << caseno << ": ";
    cout << ans << endl;
  }

  return 0;
}
