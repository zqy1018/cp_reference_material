// ax+by=gcd(a, b)
ll extgcd(ll a, ll b, ll &x, ll &y){
    ll d;
    if (b == 0){
        d = a, x = 1, y = 0;
    } else {
        d = extgcd(b, a % b, y, x);
        y -= x * (a / b);
    }
    return d;
}
// find minimal non-negative x so that ax+by=c
ll solve(ll a, ll b, ll c){
    ll x, y;
    ll d = extgcd(a, b, x, y);
    if (c % d != 0) return NO_SOLUTION;
    x *= (c / d), y *= (c / d);
    ll t = b / d;
    x = (x % t + t) % t;
    return x;
}