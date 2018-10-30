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

int n, m, T;
int p[maxN], dp[maxN][27], deep[maxN], f[maxN];
vector<int> ke[maxN];

void dfs(int u)
{
  dp[u][0] = p[u];
  fto(i, 1, 20)
  {
    int v = dp[u][i - 1];
    if (dp[v][i - 1])
      dp[u][i] = dp[v][i - 1];
    else
      break;
  }
  fto(i, 0, (int)ke[u].size() - 1)
  {
    int v = ke[u][i];
    if (!p[v])
    {
      p[v] = u;
      deep[v] = deep[u] + 1;
      dfs(v);
    }
  }
}

int goUp(int u, int k)
{
  fdto(i, 20, 0)
  {
    if (k >= (1 << i))
    {
      u = dp[u][i];
      k -= (1 << i);
    }
  }
  return u;
}

int LCA(int u, int v)
{
  if (deep[u] > deep[v])
    swap(u, v);
  v = goUp(v, deep[v] - deep[u]);
  if (u == v)
    return u;
  fdto(i, 20, 0)
  {
    int new_v = dp[v][i];
    int new_u = dp[u][i];
    if (new_u != new_v)
    {
      u = new_u;
      v = new_v;
    }
  }
  return p[u];
}

int main()
{
  scanf("%d", &T);
  fto(iT, 1, T)
  {
    scanf("%d", &n);
    fto(i, 1, n)
    {
      ke[i].clear();
      deep[i] = p[i] = 0;
      fto(j, 0, 20) dp[i][j] = 0;
    }
    fto(u, 1, n)
    {
      int k;
      scanf("%d", &k);
      fto(j, 1, k)
      {
        int v;
        scanf("%d", &v);
        ke[u].pb(v);
      }
    }
    deep[1] = 1;
    dfs(1);
    printf("Case %d:\n", iT);
    scanf("%d", &m);
    fto(i, 1, m)
    {
      int u, v;
      scanf("%d%d", &u, &v);
      printf("%d\n", LCA(u, v));
    }
  }
  return 0;
}