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

ll ans= 0;
ll n , a[maxn] , fact[maxn] , inv[maxn] , k;

ll ent(ll r ,ll n){
    if(r > n or r < 0 or n < 0){
        return(0);
    }
    return((fact[n]*inv[r])%mod*inv[n - r]%mod);
}

int main(){
    migmig
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++){
        cin >> a[i];
    }
    fact[0] = inv[0] = 1;
    for(int i = 1; i <= 5e5 ; i ++){
        fact[i] = fact[i - 1] * i;
        fact[i]%=mod;
        inv[i] = pw(fact[i] , mod - 2);
    }
    sort(a , a + n);
    for (int i = 0 ; i < n ; i ++){
        ans+= a[i] * (ent(k - 1 , i) - ent(k - 1 , n - i - 1));
        ans%=mod;
        ans+=mod*mod;
        ans%=mod;
    }
    cout << ans;


    return(0);
}


//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
//It is important to draw wisdom from diffrent places. If you take it from only one place it becomes rigid and stale.
