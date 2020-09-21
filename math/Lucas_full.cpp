// first 记录的是阶乘模 P 的值，second 记录该阶乘中 p 的指数
pair<ll, ll> mod_fac(ll n, ll p, ll bigp){
    if (n == 0) return make_pair(1, 0);
    pair<ll, ll> res = mod_fac(n / p, p, bigp);
    ll fir = res.first * poww(fac[bigp], n / bigp, bigp) % bigp;
    fir = fir * fac[n % bigp] % bigp;
    return make_pair(fir, res.second + n / p);
}
ll extLucas(ll n, ll m, ll p, ll k, ll bigp){
    ll cnt = 1;
    fac[0] = 1;
    for (ll i = 1; i <= bigp; ++i){
        if (cnt == p) cnt = 1, fac[i] = fac[i - 1];
        else cnt++, fac[i] = fac[i - 1] * i % bigp;
    }
    pair<ll, ll> fz = mod_fac(n, p, bigp);
    pair<ll, ll> fm1 = mod_fac(m, p, bigp);
    pair<ll, ll> fm2 = mod_fac(n - m, p, bigp);
    if (fz.second - fm1.second - fm2.second >= k) return 0;
    ll ps = poww(p, fz.second - fm1.second - fm2.second, bigp);
    ps = ps * fz.first % bigp;
    ps = ps * inv(fm1.first, bigp) % bigp;
    ps = ps * inv(fm2.first, bigp) % bigp;
    return ps;
}
// 求 C(n, m) mod p^k 时，调用 extLucas(n, m, p, k, p^k)