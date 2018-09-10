int Gcd(int a, int b) {
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
