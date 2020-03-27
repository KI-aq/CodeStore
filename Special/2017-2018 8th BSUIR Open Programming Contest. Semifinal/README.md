# Partial Solution
## A.BSUIR Open
  找到BSUIROPEN每个字母的出现次数，直接相乘即可</br></br>
## B.Freebie 
  </br></br>
## C.Good subset 
  </br></br>
## D.Friends rescue 
  可以注意到如果能从左边到达右边，那么不能从上面的岛屿间隔走到下面，反之亦然。由于是$$n*(n+1)$$的图，保证第一列与左边有连接，最后一列与右边有链接，故横竖的连通性是等价的，答案就是所有建桥情况的一半。</br></br>
## E.Equation 
  由于串中出现的数介于$$1~9$$之间，那么质因子的个数最多只有四个，四个因子会对应四个多元一次方程，对其做完全背包就可以解决了。</br></br>
## F.The closest subsequence
  发现约束条件与顺序无关，直接排序，查看与答案最靠近的数，如果有多个选择，就选择整个序列最靠近中间的那个数，直接扩展答案，最后答案需要按升序输出。</br></br>
## G.Digital characteristic 
  </br></br>
## H.Large and even 
  最大的偶因子，对于奇数而言就是$$0$$，偶数而言就是其本身，题目数据范围比较小，直接用前缀和就可以，也可以用求和公式直接算。</br></br>
## I.Happy triangles 
  待填坑</br></br>
## J.Vova, who doesn't know
  异或和与顺序无关，所以随便输就好了。</br></br>
## K.A Boring Problem 
  树上随机游走，计算出父亲到儿子的期望步数，儿子到父亲的期望步数，最后做的就是倍增求解树上距离。</br></br>
