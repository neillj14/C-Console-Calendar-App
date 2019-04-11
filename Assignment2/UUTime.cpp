#include "UUTime.h"

#include <regex>


UUTime::UUTime() {

    //Default constructor 10:00

    hours_ = 10;//default constructor
    minutes_ = 00; //default constructor

}

UUTime::UUTime(int hours, int minutes) {

    //validate minutes and hours. If invalid arguments are supplied time set 
    //to default time

    if (hours >= 0 && hours <= 23) {//the 24 hour should range between 0-23 
        hours_ = hours; //if the hour is between 0 and 23 the hour is correct
    }
    else {
        hours_ = 10; //if the hour is outside 0 and 23 it will be set to the 
        //default value of 10
    }
    if (minutes >= 0 && minutes <= 59) {//the minutes should range between 0-59
        minutes_ = minutes;//if minutes are between 0-59 the minute will set
    }
    else {
        minutes_ = 0;// if minutes are not between 0-59 the minute will set to 
        //default value 00
    }
}

int UUTime::GetHours() const {

    return hours_;

}

void UUTime::SetHours(int hours) {
    //validating hours 

    if (hours >= 0 && hours <= 23) {
        hours_ = hours;
    }

}

int UUTime::GetMinutes() const {

    return minutes_;

}

void UUTime::SetMinutes(int minutes) {

    //setting minutes

    if (minutes >= 0 && minutes <= 59  ) {
        minutes_ = minutes;
    }

}

void UUTime::SetTime(int hours, int minutes) {

    //validating hours

    SetHours(hours);
    SetMinutes(minutes);


}

std::string UUTime::GetTime() const {

    //Time string should be formatted "hh:mm" e.g. 09:09 using 24 hour clock

    //set up a string to hold the completed string 

    std::string time{ "" };

    //check if the hour is less than 10 and add a 0 before it if so

    if (hours_ < 10) {
        time+="0";
    }
    time+=std::to_string(hours_);
    time+=":";

    //check if the minutes is less than 10 and add a 0 before it if so

    if (minutes_ < 10) {
        time+="0";

    }
    time+=std::to_string(minutes_);

    return time;

}

//([0 - 2][0 - 9] : [0 - 5][0 - 9])

bool UUTime::operator==(const UUTime & otherTime)
{
    if (GetTime() == otherTime.GetTime())
    {
        return true;
    }
    return false;
}

bool UUTime::operator<(const UUTime & otherTime)
{
    if (hours_ < otherTime.GetHours()) {
        return true;
    }
    if (hours_ == otherTime.GetHours() && minutes_ < otherTime.GetMinutes()) {
        return true;
    }
    return false;
}

bool UUTime::operator>(const UUTime & otherTime)
{
    if (hours_ > otherTime.GetHours()) {
        return true;
    }
    if (hours_ == otherTime.GetHours() && minutes_ > otherTime.GetMinutes()) {
        return true;
    }
    return false;
}

bool UUTime::operator>=(const UUTime & otherTime)
{
    if (hours_ > otherTime.GetHours()) {
        return true;
    }
    if (hours_ == otherTime.GetHours() && minutes_ > otherTime.GetMinutes()) {
        return true;
    }
    if (GetTime() == otherTime.GetTime())
    {
        return true;
    }
    return false;
}

bool UUTime::operator<=(const UUTime & otherTime)
{
    if (hours_ < otherTime.GetHours()) {
        return true;
    }
    if (hours_ == otherTime.GetHours() && minutes_ < otherTime.GetMinutes()) {
        return true;
    }
    if (GetTime() == otherTime.GetTime())
    {
        return true;
    }
    return false;
}
