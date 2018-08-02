# CS 126 FinalProject
### Financial Data Visualization
This project aims to provide its users with a unique experience to customize how they
look at financial data. Essentially, it uses multiple different libraries, coupled with
the AlphaVantage API, to pull real time data from the stock market and visualize that data
in an easy to understand way. The user has the option to enter any ticker that is valid
on the IEX database, as well as three different time series options.

### How to Download and Use the Project
To download and use this project, you must first have XCode installed on your computer.
Then, you must also clone the [Open Frameworks Library](http://openframeworks.cc/) onto
your desktop. Finally, it is just a simple matter of cloning this project repo into the
"myApps" directory of the Open Frameworks folder that you just cloned somewhere on your
computer. After that, you should just navigate into the "mySketch" directory and open up
the "mySketch.xcodeproj". Finally, click the run/compile button and have fun!

### Potential Issues
Although all the libraries that my project uses should be linked without any trouble, there
could be an issue with libcurl. Fortunately, this is an easy fix. Just clone the
[Curl Library](https://github.com/curl/curl) into the "myApps" folder of your Open Frameworks
folder. Then you should be good to go!

### Libraries/APIs Utilized

1. [Libcurl/Curl](https://github.com/curl/curl)
2. [ofxDatGui](https://github.com/braitsch/ofxDatGui)
3. [ofxGraphica](https://github.com/jagracar/ofxGrafica)
4. [AlphaVantage](https://www.alphavantage.co/documentation/)

### Author
Spencer Gilbert - Freshman in CS at UIUC
