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

inline ll Rand(ll l, ll h)
{
  return l + ((ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
              (ll)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
              (ll)rand() * (RAND_MAX + 1) +
              rand()) %
                 (h - l + 1);
}

inline void fastRead(string &s)
{
  char tmp[maxN];
  scanf("%s", tmp);

  s.assign(tmp);
  s = '#' + s;

  return;
}

int main()
{
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin.precision(10);
  cout << fixed;

  return 0;
}