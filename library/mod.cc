// Mod Requirements
#include <vector>
using namespace std;

// Mod begin
class Mod {
public:
  // 全部 mod p で考える。
  // Combを使うにはpが素数である必要がある。
  int p;
  vector<int> fact;
  Mod(int p) : p(p), fact{1} {}

  int Fact(int n) {
    if (n % p > fact.size() - 1) {
      int i = fact.size();
      fact.resize(n % p + 1);
      for (; i <= n % p; ++i) {
        fact[i] = (fact[i-1] * i) % p;
      }
    }
    return fact[n];
  }

  // n! = a * p^e の a mod p をreturnしeを変更で返す
  int ModFact(int n, int& e) {
    e = 0;
    if (n == 0) { return 1; }

    int res = ModFact(n / p, e);
    e += n / p;

    if ((n / p) % 2 == 0) {
      return (res * Fact(n % p)) % p;
    } else {
      return (res * (p - Fact(n % p))) % p;
    }
  };

  int Extgcd(int a, int b, int& x, int& y) {
    int d = a;
    if (b != 0) {
      d = Extgcd(b, a % b, y, x);
      y -= (a / b) * x;
    } else {
      x = 1; y = 0;
    }
    return d;
  };

  // 一般的すぎるので繰り返し自乗法とかにしてもいいかも
  int Inv(int n) {
    int x, y;
    Extgcd(n, p, x, y);
    return ((p + x) % p) % p;
  };

  int Comb(int n, int k) {
    if (n < 0 || k < 0 || n < k) { return 0; }
    int e1, e2, e3;
    int a1 = ModFact(n, e1), a2 = ModFact(k, e2), a3 = ModFact(n - k, e3);
    if (e1 > e2 + e3) {
      return 0;
    } else {
      return (a1 * Inv((a2 * a3) % p)) % p;
    }
  };
};
// Mod end

// Mod test
#include <iostream>
int Ans() {
  Mod m(10007);
  // int e;
  return m.Comb(10, 4);
}
signed main() {
  // cin >>

  auto ans = Ans();

  cout << ans << endl;
  return 0;
}
