#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int n;


	while(cin >> n){
			int p=1;
	int N=2,W=3,E=4,S=5;
		if(n>1024)return 0;
		else if(n==0)return 0;
		for(int i=0;i<n ;i++){
			string str;
			cin >>str; 
			if(str=="north"){
				N=p;
				p=S;
				S=7-N;
			
			}
			else if(str=="south"){
				S=p;
				p=N;
				N=7-S;
		
			}
			else if(str=="east"){
				E=p;
				p=W;
				W=7-E;
				
			}
			else if(str=="west"){
				W=p;
				p=E;
				E=7-W;
		
			}
			
		}
		cout << p;
			cout <<endl;
	}
	
	
	return 0;
}
