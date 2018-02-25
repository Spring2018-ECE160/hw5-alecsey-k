## Question 4

(K&R Exercise 5-5) Write a version of the library function <code>strncpy</code>, which operate on at most the first n characters of their argument strings. For example, <code>strncpy(s,t,n)</code> copies at most n characters of t to s. **Be sure to use pointers**. Verify that your function works with at least 3 examples.

Compile Steps:

gcc hw5q4.c -o hw5q4.exe

Output:

s1 = Football, t1 = Railroad, n1 = 4
Railball

s2 = Himself, t2 = Her, n2 = 5
Herself

s3 = Computer, t3 = Monitor, n3 = 5
Monitter
