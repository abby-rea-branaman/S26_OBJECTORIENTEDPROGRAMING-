#ifndef dateType_H
#define dateType_H 
   
class dateType 
{
public:
    void setDate(int month, int day, int year);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void printDate() const;

	dateType(int month = 1, int day= 1, int year= 1900);

    bool isLeapYear() const;

private:
    int dMonth; //variable to store the month
    int dDay;   //variable to store the day
    int dYear;  //variable to store the year
};

#endif