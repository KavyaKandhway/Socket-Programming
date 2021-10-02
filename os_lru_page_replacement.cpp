#include<bits/stdc++.h>
using namespace std;
int main()
{
	int f;
	cout<<"Enter the frane size:\n";
	cin>>f;
	int n;
	cout<<"Enter the number of page references:\n";
	cin>>n;
	vector<int> frames,page(n);
	int i=0,cur=0,j;
	cout<<"Enter the page references\n";
	for(i=0;i<n;i++)
	{
		int x;
		cin>>x;
		page[i]=x;
	}
	vector<vector<int> > display(n);
	int miss=0,hit=0;
	vector<bool> hit_or_miss(n,false);
	map<int,int> m,m1;
	unordered_set<int> s;
	for(i=0;i<n;i++)
	{
	//	cout<<"page="<<page[i]<<endl;
		if(s.find(page[i])==s.end())
		{
			miss++;
			hit_or_miss[i]=false;
			if(s.size()<f)
			{
				s.insert(page[i]);
				m[page[i]]=i;
				if(i>0)
				{
					display[i]=display[i-1];
					for(j=0;j<f;j++)
					{
						if(display[i][j]==-1)
						{
							display[i][j]=page[i];
							break;
						}
					}
				}
				else
				{
					display[i].push_back(page[i]);
				}
				
			}
			else
			{
				int lru=INT_MAX;
				int val;
				for(auto it=s.begin();it!=s.end();it++)
				{
					if(lru>m[*it])
					{
						lru=m[*it];
						val=*it;
					}
				}
				s.erase(val);
				s.insert(page[i]);
				m[page[i]]=i;
				display[i]=display[i-1];
				for(j=0;j<f;j++)
				{
					if(display[i][j]==val)
					{
						display[i][j]=page[i];
					}
				}
			}
		}
		else
		{
			display[i]=display[i-1];
			hit++;
			hit_or_miss[i]=true;
			m[page[i]]=i;
		}
		
		while(display[i].size()<f)
		{
			display[i].push_back(-1);
		}
		
	}
	
	//Displaying
	cout<<"\n==================================\n";
	cout<<"Frame replacement process LRU\n";
	cout<<"==================================\n\n";
	for(i=f-1;i>=0;i--)
	{
		for(j=0;j<n;j++)
		{
			if(display[j][i]==-1)
			{
				cout<<"  ";
			}
			else
			{
				cout<<display[j][i]<<" ";
			}
		}
	
		cout<<endl;
	}
	for(i=0;i<n;i++)
	{
		if(hit_or_miss[i])
		{
			cout<<"H ";
		}
		else
		{
			cout<<"M ";
		}
	}
	cout<<"\n\nNumber of hits="<<hit<<endl;
	cout<<"Number of Page faults="<<miss<<endl;
	cout<<"\nSequence of pages in frames\n";
	for(i=0;i<f;i++)
	{
		cout<<display[n-1][i]<<" ";
	}
	cout<<endl;
}
