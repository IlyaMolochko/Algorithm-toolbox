#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;
using ll = long long;

long long eval(long long a, long long b, char op) {
    if (op == '*') {
        return a * b;
    } else if (op == '+') {
        return a + b;
    } else {
        return a - b;
    }
}

ll get_max(vector<ll> &v, vector<char> &op){
    vector<vector<pair<ll, ll>>> d(v.size(), vector<pair<ll, ll>>(v.size(),
            {numeric_limits<ll>::max(), numeric_limits<ll>::min()}));
    for (int i = 0; i < v.size(); ++i){
        d[i][i] = {v[i], v[i]};
    }
    for (int j = 1; j < v.size(); ++j){
        for (int i = j - 1; i >= 0; --i){
            for (int l = 0; l + i < j; ++l){
                d[i][j].first = min(d[i][j].first, eval(d[i][i + l].first, d[i + l + 1][j].first, op[i + l]));
                d[i][j].first = min(d[i][j].first, eval(d[i][i + l].first, d[i + l + 1][j].second, op[i + l]));
                d[i][j].first = min(d[i][j].first, eval(d[i][i + l].second, d[i + l + 1][j].first, op[i + l]));
                d[i][j].first = min(d[i][j].first, eval(d[i][i + l].second, d[i + l + 1][j].second, op[i + l]));
                d[i][j].second = max(d[i][j].second, eval(d[i][i + l].second, d[i + l + 1][j].second, op[i + l]));
                d[i][j].second = max(d[i][j].second, eval(d[i][i + l].first, d[i + l + 1][j].second, op[i + l]));
                d[i][j].second = max(d[i][j].second, eval(d[i][i + l].second, d[i + l + 1][j].first, op[i + l]));
                d[i][j].second = max(d[i][j].second, eval(d[i][i + l].first, d[i + l + 1][j].first, op[i + l]));
            }
        }
    }
    return d[0][v.size() - 1].second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    vector<ll> v;
    vector<char> op;
    ll value = 0;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] >= '0' and s[i] <= '9'){
            value = 10 * value + (s[i] - '0');
        } else {
            v.push_back(value);
            op.push_back(s[i]);
            value = 0;
        }
        if (i == s.size() - 1){
            v.push_back(value);
        }
    }
    cout << get_max(v, op);
}
