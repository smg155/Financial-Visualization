# Project Proposal
### Financial Modeling Using Open Frameworks

My vision for this project is to create a tool for financial modeling
that is able to interperet and display data for a specific ticker on
the stock market. For example, give the ticker CAT (for Caterpillar)
my program could calculate the PE ratio, EBITDA margin, graph the 
share prices for the stock over the last year, and more. This data would
all be displayed in an easy-to-understand form that could allow people
to more quickly access and utilize financial data - as opposed to 
searching through balance sheets themselves, calculating ratios, and
taking hours to make an informed decision about a stock investment.

### Project Motivation

This project is also useful because it will make the user interface
of the stock data much more simple to understand than say Yahoo Finance,
which in my opinion, can be slightly overwhelming to someone new in
financial markets. There's a possibility of adding on a feature to actually
explain each data point when prompted by the user as well. For instance,
if the user wants to know what the PE ratio measures, they could click on
it and then the program could display a simple definition to help the
user understand and make a more informed analysis of the stock they are
looking at.

I am also motivated to do this project due to my interest in high
frequency trading and the fintech industry. Over the last year, and
especially this last semester, I've had the opportunity to learn a lot
more about the stock market and finance, and I've realized it's an
area of intersection between business and computer science that I really
would like to look more into. This project is a start for that.

### Project Function

This project would be built in Open Frameworks of course, but it would
also use the library QuantLib library to pull, analyze, and display the financial
data that the user is requesting. I think utilizing this library and Open
Frameworks would be an appropriate final project for this class, and I am 
actually quite excited to begin working on it!

### Source of Library

Here is the link to the library [website](http://www.quantlib.org/).

### UPDATES

Through much trial and error with the libraries I decided to use plus some
others that I will explain shortly, I have decided to change the core libraries
and purpose of my project. The libraries I am now using are as follows:

1. Open Frameworks
2. ofxDatGui
3. Libcurl
4. AlphaVantage API

Now, since I am changing the libraries I am using, I am also changing the design
and purpose of the project as I stated before. Now, I am going to be using
these libraries to pull real time stock data that the user requests, and I 
am going to plot this data on a graph to show the progression of the share prices
over a specified time series. Then, as a stretch goal, I will be making
financial regressions on the data and plotting a line of best fit to show the
user more easily the trend in the stock data. This is something that is exciting,
challenging, and possible I believe.
