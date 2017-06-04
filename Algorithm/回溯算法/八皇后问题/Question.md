## 八皇后问题

&nbsp;&nbsp;This one is a classic in computer science. The goal is to assign eight queens to eight positions on an 8x8 chessboard so that no queen, according to the rules of normal chess play, can attack any other queen on the board. 
In pseudocode, our strategy will be:

```
Start in the leftmost columm
If all queens are placed, return true
for (every possible choice among the rows in this column)
    if the queen can be placed safely there,
        make that choice and then recursively try to place the rest of the queens
        if recursion successful, return true
        if !successful, remove queen and try another row in this column
if all rows have been tried and nothing worked, return false to trigger backtracking
```

`8quuens.cpp` 采用递归回溯算法解决。

`8quuens-better.cpp` 对空间上进行了优化。