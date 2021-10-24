# [Spies of Red and Blue](https://csacademy.com/ieeextreme15/task/spies/)

Time limit: 2000 ms
Memory limit: 256 MB

Red and Blue are two countries currently engaged in a battle for world dominance in an era of the cold war. Since information is key in winning this war, both countries have invested time, money, and effort in developing spy agencies and have spies across the world to provide them with information in order to act as quickly as possible.

In order to retain secrecy, the spy agencies are structured such that a spy will only report to their immediate senior. Any information received by a spy will be passed to their immediate senior till it reaches the head of the spy agency with R1 and B1 being the head of spy agencies of Red and Blue. Spies may be turned over to the other side and the compromised spies will get a new immediate senior to whom he/she will report information.

In the above spy reporting structure, Red has 4 spies and Blue has 3 spies with R1 B1 being the head of their respective countries. It will take 3 interactions for information to reach R1 from R4, and it will take 11 interaction for information to reach B1 rom B2. If B2 had turned over to the red country with R3 as his immediate senior, then, the information from B2 will never reach B1, and it will reach R1 via R3 with 3 interactions instead (as shown below).

Given the spies' organizational structure of Red and Blue countries and the sequence of events as to which spy receives the information or is turned over, find which country will win the information war by getting information faster and how many interactions will it take to pass the information to its head of spy agency.

## Standard input
The first line has a single integer TT, the number of test cases.

For each test case, the first line consists of three integers NR, NB, E, where NR is the number of spies in the Red country, NB is the number of spies in the Blue country, and E is the number of events that will occur. The spies in the Red countries are named R_1, R_2, ... R_{N_R} and the spies in the Blue countries are named B_1, B_2, ... B_{N_B}.

The second line has N_R−1 space separated strings. The iith of these strings is the name of the immediate senior of spy R_{i+1}.

The third line has N_B-1 space separated strings. The iith of these strings is the name of the immediate senior of spy B_{i+1}.

The next E lines each describe an event. An event is one of the two types:

- c xx yy: There is a spy crossover. Spy xx now reports to spy yy as his/her immediate senior.
- w xx yy: There is a piece of battle information received by spy xx and spy yy at the same time.

Note that due to the crossovers, xx yy can be originally spies of a same country. A same crossover may happen multiple times.

## Standard output
For each battle information event w , output the winner country of the information war, along with kk, the minimum number of interactions required for the piece of information to reach its head of spy agency. There can be four possible output scenarios:

- RED kk: The information reaches R_1 first, in kk interactions.
- BLUE kk: The information reaches B_1 first, in kk interactions.
- TIE kk: The information reaches R_1 and B_1 at the same time, in kk interactions.
- NONE: The information reaches neither R_1 nor B_1.

Note that kk does not need to be printed for the NONE scenario.

## Constraints and notes:
- 1≤T≤30
- 2 ≤ N_R, N_B ≤ 1000
- 1 ≤ E ≤ 1000
- Initially before all the events, the spy reporting structure guarantees that information received by any Red country spy can reach R_1, and information received by any Blue country spy can reach B_1.
- In a crossover event, spy xx is not R_1 and not B_1.
- In each event, x, y are both valid spy names from either country. x != y

## Input 

```
1
4 4 6
R1 R2 R3
B1 B1 B2
w R2 B2
w R4 B3
c B2 R3
w R4 B2
c R3 B4
w R4 B2
```

## Output

```
TIE 1
BLUE 1
RED 3
NONE
```