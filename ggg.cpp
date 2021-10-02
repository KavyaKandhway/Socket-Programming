
// Problem : B. Stairs
// Contest : Codeforces - Codeforces Round #671 (Div. 2)
// URL : https://codeforces.com/contest/1419/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int> >
#define vb vector<bool>
#define vs vector<string>
#define vpii vector<pair<int,int> >
#define pii pair<int,int>
#define mii map<int,int>
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mkp make_pair
#define all(v) v.begin(),v.end()
#define input(a,b,n) for(i=b;i<n;i++){cin>>a[i];}
#define print(a) for(i=0;i<a.size();i++){cout<<a[i]<<" ";}cout<<endl;
#define trace1(a); cout<<"a="<<a<<endl;
#define trace2(a,b); cout<<"a="<<a<<" b="<<b<<endl;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int inf=0x3f3f3f3f3f3f3f3f;
int power(int a, int b){
    int res = 1;
    while(b!=0){
        if(b&1){
            res *= a; 
        }
        a = (a * a);
        b = (b / 2);
    }
    return res;
}
int main()
{
	fast;
    int t;
    //t=1;
    cin>>t;
    while(t--)
    {
    	int x,i;
    	cin>>x;
    	vi st(63,0);
    	st[0]=1;
    	
    	for(i=1;i<63;i++)
    	{
    		st[i]=st[i-1]*2+1;
    	}
    	i=0;
    	cout<<st[62]<<endl;
    	int ans=0;
    	for(i=0;i<63;i++)
    	{
    		st[i]=(st[i]+1)*st[i]/2;
    	}
    	for(i=1;i<63;i++)
    	{
    		st[i]=st[i-1]+st[i];
    	}
    	cout<<st[60]<<endl;
    	int lo=0,hi=60;
    	while(lo<hi)
    	{
    		
    		int mid=lo+(hi-lo)/2;
    		cout<<hi<<" "<<lo<<" "<<mid<<endl;
    		if(st[mid]<x)
    		{
    			lo=mid+1;
    		}
    		else
    		{
    			hi=mid;
    		}
    	}
    	cout<<lo<<endl;
	}
    return 0;
}

