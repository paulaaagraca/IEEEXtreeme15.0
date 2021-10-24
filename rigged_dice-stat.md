# [Rigged Dice](https://csacademy.com/ieeextreme15/task/rigged-dice/)
Time limit: 2000 ms
Memory limit: 256 MB

Alice and Bob are playing a dice game with two dice labeled die 1 and die 2. Both dice have six faces valued from 11 to 66. Initially, Alice has die 1 and Bob has die 2. They both start with an initial score of zero. One game consists of N rounds. In one round, Alice and Bob roll their own dice at the same time, and add the rolled value to their own score, so that each player's score tracks the sum of all the values rolled by the player in this game. After a roll, if Alice's and Bob's scores are not equal, they will exchange their dice before the next round -- This is to avoid cheating in case one of the dice is rigged.

Unfortunately, one of the two dice is indeed rigged. With a normal die, each value from 1 to 6 has a uniform probability to face up. However, the rigged die has a probability of 2/7 to roll a 6, while the values from 1 to 5 each have a probability of 1/7 to face up.

Given the values that Alice and Bob rolled in a game, can you identify which die is rigged?

## Standard input
The first line contains a single integer T, the number of games. The die that is rigged in each game is independently selected.

Each game starts with a single integer N on a single line, the number of rounds. This is followed by N lines each having two integers between 1 and 6: the value that Alice rolled, and the value that Bob rolled in one round.


## Standard output
For each game output a single integer. Output 1 if die 1 (the die that Alice initially had) is rigged. Otherwise, output 2.


## Constraints and notes
- T = 500
- N = 1000
-The values rolled in each game are according to the rule specified above. Alice and Bob have kept track of their own scores and exchanged dice when required by the rule. Because of those exchanges, Alice and Bob may roll different dice in different rounds of the game.
- For each test file, your solution is judged correct if it identifies the rigged dice correctly in at least 99% of the games.
- You must output either 1 or 2 for each game. Any other output, or missing output for a game, will result in a Wrong Answer verdict.
- The sample test has T=2,N=4 only for an exemplification of the dice exchanges. The output in the sample answer only showcases output format, and should not be considered successful identifications of the rigged dice. Any answer submitted to the sample test will be judged correct.

## Input 
```
2
4
1 4
6 3
3 3
2 3
4
2 3
2 2
1 4
5 4
```

## Output 
```
1
2
```