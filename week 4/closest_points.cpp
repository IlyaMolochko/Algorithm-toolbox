#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <cmath>

using namespace std;
typedef long long ll;
struct point
{
	ll x;
	ll y;
};


double get_dist(point p1, point p2){
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double get_min_dist(std::vector<point> &v, int l, int r){
	if (r - l > 0){
		int mid = (l + r) / 2;
		double left = get_min_dist(v, l, mid);
		double right = get_min_dist(v, mid + 1, r);
		double dist = min(left, right);
		std::vector<point> a;
		for (int i = mid; i >= l; --i){
			if (v[mid].x - v[i].x < dist){
				a.push_back(v[i]);
			}
		}
		for (int i = mid + 1; i <= r; ++i){
			if (v[i].x - v[mid].x < dist){
				a.push_back(v[i]);
			}
		}
		sort(a.begin(), a.end(), [](point p1, point p2){
			return p1.y < p2.y;
		});
		double min_dist = dist;
		for (int i = 0; i < a.size() - 1; ++i){
			for (int j = i + 1; j < a.size(); ++j){
				if (a[j].y - a[i].y < dist){
					min_dist = min(get_dist(a[i], a[j]), min_dist);
				} else {
					break;
				}
			}
		}
		return min_dist;
	}
	return numeric_limits<double>::max();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	std::vector<point> v(n);

	for (auto &i : v){
		cin >> i.x >> i.y;
	}
	sort(v.begin(), v.end(), [](point p1, point p2){
		if (p1.x == p2.x){
			return p1.y < p2.y;
		}
		return p1.x < p2.x;
	});
	cout << setprecision(5) << fixed;
	double dist = get_min_dist(v, 0, n - 1);
	cout << dist << '\n';
}