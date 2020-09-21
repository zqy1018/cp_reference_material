class Factorization{
    typedef long long ll;
    const ll prime[12];
    vector<ll> res;
    // gcd, poww, fstmul 自己写
    bool witness(ll a, ll n, ll t, ll u){
        ll x = poww(a, u, n);
        for (ll i = 0; i < t; ++i){
            ll xx = fstmul(x, x, n);
            if (xx == 1 && x != 1 && x != n - 1)
                return true;
            x = xx;
        }
        if (x != 1) return true;
        return false;
    }
    bool miller_rabin(ll n){
        for (int i = 0; i < 12; ++i)
            if (n % prime[i] == 0){
                if (n == prime[i]) return true;
                return false;
            }
        ll t = 0, u = n - 1;
        while (!(u & 1ll)) ++t, u >>= 1;
        for (int i = 0; i < 12; ++i)
            if (witness(prime[i], n, t, u)) 
                return false;
        return true;
    }
    ll rho(ll n, ll c){
        ll x = rand();
        ll y = x, d = 1, q = 1;
        for (int k = 2; d == 1; k <<= 1, y = x, q = 1){
            for (int i = 0; i < k; ++i){
                x = fstmul(x, x, n) + c;
                if (x >= n) x -= n;
                ll Abs = (x > y) ? x - y : y - x;
                q = fstmul(q, Abs, n);
                if (!(i & 127)){
                    d = gcd(q, n);
                    if (d > 1) return d;
                }
            }
            d = gcd(q, n);
        }
        return d;
    }
    ll Pollard(ll n){
        for (int i = 0; i < 12; ++i)
            if (n % prime[i] == 0)
                return prime[i];
        ll d = n;
        while (d == n)
            d = rho(n, rand() % (n - 1) + 1);    
        return d;
    }
    void findD(ll n){
        if (miller_rabin(n)){
            res.push_back(n);
            return ;
        } else {
            ll d = Pollard(n);
            findD(d), findD(n / d);
        }
    }
public:
    Factorization(): prime{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}{}
    vector<ll> get(ll n, bool need_unique){
        res.clear();
        srand(time(NULL));
        findD(n);
        sort(res.begin(), res.end());
        if (need_unique){
            int n = unique(res.begin(), res.end()) - res.begin();
            while ((int)res.size() > n)
                res.pop_back();
        }
        return res;
    } 
};