#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 5e3;
const ll mod =998244353;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , k;
ll c[maxn][maxn];
ll C(ll r , ll n){
    if(r>n)return(0);
    return(c[n][r]);
}
ll ans[maxn];

int main(){
    migmig
    cin >> k >> n;
    for(int i = 0 ; i < 5000 ; i ++)c[i][0] = 1;
    for(int i = 1 ; i < 5000 ; i ++)
        for(int j = 1 ; j <= i ; j ++)
            c[i][j] = (c[i-1][j-1] + c[i-1][j])%mod;
    for(int i = 2 ; i <= k + 1 ; i ++){
        for(int j = 0 ; j <= i/2 ; j ++){
            if(j%2)
                ans[i] = (ans[i] - C(j , i / 2 ) * C(n - j * 2 , k + n - j * 2 - 1)% mod + mod ) % mod;
            else
                ans[i] = (ans[i] + C(j , i / 2 ) * C(n - j * 2 , k + n - j * 2 - 1)% mod) % mod;
        }
    }
    for(int i = 2 ; i <= k*2 ; i ++ )
        cout << ((i>=k+2)? ans[2*k+2-i] : ans[i]) << endl;
    return(0);
}