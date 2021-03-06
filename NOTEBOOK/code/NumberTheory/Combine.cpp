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

int comb[1001][1001];

void calc_combination()
{
    comb[0][0] = 1;
    fto(i, 1, 1000)
    {
        fto(j, 0, i)
        {
            if (j == 0)
                comb[i][j] = 1;
            else
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % oo;
        }
    }
}

int main()
{
    calc_combination();

    int q;
    cin >> q;

    while (q--)
    {
        int n, r;
        cin >> n >> r;
        cout << comb[n][r] << "\n";
    }
    return 0;
}