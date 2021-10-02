#include<bits/stdc++.h>
using namespace std;
struct process {
    int pid,at,bt,st,ct,tat,wt;
};
bool compare1(process p1, process p2) 
{ 
    return p1.at < p2.at;
}
bool compare2(process p1, process p2) 
{  
    return p1.pid < p2.pid;
}
int main() {
    int n,tq;
    struct process p[100];
    float avg_tat,avg_wt;
    int t_tat = 0,t_wt=0,t_it=0,idx;
    int brt[100];
    cout << setprecision(2) << fixed;
    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter time quantum: ";
    cin>>tq;
    cout<<"Enter arrival time and burst time\n";
    for(int i = 0; i < n; i++) {
        cout<<"Process P"<<i+1<<": ";
        cin>>p[i].at>>p[i].bt;
        brt[i] = p[i].bt;
        p[i].pid = i+1;
        cout<<endl;
    }
    sort(p,p+n,compare1);
    queue<int> q;
    int cur = 0,done=0;
    q.push(0);
    vector<int> mark(100,0);
    mark[0] = 1;
    while(done != n) {
        idx = q.front();
        q.pop();
        if(brt[idx] == p[idx].bt) {
            p[idx].st = max(cur,p[idx].at);
            t_it += p[idx].st - cur;
            cur = p[idx].st;
        }
        if(brt[idx]-tq > 0) {
            brt[idx] -= tq;
            cur += tq;
        }
        else {
            cur += brt[idx];
            brt[idx] = 0;
            done++;
            p[idx].ct = cur;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            t_tat += p[idx].tat;
            t_wt += p[idx].wt;
        }
        for(int i = 1; i < n; i++) {
            if(brt[i] > 0 && p[i].at <= cur && mark[i] == 0) {
                q.push(i);
                mark[i] = 1;
            }
        }
        if(brt[idx] > 0) {
            q.push(idx);
        }
        if(q.empty()) {
            for(int i = 1; i < n; i++) {
                if(brt[i] > 0) {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }
    }
    avg_tat = (float) t_tat / n;
    avg_wt = (float) t_wt / n;
    sort(p,p+n,compare2);
    cout<<"\n#P\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t\n"<<endl;
    for(int i = 0; i < n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time = "<<avg_tat<<endl;
    cout<<"Average Waiting Time = "<<avg_wt<<endl;
	return 0;
}
