#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int u, v, k;
        cin >> u >> v >> k;
        a[u] += k;
        a[v + 1] -= k;
    }
    for (int i = 1; i <= n; ++i)
        a[i] += a[i - 1];
    for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
    return 0;
}
