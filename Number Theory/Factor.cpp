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

int n, T;
int minPrime[maxN];

void findMinPrime()
{
    fto(i, 2, maxN)
    {
        if (!minPrime[i])
        {
            fto(j, 2, maxN / i)
            {
                if (!minPrime[i * j])
                    minPrime[i * j] = i;
            }
        }
    }
    fto(i, 2, maxN)
    {
        if (!minPrime[i])
            minPrime[i] = i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.precision(10);
    cout << fixed;
    findMinPrime();

    vi p;
    cin >> n;
    while (n != 1)
    {
        p.pb(minPrime[n]);
        n /= minPrime[n];
    }
    for (auto it : p)
        cout << it << " ";

    return 0;
}