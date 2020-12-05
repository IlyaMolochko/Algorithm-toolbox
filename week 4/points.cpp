#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <iomanip>
#include <cmath>

using ll = long long ;
using namespace std;
std::istream& operator >> (std::istream &is, std::pair<ll, ll> &p){
    is >> p.first >> p.second;
    return is;
}

double distance(std::pair<ll, ll> p1, std::pair<ll, ll> p2){
    return std::sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

double minimal_distance(std::vector<std::pair<ll, ll>> &v, int l, int r){
    if (r - l > 0){
        int mid =(l + r) / 2;
        double left = minimal_distance(v, l, mid);
        double right = minimal_distance(v, mid + 1, r);
        double dist = std::min(left, right);
        std::vector<std::pair<ll, ll>> a;

        for (int i = mid; i >= l; --i){
            if (v[mid].first - v[i].first < dist){
                a.push_back(v[i]);
            }
        }
        for (int i = mid + 1; i <= r; ++i){
            if (v[i].first - v[mid].first < dist){
                a.push_back(v[i]);
            }
        }
        std::sort(a.begin(), a.end(), [](std::pair<ll, ll> p1, std::pair<ll, ll> p2){
            return p1.second < p2.second;
        });
        double d = dist;
        for (int i = 0; i < a.size() - 1; ++i){
            for (int j = i + 1; j < a.size(); ++j){
                if (a[j].second - a[i].second < dist){
                    d = std::min(distance(a[i], a[j]), d);
                } else {
                    break;
                }
            }
        }
        return d;
    }
    return std::numeric_limits<double>::max();
}

int main() {
	ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    int n;
    std::cin >> n;
    std::vector<std::pair<ll, ll>> v(n);
    for (auto &i : v){
        std::cin >> i;
    }
    std::sort(v.begin(), v.end(), [](std::pair<ll, ll> p1, std::pair<ll, ll> p2){
        if (p1.first == p2.first){
            return p1.second < p2.second;
        }
        return p1.first < p2.first;
    });
    std::pair<ll, ll> item = v[0];
    ll mn = std::numeric_limits<int>::max();
    double s = minimal_distance(v, 0, n);
    std::cout << std::setprecision(4) << std::fixed;
    std::cout << s << '\n';

    return 0;
}