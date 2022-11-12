#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>s;


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

int n;
int a[maxn];
vector < int > one , two;
s st;
map < int , int > mp;

int main(){
    migmig
    cin >> n;
    for(int i = 0 ; i < n ; i ++)
		cin >> a[i];
	for(int i = 0 ; i < n ; i ++)
		if(i%2)
			two.pb(a[i]);
		else
			one.pb(a[i]);
	sort(one.begin() , one.end());
    sort(two.begin() , two.end());
    sort(a , a + n);
    for(int i = 0 ; i < n ; i ++){
		mp[a[i]] = i%2;
	}
    int p1 = 0 , p2 = 0;
    for(int i = 0 ; i < n ; i ++)
		if(i%2)
			a[i] = two[p1++];
		else
			a[i] = one[p2++];
	
	int ans = 0;
	for(int i = 0 ; i < n ; i ++){
		if(i%2!=mp[a[i]])ans++;
	}
	
	cout << ans /2;
    return(0);
}