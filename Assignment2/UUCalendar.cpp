#include "UUCalendar.h"
#include<cmath>
UUCalendar::UUCalendar() {
    std::vector<UUEntry> entries{};
    calendar_entries_ = entries;
}

//Main calendar entry functions

bool UUCalendar::AddEntry(const UUEntry& entry) {
    //This function should add the entry to the calendar if it doesn't clash 
    //with an existing entry and return true
    //If there is a clash return false and reject the entry
    UUDate nextDate;
    switch (entry.GetEntryReminderType()) {
    case No_Repeat:
        if (!clash(entry)) {
            calendar_entries_.push_back(entry);
            return true;
        }
        else {
            return false;
        }
        break;
    case Daily:
        nextDate = entry.GetEntryDate();
        for (int i = 0; i <= entry.GetEntryRepeatDuration(); ++i) {
            UUEntry nextEntry{ nextDate.GetDate(),
                entry.GetEntryTime().GetHours(),
                entry.GetEntryTime().GetMinutes(),
                entry.GetEntryDuration(), entry.GetEntryTitle(),
                entry.GetEntryDescription(), entry.GetEntryReminderType(),
                entry.GetEntryRepeatDuration() };
            if (!clash(nextEntry)) {
                calendar_entries_.push_back(nextEntry);
                ++nextDate;
            }
            else {
                return false;
            }
        }
        return true;
        break;
    case Weekly:
        nextDate = entry.GetEntryDate();
        for (int i = 0; i <= entry.GetEntryRepeatDuration(); ++i) {
            UUEntry nextEntry{ nextDate.GetDate(),
                entry.GetEntryTime().GetHours(),
                entry.GetEntryTime().GetMinutes(),
                entry.GetEntryDuration(), entry.GetEntryTitle(),
                entry.GetEntryDescription(), entry.GetEntryReminderType(),
                entry.GetEntryRepeatDuration() };
            if (!clash(nextEntry)) {
                calendar_entries_.push_back(nextEntry);
                for (int i = 0; i < 7; ++i) {
                    ++nextDate;
                }
            }
            else {
                for (int i = 0; i < 7; ++i) {
                    ++nextDate;
                }
            }
        }
        return true;
        break;
    case Monthly:
        nextDate = entry.GetEntryDate();
        for (int i = 0; i <= entry.GetEntryRepeatDuration(); ++i) {
            UUEntry nextEntry{ nextDate.GetDate(),
                entry.GetEntryTime().GetHours(),
                entry.GetEntryTime().GetMinutes(),
                entry.GetEntryDuration(), entry.GetEntryTitle(),
                entry.GetEntryDescription(), entry.GetEntryReminderType(),
                entry.GetEntryRepeatDuration() };
            if (!clash(nextEntry)) {
                calendar_entries_.push_back(nextEntry);
                for (int i = 0; i < 28; i++) {
                    ++nextDate;
                }
            }
            else {
                for (int i = 0; i < 28; i++) {
                    ++nextDate;
                }
            }
        }
        return true;
        break;
    case Annually:
        nextDate = entry.GetEntryDate();
        for (int i = 0; i <= entry.GetEntryRepeatDuration(); ++i) {
            UUEntry nextEntry{ nextDate.GetDate(),
                entry.GetEntryTime().GetHours(),
                entry.GetEntryTime().GetMinutes(),
                entry.GetEntryDuration(), entry.GetEntryTitle(),
                entry.GetEntryDescription(), entry.GetEntryReminderType(),
                entry.GetEntryRepeatDuration() };
            if (!clash(nextEntry)) {
                calendar_entries_.push_back(nextEntry);
                nextDate.SetYear(nextDate.GetYear() + 1);
            }
            else {
                nextDate.SetYear(nextDate.GetYear() + 1);
            }
        }
        return true;
        break;
    default:
        return false;
        break;
    }
    return false;
}

bool UUCalendar::RemoveEntry(const UUEntry& entry) {
    //The entry should be removed from the calendar
    //Return true if entry was found and removed otherwise false
    for (int i = 0; i < calendar_entries_.size(); ++i) {
        if (calendar_entries_[i] == entry) {
            calendar_entries_.erase(calendar_entries_.begin() + i);
            return true;
        }
    }
    return false;
}

bool UUCalendar::UpdateEntry(const std::string& entryDateTime, 
    const UUEntry& newEntryDetails) {
    //Attempt to update the entry matching the entryDateTime with the 
    //newEntryDetails, the entry should be rejected if it overlaps with an 
    //existing entry, leaving the existing entry in the calendar, return true 
    //if entry has been updated otherwise false
    for (int i = 0; i < calendar_entries_.size(); ++i) {
        if (calendar_entries_[i].GetEntryDateTime() == entryDateTime) {
            calendar_entries_[i] = newEntryDetails;
            return true;
        }
    }
    return false;

}

void UUCalendar::RemoveAllEntries() {
    //Remove all entries
    for (int i = 0; i < calendar_entries_.size(); ++i) {
        calendar_entries_.clear();
    }
}

void UUCalendar::RemoveEntriesOnDate(std::string date) {
    //Remove all entries on a given date	
    std::vector<UUEntry> entriesNotOnDate{};
    for (int i = 0; i < calendar_entries_.size(); ++i) {
        if (calendar_entries_[i].GetEntryDateString() != date) {
            entriesNotOnDate.push_back(calendar_entries_[i]);
        }
    }
    calendar_entries_ = entriesNotOnDate;
}

std::vector <UUEntry> UUCalendar::GetAllCalendarEntries() {
    //Return a vector of all calendar entires
    return calendar_entries_;
}

std::vector <UUEntry> UUCalendar::GetCalendarEntriesBetweenDates(std::string 
    startDate, std::string endDate) {
    //Return a vector with calendar entries between two dates (including those 
    //dates)
    std::vector <UUEntry> entriesBetween{};
    UUDate currentDate{ startDate };
    UUDate endDateObj{endDate};
    while (currentDate <= endDateObj) {
        for (int i = 0; i < calendar_entries_.size(); ++i) {
            if (calendar_entries_[i].GetEntryDateString() == 
                currentDate.GetDate()) {
                entriesBetween.push_back(calendar_entries_[i]);
            }
        }
        ++currentDate;
    }
    return entriesBetween;
}

void UUCalendar::RemoveEntriesBetweenDates(std::string startDate, 
    std::string endDate) {
    //Remove all entries between two dates
    UUDate currentDate{ startDate };
    while (currentDate.GetDate() <= endDate) {
        for (int i = 0; i < calendar_entries_.size(); ++i) {
            if (calendar_entries_[i].GetEntryDateString() == 
                currentDate.GetDate()) {
                calendar_entries_.erase(calendar_entries_.begin() + i);
            }
        }
        ++currentDate;
    }
}

int UUCalendar::GetCalenderEntryCount() {
    //Return the number of calendar entries
    return (int)calendar_entries_.size();
}

int UUCalendar::CountEntries(std::string startDate, std::string endDate) {
    //Return the number of calendar entries between two dates
    int entriesBetween{ 0 };
    UUDate currentDate{ startDate };
    while (currentDate.GetDate() <= endDate) {
        for (int i = 0; i < calendar_entries_.size(); ++i) {
            if (calendar_entries_[i].GetEntryDateString() == 
                currentDate.GetDate()) {
                ++entriesBetween;
            }
        }
        ++currentDate;
    }
    return entriesBetween;
}

std::vector <UUEntry> UUCalendar::GetEntriesForGivenDay(std::string date) {
    //Return a vector containing any and all entries within the calendar for 
    //the given date.
    //If there are no matching entries, return an empty vector of UUEntry
    std::vector <UUEntry> entriesOn{};
    for (int i = 0; i < calendar_entries_.size(); ++i) {
        if (calendar_entries_[i].GetEntryDateString() == date) {
            entriesOn.push_back(calendar_entries_[i]);
        }
    }
    return entriesOn;
}

UUEntry UUCalendar::GetEntry(int index) {
    //Return the entry in the calendar at the index if it exists
    //Otherwise return an empty entry
    try {
        UUEntry* entryAtIndex = &calendar_entries_[index];
        return *entryAtIndex;
    }
    catch (std::exception e) {
        return UUEntry{};
    }
}

bool UUCalendar::clash(const UUEntry &entry)
{
    //Iterate through the vector
    for (int i = 0; i < calendar_entries_.size(); ++i) {
        //If the current existing event is on the same date as the new event
        if (calendar_entries_[i].GetEntryDateString() == 
            entry.GetEntryDateString()) {
            //If the CEE starts at the same time as the NE
            if (calendar_entries_[i].GetEntryTime() == entry.GetEntryTime()) {
                return true;
            }
            //If the CEE starts before the NE and finishes during the NE
            if ((calendar_entries_[i].GetEntryTime() <= entry.GetEntryTime()) 
                && GetEndTime(entry) <= GetEndTime(calendar_entries_[i])) {
                return true;
            }
            //If the CEE starts after the NE and finishes during it
            if ((calendar_entries_[i].GetEntryTime() >= entry.GetEntryTime()) 
                && GetEndTime(entry) <= GetEndTime(calendar_entries_[i])) {
                return true;
            }
        }
    }
    return false;
}

UUTime UUCalendar::GetEndTime(UUEntry entry) {
    UUTime endTime{ entry.GetEntryTime().GetHours(),
        entry.GetEntryTime().GetMinutes() };
    double hours{ std::floor(entry.GetEntryDuration() / 3600) };
    double minutes{ std::floor((entry.GetEntryDuration() % 3600) / 60) };
    endTime.SetTime(endTime.GetHours() + (int)hours, endTime.GetMinutes() + 
        (int)minutes);
    return endTime;
}