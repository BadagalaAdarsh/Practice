#include<bits/stdc++.h>
using namespace std;

bool isLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    }
    if (year % 100 == 0) {
        return false;
    }
    if (year % 4 == 0) {
        return true;
    }
    return false;
}


int main() {

    // take two inputs as dd mm yyyy
    int startingDate, startingMonth, startingYear;
    int endingDate, endingMonth, endingYear;

    int monthDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // take input for starting date
    cin >> startingDate >> startingMonth >> startingYear;

    // take input for ending date
    cin >> endingDate >> endingMonth >> endingYear;

    int numberOfYears = 0, numberOfMonths = 0, numberOfDays = 0;

    if (endingMonth > startingMonth) {
        numberOfYears = endingYear - startingYear;
        numberOfMonths = endingMonth - startingMonth;
        numberOfDays = endingDate - startingDate + 1;

        if (isLeapYear(endingYear)){
            monthDays[2] = 29;
        }

        if(numberOfDays == monthDays[endingMonth]){
            numberOfDays = 0;
            numberOfMonths++;
        }

        if(numberOfMonths == 12){
            numberOfMonths = 0;
            numberOfYears++;
        }

    }

    else if (endingMonth < startingMonth) {
        numberOfYears = endingYear - startingYear - 1;
        numberOfMonths = 12 - startingMonth + endingMonth;
        numberOfDays = endingDate - startingDate + 1;

        if (isLeapYear(endingYear)){
            monthDays[2] = 29;
        }

        if(numberOfDays == monthDays[endingMonth]){
            numberOfDays = 0;
            numberOfMonths++;
        }

        if(numberOfMonths == 12){
            numberOfMonths = 0;
            numberOfYears++;
        }
    }

    else {
        if (endingDate > startingDate) {
            numberOfYears = endingYear - startingYear;
            numberOfMonths = endingMonth - startingMonth;
            numberOfDays = endingDate - startingDate + 1;

            if (isLeapYear(endingYear)){
                monthDays[2] = 29;
            }

            if(numberOfDays == monthDays[endingMonth]){
                numberOfDays = 0;
                numberOfMonths++;
            }

            if(numberOfMonths == 12){
                numberOfMonths = 0;
                numberOfYears++;
            }
        }

        else if (endingDate < startingDate) {
            numberOfYears = endingYear - startingYear - 1;
            numberOfMonths = 12 - startingMonth + endingMonth;
            numberOfDays = endingDate - startingDate + 1;

            if (isLeapYear(endingYear)){
                monthDays[2] = 29;
            }

            if(numberOfDays == monthDays[endingMonth]){
                numberOfDays = 0;
                numberOfMonths++;
            }

            if(numberOfMonths == 12){
                numberOfMonths = 0;
                numberOfYears++;
            }
        }

        else {
            numberOfYears = endingYear - startingYear;
            numberOfMonths = 0;
            numberOfDays = 0;
        }
    }

    cout << numberOfYears << " " << numberOfMonths << " " << numberOfDays << endl;

}