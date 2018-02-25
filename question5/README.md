## Question 5

(K&R Exercise 5-8) There is no error checking in <code>day_of_year</code> or <code>month_day</code>. Remedy this defect and verify that all of the cases are covered with examples.

Compile Steps:

gcc hw5q5.c -o hw5q5.exe

Output:

13/30/2017
ERROR: 13 is not a valid entry for month.
Day 1 = 0

2/-1/2018
ERROR: Day cannot be zero or negative.
Day 2 = 0

2/29/2018
ERROR: 29 is not a day in 2/2018.
Day 3 = 0

Day -1 in 2018
ERROR: Day cannot be zero or negative.

Day 366 in 2018
ERROR: 366 is not a day in the year 2018.
