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

int n;
int a[3][maxn];

int32_t main(){
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int j = 0 ; j < 3 ; j ++)
		for(int i = 0 ; i < n ; i ++)
			cin >> a[j][i];
	for(int i = 0 ; i < 3 ; i ++)
		sort(a[i] , a[i] + n);
	int ans = 0;
	int pos[] = {0 , 0 , 0};
	while(*max_element(pos , pos + 3) < n){
		if(a[1][pos[1]] <= a[0][pos[0]]){
			pos[1] ++;
		}
		else if(a[2][pos[2]] <= a[1][pos[1]]){
			pos[2] ++;
		}
		else{
			ans ++;
			for(int i = 0 ; i < 3 ; i ++)pos[i] ++;
		}
	}
	cout << ans;
	return(0);
}
