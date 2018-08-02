### April 19, 2018:
Researched more about QuantLib. It has several incredibly useful classes that I want
to incorporate into my project. For example, the calendar and date objects calculate day differences,
format output, and more for all financial dates and calendars. However, I have come to realize that
QuantLib will not be enough to get the data that I will need to supply financial data for a certain 
stock or ticker. As such, I have decided to integrate the AlphaVantage API as well to pull financial
data from the stock market in real time. Then I will use the functions from QuantLib's date and
calendar classes mostly to format output and perform operations on dates that I need.

### April 20, 2018
Found yet another issue with the actual setup of my project. Unfortunately, not many APIs have support
for c++ in mac OS. My API request does not work right now because of linker errors. Therefore, I may have
to develop my final project in a virtual machine for ubuntu. That way I could actually use the AVAPI c++
wrapper for the AlphaVantage API. So we'll see how this goes!

### April 22, 2018
This is highly aggravating. I have tried everything to fix the linker errors for the c++ wrapper, but
to no avail. There are also no other API's on the web that have c++ mac OS access for free financial
data in real time. As such, I will be setting up a virtual box to code my entire project in. Thus,
I will also be relaxing some of the conditions of my project because this is a major setback. I will
be able to use CLion in Ubuntu to accomplish this.

### April 24, 2018
This project is very difficult to integrate with the CPR library I am trying to use to get my API calls.
Unfortunately, XCode doesn't use CMakeLists.txt, and because of that I can't actually follow the directions
that I need to so that I can get the library working. And the only reason I am using XCode is because of
Open Frameworks. So, I am going to look possibly using CLion with Open Frameworks instead so I can modify
the CMakeLists.txt and easily integrate the CPR library. If I don't get this working soon, it's going to
be very difficult to actually finish this project.

### April 24, 2018
This is a better turn of events finally. So, instead of using CPR to perform my GET requests, I am going
to use the good old Curl library (in specific, libcurl). I only get small linker errors right of the bat,
so this gives me confidence that I can get this to work (since I forked the actual source code, not some
precompiled piece of code).

### April 24, 2018
This is amazing. Curl is amazing. I am very happy that it actually works now. I can finally start really
building my final project. I LOVE CURL.

### April 25, 2018
Curl working seems to have weird dependencies, but it's ok. It works and compiles on my computer.

### April 25, 2018
Got curl API requests to actually pull data in the form of JSON strings down to my program! This is great,
I made a lot of progress this week. I think I might consider pulling the data in the form of CSV. Then,
I'm going to make regressions and plot the financial data instead of giving the user ratios that they
can get for themselves online. So, this week saw a lot of changes to this project, but now I really see
the end goal of it. Just need to sort out the backend for the next week. Basically finished front end
and API stuff in general.

### April 27, 2018
Development is still going great. In the past two days, I've essentially figured out how to automate the
creation of the API url that I need to get the correct data. As well as that, since the API sends back the
same error message each time that it gets an incorrect request (due to something like an invalid ticker),
I am able to actually check for that and let the user know that they entered an incorrect ticker. So, now
the only thing that I have to complete for the rest of the project is the CSV parser and the actual
plotting of the graph. I also may add a visualization for the average amount of shares that are in
circulation for a particular stock.

### April 27, 2018
Finished the CSV Reader class completely. Now, the volumes of a particular stock as well as the closing
prices of the shares are each stored in separate, easily-accessible vectors. Considering adding a class
for the calculation of the average of the volume of shares, but this may be overkill. Next up is creating
the graph out of the data that I have. Not exactly sure how to accomplish this specifically yet, but I am
assuming that I can use the plotting feature of the ofxDatGui library to create it. If not, then another
library must be used!

### April 28, 2018
It's interesting how complicated a project can become. I am now adding yet another library (now I'm up
to 5 different libraries/API's) so that I can plot the data I have on a chart. But it's exciting; I have
to just learn how to use this library correctly and then I'll have my finished final project!

## April 28, 2018
So, ofxHistoryPlot is not the addon I need to use. I have found the perfect addon and have attached it to
my project in XCode. It is called ofxGrafica, and it is amazing!

### April 28, 2018
I have finished my final project! Now I just have to add a slider view or dropdown menu for the x-axis
legend. Finally, I will test the backend of the project.

### April 28, 2018
The scroll view is completely finished. The only things left to do now are testing and stretch goals.

### April 30, 2018
Testing seems to be almost more trouble than it's worth with the amount of errors that OF gives with 
catch. Plus, the fact that my project runs and works perfectly when I actually run the debug means
that my methods do work correctly. I think that unless I get some help with the testing from piazza
or office hours, my final project is finished! I am very happy with the outcome.

### May 1, 2018
Finished the rest of the formatting and commenting that I needed to. Finished the final project! Again,
I believe that my program verifies that my methods work because they display data using the methods in
my ofApp files. Therefore, the testing I have should be enough to prove that my program works.
