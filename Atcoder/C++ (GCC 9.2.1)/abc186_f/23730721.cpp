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

#define L (k<<1)
#define R (L+1)
#define mid (l+r>>1)
vector<int>v[maxn];
int n,m,k,x,y,f[maxn<<2];
ll ans;
void update(int k,int l,int r,int x,int y){
	if (l==r){
		f[k]=y;
		return;
	}
	if (x<=mid)update(L,l,mid,x,y);
	else update(R,mid+1,r,x,y);
	f[k]=f[L]+f[R];
}
int query(int k,int l,int r,int x,int y){
	if ((l>y)||(x>r))return 0;
	if ((x<=l)&&(r<=y))return f[k];
	return query(L,l,mid,x,y)+query(R,mid+1,r,x,y);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
	if (!v[1].size())x=m;
	else x=v[1][0]-1;
	for(int i=1;i<=x;i++)update(1,1,m,i,1);
	for(int i=1;i<=n;i++){
		int mx=0;
		for(int j=0;j<v[i].size();j++)update(1,1,m,v[i][j],0);
		if (query(1,1,m,1,1)){
			if (!v[i].size())mx=m;
			else mx=v[i][0]-1;
		}
		ans+=mx+query(1,1,m,mx+1,x);
	}
	printf("%lld",ans);
}
