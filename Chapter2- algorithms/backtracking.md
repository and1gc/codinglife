
    回溯法：是一种组织搜索技术，可以被描述为有组织的穷尽搜索,它可以常常避免搜索所有的可能性，
    一般适用于求解那些有潜在的大量解，但有限个数解已经检查过的问题。

    典型问题如下：
1. 三着色问题
2. 八皇后问题
3. 矩阵中的路径
4. 机器人的移动范围

    处理这类的问题有通用的原型算法，一个是递归（Backtrackrec）,另一个是迭代（Backtrackiter）. 
(''') 
   Backtrackrec:
   输入：集合 X1,X2,X3....Xn的清楚或者隐含的描述
   输出：解向量 v=(x1,x2,x3....xn)
      1 v=空集
      2 flag=false
      3 advance(1)
      4 if flag then output v
      5 else output "no solution"
   过程 advance(k)
      1 for 每个x属于Xk
      2 xk=x; 然后将其加入v
      3 if v为最终解 then set flag=true and exit
      4 else if v是部分解 then advance（k+1）
(''')    

