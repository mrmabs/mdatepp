# mdate++

# Welcome to mdate++

A C++ rewrite of mdate: https://github.com/ewe2/mdate

basic stuff all works -- have a play, see if you can find a bug :)

see LICENSE file for license information

# How does it work?

`mdate++` converts between three date formats, Gregorian, Julian and Mayan Long Count calendars; making 3 inputs and 3 outputs. 

There is a `Date` superclass for all the inputs that you use to initialise the main variable, then you initialise the class with the relevant input (eg. `GregDate` for Gregorian `Date` object).

This class only takes the input from when it was instantiated, no helper functions to get things in the right order and the rest of the code doesn't care which date type was used to create the `Date` object.

On instantiation it converts the input value to a Julian Day value, and then creates the output objects, `Julian`, `Longcount` & `Gregorian`; each of them has a specific functions to return the date.

`cons.cc` is a simple console interface.
