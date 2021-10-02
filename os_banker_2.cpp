/*KAVYA KANDHWAY 18JE0408 DDCSE*/
#include<bits/stdc++.h>
#define display(a)      for(auto x: a) cout<<x<<" "; cout<<"\n";
using namespace std;

int main(){
    
    cout<<"Enter the number of processes: "<<endl;
	int n;
	cin>>n;
	cout<<"Enter the number of resources: "<<endl;
	int m;
	cin>>m;
	vector<int> a(n);
	map <int, vector<int> > mx, al;
	vector<int>  avl(m), total(m);
	for(int i=0;i<n;i++){
		mx[i].resize(m);
		al[i].resize(m);
	}
	cout<<"Enter PID / Maximum Need Vector / Initial Allocation Vector: "<<endl;

	for(int i=0;i<n;i++){
		int id;
		cin>>id;
		a[i]=id;
		for(int j=0;j<m;j++){
			int temp;
			cin>>temp;
			mx[id][j]=temp;
		}
		for(int j=0;j<m;j++){
			int temp;
			cin>>temp;
			al[id][j]=temp;
			avl[j]+=temp;
		}
	}
	cout<<"Enter the number of resource instances: "<<endl;
	for(int i=0;i<m;i++){
		cin>>total[i];
		avl[i]=total[i]-avl[i];
	}
	sort(a.begin(), a.end());
	set <vector<int> > s;
	vector<int>  temp=avl;
	do{	
		avl=temp;
		int flag=1;
		for(int j=0;j<n;j++){
			vector<int>  need(m);
			for(int i=0;i<m;i++){
				need[i]=mx[a[j]][i]-al[a[j]][i];
				if(need[i]>avl[i]){
					flag=0;
					break;
				}
			}
			if(flag==0) break;
			else for(int i=0;i<m;i++) avl[i]+=(al[a[j]][i]);
		}
		if(flag==0) continue;
		else s.insert(a);
	}while(next_permutation(a.begin(), a.end()));
    cout<<"Possible safe sequences: "<<endl;
    int id;
	for(auto i:s){
		display(i);
        id=i[n-1];
		for(int j=0;j<n+5;j++) cout<<"-";
		cout<<endl;
	}
    cout<<"Process ID "<<id<<" executed last"<<endl;
    return 0;
}
