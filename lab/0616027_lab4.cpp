#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int T,n;
	
	int b=1;
	
	
	cin >>T;
	if(T>300){
		return 0;
	}
	for(int k=1;k<=T;k++){
		char A,B;
		int i,j;
		
		

		while(cin >> A >> B >> n ){
			long long int a[n][n];
			bool is_symmetric = true;
			for( i=0;i<n;i++){
				for( j=0;j<n;j++){
					cin >> a[i][j];
				}
			}
			for( i=0;i<n;i++){
				for( j=0;j<n;j++){	
					if(a[i][j]!=a[n-i-1][n-j-1] || a[i][j]<0){
						is_symmetric = false;
					}		
				}
			}
			
			if(is_symmetric){
				cout << "Test #"<< b <<": "<< "Symmetric." << endl;
			}
		
			else if(!is_symmetric)	{
				cout << "Test #"<< b <<": "<< "Non-symmetric."<< endl;
			} 
			b++;
		
			break;
			
		}
		
				
			
		
	}
	return 0;
}
