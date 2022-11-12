#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e5 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n, k, ans, a[maxn];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
    ll k;
    cin>>n>>k;
    
    vector < ll >  a(n);
    for(auto &in:a) cin>>in;
    
    ll ng=0, ok=2e9+10;
    while(ok-ng>1){
        int mid=(ng+ok)/2;
        
        ll sum=0;
        for(auto elem:a){
            if(elem>=mid) sum+=elem-mid+1;
        }
        
        if(sum<=k) ok=mid;
        else ng=mid;
    }
    
    ll rest=k;
    ll ans=0;
    for(auto elem:a){
        if(elem>=ok){
            ans+=(elem-ok+1)*(elem+ok)/2;
            rest-=elem-ok+1;
        }
    }
    ans+=rest*(ok-1);
    
    cout<<ans;

	return(0);
}
