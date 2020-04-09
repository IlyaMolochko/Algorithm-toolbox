#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using ll = long long ;

void quick_sort(std::vector<int> &v, int l, int r){
    int x = v[(l + r) / 2];
    int i = l;
    int j = r;
    while (i < j){
        while (v[i] < x){
            ++i;
        }
        while (v[j] > x){
            --j;
        }
        if (i <= j){
            std::swap(v[i], v[j]);
            ++i;
            --j;
        }
    }
    if (i < r){
        quick_sort(v, i, r);
    }
    if (l < j){
        quick_sort(v, l, j);
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> v(n);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i){
        std::cin >> v[i] >> a[i];
    }
    quick_sort(v, 0, n - 1);
    quick_sort(a, 0, n - 1);
    int cnt = 0;
    int item;
    for (int i = 0; i < m; ++i){
        std::cin >> item;
        cnt = 0;
        cnt -= v.end() - std::upper_bound(v.begin(), v.end(), item);
        cnt += a.end() - std::lower_bound(a.begin(), a.end(), item);
        std::cout << cnt << ' ';
    }

    return 0;
}