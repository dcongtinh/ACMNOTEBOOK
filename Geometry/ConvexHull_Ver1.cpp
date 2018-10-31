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

ii origin;

void operator-=(ii &A, ii B)
{
    A.fi -= B.fi;
    A.se -= B.se;
}
bool ccw(ii O, ii A, ii B)
{
    A -= O, B -= O;
    return A.fi * B.se > A.se * B.fi;
}

bool cmp(ii A, ii B) { return ccw(origin, A, B); }

int n;
ii a[12309];

int main()
{
    int i, t;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d%d", &a[i].fi, &a[i].se);
    sort(a + 1, a + n + 1);
    origin = a[1];
    sort(a + 2, a + n + 1, cmp);
    a[0] = a[n];
    a[n + 1] = a[1];
    int j = 1;
    for (i = 1; i <= n + 1; i++)
    { // a[1] and a[n+1] will be both added
        while (j > 2 && !ccw(a[j - 2], a[j - 1], a[i]))
            j--;
        a[j++] = a[i];
    }
    n = j - 2;
    for (i = 1; i <= n; i++)
        printf("%d %d\n", a[i].fi, a[i].se);
}
