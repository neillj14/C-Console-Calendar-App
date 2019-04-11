/*
* UUDate.cpp
*
* Version information
* Author: Dr. Shane Wilson
* Date:01/10/2018
* Description: This file is the header file for the UUDate class and declares the class interface. 
* The class does not repesent the most elegant or efficient implementation and was designed for the purposes of teaching!
* Add your own UUDate class if you prefer. 
* Copyright notice -
*/ 

#pragma once

#include <string>
#include <iostream>
#include <regex>

//You can include addition non-date/time related headers

const std::regex validDateReg{ R"(\d{1,2}\/\d{1,2}\/\d{4})" };//

class UUDate
{

private:
	//Date data
	int day_;
	int month_;
	int year_;
	
	bool IsLeapYear(int year);
	bool ValidateDay(int day, int month, int year);
	bool ValidateDateValues(int day, int month, int year);

public:
	UUDate(); //Default constructor sets date to 1/1/2000
	
	//Non default constructors - remeber to validate input
	UUDate(int day, int month, int year);
	UUDate(std::string date); //Should accept "2/8/2018" or "02/08/2018
	
	int Between(UUDate date); //Return # days between object and date
	void SetDate(std::string date); //Set the date using a string
	std::string GetDate() const; //Return date as a string in correct format


	//Getters and Setters, remember to validate input to setters
	int GetDay() const;
	void SetDay(int day);
	int GetMonth() const;
	void SetMonth(int month);
	int GetYear() const;
	void SetYear(int year);
	
	void IncrementDate();//Increment the current date by one day

    //Overload ++ to help with calendar
    void operator++();
    bool operator<=(const UUDate & otherDate);

};

