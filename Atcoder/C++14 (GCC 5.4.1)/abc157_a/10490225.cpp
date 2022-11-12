#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;
typedef pair<ll  ,ll > pll;

const ll maxn =2e6;
const ll mod = 1e9+7;
const ld PI = 4 * atan((ld) 1);

#define pb(x) push_back(x);
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
#define ms(x , y) memset(x , y , sizeof x);
ll pw(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * pw(a * a % mod, b / 2) % mod : pw(a * a % mod, b / 2) % mod));
}

string s;
int cnt[maxn];

int main(){
    migmig
    cin >> s;
    int cur = 0;
    ms(cnt , 0);
    for (int i = s.size()-1 ; i >=  0 ; i --){
        cnt[cur++] = s[i] - '0';
    }
    pll ans = {0 , 1};
    for(int i = 0 ; i < 1e6+100 ; i ++){
        ll a = min(ans.first + cnt[i] , ans.second+10 - cnt[i]);
        ll b = min(ans.first + cnt[i] +1 , ans.second+10 - (cnt[i] + 1 ) );
        ans = {a , b};
    }

    cout << ans.first;


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
