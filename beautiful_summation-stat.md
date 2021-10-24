# [Beautiful Summation](https://csacademy.com/ieeextreme15/task/summation/)

Time limit: 2000 ms
Memory limit: 256 MB

Andy loves arithmetic and geometric progressions. He has mastered the summation formulas for arithmetic and geometric progressions. But, he is already bored with those standard formulas. So, he comes up with a more beautiful summation, i.e.


S_N= \sum_{k = 1}^{N} P^k \times k^Q

But, he does not know how to calculate the value of S_N. Since you are an awesome problem solver, Andy asks your help to calculate the value of S_N modulo M for given numbers P, Q, N, and M.

## Standard input
There is only one line in the input containing four integers separated by single spaces, PP, QQ, NN, and MM that represent the parameters in Andy's summation.


## Standard output
You should output an integer between 00 and M-1M−1 representing the result of Andy's summation after modulo by MM.


## Constraints and notes
- 1≤P≤1000
- 0≤Q≤1000
- 1≤N,M≤10^9

- For 20% of the test files, N ≤ 10^6
- For another 40% of the test files (not including the 20% above), M≤10^6

## Input | Output
```
2 3 4 10      4
```

```
7 0 5 128      23
```