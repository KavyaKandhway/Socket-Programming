#include<bits/stdc++.h>
using namespace std;
struct process
{
	int id,at,bt,ct,wt,tat;
	bool operator<(process B){
		if(at==B.at)
			return id<B.id;
		return at<B.at;
	}
	process(int ID,int AT,int BT)
	{
		id=ID;
		at=AT;
		bt=BT;
		wt=0;
	}
};
int main()
{
	cout<<"Enter number of processes: ";
	int n;
	cin>>n;
	vector<process> sys,us;
	cout<<"Enter process id, arrival time and burst time and process type respectively"<<endl;
	cout<<"0=sys process\n1=us process"<<endl;
	for(int i=0;i<n;i++)
	{
		int id,at,bt,type;
		cin>>id>>at>>bt>>type;
		process p(id,at,bt);
		if(type==0){
			sys.push_back(p);
		}else
			us.push_back(p);
	}
	sort(us.begin(),us.end());
	sort(sys.begin(),sys.end());
	int x=0,y=0;
	int s=sys.size(),u=us.size();
	int curr=0;
	while(x<s && y<u)
	{
		curr=max(curr,min(sys[x].at,us[y].at));
		if(curr>=sys[x].at){
			sys[x].ct=curr+sys[x].bt;
			sys[x].tat=sys[x].ct-sys[x].at;
			sys[x].wt+=sys[x].tat-sys[x].bt;
			curr+=sys[x].bt;
			x++;
		}else if(curr+us[y].bt<=sys[x].at){
			us[y].ct=curr+us[y].bt;
			us[y].tat=us[y].ct-us[y].at;
			us[y].wt+=us[y].tat-us[y].bt;
			curr+=us[y].bt;
			y++;
		}else{
			us[y].bt-=sys[x].at-curr;
			us[y].wt-=sys[x].at-curr;
			curr=sys[x].at;
		}
	}
	while(x<s)
	{
		curr=max(curr,sys[x].at);
		sys[x].ct=curr+sys[x].bt;
		sys[x].tat=sys[x].ct-sys[x].at;
		sys[x].wt+=sys[x].tat-sys[x].bt;
		curr+=sys[x].bt;
		x++;
	}
	while(y<u){
		curr=max(curr,us[y].at);
		us[y].ct=curr+us[y].bt;
		us[y].tat=us[y].ct-us[y].at;
		us[y].wt+=us[y].tat-us[y].bt;
		curr+=us[y].bt;
		y++;
	}
	double avg_wt=0,avg_tat=0;
	cout<<"Process id\tarrival time\tburst time\tprocess type\tcompletion time\tturn-around time\twaiting time"<<endl;
	for(int i=0;i<s;i++){
		cout<<sys[i].id<<"\t\t"<<sys[i].at<<"\t\t"<<sys[i].bt<<"\t\tsys\t\t"<<sys[i].ct<<"\t\t"<<sys[i].tat<<"\t\t\t"<<sys[i].wt<<endl;
		avg_wt+=sys[i].wt;
		avg_tat+=sys[i].tat;
	}
	for(int i=0;i<u;i++){
		cout<<us[i].id<<"\t\t"<<us[i].at<<"\t\t"<<us[i].bt<<"\t\tus\t\t"<<us[i].ct<<"\t\t"<<us[i].tat<<"\t\t\t"<<us[i].wt<<endl;
		avg_tat+=us[i].tat;
		avg_wt+=us[i].wt;
	}
	cout<<"Average WT: "<<avg_wt/n<<endl;
	cout<<"Average TAT: "<<avg_tat/n<<endl;
	return 0;
}
