#include <iostream>
using namespace std;

int dp[5001][2000] ;

int main()
{

	dp[1][0] = 1;
	int i, j;
	for( i = 2 ; i <= 5000 ; i++ )
	{
		for( j = 0 ; j < 2000 ; j++ )
		{
			dp[i][j] += dp[i-1][j] + 2*dp[i-2][j];
			dp[i][j+1] += dp[i][j]/10;
			dp[i][j] %= 10;
			
		}
	}
	
	int n;
	while(cin >> n)
	{
		cout << "The Fibonacci number for " << n <<" is " ;
		//printf( "The Fibonacci number for %d is ", n );
		for( i = 1999 ; i >= 0 ; i-- )
		{
			if( dp[n][i] != 0 )
				break;
		}
		
			for( ; i >= 0 ; i-- )
				cout << dp[n][i] ;
			//	printf( "%d", dp[n][i] );
			cout <<endl;
	}
	return 0;
}
