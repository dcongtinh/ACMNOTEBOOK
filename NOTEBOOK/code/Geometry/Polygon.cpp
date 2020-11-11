int n, ans = 0;
ii a[maxN];
db s = 0.0;

int check(ii a, ii b, ii c)
{
    int xa = b.fi - a.fi, ya = b.se - a.se;
    int xb = c.fi - b.fi, yb = c.se - b.se;
    if (xa * yb - xb * ya < 0)
        return 1;
    return -1;
}
int main()
{
    cin >> n;
    fto(i, 1, n) cin >> a[i].fi >> a[i].se;
    a[n + 1] = a[1];
    a[n + 2] = a[2];
    //Check đa giác lồi || lõm
    fto(i, 1, n) ans += (check(a[i], a[i + 1], a[i + 2]));
    if (ans == n || ans == -n)
        puts("Da giac loi");
    else
        puts("Da giac lom");
    // Diên tích đa giác
    fto(i, 1, n) s += abs((a[i].fi * a[i + 1].se - a[i + 1].fi * a[i].se));
    printf("%.3f", s / 2);
    return 0;
}