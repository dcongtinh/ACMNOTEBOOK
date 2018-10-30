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

pair<int, ii> a[maxN];
int n, m;

struct UFDS
{
  int pset[maxN], numSet;
  int Rank[maxN];
  int setRank[maxN];
  void initSet(int n)
  {
    fto(i, 1, n) pset[i] = i, setRank[i] = 1;
    numSet = n;
  }
  int findSet(int u)
  {
    return ((pset[u] == u) ? u : pset[u] = findSet(pset[u]));
  }
  bool isSameSet(int u, int v)
  {
    return findSet(u) == findSet(v);
  }
  void unionSet(int u, int v)
  {
    if (!isSameSet(u, v))
    {
      int x = findSet(u), y = findSet(v);
      if (x != y)
      {
        if (setRank[x] > setRank[y])
          swap(x, y);
        setRank[y] += setRank[x];
        pset[x] = y;
      }
      --numSet;
    }
  }
  int setOfRank(int u)
  {
    return setRank[findSet(u)];
  }
  int numOfSet()
  {
    return numSet;
  }
} tree;

int main()
{
  cin >> n >> m;
  fto(i, 0, m - 1)
  {
    int u, v, w;
    cin >> u >> v >> w;
    a[i] = mp(w, mp(u, v));
  }
  sort(a, a + m);
  ll ans = 0;
  tree.initSet(n);
  int cnt = 0;
  fto(i, 0, m - 1)
  {
    int u = a[i].se.fi, v = a[i].se.se;
    int w = a[i].fi;
    if (tree.isSameSet(u, v))
      continue;
    tree.unionSet(u, v);
    ans += w;
    if (tree.setOfRank(u) == n)
      break;
  }
  cout << ans;
  return 0;
}
