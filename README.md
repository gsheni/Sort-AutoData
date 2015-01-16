Sort-AutoData
=============

This program sorts data for automobiles. 
It does so by using an AutoData class 
The SortAutoData program reads in four command line arguments that corresponds to 
1) an automobile database file
2) the word “bubble”, “quick”, or “brick”, depending on the sorting algorithm used
3) the number of datum to sort
4) the output flags “verbose” or “terse” (see below). 
The database file is formatted such that the attributes for each automobile are separated by a colon (“:”). The attributes and their types are as follows:

+ mpg: float
+ cylinders:	int
+ displacement: float
+ horsepower: float
+ weight: float
+ acceleration: float
+ model year: int
+ origin: int
+ car name: string

The program opens the file and reads in each line, separating each attribute to construct AutoData objects. 

The program then places each AutoData object into a vector, and sorts them by the following criteria: 
First, it checks the mpg’s.
If two AutoData objects have the same mpg, the tie is broken by comparing their horsepowers.

For each sorting algorithm, the number of swaps are counted. For the brick sort algorithm, multiple swaps which are done independently all count as a single swap.
Finally, the program outputs the sorted list in the same format as the original database file if the output type is “verbose” or the number of swaps if the output type is “terse”.


