// 有 __int128 请用 __int128 ！！！不要冒险！！！
inline ll fstmul(ll a, ll b, ll M){
  a %= M, b %= M;
  return (a * b - (ll)((long double)a / M * b) * M + M) % M;
}