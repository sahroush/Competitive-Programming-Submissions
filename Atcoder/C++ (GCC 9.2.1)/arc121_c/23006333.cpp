//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 510;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

#define sz(x) int(x.size())

int n , q;
int a[maxn];
vector < int > ans;

void solve(int t = 0){//0 age fard , 1 age zoj
	int pos = 0 , cnt = 0;
	for(int i = 1 ; i <= n ; i ++)cnt += (a[i] != i);
	if(cnt == 0)return;
	for(int i = ((t) ? ((n % 2) ? n-1 : n-2) : ((n % 2) ? n-2 : n - 1)) ; i >= 1 ; i -= 2)
		if(a[i] > i){
			pos = i;
			while(a[pos] > pos){
				swap(a[pos] , a[pos + 1]) , ans.pb(pos);
				pos ++;
				t = 1-t;
			}
			break;
		}
	if(pos == 0){
		for(int i = 1 + t ; i < n ; i += 2)
		if(a[i+1] < i+1){
			pos = i;
			while(a[pos+1] < pos+1 and pos){
				swap(a[pos] , a[pos + 1]) , ans.pb(pos);
				pos --;
				t = 1-t;
				
			}
			pos = 100;
			break;
		}
	}
	if(pos == 0){
		//panik
		int pos = rng()%n + 1;
		if(pos == n)pos--;
		if(pos % 2 == t){
			if(pos > 1)pos--;
			else pos ++;
		}
		swap(a[pos] , a[pos+1]);
		ans.pb(pos);
		t = 1-t;
		//dokme("shit");
	}
	
	solve(t);
}

int32_t main(){
	cin >> q;
	while(q --){
		cin >> n;
		ans.clear();
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i];
		solve();
		for(int i = 1 ; i <= n ; i ++)
			assert(a[i] == i);
		assert(sz(ans) <= n * n);
		for(int i = 1 ; i <= ans.size() ; i ++)	
			assert(ans[i-1] % 2 == i % 2);
		//cout << "ok";
		
		cout << sz(ans) << endl;
		for(auto x : ans)cout << x << ' ';
		cout << endl;
		
	}
	return(0);
}
