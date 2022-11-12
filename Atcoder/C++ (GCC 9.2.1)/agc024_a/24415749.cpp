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

ll a, b, c, k;

struct matrix{
	ll n, m;
	ll a[10][10];
	friend matrix operator * (matrix a, matrix b){
		assert(a.m == b.n);
		matrix c;
		ms(c.a , 0);
		c.n = a.n , c.m = b.m;
		for(int i = 0 ; i < a.n ; i ++)
			for(int k = 0 ; k < a.m ; k ++)
				for(int j = 0 ; j < b.m ; j ++){
					if(a.a[i][j] > 1e18 / b.a[k][j])dokme("Unfair");
					c.a[i][j] = (c.a[i][j] + a.a[i][k] * b.a[k][j]);
					if(c.a[i][j] > 1e18)dokme("Unfair");
				}
		return c;
	}
};

matrix pw(matrix a , ll b){
	matrix res;
	res.n = res.m = 3;
	ms(res.a , 0);
	for(int i = 0 ; i < 3 ; i ++)res.a[i][i] = 1;
	while(b){
		if(b & 1)res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> b >> a >> c >> k;
	cout << ((k & 1) ? a - b : b - a);
	return(0);
}
