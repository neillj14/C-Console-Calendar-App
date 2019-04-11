#include "UUDate.h"

UUDate::UUDate(){
	//Initialise the date to 01/01/2000
	day_ = 01;
	month_ = 01;
	year_ = 2000;
}

UUDate::UUDate(int day, int month, int year){
	//Check that the values are valid
	if(ValidateDateValues(day, month, year)) {
		day_ = day;
		month_ = month;
		year_ = year;
	}
	else { //not a valid date so set it to 01/01/2000
		day_ = 01;
		month_ = 01;
		year_ = 2000;

	}
	
}

UUDate::UUDate(std::string date) {
	//This member function first checks that the date string is in the correct format
	//If it isn't it sets the date object to a default value of 01/01/2000
	//Valid format is 01/01/2001 or 1/1/2001

	int day, month, year;
	int forwardslash{ 0 };

	std::string substring{ "" };

	//Use the regular expression to check the date format
	if (!std::regex_match(date, validDateReg)) {
		std::cerr << "Invalid date string format for constructor argument" << std::endl;

		//Set default value for the date
		day_ = 01;
		month_ = 01;
		year_ = 2000;
		return;
	}
	//The string matches the date regular expression so extract the date values
	for (std::size_t index = 0; index < date.length(); ++index) {
		//Keep reading until we get a '/' characters
		if (date[index] == '/'){
			++forwardslash;
			if (forwardslash==1) { //we have the day
				day = std::stoi(substring);
				substring = "";
			}
			else if (forwardslash==2){ //must be month values
				month = std::stoi(substring);
				substring = "";
			}
		}
		else {//add number to substring
			substring += date[index];
		}
	}
	//We got to the end of the date string, the last 4 characters are the year
	year = std::stoi(substring);

	if (ValidateDateValues(day, month, year)) {
		day_ = day;
		month_ = month;
		year_ = year;
	}
	else { //not a valid date so set it to 01/01/2000
		day_ = 01;
		month_ = 01;
		year_ = 2000;

	}
}

bool UUDate::ValidateDateValues(int day, int month, int year) {
	// Validate the day, month and year to ensure they 
	// are valid numbers for dates
	if (year == 0) {
		std::cerr << "The year cannot be 0" << std::endl;
		return false;
	}
	if ((month < 1) || (month > 12) ){
		std::cerr << "The month must be between 1 and 12" << std::endl;
		return false;
	}
	
	return ValidateDay(day, month, year);
}

bool UUDate::ValidateDay(int day, int month, int year) {
	if (day < 1) {
		std::cerr << "Invalid day argument: The day cannot be a negative value" << std::endl;
		return false;
	}
	switch (month)
	{
	case 1: {
		if (day > 31) {
			std::cerr << "Invalid day argument: The month Janurary does not have > 31 days" << std::endl;
			return false;
		}
		break;
	}
	case 3: {
		if (day > 31) {
			std::cerr << "Invalid day argument: The month March does not have > 31 days" << std::endl;
			return false;
		}
		break;
	}
	case 5: {
		if (day > 31) {
			std::cerr << "Invalid day argument: The month May does not have > 31 days" << std::endl;
			return false;
		}
		break;
	}
	case 7: {
		if (day > 31) {
			std::cerr << "The month July does not have > 31 days" << std::endl;
			return false;
		}
		break;
	}
	case 8: {
		if (day > 31) {
			std::cerr << "Invalid day argument: The month August does not have > 31 days" << std::endl;
			return false;
		}
		break;
	}
	case 10: {
		if (day > 31) {
			std::cerr << "Invalid day argument: The month October does not have > 31 days" << std::endl;
			return false;
		}
		break;
	}
	case 12: {
		if (day > 31) {
			std::cerr << "Invalid day argument: The month December does not have > 31 days" << std::endl;
			return false;
		}
		break;
	}
	case 4: {
		if (day > 30) {
			std::cerr << "Invalid day argument: The month April does not have > 30 days" << std::endl;
			return false;
		}
		break;
	}
	case 6: {
		if (day > 30) {
			std::cerr << "Invalid day argument: The month June does not have > 30 days" << std::endl;
			return false;
		}
		break;
	}
	case 9: {
		if (day > 30) {
			std::cerr << "Invalid day argument: The month September does not have > 30 days" << std::endl;
			return false;
		}
		break;
	}
	case 11: {
		if (day > 30) {
			std::cerr << "Invalid day argument: The month Novemeber does not have > 30 days" << std::endl;
			return false;
		}
		break;
	}
	case 2: {
		if ((day < 0) || (day > 29)) {
			std::cerr << "Invalid day argument: The month February does not have > 30 days" << std::endl;
			return false;
		}
		
		if (day == 29 && IsLeapYear(year) == false) {
			std::cerr << "Invalid day argument: The month February does not have > 30 days" << std::endl;
			return false;
		}
		break;
	}
	default:
		return true;
	}
	return true;
}

void UUDate::IncrementDate() {
	//Add to day
	++day_;
	switch (month_)
	{
		case 1: {
			if (day_ > 31) {
				++month_;
				day_ = 1;
				break;
			}
			break;
		}

		case 3: {
			if (day_ > 31) {
				++month_;
				day_ = 1;
				break;
			}
			break;
		}
		case 4: {
			if (day_ > 30) {
				//Increment month, set day to 1
				++month_;
				day_ = 1;
				break;
			}
			break;
		}
		
		case 5: {
			if (day_ > 31) {
				++month_;
				day_ = 1;
				break;
			}
			break;
		}
		case 6: {
			if (day_ > 30) {
				//Increment month, set day to 1
				++month_;
				day_ = 1;
				break;
			}
			break;
		}
		case 7: {
			if (day_ > 31) {
				++month_;
				day_ = 1;
				break;
			} 
			break;
		}
		case 8: {
			if (day_ > 31) {
				++month_;
				day_ = 1;
				break;
			}
			break;
		}
		case 9: {
			if (day_ > 30) {
				//Increment month, set day to 1
				++month_;
				day_ = 1;
				break;
			}
			break;
		}
		case 10: {
			if (day_ > 31) {
				++month_;
				day_ = 1;
				break;
			}
			break;
		}
		case 11: {
			if (day_ > 30) {
				++month_;
				day_ = 1;
				break;
			}
			break;
		}
	
		case 12: {
			if (day_ > 31) {
				//Increment year, set month and day to 1
				++year_;
				month_ = 1;
				day_ = 1;
				break;
			}
			break;
		}
		
		
		case 2:
			if (((day_ == 29) && (IsLeapYear(year_) == false)) || (day_ == 30)) {
				//Increment month, set day to 1
				++month_;
				day_ = 1;
				break;
			}
			break;
		
		default:
			break;
		
		}
}

void UUDate::operator++()
{
    this->IncrementDate();
}

bool UUDate::operator<=(const UUDate & otherDate)
{
    if (day_ < otherDate.day_ && month_ <= otherDate.month_ && year_ <= otherDate.year_) {
        return true;
    }
    else if (month_ < otherDate.month_ && year_ <= otherDate.year_) {
        return true;
    }
    else if (year_ < otherDate.year_) {
        return true;
    }
    else if (day_ == otherDate.day_ && month_ == otherDate.month_ && year_ == otherDate.year_) {
        return true;
    }
    else {
        return false;
    }
}

int UUDate::Between(UUDate date) {
	int days_between{ 0 };
// Increment by one until the dates are the same?
	//Which date is earliest 
	if ((day_ == date.GetDay()) && (month_ == date.GetMonth()) && (year_ == date.GetYear())){
		//The dates are the same
		return 0;
	}

	//if (year_ < date.GetYear()) {
		UUDate temp_date{day_, month_, year_};
		while ((temp_date.GetDay() != date.GetDay()) || (temp_date.GetMonth() != date.GetMonth()) || (temp_date.GetYear() != date.GetYear())) {
		
			temp_date.IncrementDate();
			++days_between;
		}
		return days_between;
	//}
	//return daysBetween;
}

bool UUDate::IsLeapYear(int year) {
	if (year < -46) // 46 BC
		return false;
	 // Gregorian  Calendar
	
	return ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)));
 }

int UUDate::GetDay() const { return day_; }

void UUDate::SetDay(int day) {
	//Validate input
	if (ValidateDay(day, month_, year_)) {
		day_ = day;
	}
}

int UUDate::GetMonth() const { return month_; }
void UUDate::SetMonth(int month) {
	if ((month < 1) || (month > 12)) {
		std::cerr << "Invalid month argument: " << month << ". " << "Valid month values must be within the range [1..12]" << std::endl;
	}
	else {
		month_ = month;
	}
}
int UUDate::GetYear() const { return year_; }

void UUDate::SetYear(int year) {
	if (year == 0) {
		std::cerr << "Invalid year argument: " << year << ". " << "The year cannot be 0" << std::endl;
	}
	else {
		year_ = year;
	}
}

std::string UUDate::GetDate() const {
	std::string date;
	if (day_ <= 9) {
		date.append("0");
	}
	date.append(std::to_string(day_) + "/");
	if (month_ <= 9) {
		date.append("0");
	}
	date.append(std::to_string(month_) + "/" + std::to_string(year_));
	return date;
}

void UUDate::SetDate(std::string date) {

	int day, month, year;
	int forwardslash{ 0 };

	std::string substring{ "" };

	//Use the regular expression to check the date format
	if (!std::regex_match(date, validDateReg)) {
		//If the string doesn't match don't do anything and just return
		return;
	}
	//The string matches the date regular expression so extract the date values
	for (std::size_t index = 0; index < date.length(); ++index) {
		//Keep reading until we get a '/' characters
		if (date[index] == '/') {
			++forwardslash;
			if (forwardslash == 1) { //we have the day
				day = std::stoi(substring);
				substring = "";
			}
			else if (forwardslash == 2) { //must be month values
				month = std::stoi(substring);
				substring = "";
			}
		}
		else {//add number to substring
			substring += date[index];
		}
	}
	//We got to the end of the date string, the last 4 characters are the year
	year = std::stoi(substring);

	if (ValidateDateValues(day, month, year)) {
		day_ = day;
		month_ = month;
		year_ = year;
	}
	
} 