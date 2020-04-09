#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <random>
#include <time.h>

using namespace std;
using ll = long long ;

ll func(vector<pair<int, int>> f, vector<pair<int, int>> s, vector<pair<int, int>>& merge){
    int i = 0, j = 0;
    ll cnt = 0;
    while (merge.size() < f.size() + s.size()){
        if (s[j].first < f[i].first){
            cnt += f.size() - i;
            merge.push_back(s[j]);
            ++j;
            if (j == s.size()){
                for (; i < f.size(); ++i){
                    merge.push_back(f[i]);
                }
            }
        } else {
            merge.push_back(f[i]);
            ++i;
            if (i == f.size()){
                for (; j < s.size(); ++j){
                    merge.push_back(s[j]);
                }
            }
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    queue<vector<pair<int, int>>> q;
    int item;
    ll cnt = 0;
    for (int i = 0; i < n; ++i){
        cin >> item;
        q.push({{item, i}});
    }
    int m = log2(n) + 1;
    for (int i = n; log2(i) < m; ++i){
        q.push({{numeric_limits<int>::max(), i}});
    }
    vector<pair<int, int>> merge;
    vector<pair<int, int>> f;
    vector<pair<int, int>> s;
    int i = 0, j = 0;
    while (q.size() > 1){
        f = q.front();
        q.pop();
        s = q.front();
        q.pop();
        merge.resize(0);
        if (f.size() == s.size()){
            cnt += func(f, s, merge);
        } else {
            cnt += func(s, f, merge);
        }
        q.push(merge);
    }
    cout << cnt;
    return 0;
}