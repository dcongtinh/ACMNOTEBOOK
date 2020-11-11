#include <bits/stdc++.h>
#define fto(i, x, y) for (int i = (x); i <= (y); ++i)
#define fdto(i, x, y) for (int i = (x); i >= (y); --i)
#define forit(it, var) for (__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(it, var) for (__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define DEBUG(x)         \
  {                      \
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

#define pdd pair<double, double>

using namespace std;

int N;
double Dx, Dy;
typedef pair<double, pdd > dot;
vector< dot > dots;
int convexhull[100001]; // stack
int top; // stack push idx

int ccw(pdd a, pdd b, pdd c) {
	pdd ab, bc;
	ab.fi = b.fi - a.fi; 
	ab.se = b.se - a.se;
	
	bc.fi = c.fi - b.fi;
	bc.se = c.se - b.se;
	
	double ret = ab.fi*bc.se - ab.se*bc.fi;
	ret = -ret;
	if (ret > 0) return 1;
	else if (ret == 0) return 0;
	else return -1;
}

double getDistance(const dot A, const dot B) {
	return sqrt(pow(A.se.fi - B.se.fi, 2.0) + pow(A.se.se - B.se.se, 2.0));
}


bool settingDots(dot A, dot B) {
	int cw = ccw(dots[0].se, A.se, B.se);
	if (cw > 0) return 1;
	if (cw < 0) return 0;
	else if (A.fi < B.fi) { return 1;} // dist A < dist B (기준 점에서 거리)
	return 0;
}

void setSlope(const dot P0) {
	fto(i, 1, N-1) {
		dots[i].fi = getDistance(P0, dots[i]);
	}
	sort(dots.begin() + 1, dots.end(), settingDots);
}
void ConvexHull() {
	for (int i = 2; i < N; i++) {
		while (top >= 2 && ccw(dots[convexhull[top-2]].se, dots[convexhull[top - 1]].se, dots[i].se) <= 0) top--;
		convexhull[top++]=i;
	}
}
int main() {
	cin >> N;
	dots.resize(N);
	fto(i, 0, N-1) {
		cin >> Dx >> Dy;
		dots[i].se.fi = Dy;
		dots[i].se.se = Dx;
	}
	sort(dots.begin(), dots.end());
	setSlope(dots[0]);
	convexhull[top++] = 0;;
	convexhull[top++] = 1 ;
	ConvexHull();

	cout << top << endl;

}