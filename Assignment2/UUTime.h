/*
* UUTime.h
*
* Version information
* Author: Dr. Shane Wilson
* Date:08/10/2018
* Description: This header file declares the interface for the UUTime class.
* Do not change the signatures of the provided public member functions
* Copyright notice -
*/

#pragma once
#include <string>
#include <iostream>
#include <regex>

class UUTime
{
    //using 24 hour clock
    int hours_; //Valid range [0..23]
    int minutes_; //Valid range [0..59]

public:
    UUTime();
    UUTime(int hours, int minutes);

    int GetHours() const;
    void SetHours(int hours);

    int GetMinutes() const;
    void SetMinutes(int hours);

    void SetTime(int hours, int minutes);
    std::string GetTime() const;

    bool operator==(const UUTime &otherTime);
    bool operator<(const UUTime &otherTime);
    bool operator>(const UUTime &otherTime);
    bool operator>=(const UUTime &otherTime);
    bool operator<=(const UUTime &otherTime);
};

