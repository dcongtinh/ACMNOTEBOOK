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

int n, m, s, t, f[maxN][maxN], c[maxN][maxN], delta[maxN], trace[maxN];

bool FindPath()
{
  fto(u, 1, n) trace[u] = 0;
  trace[s] = s;
  delta[s] = oo;
  queue<int> q;
  q.push(s);
  while (!q.empty())
  {
    int u = q.front();
    q.pop();
    fto(v, 1, n)
    {
      if (!trace[v])
      {
        if (c[u][v] > f[u][v])
        {
          trace[v] = u;
          delta[v] = min(delta[u], c[u][v] - f[u][v]);
          q.push(v);
        }
        else if (f[v][u])
        {
          trace[v] = -u;
          delta[v] = min(delta[u], f[v][u]);
          q.push(v);
        }
      }
    }
  }
  return trace[t];
}

void IncFlow()
{
  int v = t;
  while (v != s)
  {
    int u = trace[v];
    if (u > 0)
      f[u][v] += delta[t];
    else
    {
      u = -u;
      f[v][u] -= delta[t];
    }
    v = u;
  }
}

int main()
{
  scanf("%d%d%d%d", &n, &m, &s, &t);
  fto(i, 0, m - 1)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    c[u][v] = w;
  }

  while (FindPath())
    IncFlow();
  int ans = 0;
  fto(i, 1, n) if (f[s][i]) ans += f[s][i];
  printf("%d", ans);
  return 0;
}