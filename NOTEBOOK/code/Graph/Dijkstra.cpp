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
#define oo 1000000007
#define maxN 100005

using namespace std;

int n, m, s, t;
int d[maxN], trace[maxN];
vii ke[maxN];

void dijkstra(int s, int t)
{
    fto(i, 1, n) d[i] = oo;
    d[s] = 0;
    set<ii> q;
    q.insert(mp(d[s], s));
    while (!q.empty())
    {
        ii top = *q.begin();
        q.erase(top);
        int u = top.se;
        fto(i, 0, ke[u].size() - 1)
        {
            int v = ke[u][i].fi;
            int w = ke[u][i].se;
            if (d[v] > d[u] + w)
            {
                q.erase(mp(d[v], v));
                d[v] = d[u] + w;
                trace[v] = u;
                q.insert(mp(d[v], v));
            }
        }
    }
}

void print(int s, int t)
{
    if (s == t)
        return;
    print(s, trace[t]);
    printf("%d ", t);
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    fto(i, 1, m)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        ke[u].pb(mp(v, w));
        ke[v].pb(mp(u, w));
    }
    dijkstra(s, t);

    printf("%d ", s);
    print(s, trace[t]);
    printf("%d ", t);
    return 0;
}