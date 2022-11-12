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
/*bool cmp(pair<int,int> p1,pair<int,int> p2)
{
	if(p1.second!=p2.second)return p1.second>p2.second;
	return p1.first<p2.first;
}*/
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
vector<pair<int,int> >ivan;
void precompute()
{
	for(int i=1;i<=n;++i)
	{
		ivan.clear();
		ivan.push_back({0,i});
		for(auto v:rg[i])
		{
			for(auto xd:bestSQRT[v])
			{
				ivan.push_back({-xd.first-1,xd.second});
			}
		}
		sort(ivan.begin(),ivan.end());
		for(auto xd:ivan)
		{
			if(c[xd.second])continue;
			bestSQRT[i].push_back({-xd.first,xd.second});
			if(bestSQRT[i].size()==SQRT)
			{
				break;
			}
			c[xd.second]=1;
		}
		for(auto xd:bestSQRT[i])
		{
			c[xd.second]=0;
		}
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
	/*for(int i=1;i<=n;i++)
	{
		cout<<i<<":\n";
		for(auto xd:bestSQRT[i])
		{
			cout<<xd.first<<" "<<xd.second<<endl;
		}
	}*/
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