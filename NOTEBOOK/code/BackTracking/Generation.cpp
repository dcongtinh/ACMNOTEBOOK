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
