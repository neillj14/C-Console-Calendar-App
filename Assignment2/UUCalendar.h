/*
* UUCalendar.cpp
*
* Version information
* Author: Dr. Shane Wilson
* Date:08/10/2018
* Description: This header file declares the interface for the UUCalendar class.
* Do not change the signatures of the provided member functions or attributes
* Copyright notice -
*/
#pragma once

#include <string>
#include <vector>
#include <memory>
#include "UUEntry.h"
#include "UUTime.h"

class UUCalendar
{

private:
	//A vector of UUEntries
	std::vector <UUEntry> calendar_entries_; 
	
public:
	UUCalendar(); //Default constructor
	
	bool AddEntry(const UUEntry& entry);
	bool RemoveEntry(const UUEntry& entry);
	bool UpdateEntry(const std::string& entryDateTime, const UUEntry& newEntryDetails);
	void RemoveAllEntries();
	void RemoveEntriesOnDate(std::string date);
	void RemoveEntriesBetweenDates(std::string startDate, std::string endDate);

	int GetCalenderEntryCount();
	
	//Functions to get Calendar entries
	std::vector <UUEntry> GetCalendarEntriesBetweenDates(std::string startDate, std::string endDate);
	int CountEntries(std::string startDate, std::string endDate);
	std::vector <UUEntry> GetEntriesForGivenDay(std::string date);
	std::vector <UUEntry> GetAllCalendarEntries();
	UUEntry GetEntry(int index);

    //Helper Functions
    bool clash(const UUEntry &entry);
    UUTime GetEndTime(UUEntry entry);
};

