
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps = 1e-10;
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
int dots_inline(Point p1, Point p2, Point p3) {
	return dcmp(Cross(p1 - p3, p2 - p3)) == 0;
}
double Dot(Vector a, Vector b) { return a.x*b.x + a.y*b.y; }
double Length(Vector a) { return sqrt(Dot(a, a)); }
struct Line {
	Point p, b;
	Vector v;
	Line() {}
	Line(Point pp, Point bb) {
		p = pp; b = bb; v = b - p;
	}
};
double DisToLine(Point p, Line a) {
	return fabs(Cross(a.v, p - a.p)) / Length(a.v);
}
Point LineInter(Line a, Line b) {
	double t = Cross(b.v, a.p - b.p) / Cross(a.v, b.v);
	return a.p + a.v*t;
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		double a, b, c, d, e, f;
		scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);
		Point x = Point(a, b), y = Point(c, d), z = Point(e, f);
	//	printf("%.0f\n", ans);
		double ff = DisToLine(z, Line(x, y))*Length(y - x) / 2;
		printf("%.0f\n", ff / 7);
	}
	return 0;
}

