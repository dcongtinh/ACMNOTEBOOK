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

int a[maxN], n, T;
ii nodes[4 * maxN];

void initIT(int root, int l, int r)
{
    if (l == r)
        nodes[root] = mp(a[l], -1);
    else
    {
        int m = (l + r) / 2;
        initIT(2 * root, l, m);
        initIT(2 * root + 1, m + 1, r);
        nodes[root].fi = nodes[2 * root].fi + nodes[2 * root + 1].fi;
        nodes[root].se = -1;
    }
}

void updateIT(int root, int l, int r, int i, int j, int x)
{
    if (i <= l && r <= j)
    {
        nodes[root].fi = (r - l + 1) * x;
        nodes[root].se = x;
        return;
    }
    if (i > r || j < l)
        return;
    int m = (l + r) / 2;
    if (nodes[root].se != -1)
    {
        int mem = nodes[root].se;
        nodes[2 * root].fi = (m - l + 1) * mem;
        nodes[2 * root + 1].fi = (r - m) * mem;
        nodes[2 * root].se = nodes[2 * root + 1].se = mem;
        nodes[root].se = -1;
    }
    updateIT(2 * root, l, m, i, j, x);
    updateIT(2 * root + 1, m + 1, r, i, j, x);
    nodes[root].fi = nodes[2 * root].fi + nodes[2 * root + 1].fi;
}

int queryIT(int root, int l, int r, int i, int j)
{
    if (i <= l && r <= j)
        return nodes[root].fi;
    if (i > r || j < l)
        return 0;
    int m = (l + r) / 2;
    if (nodes[root].se != -1)
    {
        int mem = nodes[root].se;
        nodes[2 * root].fi = (m - l + 1) * mem;
        nodes[2 * root + 1].fi = (r - m) * mem;
        nodes[2 * root].se = nodes[2 * root + 1].se = mem;
        nodes[root].se = -1;
    }
    return queryIT(2 * root, l, m, i, j) + queryIT(2 * root + 1, m + 1, r, i, j);
}

int main()
{
    scanf("%d%d", &n, &T);
    fto(i, 1, n) scanf("%d", &a[i]);
    initIT(1, 1, n);
    while (T--)
    {
        int p, i, j, val;
        scanf("%d%d%d", &p, &i, &j);
        if (p == 1)
        {
            scanf("%d", &val);
            updateIT(1, 1, n, i, j, val);
        }
        else
            printf("%d\n", queryIT(1, 1, n, i, j));
    }
    return 0;
}
