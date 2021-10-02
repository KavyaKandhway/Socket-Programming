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
	for(i=0;i<n;i++)
	{
		bool flag=0;
		for(j=0;j<frames.size();j++)
		{
			if(frames[j]==page[i])
			{
				flag=1;
				hit_or_miss[i]=true;
				hit++;
				break;
			}
		}
		if(!flag)
		{
			hit_or_miss[i]=false;
			miss++;
			if(frames.size()<f)
			{
				frames.push_back(page[i]);
			}
			else
			{
				frames[cur]=page[i];
				cur++;
				cur=cur%f;
			}
		}
		for(j=0;j<frames.size();j++)
		{
			display[i].push_back(frames[j]);
		}
		for(;j<f;j++)
		{
			display[i].push_back(-1);
		}
	}
	cout<<"\n==================================\n";
	cout<<"Frame replacement process FIFO\n";
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
		cout<<frames[i]<<" ";
	}
	cout<<endl;
}
