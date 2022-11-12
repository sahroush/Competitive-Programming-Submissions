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

ll n , k;
ll a[maxn];
ll pos= 0 , neg = 0 , zer = 0;

bool chk(ll x){
    ll cnt = 0;
    for (int i = 0 ; i < n ; i ++){
        if(a[i] < 0){
            ll l = -1 , r = n;
            while(r - l > 1){
                ll mid = (l + r)/2;
                if(a[i]*a[mid] < x){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            cnt+=n - r;
        }
        else{
            ll l = -1 , r = n;
            while(r - l > 1){
                ll mid = (l + r)/2;
                if(a[i]*a[mid] < x){
                    l = mid;
                }
                else{
                    r = mid;
                }
            }
            cnt+=r;
        }
        if(a[i]*a[i] < x){
            cnt--;
        }
    }
    cnt/=2;
    return(cnt < k);
}

int main(){
    migmig
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++){
        cin >> a[i];
        neg+=(int)(a[i] < 0);
        pos+=(int)(a[i] > 0);
        zer+=(int)(a[i] == 0);
    }
    sort(a , a + n);
    ll negt = neg * pos;
    ll zero = zer * neg + zer * pos;
    ll post = neg*(neg - 1) + pos*(pos - 1);
    if(k > negt and k <= negt + zero){
        dokme(0);
    }
    ll l = -1e18 , r = 1e18;
    while(r - l > 1){
        ll mid = ( l + r) / 2;
        if(chk(mid)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    cout << l;
    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
