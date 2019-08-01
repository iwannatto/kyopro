int Gcd(int a, int b) {
  if (b > a) { return Gcd(b, a); }
  if (b == 0) { return a; }
  return Gcd(b, a%b);
}

int Pow(int a, int b) {
  int r = 1;
  while (b > 0) {
    if (b&1) { r *= a; }
    a *= a;
    b >>= 1;
  }
  return r;
}

int PowMod(int a, int b, int m) {
  int r = 1;
  while (b > 0) {
    if (b&1) { r = r*a % m; }
    a = a*a % m;
    b >>= 1;
  }
  return r;
}

map<int, int> PrimeFactor(int n) {
  map<int, int> prime_factor;
  for (int i = 2; i*i <= n; ++i) {
    while (n%i == 0) {
      ++prime_factor[i];
      n /= i;
    }
  }
  if (n != 1) { prime_factor[n] = 1; }
  return prime_factor;
}

void P1(int a) {
  cout << a << endl;
  return;
}

void P2(int a, int b) {
  cout << a << " " << b << endl;
  return;
}

void P3(int a, int b, int c) {
  cout << a << " " << b << " " << c << endl;
  return;
}
