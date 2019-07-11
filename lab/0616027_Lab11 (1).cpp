#include <iostream>
using namespace std;
int length = 0, sum = 0;
int a[27][352]; 
 
void A(int x)
{
    int i; 
    if(length >= 26 || sum >= 351){ 
    }    
    else{
        for(i = 1; i <= 26; i++){
            if(i > x){
                 length++;
                 sum += i;
                 a[length][sum]++;
                 A(i);
                 sum -= i;
                 length--;   
            }
        }
    }
} 
int main()
{
    int c = 0;
    int l, s;
    A(0); 
    while(cin >> l >>s){
       c++;
        if(l == 0 && s == 0)
         break;
       
        if(l > 26 || s > 351){
        	cout << "Case "  << c <<": " << 0 << endl;
		}
           
        else
           cout << "Case "  << c <<": "<< a[l][s] << endl;
    }
    return 0;
}


