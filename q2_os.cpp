#include <bits/stdc++.h>
using namespace std;

struct pro
{
	int at;
	int pid;
	int wt;
	int bt, pri;
	int comp;
	int tat;
    bool curr=false;
};
struct cmp { 
    bool operator()(pro const& p1, pro const& p2){ 
        if(p1.pri!=p2.pri)
        return p1.pri>p2.pri;
        else return p1.at>p2.at;
    } 
};

int main()
{
	cout<<"enter the number of process: ";
	int q=2;
	int n;
	cin>>n;
	cout<<"Enter pro id, arrival time and burst time and pro type"<<endl;
	pro p[n];
	int i,j,k,l;
	for(i=0;i<n;i++){
		cin>>p[i].pid>>p[i].at>>p[i].bt>>p[i].pri;
	}
	priority_queue <pro,vector<pro>,cmp> pq;
	int currt=0;
	for(i=0;i<n;i++){
		if(p[i].at==0){
			pq.push(p[i]);
			p[i].curr=true;
	    }
	}
	cout<<"sequence of execution"<<endl;
	while(!pq.empty()){   
	    currt++;
		pro xx=pq.top();
		cout<<"P"<<xx.pid<<" ";
		pq.pop();
		if(xx.pri==1){
			if(xx.bt!=1){
				currt++;
				xx.bt--;
				cout<<"P"<<xx.pid<<" ";
			}
		}
		xx.bt--;
		if(xx.pri==1){
			xx.at=currt+1;
		}
		if(xx.bt!=0)
		pq.push(xx);
		else{ 
		  p[xx.pid-1].comp=currt;	
		}
		for(i=0;i<n;i++){
			if(p[i].at==currt||p[i].at==currt-1){
				pq.push(p[i]);
				p[i].curr=true;
			}
		}
	}
	cout<<endl;
	float wt=0,tt=0;
	for(i=0;i<n;i++){
		p[i].tat=p[i].comp-p[i].at;
		p[i].wt=p[i].tat-p[i].bt;
		wt+=p[i].wt;
		tt+=p[i].tat;
	}
	cout<<"proid\tarrivaltime\tbursttime\tpriority\tcomptime\tturnaroundtime\twaitingtime"<<endl;
	for(i=0;i<n;i++)
		cout<<p[i].pid<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].pri<<"\t\t"<<p[i].comp<<"\t\t"<<p[i].tat<<"\t\t"<<p[i].wt<<endl;
	cout<<"Average Turn_around_time = "<<(tt/n)<<endl;
	cout<<"Average  wt = "<<(wt/n)<<endl;
	
	
}
