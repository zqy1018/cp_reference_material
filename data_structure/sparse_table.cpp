int n, f[100005][18], a[100005], logg[100005];
void build_ST(){
    logg[0] = -1;
    for(int i = 1; i <= n; ++i)
        f[i][0] = a[i], logg[i] = logg[i >> 1] + 1;
    for(int i = 1; i <= logg[n]; ++i){
        int p = (1 << i);
        for(int j = 1; j + p - 1 <= n; ++j)
            f[j][i] = max(f[j][i - 1], f[j + (p >> 1)][i - 1]);
    }
}
int query(int l, int r){
    assert(r >= l);
    int od = logg[r - l + 1];
    return max(f[l][od], f[r - (1 << od) + 1][od]);
}