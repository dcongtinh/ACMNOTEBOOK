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

int n, m, low[maxN], num[maxN], dfsCount = 0, ans = 0;
vector<int> ke[maxN];
stack<int> q;
bool vis[maxN];

void visit(int u)
{
    num[u] = low[u] = ++dfsCount;
    int m = (int)ke[u].size();
    q.push(u);
    fto(i, 0, m - 1)
    {
        int v = ke[u][i];
        if (!vis[v])
        {
            if (num[v] == 0)
            {
                visit(v);
                low[u] = min(low[u], low[v]);
            }
            else
                low[u] = min(low[u], num[v]);
        }
    }
    if (num[u] == low[u])
    {
        ++ans;
        int v;
        do
        {
            v = q.top();
            q.pop();
            vis[v] = true;
        } while (v != u);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    fto(i, 0, m - 1)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v);
    }
    fto(u, 1, n)
    {
        if (num[u] == 0)
            visit(u);
    }
    cout << ans;
    return 0;
}