//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 3e6;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

ll n , k , a[maxn] , b[maxn] , srt[maxn];

bool cmp(int i , int j){
	return a[i] < a[j];
}

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i] >> b[i] , srt[i] = i;;
	sort(srt + 1 , srt + n + 1 , cmp);
	ll cur = 1;
	while(cur <= n and k >= a[srt[cur]]){
		k += b[srt[cur]];
		cur++;
	}
	cout << k;
	return(0);
}
