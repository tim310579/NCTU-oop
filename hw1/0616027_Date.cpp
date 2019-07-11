#include <iostream>
#include "0616027_Date.h"
#include <iomanip> 
using namespace std;


Date::Date(int d ,int m,int y ){
	day=d;
	month=m;
	year=y;
}
Date::~Date(){
	
}
int Date::getDay(){
	return day;
}
int Date::getMonth(){
	return month;
}

int Date::getYear(){
	return year;
}
int Days[]=
	{0,31,28,31,30,31,30,31,31,30,31,30,31};
int LeapDays[]=
	{0,31,29,31,30,31,30,31,31,30,31,30,31};


void Date::setDay(int dd){
	if(month==2&& year %4 ==0 && year%100 !=0 || year %400 ==0)
		day = (dd>=1 && dd<=29)?dd:1;
	else
		day = (dd>=1&& dd <=Days[month])?dd:1;
}
void Date::setMonth(int mm){
		month = (mm>=1 && mm<=12)?mm:1;
}
void Date::setYear(int yy){
	year = (yy>=1900&&yy <=2100)?yy:1900;	
}


 Date Date::DateAfter(int days){
 	int d,m,y;
 	int D; 
	d=day;
	m=month;
	y=year;
	if(y %4 ==0 && y%100 !=0 || y %400 ==0)
		{
			switch(m)
			{
				case 1:D=31;break;
				case 2:D=29;break;
				case 3:D=31;break;
				case 4:D=30;break;
				case 5:D=31;break;
				case 6:D=30;break;
				case 7:D=31;break;
				case 8:D=31;break;
				case 9:D=30;break;
				case 10:D=31;break;
				case 11:D=30;break;
				case 12:D=31;break;
			}
		}
	else{
		switch(m)
			{
				case 1:D=31;break;
				case 2:D=28;break;
				case 3:D=31;break;
				case 4:D=30;break;
				case 5:D=31;break;
				case 6:D=30;break;
				case 7:D=31;break;
				case 8:D=31;break;
				case 9:D=30;break;
				case 10:D=31;break;
				case 11:D=30;break;
				case 12:D=31;break;
			}
	}		
	d=d+days;
	if(d<=D){
		goto C;
	}
	
	A:{

	while(d>D)
	{
		if(y %4 ==0 && y%100 !=0 || y %400 ==0)
		{
			switch(m)
			{
				case 1:D=31;break;
				case 2:D=29;break;
				case 3:D=31;break;
				case 4:D=30;break;
				case 5:D=31;break;
				case 6:D=30;break;
				case 7:D=31;break;
				case 8:D=31;break;
				case 9:D=30;break;
				case 10:D=31;break;
				case 11:D=30;break;
				case 12:D=31;break;
			}
			d=d-D;
		
			m++;
			switch(m)
			{
				case 1:D=31;break;
				case 2:D=29;break;
				case 3:D=31;break;
				case 4:D=30;break;
				case 5:D=31;break;
				case 6:D=30;break;
				case 7:D=31;break;
				case 8:D=31;break;
				case 9:D=30;break;
				case 10:D=31;break;
				case 11:D=30;break;
				case 12:D=31;break;
			}
			while(m>12){
				m=m-12;
				y++;
			}
	
		}
		else{
			goto B;
		}
	}
}
	B:{

	while(d>D)
	{
		if(y %4 ==0 && y%100 !=0 || y %400 ==0){
			goto A;
		}
		else
		{
		
			switch(m)
			{
				case 1:D=31;break;
				case 2:D=28;break;
				case 3:D=31;break;
				case 4:D=30;break;
				case 5:D=31;break;
				case 6:D=30;break;
				case 7:D=31;break;
				case 8:D=31;break;
				case 9:D=30;break;
				case 10:D=31;break;
				case 11:D=30;break;
				case 12:D=31;break;
			}
			d=d-D;
		
			m++;
			switch(m)
			{
				case 1:D=31;break;
				case 2:D=28;break;
				case 3:D=31;break;
				case 4:D=30;break;
				case 5:D=31;break;
				case 6:D=30;break;
				case 7:D=31;break;
				case 8:D=31;break;
				case 9:D=30;break;
				case 10:D=31;break;
				case 11:D=30;break;
				case 12:D=31;break;
			}
			while(m>12){
					m=m-12;
					y++;
				}
		}	
	}
}
	C:
	return Date(d,m,y);
}

	
		
   
Date Date::DateBefore(int days){
	int d,m,y;
	d=day;
	m=month;
	y=year;
	int sumdays=0;
	int D,Y=100,M=1,DD;
	
	
	for(int i=100;i<y;i++){
		if(i %4 ==0 && i%100 !=0 || i %400 ==0){
		sumdays=sumdays+366;
		}
		else{
		sumdays=sumdays+365;	
		}
	}
	
	if(y %4 ==0 && y%100 !=0 || y %400 ==0){
		switch(m)
		{
		
		case 12:sumdays+=30;
		case 11:sumdays+=31;
		case 10:sumdays+=30;
		case 9:sumdays+=31;
		case 8:sumdays+=31;
		case 7:sumdays+=30;
		case 6:sumdays+=31;
		case 5:sumdays+=30;
		case 4:sumdays+=31;
		case 3:sumdays+=29;
		case 2:sumdays+=31;
		case 1:sumdays+=0;
		}
	}
	else{
		switch(m)
		{
		
		case 12:sumdays+=30;
		case 11:sumdays+=31;
		case 10:sumdays+=30;
		case 9:sumdays+=31;
		case 8:sumdays+=31;
		case 7:sumdays+=30;
		case 6:sumdays+=31;
		case 5:sumdays+=30;
		case 4:sumdays+=31;
		case 3:sumdays+=29;
		case 2:sumdays+=31;
		case 1:sumdays+=0;
		}

		
	}
	sumdays+=d;
	d=sumdays-days;
	DD=d-1;
	if(y %4 ==0 && y%100 !=0 || y %400 ==0)
		{
			switch(M)
			{
				case 1:D=31;break;
				case 2:D=29;break;
				case 3:D=31;break;
				case 4:D=30;break;
				case 5:D=31;break;
				case 6:D=30;break;
				case 7:D=31;break;
				case 8:D=31;break;
				case 9:D=30;break;
				case 10:D=31;break;
				case 11:D=30;break;
				case 12:D=31;break;
			}
		}
	else{
		switch(M)
			{
				case 1:D=31;break;
				case 2:D=28;break;
				case 3:D=31;break;
				case 4:D=30;break;
				case 5:D=31;break;
				case 6:D=30;break;
				case 7:D=31;break;
				case 8:D=31;break;
				case 9:D=30;break;
				case 10:D=31;break;
				case 11:D=30;break;
				case 12:D=31;break;
			}
	}		



	A:{
		while(DD>D)
	{
		if(Y %4 ==0 && Y%100 !=0 || Y %400 ==0)
		{
			switch(M)
			{
				case 1:D=31;break;
				case 2:D=29;break;
				case 3:D=31;break;
				case 4:D=30;break;
				case 5:D=31;break;
				case 6:D=30;break;
				case 7:D=31;break;
				case 8:D=31;break;
				case 9:D=30;break;
				case 10:D=31;break;
				case 11:D=30;break;
				case 12:D=31;break;
			}
			DD=DD-D;
			
			M++;
			switch(M)
			{
				case 1:D=31;break;
				case 2:D=29;break;
				case 3:D=31;break;
				case 4:D=30;break;
				case 5:D=31;break;
				case 6:D=30;break;
				case 7:D=31;break;
				case 8:D=31;break;
				case 9:D=30;break;
				case 10:D=31;break;
				case 11:D=30;break;
				case 12:D=31;break;
			}
			while(M>12){
				M=M-12;
				Y++;
			}
	
		}
		else{
			goto B;
		}
	}
}
	B:{

	while(DD>D)
	{
		if(Y %4 ==0 && Y%100 !=0 || Y %400 ==0){
			goto A;
		}
		else
		{
		
			switch(M)
			{
				case 1:D=31;break;
				case 2:D=28;break;
				case 3:D=31;break;
				case 4:D=30;break;
				case 5:D=31;break;
				case 6:D=30;break;
				case 7:D=31;break;
				case 8:D=31;break;
				case 9:D=30;break;
				case 10:D=31;break;
				case 11:D=30;break;
				case 12:D=31;break;
			}
			DD=DD-D;
			
			M++;
			switch(M)
			{
				case 1:D=31;break;
				case 2:D=28;break;
				case 3:D=31;break;
				case 4:D=30;break;
				case 5:D=31;break;
				case 6:D=30;break;
				case 7:D=31;break;
				case 8:D=31;break;
				case 9:D=30;break;
				case 10:D=31;break;
				case 11:D=30;break;
				case 12:D=31;break;
			}
			while(M>12){
					M=M-12;
					Y++;
				}
			
		}	
	}
}
	
	y=Y;
	m=M;
	d=DD;
	
	return Date(d,m,y);
}

string Date::dayOfWeek(){
		if (month == 1 || month == 2) {  
        month += 12;  
        year--;  
    } 
	int iWeek = (day + 2 * month + 3 * (month + 1) / 5 + year+ year / 4 - year / 100 + year / 400) % 7;  
    switch (iWeek)  
    {  
    case 0: return "Monday"  ;  
    case 1: return "Tuesday" ;  
    case 2: return "Wednesday" ;  
    case 3: return "Thursday" ;   
    case 4: return "Friday" ; 
    case 5: return "Saturday" ; 
    case 6: return "Sunday" ; 
    }  
     
}

int Date::numberOfDays(){
	if(year %4 ==0 && year%100 !=0 || year %400 ==0){
	int numberOfDays=LeapDays[month];
	}
	else{
	int numberOfDays=Days[month];
	}
}

void Date::printMonthCalendar(){
	switch(month){
      	case 1:cout<<"----------January-----------"<< endl;break;
      	case 2:cout<<"----------Febuary-----------"<< endl;break;
      	case 3:cout<<"-----------March------------"<< endl;break;
      	case 4:cout<<"-----------April------------"<< endl;break;
      	case 5:cout<<"------------May-------------"<< endl;break;
      	case 6:cout<<"------------June------------"<< endl;break;
      	case 7:cout<<"------------July------------"<< endl;break;
      	case 8:cout<<"-----------August-----------"<< endl;break;
      	case 9:cout<<"---------September----------"<< endl;break;
      	case 10:cout<<"----------October----------"<< endl;break;
      	case 11:cout<<"--------November-----------"<< endl;break;
      	case 12:cout<<"--------December-----------"<< endl;break;
	  }
	  int M,Y;
	M=month;
	Y=year;
	if (month == 1 || month == 2) {  
        M=month + 12;  
        Y=year-1;  
    } 
	int iWeek = (1 + 2 * M + 3 * (M + 1) / 5 +Y+ Y / 4 - Y / 100 + Y / 400) % 7;  
    int w,i;
    
    w=(iWeek+1)%7;
    if(year %4 ==0 && year%100 !=0 || year %400 ==0){
    	cout << " Sun Mon Tue Wed Thu Fri Sat"<<endl;
   	 	cout << setw(w*4+3);
    	for(i=1;i<=LeapDays[month];i++) { 
			if(w>6) { 
				w=0; 
				cout << endl; 
			} 
				if(i<10) 
					cout << "   " << i; 
				else  
					cout << "  " << i; 
				w++; 
		} 
		cout<<endl; 
	}
	else{
   		cout << " Sun Mon Tue Wed Thu Fri Sat"<<endl;
    	cout << setw(w*4+3);
   		for(i=1;i<=Days[month];i++) { 
			if(w>6) 
			{ 
				w=0; 
				cout << endl; 
			} 
			if(i<10) 
				cout << "   " << i; 
			else  
				cout << "  " << i; 
			w++; 
		} 
	cout<<endl; 

	}
}

