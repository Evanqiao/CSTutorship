&emsp;&emsp;有n个人去银行排队办事（n<=1000000）。银行只有一个窗口，每人有不同的优先级。每办完一个人，从等待的人中选优先级最高的人办理，同级选最先到的。
输入n以及n行数据Ai，Pi，Ti，表示第i个人的到达时间、优先级、办理用时。所有输入都是正整数，输入顺序为Ai递增顺序，输出实际办理的人的顺序。

样例输入：  
5  
0 1 10  
2 1 10  
5 3 10  
7 2 5  
11 3 5  

样例输出：

1 3 5 4 2

两个方法去做这个题目：

性能一般：
[bankqueue2.cpp](https://github.com/Evanqiao/CSTutorship/blob/master/Algorithm/bankQueue/bankqueue2.cpp)

性能较好：

[bankqueue_BEST.cpp](https://github.com/Evanqiao/CSTutorship/blob/master/Algorithm/bankQueue/bankqueue_BEST.cpp)


具体的思路分析见： [堆和优先队列的算法应用](http://blog.xiaojn.cn/2017/05/21/heap_priority_queue/)