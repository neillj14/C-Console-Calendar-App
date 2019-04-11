#include "pch.h"

int currentPoints = 0;
int maxPoints = 100;

//UUTime tests

TEST(UUTime, TestTimeConstructor1)
{
	std::cout << "\nRunning test TestConstructor 1" << std::endl;

	//Arrange
	int expected_result{10};
	int actual_result {0};
		

	//ACT
	UUTime newTime{};
	actual_result = newTime.GetHours();


	//Assert
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 1; //add points
		std::cout << "Test UUTime constructor PASSED! : The default UUTime constructor sets the time correctly" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "Test UUTime constructor FAILED! : The default UUTime constructor doesn't set the time correctly " << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUTime, TestTimeConstructor2)
{
	std::cout << "\nRunning test TimeConstructor2 " << std::endl;

	//Arrange
	int expected_result{ 15 };
	int actual_result{ 15 };


	//ACT
	UUTime newTime{15,15};
	actual_result = newTime.GetHours();


	//Assert
	ASSERT_EQ(expected_result, actual_result);
	actual_result = newTime.GetMinutes();
	ASSERT_EQ(expected_result, actual_result);

	

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 1; //add points
		std::cout << "Test UUTime constructor2 PASSED! : The default UUTime constructor sets the time correctly when supplied arguments" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "Test UUTime constructor2 FAILED! : The default UUTime constructor does not set the time correctly when supplied with arguments" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUTime, TestTimeConstructor3)
{
	std::cout << "\nRunning test TimeConstructor2 " << std::endl;

	//Arrange
	int expected_result{ 10 };
	int actual_result{};


	//ACT
	UUTime newTime{ 25,15 };
	actual_result = newTime.GetHours();


	//Assert
	ASSERT_EQ(expected_result, actual_result);
	
	expected_result= 15;
	actual_result = newTime.GetMinutes();
	ASSERT_EQ(expected_result, actual_result);
	   
	if (!HasFailure()) {
		//Test has passed
		currentPoints += 2; //add points
		std::cout << "Test UUTime constructor3 PASSED! : The default UUTime constructor sets the time correctly when supplied with invalid arguments" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "Test UUTime constructor2 FAILED! : The default UUTime constructor does not set the time correctly when supplied with invalid arguments" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUTime, TestSetTime1)
{
	std::cout << "\nRunning test SetTime" << std::endl;

	//Arrange
	int expected_result{ 16 };
	int actual_result{};
	UUTime newTime{ 12,15 };


	//ACT
	newTime.SetTime(16, 20);
	actual_result = newTime.GetHours();


	//Assert
	ASSERT_EQ(expected_result, actual_result);

	expected_result= 20;
	actual_result = newTime.GetMinutes();
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 2; //add points
		std::cout << "Test UUTime SetTime PASSED! : The UUTime SetTime function correctly sets time with valid arguments" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "Test UUTime SetTime FAILED! : The UUTime SetTime function incorrectly sets time with invalid arguments" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUTime, TestSetTime2)
{
	std::cout << "\nRunning test SetTime with bad arguments" << std::endl;

	//Arrange
	int expected_result{ 12 };
	int actual_result{};
	UUTime newTime{ 12,15 };


	//ACT
	newTime.SetTime(26, 61);
	actual_result = newTime.GetHours();


	//Assert
	ASSERT_EQ(expected_result, actual_result);

	expected_result = 15;
	actual_result = newTime.GetMinutes();
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 2; //add points
		std::cout << "Test UUTime SetTime with bad arguments PASSED! : The UUTime SetTime function correctly ignores invalid arguments" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "Test UUTime SetTime wiht bad arguments FAILED! : The UUTime SetTime function incorrectly sets time with invalid arguments" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUTime, TestGetTime)
{
	std::cout << "\nRunning test GetTime " << std::endl;

	//Arrange
	std::string expected_result{"08:27"};
	std::string actual_result{};
	UUTime newTime{ 8,27 };


	//ACT
	actual_result = newTime.GetTime();


	//Assert
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 2; //add points
		std::cout << "Test UUTime GetTime PASSED! : The UUTime GetTime function returns time as a string" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "Test UUTime GetTime FAILED! : The UUTime GetTime function does not return time as a correclty formatted string, eg 9:42" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

//UUEntry tests

TEST(UUEntry, TestUUEntryDefaultConstructor)
{
	std::cout << "\nRunning TestUUEntryDefaultConstructor " << std::endl;

	//Arrange
	std::string expected_result{ "YAM"};
	std::string actual_result{ };
	int expected_duration{0};
	int actual_duration{};
	//Test default constructor


	//ACT
	UUEntry newEntry{};
	actual_result = newEntry.GetEntryTitle();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	//Check other object attributes

	expected_result = "Yet another meeting";
	actual_result = newEntry.GetEntryDescription();
	ASSERT_EQ(expected_result, actual_result);

	
	actual_duration = newEntry.GetEntryDuration();
	ASSERT_EQ(expected_duration, actual_duration);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 2; //add points
		std::cout << "TestUUEntryConstructor1 PASSED! : UUEntry() correctly creating a UUEntry object " << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestUUEntryConstructor1 FAILED! : UUEntry() incorrectly creating a UUEntry object - are you setting all of the attributes correctly?" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUEntry, TestUUEntryCustomConstructor)
{
	std::cout << "\nRunning TestUUEntryCustomConstructor " << std::endl;

	//Arrange
	std::string  expected_string_result{ "Play lotto" };
	std::string  actual_string_result;

	int expected_int_result{0};
	int actual_int_result;

	
	//ACT
	UUEntry newEntry{ "09/11/2018", 18,30,0,"Play lotto", "Play Euromillions",UUReminderType::Weekly,0 };
	actual_string_result = newEntry.GetEntryTitle();

	//Assert
	ASSERT_EQ(expected_string_result, actual_string_result);

	//Check other object attributes
	expected_string_result = "Play Euromillions";
	actual_string_result = newEntry.GetEntryDescription();
	ASSERT_EQ(expected_string_result, actual_string_result);

	actual_int_result = newEntry.GetEntryRepeatDuration();
	ASSERT_EQ(expected_int_result, actual_int_result);


	//ASSERT_EQ(expected_result, actual_result);
	
	if (!HasFailure()) {
		//Test has passed
		currentPoints += 6; //add points
		std::cout << "TestUUEntryCustomConstructor PASSED! : UUEntry - custom constructor correctly creating a UUEntry object " << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestUUEntryCustomConstructor FAILED! : UUEntry - custom constructor isn not correctly creating a UUEntry object " << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUEntry, TestUUEntrySetDate)
{
	std::cout << "\nRunning  Test UUEntry SetDate " << std::endl;

	//Arrange
	std::string expected_result{ "23/07/1997" };
	std::string actual_result{ };
	
	//Test default constructor

		//ACT
	UUEntry newEntry{};
	newEntry.SetEntryDate("23/07/1997");
	actual_result = newEntry.GetEntryDateString();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 1; //add points
		std::cout << "TestUUEntrySetDate PASSED! : SetEntryDate() correctly setting the date of a UUEntry object " << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestUUEntrySetDate FAILED! : SetEntryDate() incorrectly setting the date of a UUEntry object " << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUEntry, TestUUEntrySetDuration1)
{
	std::cout << "\nRunning TestUUEntry SetDuration 1  " << std::endl;

	//Arrange
	int expected_result{ 3600};
	int actual_result{ };

	//ACT
	UUEntry newEntry{};
	newEntry.SetEntryDuration(3600);
	actual_result = newEntry.GetEntryDuration();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 1; //add points
		std::cout << "TestUUEntrySetDuration PASSED! : SetDuration() correctly sets the duration of a UUEntry object with valid duration" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestUUEntrySetDuration FAILED! : SetDuration() incorrectly sets the duration of a UUEntry object with valid duration" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUEntry, TestUUEntrySetDuration2)
{
	std::cout << "\nRunning TestUUEntry SetDuration 2 - with invalid data " << std::endl;

	//Arrange
	int expected_result{ 0 };
	int actual_result{ };

	//ACT
	UUEntry newEntry{};
	newEntry.SetEntryDuration(43201);
	actual_result = newEntry.GetEntryDuration();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 2; //add points
		std::cout << "TestUUEntrySetDuration PASSED! : SetDuration() ignores invalid duration values " << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestUUEntrySetDuration FAILED! : Entry duration should not exceed 12 hours" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUEntry, TestUUEntryDateTime)
{
	std::cout << "\nRunning TestUUEntryDateTime" << std::endl;

	//Arrange
	std::string expected_result{ "08/03/1568" };
	std::string actual_result{ };
	int expected_time_result{ 15 };
	int actual_time_result{ };

	//ACT
	UUEntry newEntry{};
	newEntry.SetEntryDateTime("08/03/1568",15,36);
	actual_result = newEntry.GetEntryDateString();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	//Check the time
	UUTime tempTime = newEntry.GetEntryTime();
	actual_time_result = tempTime.GetHours();
	ASSERT_EQ(expected_time_result, actual_time_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "Test TestUUEntryDateTime PASSED! : SetEntryDateTime and GetEntryDateTime work " << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "Test TestUUEntryDateTime FAILED! : Either SetEntryDateTime or GetEntryDateTime work did not work" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUEntry, TestUUEntryReminder)
{
	std::cout << "\nRunning TestUUEntry TestUUEntryReminderType" << std::endl;

	//Arrange
	UUReminderType expected_result{ UUReminderType::Daily };
	UUReminderType actual_result{ };
	
	//ACT
	UUEntry newEntry{};
	newEntry.SetEntryReminderType(UUReminderType::Daily);
	actual_result = newEntry.GetEntryReminderType();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestUUEntryReminder PASSED! : SetEntryReminder and GetEntryReminder function correctly" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestUUEntryReminder FAILED! : SetEntryReminder and GetEntryReminder do not function correctly" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

//UUCalendar tests

TEST(UUCalendar, TestAddEntry)
{
	std::cout << "\nRunning TestAddEntry to calendar " << std::endl;

	//Arrange
	int expected_result{ 5 };
	int actual_result{ 0 };

	UUCalendar myCalendar;
	UUEntry newEntry{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "17/06/2019", 18,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "18/06/2019", 20,30,4890,"Meet Niall", "Meet Niall for pints",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 18,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };

	//ACT
	myCalendar.AddEntry(newEntry);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);

	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(expected_result, actual_result);
	
	//Test an actual entry has been added
	UUEntry temp = myCalendar.GetEntry(2);

	std::string actual_title = temp.GetEntryTitle();
	std::string expected_title = "Fix lock";

	ASSERT_EQ(expected_title, actual_title);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestAddEntry PASSED! : AddEntry correctly adding an entry to the calendar" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestAddEntry Failed! : AddEntry is not adding an entry to the calendar. Are you sure your entry constructor and AddEntry functions work?" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}


TEST(UUCalendar, TestRemoveEntry)
{
	std::cout << "\nRunning TestRemoveEntry from the calendar " << std::endl;

	//Arrange
	int expected_result{ 4 };
	int actual_result{ 0 };

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "17/06/2019", 18,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "18/06/2019", 20,30,4890,"Meet Niall", "Meet Niall for pints",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 18,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };

	//ACT
	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);

	myCalendar.RemoveEntry(newEntry3);

	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	//Test the correct entry was removed entry has been added
	UUEntry temp = myCalendar.GetEntry(2); //Should not be Entry4

	std::string actual_title = temp.GetEntryTitle();
	std::string expected_title = "Meet Niall";

	ASSERT_EQ(expected_title, actual_title);


	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestRemoveEntry PASSED! : RemoveEntry correctly removed an entry from the calendar" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestRemoveEntry Failed! : RemoveEntry is not removing an entry from the calendar. Are you removing the correct entry n the calendar?" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestUpdateEntry)
{
	std::cout << "\nRunning TestUpdatingEntry in the calendar " << std::endl;

	//Arrange
	std::string expected_result{ "Swim with white sharks"};
	std::string actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "17/06/2019", 18,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "18/06/2019", 20,30,4890,"Meet Niall", "Meet Niall for pints",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 18,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };

	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);

	newEntry4.SetEntryTitle("Swim with white sharks");

	//ACT
	myCalendar.UpdateEntry(newEntry4.GetEntryDateTime(), newEntry4);

	actual_result = myCalendar.GetEntry(3).GetEntryTitle();

	//Assert
	ASSERT_EQ(expected_result, actual_result);


	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestUpdateEntry PASSED! : UpdateEntry correctly updated an entry in the calendar" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestUpdateEntry Failed! : UpdateEntry is not updating an entry in the calendar. Check UUEntry setters, getters and the UpdateEntry function" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestRemoveAllEntries)
{
	std::cout << "\nRunning TestRemoveAllEntries from the calendar " << std::endl;

	//Arrange
	int expected_result{ 0};
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "17/06/2019", 18,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "18/06/2019", 20,30,4890,"Meet Niall", "Meet Niall for pints",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 18,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };

	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);


	//ACT
	myCalendar.RemoveAllEntries();

	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(expected_result, actual_result);


	if (!HasFailure()) {
		//Test has passed
		currentPoints += 2; //add points
		std::cout << "TestRemoveAllEntries PASSED! : RemoveAllEntries correctly deleted all entries in the calendar" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestRemoveAllEntries Failed! : RemoveAllEntries did not delete all entries in the calendar. Check the RemoveAllEntries() function" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestRemoveEntriesOnDate)
{
	std::cout << "\nRunning RemoveEntriesOnDate on the calendar " << std::endl;

	//Arrange
	int expected_result{ 2 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "19/06/2019", 19,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "19/06/2019", 10,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "19/06/2019", 15,30,4890,"Meet Niall", "Meet Niall for pints",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	

	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);


	//ACT
	myCalendar.RemoveEntriesOnDate("19/06/2019");

	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(expected_result, actual_result);


	if (!HasFailure()) {
		//Test has passed
		currentPoints += 3; //add points
		std::cout << "TestRemoveEntriesOnDate PASSED! : RemoveEntriesOnDate correctly deleted all entries in the calendar for a given date" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestRemoveEntriesOnDate Failed! : RemoveEntriesOnDate did not delete all entries in the calendar for a given date. Check the RemoveAllEntries() function" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestRemoveEntriesBetweenDates)
{
	std::cout << "\nRunning TestRemoveEntriesBetweenDates on the calendar " << std::endl;

	//Arrange
	int expected_result{ 2 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "17/06/2019", 19,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "18/06/2019", 10,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 15,30,4890,"Meet Niall", "Meet Niall for pints",UUReminderType::No_Repeat,0 };


	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);


	//ACT
	myCalendar.RemoveEntriesBetweenDates("17/06/2019", "19/06/2019");

	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(expected_result, actual_result);


	if (!HasFailure()) {
		//Test has passed
		currentPoints += 3; //add points
		std::cout << "TestRemoveEntriesBetweenDates PASSED! : RemoveEntriesBetweenDates correctly deleted all entries in the calendar between the specified dates" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestRemoveEntriesBetweenDates Failed! : RemoveEntriesBetweenDates did not delete all entries in the calendar between the specified dates. Check the RemoveEntriesBetweenDates() function" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestGetEntriesBetweenDates)
{
	std::cout << "\nRunning GetCalendarEntriesBetweenDates on the calendar " << std::endl;

	//Arrange
	int expected_result{3};
	int actual_result{};
	
	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "17/06/2019", 19,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "18/06/2019", 10,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 15,30,4890,"Meet Niall", "Meet Niall for pints",UUReminderType::No_Repeat,0 };


	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);
	
	//ACT
	actual_result = (myCalendar.GetCalendarEntriesBetweenDates("17/06/2019", "19/06/2019")).size();

	//Assert
	ASSERT_EQ(expected_result, actual_result);


	if (!HasFailure()) {
		//Test has passed
		currentPoints += 3; //add points
		std::cout << "TestGetEntriesBetweenDates PASSED! : GetEntriesBetweenDates correctly returned all entries in the calendar between the specified dates" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestGetEntriesBetweenDates Failed! : GetEntriesBetweenDates did not return all entries in the calendar between the specified dates. Check the GetEntriesBetweenDates() function" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestCountEntriesBetweenDates)
{
	std::cout << "\nRunning TestCountEntriesBetweenDates on the calendar " << std::endl;

	//Arrange
	int expected_result{ 5 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "17/06/2019", 19,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "18/06/2019", 10,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 10,30,4890,"Meet Niall", "Meet Niall for coffee",UUReminderType::No_Repeat,0 };
	UUEntry newEntry6{ "19/06/2019", 14,30,4890,"Collect parcel", "Collect parcel from sorting office",UUReminderType::No_Repeat,0 };
	UUEntry newEntry7{ "19/06/2019", 20,30,4890,"Phone Dad", "Phone father",UUReminderType::No_Repeat,0 };


	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);
	myCalendar.AddEntry(newEntry6);
	myCalendar.AddEntry(newEntry7);

	//ACT
	actual_result = myCalendar.CountEntries("17/06/2019", "19/06/2019");

	//Assert
	ASSERT_EQ(expected_result, actual_result);


	if (!HasFailure()) {
		//Test has passed
		currentPoints += 3; //add points
		std::cout << "TestCountEntriesBetweenDates PASSED! : GetEntriesBetweenDates correctly counted all entries in the calendar between the specified dates" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestCountEntriesBetweenDates Failed! : GetEntriesBetweenDates did not count all entries in the calendar between the specified dates. Are you including entries on the dates specified?" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestGetAllEntriesOnDate)
{
	std::cout << "\nRunning TestGetAllEntriesOnDate on the calendar " << std::endl;

	//Arrange
	int expected_result{ 3 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "17/06/2019", 19,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "18/06/2019", 10,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 10,30,4890,"Meet Niall", "Meet Niall for coffee",UUReminderType::No_Repeat,0 };
	UUEntry newEntry6{ "19/06/2019", 14,30,4890,"Collect parcel", "Collect parcel from sorting office",UUReminderType::No_Repeat,0 };
	UUEntry newEntry7{ "19/06/2019", 20,30,4890,"Phone Dad", "Phone father",UUReminderType::No_Repeat,0 };


	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);
	myCalendar.AddEntry(newEntry6);
	myCalendar.AddEntry(newEntry7);

	//ACT
	std::vector <UUEntry> tempEntries = myCalendar.GetEntriesForGivenDay("19/06/2019");

	actual_result = tempEntries.size();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	//Check one of the entries
	std::string entry_description = tempEntries.at(2).GetEntryDescription();
	ASSERT_EQ("Phone father", entry_description);


	if (!HasFailure()) {
		//Test has passed
		currentPoints += 3; //add points
		std::cout << "TestGetAllEntriesOnDate PASSED! : GetEntriesForGivenDay correctly return all entries in the calendar between the specified dates" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestGetAllEntriesOnDate Failed! : GetEntriesForGivenDay did not return all entries in the calendar between the specified dates. Are you including entries on the dates specified?" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestGetAllEntries)
{
	std::cout << "\nRunning TestGetAllEntries on the calendar " << std::endl;

	//Arrange
	int expected_result{ 7 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "17/06/2019", 19,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "18/06/2019", 10,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 10,30,4890,"Meet Niall", "Meet Niall for coffee",UUReminderType::No_Repeat,0 };
	UUEntry newEntry6{ "19/06/2019", 14,30,4890,"Collect parcel", "Collect parcel from sorting office",UUReminderType::No_Repeat,0 };
	UUEntry newEntry7{ "19/06/2019", 20,30,4890,"Phone Dad", "Phone father",UUReminderType::No_Repeat,0 };


	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);
	myCalendar.AddEntry(newEntry6);
	myCalendar.AddEntry(newEntry7);

	//ACT
	std::vector <UUEntry> tempEntries = myCalendar.GetAllCalendarEntries();

	actual_result = tempEntries.size();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	//Check one of the entries
	std::string entry_description = tempEntries.at(2).GetEntryDescription();
	ASSERT_EQ("Fix the lock on the garage door", entry_description);


	if (!HasFailure()) {
		//Test has passed
		currentPoints += 1; //add points
		std::cout << "TestGetAllEntries PASSED! : GetAllCalendarEntries correctly return all entries in the calendar" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestGetAllEntries Failed! : GetAllCalendarEntries did not return all entries in the calendar." << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

//Test for clashes in the calendar
TEST(UUCalendar, TestForEntryClash1)
{
	//This tests checks if the code rejects adding an entry that clashes with an existing entry 
	//with the new entry coming after an existing entry

	std::cout << "\nRunning TestForEntryClash1 on the calendar " << std::endl;

	//Arrange
	int expected_result{ 6 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "17/06/2019", 19,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "18/06/2019", 10,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 10,30,4890,"Meet Niall", "Meet Niall for coffee",UUReminderType::No_Repeat,0 };
	UUEntry newEntry6{ "19/06/2019", 14,30,4890,"Collect parcel", "Collect parcel from sorting office",UUReminderType::No_Repeat,0 };
	UUEntry newEntry7{ "19/06/2019", 14,31,3600,"Phone Dad", "Phone father",UUReminderType::No_Repeat,0 }; //clashing entry - should not get added


	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);
	myCalendar.AddEntry(newEntry6);
	

	//ACT
	bool event_added = myCalendar.AddEntry(newEntry7); //should return false

	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(false, event_added);
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestForEntryClash1 PASSED! : AddEntry does not add an entry that clashes with an existing entry " << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestForEntryClash1 Failed! : AddEntry does incorrectly adds an entry that clashes with an existing entry" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestForEntryClash2)
{
	//This tests checks if the code rejects adding an entry that clashes with an existing entry 
	//with the new entry coming before an existing entry

	std::cout << "\nRunning TestForEntryClash1 on the calendar " << std::endl;

	//Arrange
	int expected_result{ 6 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "17/06/2019", 19,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "18/06/2019", 10,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 10,30,4890,"Meet Niall", "Meet Niall for coffee",UUReminderType::No_Repeat,0 };
	UUEntry newEntry6{ "19/06/2019", 14,30,4890,"Collect parcel", "Collect parcel from sorting office",UUReminderType::No_Repeat,0 };
	UUEntry newEntry7{ "19/06/2019", 13,50,3600,"Phone Dad", "Phone father",UUReminderType::No_Repeat,0 }; //clashing entry - should not get added


	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);
	myCalendar.AddEntry(newEntry6);


	//ACT
	bool event_added = myCalendar.AddEntry(newEntry7); //should return false

	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(false, event_added);
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestForEntryClash2 PASSED! : AddEntry does not add an entry that clashes with an existing entry " << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestForEntryClash2 Failed! : AddEntry does incorrectly adds an entry that clashes with an existing entry " << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestForEntryClash3)
{
	//This tests checks if the code rejects adding an entry that clashes with an existing entry 
	//with the new entry coming after an existing entry. But the existing entry is on the previous day

	std::cout << "\nRunning TestForEntryClash3 on the calendar " << std::endl;

	//Arrange
	int expected_result{ 6 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "17/06/2019", 19,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "18/06/2019", 10,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 10,30,4890,"Meet Niall", "Meet Niall for coffee",UUReminderType::No_Repeat,0 };
	UUEntry newEntry6{ "18/06/2019", 23,59,4890,"Collect parcel", "Collect parcel from sorting office",UUReminderType::No_Repeat,0 };
	UUEntry newEntry7{ "19/06/2019", 0,10,3600,"Phone Dad", "Phone father",UUReminderType::No_Repeat,0 }; //clashing entry - should not get added


	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);
	myCalendar.AddEntry(newEntry6);


	//ACT
	bool event_added = myCalendar.AddEntry(newEntry7); //should return false

	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(false, event_added);
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestForEntryClash3 PASSED! : AddEntry does not add an entry that clashes with an existing entry on previous day " << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestForEntryClash3 Failed! : AddEntry does incorrectly adds an entry that clashes with an existing entry on previous day " << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestForEntryClash4)
{
	//Check if updating an entry that causes a clash is rejected

	std::cout << "\nRunning TestForEntryClash4 on the calendar " << std::endl;

	//Arrange
	bool expected_result{false};
	bool actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::No_Repeat,0 };
	UUEntry newEntry2{ "17/06/2019", 19,0,4890,"Mark assignments", "Spend hours marking student assignments",UUReminderType::No_Repeat,0 };
	UUEntry newEntry3{ "18/06/2019", 10,0,4890,"Fix lock", "Fix the lock on the garage door",UUReminderType::No_Repeat,0 };
	UUEntry newEntry4{ "16/06/2019", 14,25,3600,"Buy cake", "Buy birthday cake",UUReminderType::No_Repeat,0 };
	UUEntry newEntry5{ "19/06/2019", 10,30,4890,"Meet Niall", "Meet Niall for coffee",UUReminderType::No_Repeat,0 };
	UUEntry newEntry6{ "19/06/2019", 23,59,4890,"Collect parcel", "Collect parcel from sorting office",UUReminderType::No_Repeat,0 };
	UUEntry newEntry7{ "19/06/2019", 0,10,3600,"Phone Dad", "Phone father",UUReminderType::No_Repeat,0 }; //clashing entry - should not get added


	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	myCalendar.AddEntry(newEntry3);
	myCalendar.AddEntry(newEntry4);
	myCalendar.AddEntry(newEntry5);
	myCalendar.AddEntry(newEntry6);
	myCalendar.AddEntry(newEntry7);

	newEntry6.SetEntryTime(10, 32);
	//ACT
	actual_result = myCalendar.UpdateEntry(newEntry6.GetEntryDateTime(), newEntry6);

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestForEntryClash4 PASSED! : Updating an entry which results in a clash is rejected " << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestForEntryClash4 Failed! : Updating an entry which results in a clash is not rejected. Check for clashes in update entry " << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestForDailyRepeat)
{
	//Check if we can add a daily repeating event

	std::cout << "\nRunning TestForDailyRepeat on the calendar " << std::endl;

	//Arrange
	int expected_result{11};
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::Daily, 10};
	
	//ACT
	myCalendar.AddEntry(newEntry1);
	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestForDailyRepeat PASSED! : Adding a daily repeating entry works" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestForDailyRepeat FAILED! : Adding a daily repeating entry did not work." << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestForWeeklyRepeat)
{
	//Check if we can add a weekly repeating event

	std::cout << "\nRunning TestForWeeklyRepeat on the calendar " << std::endl;

	//Arrange
	int expected_result{ 4 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::Weekly, 3 };

	//ACT
	myCalendar.AddEntry(newEntry1);
	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	//Check date of last entry - it should be 06/07/2019
	std::string expected_date = "06/07/2019";
	std::string actual_date = myCalendar.GetEntry(3).GetEntryDateString();
	ASSERT_EQ(expected_date, actual_date);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestForWeeklyRepeat PASSED! : Adding a weekly repeating entry works" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestForWeeklyRepeat FAILED! : Adding a weekly repeating entry did not work." << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestForMonthlyRepeat)
{
	//Check if we can add a monthly repeating event (every four weeks)

	std::cout << "\nRunning TestForMonthlyRepeat on the calendar " << std::endl;

	//Arrange
	int expected_result{ 4 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "01/05/2019", 14,25,0,"Worms", "Deworm the dog",UUReminderType::Monthly, 3 };

	//ACT
	myCalendar.AddEntry(newEntry1);
	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	//Check date of last entry - it should be 06/07/2019
	std::string expected_date = "24/07/2019";
	std::string actual_date = myCalendar.GetEntry(3).GetEntryDateString();
	ASSERT_EQ(expected_date, actual_date);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestForMonthlyRepeat PASSED! : Adding a repeating event every four weeks entry works" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestForMonthlyRepeat FAILED! : Adding a repeating event every four weeks entry does not work" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestForYearlyRepeat)
{
	//Check if we can add a yearly repeating event (same date each year)

	std::cout << "\nRunning TestForYearlyRepeat on the calendar " << std::endl;

	//Arrange
	int expected_result{ 6 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "08/08/2019", 14,25,0,"Birthday", "A birthday to remember, but whos?",UUReminderType::Annually, 5 };

	//ACT
	myCalendar.AddEntry(newEntry1);
	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	//Check date of last entry - it should be 06/07/2019
	std::string expected_date = "08/08/2024";
	std::string actual_date = myCalendar.GetEntry(5).GetEntryDateString();
	ASSERT_EQ(expected_date, actual_date);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestForYearlyRepeat PASSED! : Adding a repeating event every year on the same date works" << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestForYearlyRepeat PASSED! : Adding a repeating event every year on the same date does not work" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestForWeeklyRepeatClash)
{
	//Check if we adding weekly repeating event doesn't add clashes

	std::cout << "\nRunning TestForWeeklyRepeatClash on the calendar " << std::endl;

	//Arrange
	int expected_result{ 4 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "29/06/2019", 14,25,0,"Clash", "A clashing event",UUReminderType::No_Repeat, 0 };
	UUEntry newEntry2{ "15/06/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::Weekly, 3 };

	//ACT
	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	//Check date of last entry - it should be 06/07/2019
	std::string expected_date = "06/07/2019";
	std::string actual_date = myCalendar.GetEntry(3).GetEntryDateString(); //Should be the clashing event 
	ASSERT_EQ(expected_date, actual_date);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestForWeeklyRepeatClash PASSED! : Adding a weekly repeating entry doesn't add clashing events " << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestForWeeklyRepeatClash FAILED! : Adding a weekly repeating entry adds clashing events and it should not!" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

TEST(UUCalendar, TestForMonthlyRepeatClash)
{
	//Check if we adding TestForMonthlyRepeatClash repeating event doesn't add clashes

	std::cout << "\nRunning TestForMonthlyRepeatClash on the calendar " << std::endl;

	//Arrange
	int expected_result{ 4 };
	int actual_result{};

	UUCalendar myCalendar;
	UUEntry newEntry1{ "24/07/2019", 14,25,0,"Clash", "A clashing event",UUReminderType::No_Repeat, 0 };
	UUEntry newEntry2{ "01/05/2019", 14,25,0,"MOT", "Take car for MOT test",UUReminderType::Monthly, 3 };

	//ACT
	myCalendar.AddEntry(newEntry1);
	myCalendar.AddEntry(newEntry2);
	actual_result = myCalendar.GetCalenderEntryCount();

	//Assert
	ASSERT_EQ(expected_result, actual_result);

	//Check date of last entry - it should be 20/06/2019
	std::string expected_date = "26/06/2019";
	std::string actual_date = myCalendar.GetEntry(3).GetEntryDateString(); //Should be the clashing event 
	ASSERT_EQ(expected_date, actual_date);

	if (!HasFailure()) {
		//Test has passed
		currentPoints += 4; //add points
		std::cout << "TestForMonthlyRepeatClash PASSED! : Adding a monthly repeating entry doesn't add clashing events " << std::endl;

	}
	else if (HasFailure()) {
		//Test failed - provide feedback
		std::cout << "TestForMonthlyRepeatClash FAILED! : Adding a monthly repeating entry adds clashing events and it should not!" << std::endl;
	}
	std::cout << "Current MARKS for asssignment 2: " << currentPoints << "/" << maxPoints << "\n" << std::endl;
}

//Final dummy testing for reporting final score
TEST(Final, FinalTest) {
	//Arrange
	bool expected_result{ true };
	bool actual_result{ true };

	//Act

	//Assert
	//EXPECT_EQ(expected_result, actual_result);
	ASSERT_EQ(expected_result, actual_result);

	std::cout << "\n\n***Final mark for unit tests: " << currentPoints << "/" << maxPoints << " ***\n\n" << std::endl;
}
