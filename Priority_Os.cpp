#include<bits/stdc++.h>
using namespace std;

struct process {
    int pid;
    int at;
    int bt;
    int pr;
    int st;
    int ct;
    int tat;
    int wt;
    int rt;
};

int main() {

    int n;
    struct process p[100];
    float avg_tat,avg_wt,avg_rt,cpu,thru;
    int tot_tat = 0,tot_wt=0,tot_rt=0,tot_it=0;
    int brt[100],comp[100];
    memset(comp,0,sizeof(comp));
    cout << setprecision(2) << fixed;
    cout<<"Enter the number of processes: ";
    cin>>n;
	cout<<"Enter arrival time, burst time, priority respectively\n";
    for(int i = 0; i < n; i++) {
        cout<<"Process P"<<i+1<<" ";
        cin>>p[i].at>>p[i].bt>>p[i].pr;
        p[i].pid = i+1;
        brt[i] = p[i].bt;
        cout<<endl;
    }
    int cur = 0,done=0,prev=0;
    while(done != n) 
	{
        int idx = -1;
        int mx = -1;
        for(int i = 0; i < n; i++) 
		{
            if(p[i].at <= cur && comp[i] == 0) 
			{
                if(p[i].pr > mx)
				 {
                    mx = p[i].pr;
                    idx = i;
                }
                if(p[i].pr == mx) {
                    if(p[i].at < p[idx].at) {
                        mx = p[i].pr;
                        idx = i;
                    }
                }
            }
        }
        if(idx != -1)
		 {
            if(brt[idx] == p[idx].bt) 
			{
                p[idx].st = cur;
                tot_it += p[idx].st - prev;
            }
            brt[idx] -= 1;
            cur++;
            prev = cur;
            if(brt[idx] == 0)
			 {
                p[idx].ct = cur;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                p[idx].rt = p[idx].st - p[idx].at;
                tot_tat += p[idx].tat;
                tot_wt += p[idx].wt;
                tot_rt += p[idx].rt;
                comp[idx] = 1;
                done++;
            }
        }
        else {
             cur++;
        }  
    }
    int min_at = 10000000;
    int max_ct = -1;
    for(int i = 0; i < n; i++) {
        min_at = min(min_at,p[i].at);
        max_ct = max(max_ct,p[i].ct);
    }
    avg_tat = (float) tot_tat / n;
    avg_wt = (float) tot_wt / n;
    avg_rt = (float) tot_rt / n;
    cpu = ((max_ct - tot_it) / (float) max_ct )*100;
    thru = float(n) / (max_ct - min_at);
    cout<<"\n\n#P\t"<<"AT\t"<<"BT\t"<<"PRI\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;
    for(int i = 0; i < n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].pr<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_tat<<endl;
    cout<<"Average Waiting Time = "<<avg_wt<<endl;
    cout<<"Average Response Time = "<<avg_rt<<endl;
}

