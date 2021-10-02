#include<bits/stdc++.h>
using namespace std;
struct process
{
	int pid;
    int atime;
    int btime;
    int ct;
    int tat;
    int wt;
};
bool asort(process a,process b)
{
    return a.atime<b.atime; 
}
bool idsort(process a,process b)
{
	return a.pid<b.pid;
}
int main()
{
	int n;
	cout<<"Enter the number of processes\n";
	cin>>n;
	int i;
	process pro[n];
	cout<<"Enter arrival time and burst time respectively\n";
	for(i=1;i<=n;i++)
	{
		
		printf("Process id P%d\n",i);
		pro[i-1].pid=i;
		cin>>pro[i-1].atime>>pro[i-1].btime;
		
	}
	sort(pro,pro+n,asort);
	int pre[n+1];
	pre[0]=0;
	cout<<"\nSequence in which process is executed\n";
	for(i=1;i<=n;i++)
	{
		pre[i]=pre[i-1]+pro[i-1].btime;
		pro[i-1].ct=pre[i];
		cout<<"P"<<pro[i-1].pid<<" ";
		printf("P%d ",pro[i-1].pid);
	}
	for(i=0;i<n;i++)
	{
		pro[i].tat=pro[i].ct-pro[i].atime;
		pro[i].wt=pro[i].tat-pro[i].btime;
	}
	sort(pro,pro+n,idsort);
	printf("\n\nPID\tAT\tBT\tCT\tTAT\tWT\n");
	double avgtat=0,avgwt=0;
	for(i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,pro[i].atime,pro[i].btime,pro[i].ct,pro[i].tat,pro[i].wt);
		avgtat+=pro[i].tat;
		avgwt+=pro[i].wt;
	}
	printf("\nAverage TAT=%f\n",avgtat/n*1.0);
	printf("Average WT=%f\n",avgwt/n*1.0);
    return 0;
}

