========================================================================
    CONSOLE APPLICATION : Lab1 Project Overview
========================================================================

AppWizard has created this Lab1 application for you.

This file contains a summary of what you will find in each of the files that
make up your Lab1 application.


Lab1.vcxproj
    This is the main project file for VC++ projects generated using an Application Wizard.
    It contains information about the version of Visual C++ that generated the file, and
    information about the platforms, configurations, and project features selected with the
    Application Wizard.

Lab1.vcxproj.filters
    This is the filters file for VC++ projects generated using an Application Wizard. 
    It contains information about the association between the files in your project 
    and the filters. This association is used in the IDE to show grouping of files with
    similar extensions under a specific node (for e.g. ".cpp" files are associated with the
    "Source Files" filter).

Lab1.cpp
    This is the main application source file.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named Lab1.pch and a precompiled types file named StdAfx.obj.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" comments to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
First build: 
h:\332 repo\labs-ubitquitin\lab1\lab1\lab1\lab1.cpp(57): warning C4018: '<': signed/unsigned mismatch
h:\332 repo\labs-ubitquitin\lab1\lab1\lab1\lab1.cpp(80): warning C4018: '<': signed/unsigned mismatch

changed ints to size_t type for vector iterators in for loop.

No warnings after that. 

Running had a few errors. First, the program would return bad file error. I realized that I was making the program
return an error message when the end of file flag was set true. I changed this to pushing the last word into output 
and returning success. 

Next, the output was being returned twice, which I later found out was because I was calling the function once when
testing to see if it returned a success, and then again immediately after, resulting in it being called twice.

Finally the digits were not being stored into my vector<int> and were being output with the strings. I fixed this
by resetting the boolean value that would assert that the entire word was digits after checking each character.

The program then succesfuly read each word in the file, outputting it the standard output stream if it was a string,
and storing it to a vector<int> and reading that after the end of the file for the words that were made up of
only digits.

For testing I did 4 tests. I tested with random characts such as @#$%^ and the program successfully counted these as strings. I also
tested across multiple lines, with Capitals and with alphanumeric strings (a combination of digits and strings) and the program also 
successfully grabbed these as strings. I tested a very large digit and this was grabbed as an all digit string, however the digit was above the
maximum integer value and thus returned a signed integer offset. This is expected behavior and to be able to account for vevry large numberes 
a different data type like long should be used. Finally I tested with negative values and these were grabbed as strings, because the '-' character
is not considered a digit.

