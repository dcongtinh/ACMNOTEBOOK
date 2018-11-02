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

int n, a[maxN], lis_id[maxN], trace[maxN];
vi f;

void printlis(int i)
{
    if (i == -1)
        return;
    printlis(trace[i]);
    printf("%d ", a[i]);
}
int main()
{
    cin >> n;
    fto(i, 1, n)
    {
        cin >> a[i];
        vi::iterator it = lower_bound(f.begin(), f.end(), a[i]);
        int pos = it - f.begin();
        if (it == f.end())
            f.pb(a[i]);
        else
            *it = a[i];
        lis_id[pos] = i;
        trace[i] = (pos > 0 ? lis_id[pos - 1] : -1);
    }
    cout << f.size() << endl;
    //printlis(lis_id[f.size()-1]);
}
