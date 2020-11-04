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

ll a, b, m;

ll mulMod(ll a, ll b, ll mod)
{
    if (a == 1)
        return b % mod;
    ll tmp = mulMod(a / 2, b, mod) % mod;
    if (a & 1)
        return (tmp + tmp + b);
    return (tmp + tmp);
}

ll powMod(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1LL;
    if (b == 1)
        return a % mod;
    ll tmp = powMod(a, b / 2, mod) % mod;
    if (b & 1)
        return mulMod(a, mulMod(tmp, tmp, mod), mod);
    return mulMod(tmp, tmp, mod);
}

int main()
{
    // Solve problem (a^b) mod m
    cin >> a >> b >> m;
    cout << powMod(a, b, m);
    return 0;
}