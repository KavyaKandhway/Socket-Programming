#include <bits/stdc++.h>
using namespace std;
int main()
{
    	string s;
    	cin>>s;
    	int n=s.size();
    	if(s[0]=='B'){
    		if(n==5&&s[1]=='E'&&s[2]=='G'&&s[3]=='I'&&s[4]=='N'){
    			cout<<"code=1"<<endl;
    			cout<<"token=begin"<<endl;
    		}else{
    			cout<<"code=0"<<endl;
    			cout<<"invalid"<<endl;
    		}
    	}else if(s[0]=='E'){
    		if(n==3&&s[1]=='N'&&s[2]=='D'){
    			cout<<"code=2\n"<<"token=end"<<endl;
    		}else if(n==4&&s[1]=='L'&&s[2]=='S'&&s[3]=='E'){
    			cout<<"code=5\ntoken=else\n";
    		}else{
    			cout<<"code=0"<<endl;
    			cout<<"invalid"<<endl;
    		}
    	}else if(s[0]=='I'){
    		if(n==2&&s[1]=='F'){
    			cout<<"code=3\ntoken=if\n";
    		}else{
    			cout<<"code=0\ninvalid\n";
    		}
    	}else if(s[0]=='T'){
    		if(n==4&&s[1]=='H'&&s[2]=='E'&&s[3]=='N'){
    			cout<<"code=4\ntoken=then\n";
    		}else{
    			cout<<"code=0\ninvalid\n";
    		}
    	}else if(s[0]>='0'&&s[0]<='9'){
    		int i=1;
    		while(i<n&&s[i]>='0'&&s[i]<='9'){
    			i++;
    		}
    		if(i==n){
    			cout<<"code="<<7<<endl;
    			cout<<"token=constant"<<endl;
    		}else{
    			cout<<"code="<<0<<endl;
    			cout<<"invalid"<<endl;
    		}
    	}else if((s[0]>='A'&&s[0]<='Z')||(s[0]>='a'&&s[0]<='z')){
    		int i=1;
    		while(i<n&&((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))){
    			i++;
    		}
    		if(i==n){
    			cout<<"code=6\ntoken=identifier\n";
    		}else{
    			cout<<"code=0\ninvalid\n";
    		}
    	}else if(s[0]=='<'){
    		if(n==1){
    			cout<<"code=8\ntoken is <\nvalue=1\n";
    		}else if(n==2&&s[1]=='='){
    			cout<<"code=8\ntoken is <=\nvalue=2\n";
    		}else if(n==2&&s[1]=='>'){
    			cout<<"code=8\ntoken is <>\nvalue=4\n";
    		}else{
    			cout<<"code=0\ninvalid\n";
    		}
    	}else if(s[0]=='='){
    		if(n==1){
    			cout<<"code=8\ntoken is =\nvalue=3\n";
    		}else{
    			cout<<"code=0\ninvalid\n";
    		}
    	}else if(s[0]=='>'){
    		if(n==1){
    			cout<<"code=8\ntoken is >\nvalue=5\n";
    		}else if(n==2&&s[1]=='='){
    			cout<<"code=8\ntoken is >=\nvalue=6\n";
    		}else{
    			cout<<"code=0\ninvalid\n";
    		}
    	}else{
    		cout<<"code=0\ninvalid\n";
    	}
	
    return 0;
}

