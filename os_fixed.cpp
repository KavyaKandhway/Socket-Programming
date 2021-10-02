#include<bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter the number of blocks: ";
	int m;
	cin >> m;
	int n;
	cout << "Enter the number of processes: ";
	cin >> n;
	int block_size[m], marked[m], internal_fragment[m];
	for(int i = 0; i < m; i++) marked[i] = 0;
	cout << "Enter the size of the blocks in Kb: ";
	for(int i = 0; i < m; i++){
		cin >> block_size[i];
		internal_fragment[i] = block_size[i];
	}
	int proc_size[n], block_assigned[n];
	cout << "Enter the size of the processes in Kb: ";
	for(int i = 0; i < n; i++){
		cin >> proc_size[i];
		block_assigned[i] = -1;
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(marked[j] == 0 && block_size[j] >= proc_size[i]){
				marked[j] = 1;
				internal_fragment[j] = block_size[j] - proc_size[i];
				block_assigned[i] = j+1;
				break;
			}
		}
	}
	cout << "\n\n";
	cout << "=========================Fixed partitioning first fit output===================\n";
	cout << "The block number of all processes is shown below:\n";
	cout << "Process No.         Block number\n";
	for(int i = 0; i < n; i++){
		if(block_assigned[i] == -1){
			cout << "External fragmentation occurs in Process " << i+1 <<"\n";
			continue;
		}
		cout << "     " << i+1 << "                 ";
		if(block_assigned[i] == -1) cout << "Not accomodated";
		else cout << block_assigned[i];
		cout <<"\n";
	}
	cout << "The internal fragment size in each block is shown below\n";
	cout << "Block No.            Fragment size\n";
	for(int i = 0; i < m; i++){
		cout << "   " << i+1 << "                     ";
		cout << internal_fragment[i];
		cout <<"\n";
	}
	
	
	cout << "===========================Fixed partitioning best fit output==============================\n";
	for(int i = 0; i < m; i++){
		marked[i] = 0;
		internal_fragment[i] = block_size[i];
	}
	for(int i = 0; i < n; i++) block_assigned[i] = -1;
	for(int i = 0; i < n; i++){
		int ind = -1;
		for(int j = 0; j < m; j++){
			if(marked[j] == 0 && block_size[j] >= proc_size[i]){
				if(ind == -1){
					ind = j;
				}else{
					if(block_size[j] < block_size[ind]) ind = j;
				}
			}
		}
		if(ind == -1) continue;
		marked[ind] = 1;
		block_assigned[i] = ind+1;
		internal_fragment[ind] = block_size[ind] - proc_size[i];
	}
	cout << "The block number of all processes is shown below:\n";
	cout << "Process No.         Block number\n";
	for(int i = 0; i < n; i++){
		if(block_assigned[i] == -1){
			cout << "External fragmentation occurs in Process " << i+1 <<"\n";
			continue;
		}
		cout << "     " << i+1 << "                 ";
		if(block_assigned[i] == -1) cout << "Not accomodated";
		else cout << block_assigned[i];
		cout <<"\n";
	}
	cout << "The internal fragment size in each block is shown below\n";
	cout << "Block No.            Fragment size\n";
	for(int i = 0; i < m; i++){
		cout << "   " << i+1 << "                     ";
		cout << internal_fragment[i];
		cout <<"\n";
	}
	cout << "\n\n";
	cout << "===========================Fixed partition worst fit output=============================\n";
	for(int i = 0; i < m; i++){
		marked[i] = 0;
		internal_fragment[i] = block_size[i];
	}
	for(int i = 0; i < n; i++) block_assigned[i] = -1;
	for(int i = 0; i < n; i++){
		int ind = -1;
		for(int j = 0; j < m; j++){
			if(marked[j] == 0 && block_size[j] >= proc_size[i]){
				if(ind == -1) ind = j;
				else{
					if(block_size[j] > block_size[ind]) ind = j;
				}
			}
		}
		if(ind == -1) continue;
		marked[ind] = 1;
		block_assigned[i] = ind+1;
		internal_fragment[ind] = block_size[ind] - proc_size[i];
	}
	cout << "The block number of all processes is shown below:\n";
	cout << "Process No.         Block number\n";
	for(int i = 0; i < n; i++){
		if(block_assigned[i] == -1){
			cout << "External fragmentation occurs in Process " << i+1 <<"\n";
			continue;
		}
		cout << "     " << i+1 << "                 ";
		if(block_assigned[i] == -1) cout << "Not accomodated";
		else cout << block_assigned[i];
		cout <<"\n";
	}
	cout << "The internal fragment size in each block is shown below\n";
	cout << "Block No.            Fragment size\n";
	for(int i = 0; i < m; i++){
		cout << "   " << i+1 << "                     ";
		cout << internal_fragment[i];
		cout <<"\n";
	}
	return 0;
}
