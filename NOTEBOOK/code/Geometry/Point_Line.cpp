struct point
{
    db x, y;
    point(db _x, db _y)
    {
        x = _x;
        y = _y;
    }
    point() { x = y = 0; }
    bool operator==(point other)
    {
        return (fabs(x - other.x) < EPS && fabs(y - other.y) < EPS);
    }
    point operator+(point other)
    {
        point res(x + other.x, y + other.y);
        return res;
    }

    void print()
    {
        printf("(%.3f, %.3f)\n", x, y);
    }
    point rotate(db theta)
    {
        theta = theta / 180 * acos(-1);
        return point(x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta));
    }
};

struct line
{
    db a, b, c;
    line() { a = b = c = 0; }
    line(db _a, db _b, db _c)
    {
        a = _a;
        b = _b;
        c = _c;
    }
    line(point p1, point p2)
    {
        if (fabs(p1.x - p2.x) < EPS)
        {
            a = 1.0;
            b = 0;
            c = -p1.x;
        }
        else
        {
            a = (p2.y - p1.y) / (p1.x - p2.x);
            b = 1.0;
            c = -a * p1.x - p1.y;
        }
    }
    bool isParallel(line other)
    {
        return (fabs(a - other.a) < EPS && fabs(b - other.b) < EPS);
    }
    bool isSame(line other)
    {
        return (isParallel(other) && fabs(c - other.c) < EPS);
    }
    void print()
    {
        printf("(%.3f, %.3f, %.3f)\n", a, b, c);
    }
};

db dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y); //sqrt((x1-x2)^2+(y1-y2)^2)
}
