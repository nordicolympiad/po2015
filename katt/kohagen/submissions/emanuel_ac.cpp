// Complexity: O(n^3)
// Expected score: 100

#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < int(b); i++)
#define trav(it, v) for(auto it = v.begin(); it != v.end(); it++)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi; 
 
vector<double> a, co, si;
int n;
double m, r;

double getArea(int i, int j, int k) {
	double x1 = r*co[i];
	double y1 = r*si[i];
	double x2 = r*co[j];
	double y2 = r*si[j];
	double x3 = r*co[k];
	double y3 = r*si[k];
	return abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
}

int main() {
	scanf("%d %lf %lf", &n, &m, &r);
	m *= 2.0;
	a.resize(n);
	co.resize(n);
	si.resize(n);
	rep(i, 0, n) {
		scanf("%lf", &a[i]);
		a[i] = a[i] * M_PI / 180.0;
	}
	sort(all(a));
	rep(i, 0, n) {
		co[i] = cos(a[i]);
		si[i] = sin(a[i]);
	}
	double ans = 8*r*r;
	rep(i, 0, n) {
		rep(j, i+2, n) {
			double ma = 0;
			int maIdx = -1;
			rep(k, i+1, j) {
				double area = getArea(i, j, k);
				if(area > ma) {
					ma = area;
					maIdx = k;
				}
			}
			assert(maIdx != -1);

			//First sweep
			double last = -1;
			int k = maIdx;
			int l = j+1;
			if(l >= n) l -= n;
			while(l != i && k != j) {
				double A = getArea(i, j, l);
				double area = getArea(i, j, k) + A;
				if(A < last) break;
				last = A;
				if(area < m) {
					l++;
					if(l >= n) l -= n;
				} else {
					ans = min(ans, area);
					k++;
				}
			}

			//Second sweep
			last = -1;
			k = maIdx;
			l = (j+1) % n;
			while(l != i && k != i) {
				double A = getArea(i, j, l);
				double area = getArea(i, j, k) + A;
				if(A < last) break;
				last = A;
				if(area < m) {
					l++;
					if(l >= n) l -= n;
					l = (l+1) % n;
				} else {
					ans = min(ans, area);
					k--;
				}
			}

			//Third sweep
			last = -1;
			k = maIdx;
			l = i-1;
			if(l < 0) l += n;
			while(l != j && k != j) {
				double A = getArea(i, j, l);
				double area = getArea(i, j, k) + A;
				if(A < last) break;
				last = A;
				if(area < m) {
					l--;
					if(l < 0) l += n;
				} else {
					ans = min(ans, area);
					k++;
				}
			}

			//Fourth sweep
			last = -1;
			k = maIdx;
			l = i-1;
			if(l < 0) l += n;
			while(l != j && k != i) {
				double A = getArea(i, j, l);
				double area = getArea(i, j, k) + A;
				if(A < last) break;
				last = A;
				if(area < m) {
					l--;
					if(l < 0) l += n;
				} else {
					ans = min(ans, area);
					k--;
				}
			}
		}
	}
	if(ans < 8*r*r) printf("%.15lf\n", ans/2.0);
	else printf("-1\n");
}

