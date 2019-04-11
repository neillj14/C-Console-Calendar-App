
# Assignment 2
## COM326 assignment 2
### Description
This README contains detailed instructions for your assignment. Read it carefully.

### Written By
* Colleen Dobbs, Zoe Turner Galbraith, Mark McVey and Jamie Neill

## Problem statement:
Implement a simple calendar system. There are four main classes within the system. 'UUCalendar', 'UUEntry' and 'UUTime' are the key classes
that you should implement. Skeleton outlines of these classes and a description of each member function's requirements are provided in the
source code. __DO NOT__ change the signatures of the class member functions or the provide data members of the class. You can add your own utility
member functions or data members to the classes listed in the section 'Files to work on'. However, your code must provide the public member functions as specified in 'UUCalendar', 'UUEntry' and 'UUTime'.

## Files to work on
* README.md - You should only add your name, student IDs and discord names
* You can also modify 'main.cpp' to debug and test your code.
* 'UUCalendar.h' and 'UUCalendar.cpp'
* 'UUEntry.h' and 'UUEntry.cpp'
* 'UUTime.h' and 'UUTime.cpp'
* 'UUDate.h' and 'UUDate.cpp'
* __DO NOT__ modify any other files in the repository. __Doing so could lead to a fail mark of 0%__

## Submission details
* __Deadline:__ Before midnight on 11/01/2019
* __Submission method:__ GitHub classroom & BBL. One submission per group to both BBL and Github. The student who submits on behalf of the team should email the module coordinator (s.wilson@ulster.ac.uk) to confirm that the group has submitted their assignment.
* __Assignment type:__ Group Assignment - group lists in BBL
* __Assignment weighting:__ 50% of coursework mark

## Exceptions
* You are not required to throw any Exceptions

## Input / Output
* You are not required to take any input from the keyboard / file or output to the screen

## Constraints
* You are not permitted to use `<ctime>`, `<chrono>` or any other time/date headers
* You may swap the UUDate implementation and use your own
* You must not change the public interface of the classes provided. You are encouraged to write your own private utility or support functions within each class as necessary.
* It should not be possible to add a calendar entry if it overlaps with an existing entry.
* Durations for UUEntry should not exceed 12 hours
* The class 'UUTime' should use a 24 hour clock. Valid value are therefore [0..23] for hours and [0..59] for minutes.
* The classes should not make use of std::cin or std::cout. No user entry of data within the classes is required!

## Notes
* We are using the Gregorian Calendar only
* Make sure your code compiles and runs. __There are no points for code that doesn't compile__
* You will receive marks for every test your code passes. Local tests are provided. Test your code before pushing to GitHub/Travis.
* The initial code provided with this assignment will not compile. You will have to write the necessary implementation of the skeleton classes provided
* Travis-CI uses the GCC compiler which is different to visual studio. Windows specific code will not compile in GCC. Ensure you __write portable C++ code__.
* Ensure your code does not have any errors or warnings before pushing to Travis-CI.
* Make sure your last push to GitHub is before the deadline. Submissions after the deadline will not be possible. Your last push will be considered as your final submission.
* Post questions (not solutions) to the assignment channel on discord
* Please contact module staff if you run into issues.

# Marking scheme
Your assignment mark will be based on the unit tests passed. The unit tests for this assignment are:

\# | Description | Marks
--- | ----------- | -----
1 |	Test default UUTime constructor 1 | 1
2 |	Test custom UUTime constructor 2 |	1
3 |	Test custom UUTime constructor 3 |	2
4 |	Test UUTime SetTime function 1 |	2
5	| Test UUTime SetTime function 2 |	2
6 |	Test UUTime GetTime function |	2
7 |	Test UUEntry Default Constructor|	2
8 |	Test UUEntry custom constructor |	6
9 |	Test UUEntry SetEntryDate |	1
10 | Test UUEntrySetEntryDuration 1 |	1
11 | Test UUEntrySetEntryDuration 2 |	2
12 | Test UUEntrySetEntryDateTime |	4
13 | Test UUEntry Set/GetEntryReminderType | 4
14 | Test UUCalendar Add an entry |	4
15 | Test UUCalendar Remove entry |	4
16 | Test UUCalendar Update entry |	4
17 | Test Remove all entries | 2
18 | Test Remove all entries on a date | 3
19 | Test removing all entries between dates | 3
20 | Test UUCalendarGetEntriesBetweenDates | 3
21 | Test UUCalendarCountEntires |	3
22 | Test UUCalendarGetEntriesOnDate | 3
23 | Test UUCalendarGetAllEntries |	1
24 | TestForEntryClash 1 | 4
25 | TestForEntryClash 2 | 4
26 | TestForEntryClash 3 | 4
27 | TestForEntryClash 4 | 4
28 | Test UUCalendarAddEntryRepeatDaily |	4
29 | Test UUCalendarAddEntryRepeatWeekly | 4
30 | Test UUCalendarUpdateEntryRepeatMonthly |	4
31 | Test UUCalendarAddEntryRepeatYearly | 4
32 | Test UUCalendarAddEntryRepeatWeeklyClash	| 4
33 | Test UUCalendarAddEntryRepeatMonthlyClash | 4
  |	Total  | 100


## Running tests
* A local google test project has been provided to help you test your project on your PC.
* The tests use the Google test extension for Visual Studio. This extension must be installed in your local copy of visual studio to run the tests locally
* Your code will automatically be tested in Travis-CI every time you push your code to GitHub.
* Examine the build logs carefully if your code does not pass a unit test or fails to build. If the Travis build stalls - cancel the build!
* When you push to GitHub kill unnecessary Travis builds.
* Check the logs from Travis to verify the correctness of your program. Kill builds that stall.
* For a list of gcc compiler warnings see: https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
