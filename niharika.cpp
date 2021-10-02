#include<bits/stdc++.h>
using namespace std;
class Student    
 {   
 	string name="";
 	string option="#####";
 	public:
 	void input()
 	{
 		cout<<"enter the name of student\n";
 		cin>>name;
 		cout<<"Enter the 5 options marked\n";
 		for(int i=0;i<5;i++)
 		{
 			cin>>option[i];
		}
	}
    void print()
    {
    	cout<<"Name="<<name<<endl;
    	cout<<"Markd\n";
    	for(int i=0;i<5;i++)
    	{
    		cout<<option[i]<<" ";
		}
		cout<<endl;
	}
     
	   
 } ;
int main()
{
	cout<<"enter the number of students\n";
	int n,i;
	cin>>n;
	vector<Student> stud(n);
	for(i=0;i<n;i++)
	{
		stud[i].input();
	}
	for(i=0;i<n;i++)
	{
		stud[i].print();
	}
	
}
