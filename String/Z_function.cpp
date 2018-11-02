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

int z[maxN], n;
string s1, s2, s = "";

int main()
{
    getline(cin, s1);
    getline(cin, s2);
    s = s2 + "#" + s1;
    int n = s.length();
    z[0] = n;
    int l = 0, r = 0;
    fto(i, 1, n - 1)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && s[r] == s[r - l])
                ++r;
            z[i] = r - l;
            --r;
        }
        else
        {
            int k = i - l;
            if (z[k] < r - i + 1)
                z[i] = z[k];
            else
            {
                l = i;
                while (r < n && s[r] == s[r - l])
                    ++r;
                z[i] = r - l;
                --r;
            }
        }
    }
    int t = s1.length();
    int k = s2.length();

    fto(i, k + 1, n - 1) if (z[i] >= k) printf("%d ", i - k);
    return 0;
}
