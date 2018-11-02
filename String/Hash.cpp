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
#define vll vector<ll>
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define ll long long
#define db double
#define EPS 1e-9
#define oo 1000000007
#define maxN 100005

using namespace std;

vll modPrime = {1000000003LL};
ll basePower[7][7][1000007];
ll p[3][7][7][1000007];

int times = 5;

inline ll Rand(ll l, ll h)
{
    return l + ((ll)rand() * ((ll)RAND_MAX + 1) * ((ll)RAND_MAX + 1) * ((ll)RAND_MAX + 1) +
                (ll)rand() * ((ll)RAND_MAX + 1) * ((ll)RAND_MAX + 1) +
                (ll)rand() * ((ll)RAND_MAX + 1) +
                (ll)rand()) %
                   (h - l + 1);
}

/// idx - index of string, (i, j) - position of character in this string
inline vll getHash(const int &idx, const int &i, const int &j)
{
    vll ans;
    fto(u, 0, times - 1)
    {
        fto(v, 0, (int)modPrime.size() - 1)
        {
            ll tmp = p[idx][u][v][j] - p[idx][u][v][i - 1] * basePower[u][v][j - i + 1];
            tmp += modPrime[v] * modPrime[v];
            ans.pb(tmp % modPrime[v]);
        }
    }
    return ans;
}

void in(vll a)
{
    for (auto it : a)
        cout << it << " ";
    cout << endl;
}
int main()
{
    // srand (time(NULL));
    vector<string> s;
    s.resize(2);

    getline(cin, s[0]);
    getline(cin, s[1]);

    s[0] = "#" + s[0];
    s[1] = "#" + s[1];

    int modLen = (int)modPrime.size();
    int _max =  max(s[0].size(), s[1].size()) - 1;

    ///Build Hash
    fto(i, 0, times - 1)
    {
        ///Random base
        int base_num = 26;

        ///Build power of base
        fto(j, 0, modLen - 1) basePower[i][j][0] = 1LL;
        fto(j, 0, modLen - 1)
        {
            fto(k, 1, 5)
            {
                basePower[i][j][k] = (base_num * basePower[i][j][k - 1]) % modPrime[j];
                cout << basePower[i][j][k] << " ";
            }
        }

        ///Change string to number
        fto(idx, 0, s.size() - 1)
        {
            fto(j, 0, modLen - 1)
            {
                int n = (int)s[idx].size();
                fto(k, 1, n)
                {
                    p[idx][i][j][k] = (base_num * p[idx][i][j][k - 1] + s[idx][k] - 'a' + 1) % modPrime[j];
                }
            }
        }
    }

    ///Get hashNum of second string

    vll res = getHash(1, 1, (int)s[1].size());
    vi sol;

    ///Try for each position in first string
    fto(i, 1, (int)s[0].size())
    {
        if (i + (int)s[1].size() - 2 > (int)s[0].size() - 1)
            break;
        vll tmp = getHash(0, i, i + (int)s[1].size() - 1);
        if (tmp == res)
            sol.pb(i);
    }

    forit(it, sol) printf("%d ", *it);
    return 0;
}