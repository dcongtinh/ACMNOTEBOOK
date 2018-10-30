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

vector<pair<int, int>> ke[maxN];
list<int> cyc;
int n, m, k = 0, a[105];

void EulerTour(list<int>::iterator it, int u)
{
    int v = 0;
    for (int i = 0; i < ke[u].size(); ++i)
    {
        pair<int, int> e = ke[u][i];
        if (e.second)
        {
            v = e.first;
            ke[u][i].second = 0;
            for (int j = 0; j < ke[v].size(); ++j)
            {
                if (ke[v][j].second && ke[v][j].first == u)
                {
                    ke[v][j].second = 0;
                    break;
                }
            }
            EulerTour(cyc.insert(it, u), v);
        }
    }
}

int main()
{

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].push_back(make_pair(v, 1));
        ke[v].push_back(make_pair(u, 1));
    }
    for (int i = 1; i <= n; ++i)
        sort(ke[i].begin(), ke[i].end());

    list<int>::iterator it = cyc.begin();

    EulerTour(it, 1);

    for (list<int>::iterator it = cyc.begin(); it != cyc.end(); ++it)
        a[k++] = *it;

    for (int i = k - 1; i >= 0; --i)
        printf("%d ", a[i]);
    printf("1");
    return 0;
}
