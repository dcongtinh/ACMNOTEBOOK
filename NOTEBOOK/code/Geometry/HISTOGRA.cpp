int main()
{
    while (scanf("%d", &n) && n)
    {
        fto(i, 1, n) scanf("%d", &h[i]);
        stack<int> stk;
        fto(i, 1, n)
        {
            while (!stk.empty() && h[stk.top()] >= h[i])
                stk.pop();
            if (stk.empty())
                l[i] = 0;
            else
                l[i] = stk.top();
            stk.push(i);
        }
        stk = stack<int>();
        fdto(i, n, 1)
        {
            while (!stk.empty() && h[stk.top()] >= h[i])
                stk.pop();
            if (stk.empty())
                r[i] = n + 1;
            else
                r[i] = stk.top();
            stk.push(i);
        }
        ll ans = 0LL;
        fto(i, 1, n)
        {
            ans = max(ans, (ll)(r[i] - l[i] - 1) * h[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
