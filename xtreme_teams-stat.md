# [Xtreme Teams](https://csacademy.com/ieeextreme15/task/xtreme-teams/)
Time limit: 2000 ms
Memory limit: 256 MB

In IEEEXtreme, each team consists of three students. The contest may challenge the students with problems on M topics. There are N students at a school who are known to specialize in some of those M topics (possibly none, possibly all). In order to achieve best performance, for each of the M topics, a team should have at least one student who specializes in that topic. In how many ways can a single team be formed by choosing 33 students from the N students, so that at least one student specializes in each of the M topics?

## Standard input
The input begins with a single integer TT on the first line, the number of test cases.

The first line of each test case has two integers NN and MM. The next NN lines each have a string of length MM that represents the topic specialties of one student. For each student, the iith letter is y if he/she specializes in topic ii, or n otherwise.


## Standard output
For each test case, output the number of different ways to choose 33 students to form a team on a single line.


##  Constraints and notes
- 151≤T≤15
- 3≤N≤5000
- 181≤M≤18
- For 33% of the test files, N≤100, M≤12.
- For 66% of the test files, M≤12.

## Intput 
```
4
4 3
ynn
nyn
yyn
yny
4 5
yyyyy
yyynn
nyyyn
nnnny
5 4
ynnn
nynn
nnyn
nnny
nnnn
6 6
yynnyy
yynnyy
nnyyyy
nnyyyy
yyyynn
yyyynn
```


## Output
```
3
4
0
20
```