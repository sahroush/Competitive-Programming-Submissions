#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 2e5 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n;
struct point{
	int x, y;
	void inp(){cin >> x >> y;}
	friend bool operator < (point a, point b){return a.x < b.x;}
}p[maxn];

set < pii > st;

bool chk(int x){
	int l = 0, r = 0;
	for(int i = 0 ; i < n ; i ++){
		while(r < n and p[r].x - p[i].x < x){
			st.erase({p[r].y, r});
			r ++;
		}
		while(l < n and p[i].x - p[l].x >= x){
			st.insert({p[l].y, l});
			l ++;
		}
		if(st.size()){
			if(abs(p[i].y - st.begin()->first) >= x)return 1;
			if(abs(p[i].y - st.rbegin()->first) >= x)return 1;
		}
	}
	return 0;
}

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		p[i].inp();
	sort(p, p + n);
	int l = 0, r = mod;
	while(r - l > 1){
		int mid = (l + r) >> 1;
		if(chk(mid))
			l = mid;
		else 
			r = mid;
	}
	cout << l;
	return(0);
}
