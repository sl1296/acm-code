
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

char s[1000010];
int tx[10] = {0,-1,0,1,-1,0,1,-1,0,1};
int ty[10] = {0,-1,-1,-1,0,0,0,1,1,1};
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		int len = strlen(s);
		Point p = Point(0, 0),ss=p,pre=p,fir;
		double sum = 0;
		for (int i = 0; i < len-1; i++) {
			p.x += tx[s[i] - 48];
			p.y += ty[s[i] - 48];
			sum += Cross(pre,p);
			if (i == 0)fir = p;
			pre = p;
		}
		sum += Cross(p,fir);
		sum = fabs(sum) / 2;
		printf("%g\n", sum);
	}
	return 0;
}

