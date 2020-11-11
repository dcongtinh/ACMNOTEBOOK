#include <bits/stdc++.h>
#define maxN 300005

using namespace std;

int n, q;
int f[maxN], ans = 0, a[maxN];

void update(int x, int inc)
{
    while (x <= n)
    {
        f[x] += inc;
        x += x & (-x);
    }
}

int get(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += f[x];
        x -= x & (-x);
    }
    return ans;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        update(i, a[i]);
    }
    cin >> q;
    while (q--)
    {
        int t, i, l, r, k;
        cin >> t;
        if (t == 1)
        {
            cin >> i >> k;
            update(i, k);
        }
        else
        {
            cin >> l >> r;
            cout << get(r) - get(l - 1) << endl;
        }
    }
}
