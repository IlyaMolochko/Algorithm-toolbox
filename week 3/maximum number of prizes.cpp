#include <algorithm>
#include <iostream>
#include <bitset>
#include <unordered_map>
#include <deque>
#include <vector>
#include <set>
#include <cassert>
#include <iomanip>

using namespace std;
typedef long long ll;

struct label{
    int l;
    int r;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int num = 2;
    vector<int> v = {1};
    --n;
    while (n >= num){
        n -= num;
        v.push_back(num++);
    }
    v[v.size() - 1] += n;
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << ' ';
    }
}
