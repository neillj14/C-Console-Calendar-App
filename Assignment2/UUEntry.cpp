#include "UUEntry.h"
#include <string>

UUEntry::UUEntry() {
    //Default constructor should initialise the data members to the following 
    //default values
    // date time : 10:00, 01/01/2000 
    //Repeat mode: No_Repeat
    //Repeat duration 0
    //TODO Add your implementation
    //Deafult entry title should be: "YAM"
    //Default entry desription should be: "Yet another meeting"
    //Default entry repeat mode is: No_Repeat
    //Default entry duration should be 0
    entry_repeat_duration_ = 0;
    entry_title_ = "YAM";
    entry_description_ = "Yet another meeting";
    entry_repeat_mode_ = No_Repeat;
    entry_duration_ = 0;
}

UUEntry::UUEntry(std::string date, int hours, int minutes, int duration,
    std::string title, std::string description, UUReminderType repeat,
    int repeat_duration):entry_date_{ UUDate{date} },
    entry_time_{ UUTime{hours, minutes} },
    entry_duration_{ duration },
    entry_title_{ title },
    entry_description_{ description },
    entry_repeat_mode_{ repeat },
    entry_repeat_duration_{ repeat_duration } {
    //Non-default constructor should initialise the entry with arguments
    //TODO Add your implementation
}



std::string UUEntry::GetEntryDateTime() const {
    //Return the date and time of the entry as a string

    //TODO - Add your implementation
    //Function should return date time in a string in the following format
    // 10:00 - 21/10/2018
    std::string DateTime{ entry_time_.GetTime() + " - " + 
        entry_date_.GetDate() };
    return DateTime;
}

void UUEntry::SetEntryDateTime(std::string date, int hours, int minutes) {
    //Set the date and time for the entry

    //Values should be validated 
    //Invalid arguments should be ignored and object data unchanged
    UUDate testingValue{ date };
    if (testingValue.GetDate() == date) {
        entry_date_.SetDate(date);
    }
    entry_time_.SetTime(hours, minutes);
}

std::string UUEntry::GetEntryDateString() const {
    //Return the date string 
    //TODO Add your implementation here
    return entry_date_.GetDate();
}

UUDate UUEntry::GetEntryDate() const {
    //Return the entry date as a UUDate
    //TODO Add your implementation here
    return entry_date_;
}
void UUEntry::SetEntryDate(std::string date) {
    //Set the entry date
    //TODO Add your implementation here
    entry_date_ = date;
}

UUTime UUEntry::GetEntryTime() const {
    //Get the entry time as a UUTime
    return entry_time_;
}
std::string UUEntry::EntryTimeToString() const {
    //Retunr the entry time as a UUTime
    //TODO add your implementation here
    return entry_time_.GetTime();
}
void UUEntry::SetEntryTime(int hours, int minutes) {
    //Set the entry time using int as hours and minutes
    //TODO add your implementation here
    entry_time_.SetTime(hours, minutes);
}

int UUEntry::GetEntryDuration() const {
    //Return the duration in seconds of the entry as an int 
    //TODO add your implementation here
    return entry_duration_;
}
void UUEntry::SetEntryDuration(int duration) {
    //Set the duration in seconds of the entry
    //The duration cannot exceed 12 hours or be negative. It can be 0
    //TODO add your implementation here
    if (duration >= 0 && duration <= (3600 * 12))
    {
        entry_duration_ = duration;
    }
}

std::string UUEntry::GetEntryTitle() const {
    //Return the title of the event
    //TODO - Add your implementation
    return entry_title_;
}

void UUEntry::SetEntryTitle(std::string title) {
    //Set the event title
    //TODO - Add your implementation
    entry_title_ = title;
}

std::string UUEntry::GetEntryDescription() const {
    //Get the entry description
    //TODO - Add your implementation
    return entry_description_;
}

void UUEntry::SetEntryDescription(std::string description) {
    //Set the event description 
    //TODO - Add your implementation
    entry_description_ = description;
}

UUReminderType UUEntry::GetEntryReminderType() const {
    //Get the entry reminder type
    //TODO - Add your implementation
    return entry_repeat_mode_;
}
void UUEntry::SetEntryReminderType(UUReminderType repeat_type) {
    //Set the entry reminder type
    //TODO - Add your implementation
    entry_repeat_mode_ = repeat_type;
}

int UUEntry::GetEntryRepeatDuration() const {
    //Get the entry repeat duration 
    //TODO - Add your implementation
    return entry_repeat_duration_;
}

void UUEntry::SetEntryRepeatDuration(int duration) {
    //Set the repeat duration
    //Valid range is [0..30]
    //Invalid value should be set to 0

    //TODO - Add your implementation
    entry_repeat_duration_ = duration;
}

bool UUEntry::operator==(const UUEntry & otherEntry)
{
    if (this->entry_date_.GetDate() == otherEntry.GetEntryDate().GetDate()) {
        if (this->entry_time_.GetTime() == otherEntry.GetEntryTime().GetTime()) {
            if (entry_duration_ == otherEntry.GetEntryDuration()) {
                if (entry_title_ == otherEntry.GetEntryTitle()) {
                    if (entry_description_ == otherEntry.GetEntryDescription()) {
                        if (entry_repeat_mode_ == otherEntry.GetEntryReminderType()) {
                            if (entry_repeat_duration_ == otherEntry.GetEntryRepeatDuration()) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}