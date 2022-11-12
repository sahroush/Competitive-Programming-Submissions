#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
const ll SIZE = 1e5 + 10;


#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

vector<pair<ll, ll>> vec;

int main() {
    fastInp;

    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        vec.push_back({ num, i });
    }
    
    sort(vec.begin(), vec.end());

    ll ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        if ((vec[i].second % 2) != (i % 2)) ans++;
    }
    cout << ans / 2;
    return 0;
}