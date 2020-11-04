#include <bits/stdc++.h>
#define fto(i, x, y) for (int i = (x); i <= (y); ++i)
#define fdto(i, x, y) for (int i = (x); i >= (y); --i)
#define forit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(it, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define DEBUG(x)             \
    {                        \
        cout << #x << " = "; \
        cout << (x) << endl; \
    }
#define pb push_back
#define mp make_pair
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define ll long long
#define db double
#define EPS 1e-9
#define oo 1000000007
#define maxN 100005

using namespace std;

lld a, b, c, d, maxX = 0LL, ans = 0LL;

pair<lld, lld> Extended_gcd(int a, int b)
{
    lld m = a, n = b;
    lld xm = 1, xn = 0;
    while (n)
    {
        lld q = m / n;
        lld r = m - q * n;
        lld xr = xm - q * xn;
        m = n;
        xm = xn;
        n = r;
        xn = xr;
    }
    return mp(m, xm);
}

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    d = Extended_gcd(a, b).fi;
    if (c % d)
        ans = 0;
    else
    {
        lld p = b / d;
        lld xm = Extended_gcd(a, b).se;
        xm *= (c / d);
        xm = (xm % p + p) % p;
        maxX = (c - b) / a;
        if (maxX < xm)
            ans = 0;
        else
        {
            ans = (maxX - xm) / p + 1;
            if (xm == 0)
                --ans;
        }
    }
    printf("%lld", ans);
    return 0;
}