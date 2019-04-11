/*
* UUEntry.cpp
*
* Version information
* Author: Dr. Shane Wilson
* Date:08/10/2018
* Description: This header file declares the interface for the UUEntry class.
* Do not change the signatures of the provided public member functions
* Copyright notice -
*/

#pragma once

#include <string>
#include "UUDate.h"
#include "UUTime.h"

enum UUReminderType { No_Repeat, Daily, Weekly, Monthly, Annually };
/* Notes on reminder repeat modes
* Reminders many or may not repeat.
* Daily - reminder repeats each day at the time specified in the inherited entry dateTime
* Weekly - reminder repeats each week at the time and day specfied in the inherited entry date time
* Monthly - reminder repeats four weeks from the original date
* Yearly - reminder repeats each year on the specified date / time
*
* repeatDuration: n =  reminder repeats for n days, weeks, months or years. Range [0..30] Not including the original date
* repeatDuration: values are ignored if the ReminderType is set to No_Repeat
* 
*/

class UUEntry
{

private:
	UUDate entry_date_; //Date of the entry
	UUTime entry_time_; //Start time of the entry
	int entry_duration_; //in seconds - cannot be > 12 hours, cannot be negative, can be 0
	std::string entry_title_;
	std::string entry_description_;
	
	//Used for reminders only
	UUReminderType entry_repeat_mode_; //Entries may or may not repeat, see comment above
	int entry_repeat_duration_; //How many times the entry repeats. Valid range [0..30]

public:
	UUEntry();
	UUEntry(std::string date, int hours, int minutes, int duration, std::string title, std::string description, UUReminderType repeat, int repeat_duration);
	
	std::string GetEntryDateTime() const;
	void SetEntryDateTime(std::string date, int hours, int minutes);

	std::string GetEntryDateString() const;
	UUDate GetEntryDate() const;
	void SetEntryDate(std::string date); 

	UUTime GetEntryTime() const;
	std::string EntryTimeToString() const;
	void SetEntryTime(int hours, int minutes);

	int GetEntryDuration() const;
	void SetEntryDuration(int duration);
		
	std::string GetEntryTitle() const;
	void SetEntryTitle(std::string title);

	std::string GetEntryDescription() const;
	void SetEntryDescription(std::string description);

	UUReminderType GetEntryReminderType() const;
	void SetEntryReminderType(UUReminderType repeat_type);

	int GetEntryRepeatDuration() const;
	void SetEntryRepeatDuration(int duration);

	//Helpers
	bool operator==(const UUEntry& otherEntry);

};

