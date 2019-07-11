#include<iostream>
#include<math.h>
using namespace std;

int sum[2750000];

bool isprime(int n)
{
	if (n == 2)return true;
	if (n % 2 == 0)return false;
	for (int i = 3; i <= sqrt(n); i += 2)if (n%i == 0)return false;
	return true;
}

int main()
{
	for (int i = 0; i < 2750000; i++)sum[i] = 0;
	for (int i = 2; i < 2750000; i++)
	{
		if (isprime(i))
		{
			long long m = i;
			while (m < 2750000)
			{
				for (int j = m; j < 2750000; j += m)sum[j]++;
				m *= i;
			
			}
		}
	}
	for (int i = 1; i < 2750000; i++)sum[i] += sum[i - 1];
	int n, low, high, mid;
	int cas = 1;
	while (cin >> n)
	{
		if (n < 0)break;
		cout << "Case " << cas++ << ": ";
		low = 0, high = 2749999;
		while (low < high - 1)
		{
			mid = (low + high) / 2;
			if (sum[mid] < n)low = mid;
			else if (sum[mid]>n)high = mid;
			else break;
		}
		if (n == 0)mid = 0;
		if (sum[mid] == n)cout << mid << "!"<<endl;
		else cout << "Not possible."<<endl ;
	}
	return 0;
}
