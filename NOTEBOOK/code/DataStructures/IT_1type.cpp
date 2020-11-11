// Update [l, r] to k
#include <bits/stdc++.h>
#define maxN 500005
#define oo 1000000007

using namespace std;

int n, q;
int a[maxN];

struct Node
{
    int val;
    int lazy;
    Node()
    {
        val = 0, lazy = -1;
    }
    Node(int v, int l)
    {
        val = v, lazy = l;
    }
};

Node node[4 * maxN];

void initIT(int k, int l, int r)
{
    if (l == r)
    {
        node[k] = Node(a[l], -1);
        return;
    }
    int m = (l + r) / 2;
    initIT(2 * k, l, m);
    initIT(2 * k + 1, m + 1, r);
    node[k].val = node[2 * k].val + node[2 * k + 1].val;
    node[k].lazy = -1;
}

void down(int k, int l, int r)
{
    //Lazy Update || Lazy Propagation
    int v = node[k].lazy;
    if (v != -1)
    {
        int m = (l + r) / 2;
        // Increasing each value in range [a, b] by x.
        node[2 * k].val += (m - l + 1) * v;
        node[2 * k + 1].val += (r - m) * v;

        // Setting each value in range [a, b] to x.
        // node[2 * k].val = (m - l + 1) * v;
        // node[2 * k + 1].val = (r - m) * v;
        node[2 * k].lazy = node[2 * k + 1].lazy = v;

        // Just increase each value in range [a, b] by x and find Min, Max
        // Keep value not SUM
        // node[2 * k].val += v;
        // node[2 * k + 1].val += v;
        // node[2 * k].lazy += v;
        // node[2 * k + 1].lazy += v;

        // Like above but set each value in range [a, b] to x.
        // node[2 * k].val = v;
        // node[2 * k + 1].val = v;
        // node[2 * k].lazy += v;
        // node[2 * k + 1].lazy += v;
        node[k].lazy = -1;
    }
}

void updateIT(int k, int l, int r, int u, int v, int val)
{
    // (u v) l, r (u v)
    if (v < l || r < u)
        return;
    // u (l, r) v
    if (u <= l && r <= v)
    {
        // Increasing each value in range [a, b] by x.
        node[k].val += (r - l + 1) * val;

        // Setting each value in range [a, b] to x.
        // node[k].val = (r - l + 1) * val;
        node[k].lazy = val;

        // Just increase each value in range [a, b] by x and find Min, Max
        // Keep value not SUM
        // node[k].val += val;
        // node[k].lazy += val;

        // Like above but set each value in range [a, b] to x.
        // node[k].val = val;
        // node[k].lazy += val;
        return;
    }

    int m = (l + r) / 2;
    down(k, l, r);
    updateIT(2 * k, l, m, u, v, val);
    updateIT(2 * k + 1, m + 1, r, u, v, val);

    node[k].val = node[2 * k].val + node[2 * k + 1].val;
}

int queryIT(int k, int l, int r, int u, int v)
{

    // (u v) l, r (u v)
    if (v < l || r < u)
        return 0;
    // u (l, r) v
    if (u <= l && r <= v)
        return node[k].val;

    int m = (l + r) / 2;
    down(k, l, r);
    return queryIT(2 * k, l, m, u, v) + queryIT(2 * k + 1, m + 1, r, u, v);
}

int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    initIT(1, 1, n);
    while (q--)
    {
        int t, u, v, val;
        cin >> t >> u >> v;
        if (t == 0)
        {
            cin >> val;
            updateIT(1, 1, n, u, v, val);
        }
        else
        {
            cout << queryIT(1, 1, n, u, v) << endl;
        }
    }
}