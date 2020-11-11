#include <bits/stdc++.h>
#define fto(i, x, y) for (int i = (x); i <= (y); ++i)

using namespace std;

int n, k, a[100];

void _try(int i)
{
    if (i > k)
    {
        fto(j, 1, k) cout << a[j] << " ";
        cout << endl;
        return;
    }
    fto(j, a[i - 1] + 1, n - k + i)
    {
        a[i] = j;
        _try(i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin.precision(10);
    cout << fixed;
    cin >> n >> k;
    _try(1);
    return 0;
}