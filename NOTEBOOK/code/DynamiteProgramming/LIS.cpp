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
}
