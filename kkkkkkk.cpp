
// Problem : C. Searching Local Minimum
// Contest : Codeforces - Codeforces Round #700 (Div. 2)
// URL : https://codeforces.com/contest/1480/problem/C
// Memory Limit : 512 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cp-editor)

#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl '\n'
#define vi vector<int>
#define vvi vector<vector<int> 
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
    t=1;
   // cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	vi a(n+2,-1);
    	a[0]=inf;
    	a[n+1]=inf;
    	int l=1,r=n;
    	while(l<=r){
    		int mid=l+(r-l)/2;
    		if(a[mid]==-1){
    			cout<<"? "<<mid<<endl;
    			cin>>a[mid];
    		}
    		if(a[mid-1]==-1){
    			cout<<"? "<<mid-1<<endl;
    			cin>>a[mid-1];
    		}
    		if(a[mid+1]==-1){
    			cout<<"? "<<mid+1<<endl;
    			cin>>a[mid+1];
    		}
    		if(a[mid]<min(a[mid+1],a[mid-1])){
    			cout<<"! "<<mid<<endl;
    			break;
    		}
    		if(a[mid]>a[mid+1]){
    			l=mid+1;
    		}else{
    			r=mid-1;
    		}
    	}
	}
    return 0;
}
