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
    vector<string> v(n);
    for (auto &i : v){
        cin >> i;
    }
    sort(v.begin(), v.end(), [](string s1, string s2){
        return s1 + s2 > s2 + s1;
    });
    for (auto i : v){
        cout << i;
    }
}
