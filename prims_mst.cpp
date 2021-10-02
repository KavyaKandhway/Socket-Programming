//Minimum spanning tree
// Prims algorithm
#include<bits/stdc++.h>
using namespace std;
int prim(int x,vector<vector<pair<int,int> > > &adj,vector<bool> &vis)
{
	priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;
	pq.push(make_pair(0,x));
	int cost=0;
	int i;
	while(!pq.empty())
	{
		pair<int,int> low=pq.top();
		pq.pop();
		int y=low.second;
		int w=low.first;
		if(vis[y])
		{
			continue;
		}
		
		cost+=w;
		vis[y]=true;
		for(i=0;i<adj[y].size();i++)
		{
			if(!vis[adj[y][i].second])
			{
				pq.push(adj[y][i]);
			}
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
	vector<vector<pair<int,int> > > adj(n+1);
	vector<bool> vis(n+1,false);
	for(i=0;i<e;i++){
		int x,y,w;
		cin>>x>>y>>w;
		adj[x].push_back(make_pair(w,y));
		adj[y].push_back(make_pair(w,x));
		
	}
	int mincost=prim(1,adj,vis);
	cout<<mincost<<endl;
	
}
