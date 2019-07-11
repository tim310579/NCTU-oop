#include <iostream>
#include <algorithm> 
 using namespace std;
int main(){
	int a,i,j,k=0,temp;
	int mid;
	int b[10000];
	while(cin >>a){
	
		b[k]=a;
		sort (b,b+k+1);

        if (k%2==0){
        	mid=b[k/2];
		}
		else if (k%2==1){
			mid=(b[(k+1)/2]+b[(k-1)/2])/2;
		}
		cout << mid <<endl;
		k++;
	}
	return 0;
}
