#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int T,N;
	int a,num=1;

	int b[50];
	cin >> T;
	if(T>=30){
		return 0;
	}
	for(int i=0;i<T;i++){
			int high=0,down=0;
		cin >> N;
			if(N>=50||N<=0){
				return 0;
			}
			for(int j=0;j<N;j++){
				cin >> a;
				b[j]=a;
		
				
				
			}
			for(int j=0;j<N-1;j++){
				if(b[j]<b[j+1]){
					high++;	
				}
				else if(b[j]>b[j+1]){
					down++;
				}
			}
		
		cout << "Case "	<< num <<": "<< high <<" "<< down <<endl;
		num+=1;
	}
	return 0;
}
