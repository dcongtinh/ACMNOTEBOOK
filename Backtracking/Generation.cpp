#include <bits/stdc++.h>

using namespace std;

int a[15], n;

void generate(int i)
{
    if (i > n)
    {
        for (int k = 1; k <= n; ++k)
            cout << a[k];
        cout << endl;
        return;
    }
    for (int j = 0; j <= 1; ++j)
    {
        a[i] = j;
        generate(i + 1);
    }
}

int main()
{
    cin >> n;
    generate(1);
    return 0;
}
