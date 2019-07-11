#include <iostream>
#include "0616027_Date.h"
#include "0616027_Date.cpp" 

// Driver Program to check your implementation
int main()
{
    Date date1(3, 8, 2018);
    Date date2 = date1.DateAfter(2100);
    Date date3 = date1.DateBefore(2500);
    
    date1.setDay(25);
    date2.setMonth(12);
    date3.setYear(2015);
	cout << date1.getDay() <<' '<< date1.getMonth() <<' '<< date1.getYear()<<endl;
	cout << date2.getDay() <<' '<< date2.getMonth() <<' '<< date2.getYear()<<endl;
	cout << date3.getDay() <<' '<< date3.getMonth() <<' '<< date3.getYear()<<endl;
	
    cout << date1.numberOfDays() << endl;
    cout << date2.dayOfWeek() << endl;
    date3.printMonthCalendar();
    
    return 0;
}
