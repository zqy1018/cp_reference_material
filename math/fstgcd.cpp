// O(N)-O(1)
const int N = 1000000, SQRTN = 1000;
int minp[N + 5] = {0}, prime[(N + 5) / 2], tot = 0;
int xa[N + 5], xb[N + 5], xc[N + 5];
int gcd_table[SQRTN + 5][SQRTN + 5];
void build(){
  // combine linear sieve with the preprocessing
  minp[1] = xa[1] = xb[1] = xc[1] = 1;
  for (int i = 2; i <= N; ++i){
    if (!minp[i])
      prime[++tot] = i, minp[i] = i;
    for (int j = 1; j <= tot; ++j){
      if (1ll * i * prime[j] > N || prime[j] > minp[i]) break;
      minp[i * prime[j]] = prime[j];
    }
    int bf = i / minp[i], xxa = xa[bf] * minp[i];
    int xxb = xb[bf], xxc = xc[bf];
    if (xxa >= xxc) 
        xa[i] = xxb, xb[i] = xxc, xc[i] = xxa;
    else {
      xc[i] = xxc;
      if (xxa >= xxb) xa[i] = xxb, xb[i] = xxa;
      else xa[i] = xxa, xb[i] = xxb;
    }
  }
  // build the map
  for (int i = 1; i <= SQRTN; ++i)
    gcd_table[i][0] = gcd_table[0][i] = i;
  for (int i = 1; i <= SQRTN; ++i)
    for (int j = 1; j <= i; ++j)
      gcd_table[i][j] = gcd_table[j][i] = gcd_table[i % j][j];
}
int query(int x, int y){
  int res = 1, tmp;
  if (1ll * xc[x] * xc[x] > x && y % xc[x] == 0)
    y /= xc[x], res *= xc[x];
  else if (1ll * xc[x] * xc[x] <= x){
    tmp = gcd_table[xc[x]][y % xc[x]];
    res *= tmp, y /= tmp;
  }
  tmp = gcd_table[xa[x]][y % xa[x]];
  res *= tmp, y /= tmp;
  tmp = gcd_table[xb[x]][y % xb[x]];
  res *= tmp, y /= tmp;
  return res;
}