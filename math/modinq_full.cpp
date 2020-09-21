ll modinq(ll m, ll d, ll l, ll r){
    if (r < l) return NO_SOLUTION;
    if (l == 0) return 0;
    if (d == 0) return NO_SOLUTION;
    if ((r / d) * d >= l) return (l - 1) / d + 1;
    ll res = modinq(d, m % d, (d - r % d) % d, (d - l % d) % d);
    return res == NO_SOLUTION ? NO_SOLUTION : (m * res + l - 1) / d + 1;
}