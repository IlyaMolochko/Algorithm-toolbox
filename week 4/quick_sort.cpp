#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

typedef long long ll;

void quickSort(std::vector<int>& v, int l, int r){
    int i = l;
    int j = r;
    int x = v[(l + r) / 2];
    while(i < j){
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
        quickSort(v, i, r);
    }
    if (l < j){
        quickSort(v, l, j);
    }
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (auto &i : v){
        std::cin >> i;
    }
    quickSort(v, 0, n - 1);
    for (const auto &i : v){
        std::cout << i << ' ';
    }
}