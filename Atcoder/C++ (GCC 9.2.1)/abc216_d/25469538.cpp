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

int n, m;
queue < int > q[maxn], res;
int pos[maxn];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= m ; i ++){
		int sz;
		cin >> sz;
		for(int j = 0; j < sz ; j ++){
			int a;
			cin >> a;
			q[i].push(a);
		}
		if(pos[q[i].front()])
			res.push(i);
		else
			pos[q[i].front()] = i;
	}
	while(res.size()){
		n --;
		int v = res.front();
		res.pop();
		int x = q[v].front();
		q[v].pop();
		if(q[v].size()){
			if(pos[q[v].front()])
				res.push(v);
			else
				pos[q[v].front()] = v;
		}
		v = pos[x];
		q[v].pop();
		if(q[v].size()){
			if(pos[q[v].front()])
				res.push(v);
			else
				pos[q[v].front()] = v;
		}
	}
	cout << ((n == 0) ? "Yes" : "No");
	return(0);
}
