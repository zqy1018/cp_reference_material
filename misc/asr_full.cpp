double F(double x); 
double calc(double l, double r){
    return (F(l) + 4 * F((l + r) / 2.) + F(r)) * (r - l) / 6.;
}
double asr(double l, double r, double A){
    double mid = (l + r) / 2.;
    double sl = calc(l, mid), sr = calc(mid, r);
    if (fabs(sl + sr - A) / 15. < eps) return sl + sr + (sl + sr - A) / 15.;
    return asr(l, mid, sl) + asr(mid, r, sr);
}
double asr(double l, double r){ // call this
    return asr(l, r, calc(l, r));
}