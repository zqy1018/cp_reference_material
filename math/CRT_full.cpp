ll extCRT(ll m[], ll b[], int n){
    ll M = m[1], ans = b[1], x, y;
    for (int i = 2; i <= n; ++i){
        ll d = extgcd(M, m[i], x, y), a_ = (b[i] - ans) % m[i];
        if (a_ < 0) a_ += m[i];
        if (a_ % d) return NO_SOLUTION;
        x = fstmul(x, a_ / d, m[i] / d);
        if (x < 0) x += m[i] / d;
        ll MM = M;
        M /= d, M *= m[i];
        ans = (ans + fstmul(x, MM, M)) % M;
        if (ans < 0) ans += M;
    }
    return ans;
}