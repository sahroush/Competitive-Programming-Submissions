//叫んで 藻掻もがいて 瞼まぶたを腫らしても
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int , int> pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 1e6 + 10;
const ll mod = 1e9+7;

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int n , m;
int x[maxn] , y[maxn];
vector < int > v , vc;
priority_queue < pii > pq;

int X(int x){
	return lower_bound(v.begin() , v.end() , x) - v.begin();
}

int Y(int x){
	return lower_bound(vc.begin() , vc.end() , x) - vc.begin();
}

set < int > ans;
set < pii > kil;
set < int > pos[maxn] , zap[maxn];

int32_t main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i ++)
		cin >> x[i] >> y[i] , v.pb(x[i]) , vc.pb(y[i]) , vc.pb(y[i] - 1) , vc.pb(y[i] + 1);
	vc.pb(n);
	vc.pb(n+1);
	vc.pb(n-1);
	v.pb(0);
	sort(v.begin() , v.end());
	v.resize(unique(v.begin() , v.end()) - v.begin());
	for(int i = 1 ; i <= m ; i ++)
		x[i] = X(x[i]);
	sort(vc.begin() , vc.end());
	vc.resize(unique(vc.begin() , vc.end()) - vc.begin());
	for(int i = 1 ; i <= m ; i ++)
		y[i] = Y(y[i]);
	for(int i = 1 ; i <= m ; i ++)
		kil.insert({x[i] , y[i]}) , pos[y[i]].insert(x[i]) , zap[y[i]].insert(x[i]);
	// x -> satr / y -> sootoon
	pq.push({-X(0) , Y(n)});
	while(!pq.empty()){
		auto [cx , cy] = pq.top();
		pq.pop();
		cx = -cx;
		while(kil.size() and (*kil.begin()).first <= cx){
			pos[(*kil.begin()).second].erase((*kil.begin()).first);
			if(zap[(*kil.begin()).second].count((*kil.begin()).first))zap[(*kil.begin()).second].erase((*kil.begin()).first);
			kil.erase((*kil.begin()));
		}
		int lim = maxn;
		if(pos[cy].empty())ans.insert(cy);
		else lim = *pos[cy].begin();
		while(zap[cy - 1].size() and *zap[cy-1].begin() <= lim){
			int nx = *zap[cy - 1].begin();
			pq.push(pii(-nx , cy - 1));
			zap[cy - 1].erase(nx);
		}
		while(zap[cy + 1].size() and *zap[cy+1].begin() <= lim){
			int nx = *zap[cy + 1].begin();
			pq.push(pii(-nx , cy + 1));
			zap[cy + 1].erase(nx);
		}
	}
	cout << ans.size();
	return(0);
}
