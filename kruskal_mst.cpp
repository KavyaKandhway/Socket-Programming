//MINUMUM Spanning tree
// kruskals algorithm
#include<bits/stdc++.h>
using namespace std;
int root(int x,vector<int> &id)
{
	while(id[x]!=x)
	{
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}
void union1(int x,int y,vector<int> &id)
{
	int p=root(x,id);
	int q=root(y,id);
	id[p]=id[q];
}
int kruskal(vector<pair<int, pair<int,int> > > &p,int e,vector<int> &id)
{
	int i;
	int cost=0;
	for(i=0;i<e;i++)
	{
		int x=p[i].second.first;
		int y=p[i].second.second;
		int w=p[i].first;
		if(root(x,id)!=root(y,id))
		{
			cost+=w;
			//cout<<x<<" "<<y<<" "<<w<<endl;
			union1(x,y,id);
		}
	}
	return cost;
}
int main()
{
	int n;
	cin>>n;
	int e;
	cin>>e;
	int i;
	vector<pair<int, pair<int,int> > > p;
	vector<int> id(n+1);
	for(i=0;i<=n;i++)
	{
		id[i]=i;
	}
	for(i=0;i<e;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		p.push_back(make_pair(w,make_pair(x,y)));
	}
	sort(p.begin(),p.end());
	int mincost=kruskal(p,e,id);
	cout<<mincost<<endl;
}
