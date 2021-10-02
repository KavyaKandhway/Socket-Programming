#include <bits/stdc++.h>
using namespace std;
//structure for every process
struct Process {
   int pid; 
   int art;
   int bt; 
   int ct;
   int tat;
   int wt;
};

int main() 
{
	
	cout<<"PRE EMPTIVE SJP JOB SCHEDULING\n";
	cout<<"Enter the number of processes: ";
	int n,i;
	
	cin>>n;
	Process proc[n];
	cout<<"Enter arrival time and burst time respectively\n";
	for(i=0;i<n;i++)
	{
		proc[i].pid=i+1;
		cout<<"Process id P"<<i+1<<endl;
		cin>>proc[i].art;
		cin>>proc[i].bt;
	}
   int wt[n], tat[n], total_wt = 0;
   int total_tat = 0;
   // Function to find waiting time of all
   // processes
   int rt[n];
   for (i = 0; i < n; i++)
   {
   		rt[i] = proc[i].bt;
   }
   
   int comp= 0, t = 0, minm = INT_MAX;
   int sh= 0, ft;
   bool check = false;
   while (comp!= n) 
   {
      for (int j = 0; j < n; j++) 
	  {
         if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0) {
            minm = rt[j];
            sh= j;
            check = true;
         }
      }
      if (check == false) {
         t++;
         continue;
      }
      // decrementing the remaining time
      rt[sh]--;
      minm = rt[sh];
      if (minm == 0)
         minm = INT_MAX;
         // If a process gets completely
         // executed
         if (rt[sh] == 0) {
            comp++;
            check = false;
            ft= t + 1;
            proc[sh].ct=ft;
            // Calculate waiting time
            wt[sh] = ft -proc[sh].bt -proc[sh].art;
            if (wt[sh] < 0)
               wt[sh] = 0;
         }
         // Increment time
         t++;
   }
   
   for (i = 0; i < n; i++)
   {
   		tat[i] = proc[i].bt + wt[i];
   }
   
   for(i=0;i<n;i++)
   {
   	proc[i].wt=wt[i];
   	proc[i].tat=tat[i];
   }
   printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
   for (int i = 0; i < n; i++) {
      total_wt = total_wt + wt[i];
      total_tat = total_tat + tat[i];
      cout << " " << proc[i].pid << "\t" << proc[i].art<<"\t"<<proc[i].bt << "\t" << proc[i].ct<<"\t"<<proc[i].tat<< "\t" << proc[i].wt << endl;
   }
   cout << "\nAverage waiting time = " << (float)total_wt / (float)n; cout << "\nAverage turn around time = " << (float)total_tat / (float)n;
}
