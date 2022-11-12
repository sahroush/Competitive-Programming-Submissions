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

int n ; 
int a[maxn];
int ans[maxn];
pii pos[maxn];

int main(){
    migmig
	cin >> n;
	for(int i = 1 ; i <= n ; i ++){
		cin >> a[i];
		pos[i] = {a[i] , i};
	}
	sort(pos+1 , pos + n+ 1);
	int cur = 1 , cnt =0;
	for(int i = 1 ; i <= n ; i ++){
		cnt = 0;
		if(ans[pos[i].first])dokme("No");
		ans[pos[i].first] = pos[i].second;
		if(pos[i].second == 1)continue;
		while(cur <= pos[i].first){
			if(!ans[cur]){
				ans[cur] = pos[i].second;
				cnt++;
				if(cnt == pos[i].second-1)
					break;
			}
			cur++;
		}
		if(cnt < pos[i].second-1)dokme("No");
	}
	cur = n*n;
	for(int i = n ; i  ; i -- ){
		cnt = 0;
		if(pos[i].second == n)continue;
		while(cur >= pos[i].first){
			if(!ans[cur]){
				ans[cur] = pos[i].second;
				cnt++;
				if(cnt == n - pos[i].second)
					break;
			}
			cur--;
		}
		if(cnt < n-pos[i].second)dokme("No");
	}
	cout << "Yes" << endl;
	for(int i = 1 ; i <= n*n ; i ++ )
		cout << ans[i] << ' ';
	
    return(0);
}