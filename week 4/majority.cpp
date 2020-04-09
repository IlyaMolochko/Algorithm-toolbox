//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iomanip>
//
//typedef long long ll;
//
//void merge_sort(std::vector<int>::iterator begin, std::vector<int>::iterator end){
//    if (end - begin == 1){
//        return;
//    }
//    std::vector<int> v(begin, end);
//    auto mid = v.begin() + v.size() / 2;
//    merge_sort(v.begin(), mid);
//    merge_sort(mid, v.end());
//    std::merge(v.begin(), mid, mid, v.end(), begin);
//}
//
//
//int main() {
//    int n;
//    std::cin >> n;
//    std::vector<int> v(n);
//    for (int i = 0; i < n; ++i){
//        std::cin >> v[i];
//    }
//    merge_sort(v.begin(), v.end());
//    int prev = v[0];
//    int mx = 1;
//    int cnt = 1;
//    for (int i = 1; i < n; ++i){
//        if (prev == v[i]){
//            ++cnt;
//        } else {
//            if (mx < cnt){
//                mx = cnt;
//            }
//            prev = v[i];
//            cnt = 1;
//        }
//    }
//    if (mx < cnt){
//        mx = cnt;
//    }
//    if (mx > n / 2){
//        std::cout << 1 << '\n';
//
//    } else {
//        std::cout << 0 << '\n';
//    }
//}



#include <algorithm>
#include <iostream>
#include <bitset>
#include <unordered_map>
#include <deque>
#include <vector>
#include <set>
#include <cassert>
#include <iomanip>
#include <random>

using namespace std;
typedef long long ll;

void get_merge(deque<pair<int, int>> f, deque<pair<int, int>> s, deque<pair<int, int>> &merge){
    int n = f.size();
    int m = s.size();
    int i = 0;
    int j = 0;
    while (i < n or j < m){
        if (f[i].first <= s[j].first){
            merge.push_back(f[i]);
            ++i;
        } else {
            merge.push_back(s[j]);
            ++j;
        }
        if (i == n){
            while (j < m){
                merge.push_back(s[j]);
                ++j;
            }
        } else if (j == m) {
            while (i < n){
                merge.push_back(f[i]);
                ++i;
            }
        }
    }
    f.clear();
    s.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1000000000);
    int n;
    cin >> n;
    int item;
    deque<deque<pair<int, int>>> q;
    for (int i = 0; i < n; ++i) {
        cin >> item;
        q.push_back({{item, 1}});
    }
    deque<pair<int, int>> f, s, merge;
    while (q.size() > 1) {
        f = q.front();
        q.pop_front();
        s = q.front();
        q.pop_front();
        get_merge(f, s, merge);
        q.push_back(merge);
        merge.clear();
    }
    int prev = q.front()[0].first;
    int mx = 1;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (q.front()[i].first == prev){
            ++cnt;
        } else {
            cnt = 1;
            prev = q.front()[i].first;
        }
        mx = max(mx, cnt);
    }
    if (mx <= n / 2) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }
}