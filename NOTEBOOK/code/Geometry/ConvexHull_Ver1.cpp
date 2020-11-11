pair<int, int> origin;

void operator-=(pair<int, int> &A, pair<int, int> B)
{
    A.fi -= B.fi;
    A.se -= B.se;
}
bool ccw(pair<int, int> O, pair<int, int> A, pair<int, int> B)
{
    A -= O, B -= O;
    return A.fi * B.se > A.se * B.fi;
}

bool cmp(pair<int, int> A, pair<int, int> B) { return ccw(origin, A, B); }

int n;
pair<int, int> a[12309];

int main()
{
    int i, t;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d%d", &a[i].fi, &a[i].se);
    sort(a + 1, a + n + 1);
    origin = a[1];
    sort(a + 2, a + n + 1, cmp);
    a[0] = a[n];
    a[n + 1] = a[1];
    int j = 1;
    for (i = 1; i <= n + 1; i++)
    { // a[1] and a[n+1] will be both added
        while (j > 2 && !ccw(a[j - 2], a[j - 1], a[i]))
            j--;
        a[j++] = a[i];
    }
    n = j - 2;
    for (i = 1; i <= n; i++)
        printf("%d %d\n", a[i].fi, a[i].se);
}
