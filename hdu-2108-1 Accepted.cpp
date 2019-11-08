
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const double eps = 1e-10;
const double PI = acos(-1.0);
int dcmp(double x) { if (fabs(x)<eps)return 0; return x<0 ? -1 : 1; }
struct Point {
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) {}
};
typedef Point Vector;
Vector operator + (Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator - (Point a, Point b) { return Vector(a.x - b.x, a.y - b.y); }
Vector operator * (Vector a, double p) { return Vector(a.x*p, a.y*p); }
Vector operator / (Vector a, double p) { return Vector(a.x / p, a.y / p); }
double Cross(Vector a, Vector b) { return a.x*b.y - a.y*b.x; }
int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (!n)break;
		vector<Point> ve;
		for (int i = 0; i < n; i++) {
			double u, v;
			scanf("%lf%lf", &u, &v);
			ve.push_back(Point(u, v));
		}
		bool pd = true;
		for (int i = 0; i < n; i++) {
			if (dcmp(Cross(ve[(i + 1) % n] - ve[i], ve[(i + 2) % n] - ve[(i + 1) % n])) < 0) {
				pd = false;
				break;
			}
		}
		if (pd) {
			printf("convex\n");
		}
		else {
			printf("concave\n");
		}
	}
	return 0;
}

