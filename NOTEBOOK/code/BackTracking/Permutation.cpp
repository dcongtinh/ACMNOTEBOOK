int main()
{

    scanf("%d", &n);

    fto(i, 0, n - 1) a.pb(i + 1);

    do
    {
        fto(i, 0, n - 1) printf("%d", a[i]);
        printf("\n");
    } while (next_permutation(a.begin(), a.end()));

    return 0;
}
