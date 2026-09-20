Circular Classroom Seating

There are N students and N seats arranged in a circle. Each student has a preferred seat given by array A.

Students arrive one by one (1 to N). Each student goes to their desired seat. If it's free they sit, if occupied they move clockwise until they find the first empty seat.

Input:

N
Array A of size N (desired seat of each student)

Output:

Array of size N where each element is the seat number where that student finally sits.

Constraints:

1 <= N <= 10^8
0 <= A[i] <= 10^8

Sample:

Input: 3 / 2 2 2
Output: 2 3 1

--- 

String Beauty Problem:

Given a string S of capital and lowercase alphabetic characters. Two adjacent characters in a string are "bad" if they share the same vowel but are of different cases (Aa, aA, Ee, eE, etc.).

Remove all such bad pairs repeatedly until no more exist. Return the final string. If the string becomes empty, return "#".

Constraints:

0 < S.size() <= 10^5
Characters are a-z and A-Z

Example:

Input: abdhjKLDgshAaCeEjfilfhU
Output: abdhjKLDgshCjffhU
