#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+6;
const int SQRT=110;
const int INF=2e9;
vector<int>g[MAXN];
vector<int>rg[MAXN];
vector<pair<int,int> >bestSQRT[MAXN];
bool no[MAXN];
int dist[MAXN],n,m,q;
bool c[MAXN];

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)

typedef pair<int , int> pii;

int calc(int u)
{
	for(int i=1;i<u;++i)
	{
		dist[i]=-INF;
	}
	dist[u]=0;
	for(int i=u-1;i>=1;--i)
	{
		for(auto v:g[i])
		{
			if(v>u)continue;
			dist[i]=max(dist[i],dist[v]+1);
		}
	}
	int ret=-1;
	for(int i=1;i<=u;++i)
	{
		if(no[i])continue;
		ret=max(ret,dist[i]);
	}
	return ret;
}


vector < pii > vc;
void precompute(){
	for(int i = 1 ; i <= n ; i ++){
		vc.clear();
		vc.pb({0 , i});
		for(auto u : rg[i])
			for(auto x : bestSQRT[u])
				vc.pb({-x.first - 1 , x.second});
		sort(vc.begin() , vc.end());
		for(auto x : vc){
			if(c[x.second])continue;
			bestSQRT[i].pb({-x.first , x.second});
			if(bestSQRT[i].size() == SQRT)break;
			c[x.second] = 1;			
		}
		for(auto x : bestSQRT[i])
			c[x.second] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m>>q;
	for(int i=0;i<m;++i)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		rg[y].push_back(x);
	}
	precompute();

	for(int i=1;i<=q;++i)
	{
		int x,y;
		cin>>x>>y;
		vector<int>busy;
		for(int j=0;j<y;++j)
		{
			int f;
			cin>>f;
			busy.push_back(f);
			no[f]=1;
		}
		if(y>=SQRT)
		{
			cout<<calc(x)<<"\n";
			for(auto f:busy)
			{
				no[f]=0;
			}
			continue;
		}
		int ans=-1;
		for(auto xd:bestSQRT[x])
		{
			if(no[xd.second])continue;
			ans=xd.first;break;
		}
		if(ans!=-1)
		{
			cout<<ans<<"\n";
			for(auto f:busy)
			{
				no[f]=0;
			}
			continue;
		}
		cout<<calc(x)<<"\n";
		for(auto f:busy)
		{
			no[f]=0;
		}
	}
return 0;
}
