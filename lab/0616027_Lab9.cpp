#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
long long dp[301][301];
long long fp[301][301];
char line[100];
int main(int argc, char** argv) {
	int i ,j;
	 dp[0][0]=fp[0][0]=1;
	for(i=1;i<301;i++){
		for( j=1;j<301;j++){
			dp[i][j]=fp[i-j][min(j,i-j)];
			fp[i][j]=fp[i][j-1]+dp[i][j];
		}
	}
	
	
	int N,a=0,b=0;
	while(gets(line)){
	
	int n =sscanf(line ,"%d%d%d",&N,&a,&b);
	if(N<0||N>300){
		return 0;
	}
	if(n>0){
		if(n==1){
			cout << fp[N][N];
		}
		else if(n==2){
			cout << fp[N][min(a,N)];
		}
		else if(a>0){
			cout <<fp[N][min(b,N)]-fp[N][a-1];
			
		}
		else {
			cout <<fp[N][min(b,N)];
		}
		cout <<endl;
	}

	} 
	return 0;
}
