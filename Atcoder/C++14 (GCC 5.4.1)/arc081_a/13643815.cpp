#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) return(cout << x , 0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ms(x , y) memset(x , y , sizeof x);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll a[7];

int main(){
    migmig
	for(int i = 0 ; i < 7 ; i ++ )
		cin >> a[i];
	ll ans = 0;
	ans+=a[0]/2*2;
	ans+=a[1];
	ans+=a[3]/2*2;
	ans+=a[4]/2*2;
	if(a[0]%2 and a[3]%2 and a[4]%2)ans+=3;
	ll ans2 = 0;
	ll boz = min(a[0] , a[3]);
	boz = min(boz , a[4]);
	ans2+=3*boz;
	a[0]-=boz , a[3]-=boz , a[4]-=boz;
	ans2+=a[0]/2*2;
	ans2+=a[1];
	ans2+=a[3]/2*2;
	ans2+=a[4]/2*2;
	a[0]+=boz , a[3]+=boz , a[4]+=boz;
	ll ans3 = 0;
	if(a[0] and a[3] and a[4]){
		ans3+=3;
		boz = 1;
		a[0]-=boz , a[3]-=boz , a[4]-=boz;
		ans3+=a[0]/2*2;
		ans3+=a[1];
		ans3+=a[3]/2*2;
		ans3+=a[4]/2*2;
	}
	cout << max(ans , max(ans3 , ans2));
    return(0);
}