#include <bits/stdc++.h>
#define fto(i, x, y) for (int i = (x); i <= (y); ++i)
#define fdto(i, x, y) for (int i = (x); i >= (y); --i)
#define forit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(it, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define DEBUG(x)         \
  {                      \
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

int n, m, root, child, dfsCnt = 0;
int low[maxN], num[maxN], parent[maxN];
bool khop[maxN];
vi ke[maxN];
vii cau;

void dfs(int u)
{
  num[u] = low[u] = ++dfsCnt;
  fto(i, 0, (int)ke[u].size() - 1)
  {
    int v = ke[u][i];
    if (!num[v])
    {
      if (u == root)
        ++child;
      parent[v] = u;
      dfs(v);
      low[u] = min(low[u], low[v]);
      if (low[v] >= num[u])
        khop[u] = true;
      if (low[v] > num[u])
        cau.pb(mp(u, v));
    }
    else if (parent[u] != v)
      low[u] = min(low[u], num[v]);
  }
}

int main()
{
  scanf("%d%d", &n, &m);
  fto(i, 1, m)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    ke[u].pb(v);
    ke[v].pb(u);
  }
  fto(u, 1, n)
  {
    if (!num[u])
    {
      root = u;
      child = 0;
      dfs(u);
      khop[u] = (child > 1);
    }
  }
  int nKhop = 0;
  fto(i, 1, n) nKhop += khop[i];
  printf("%d %d", nKhop, cau.size());

  return 0;
}