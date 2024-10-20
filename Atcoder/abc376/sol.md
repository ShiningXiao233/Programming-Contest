### D

正边反边最短路即可。

### E 

按照 $A$ 排序，枚举 $A$ ，然后维护 $B$ 的前 $K$ 小的和值即可，优先队列维护。

### F

状态数量其实很少，每次经历一次操作后，由于一个点的位置是固定的，所以最多只存在 $n$ 个状态，转移时，其实也只有两种转移方式。

由于是环状，所以情况数量很多，一个简单的建议是，将某个点偏移到0点，然后情况数量就很好分析了。

## G

[01-on-tree](https://atcoder.jp/contests/agc023/tasks/agc023_f)

其实是找到一个序列，使得 $\sum i \times a_{q_i}$ 最小。同时使得 $\lbrace q_i \rbrace$ 满足拓扑关系，即父亲不能在子的后面。

所谓的01-on-tree问题，首先需要转换为逆序对问题（非常巧妙，$a_i$ 转换为 $\lbrace 0, 0, \dots 0, 1\rbrace$， 包含 $a_i$ 个 $0$，对应答案就是逆序对），然后使用逆序对在树上的解法，解法利用了贪心的思路，每个点维护0和1的数量，记为 $C_{v0},C_{v1}$ ，每次选择一个 $\frac {C_{v0}} {C_{v1}}$ 最大的和其父亲节点合并，为什么是除法式？

考虑两个点，$u, v$，若 $u$ 在 $v$ 的前面，那么贡献是 $C_{u1} \times C_{v0}$，反过来，贡献是 $C_{v1} \times C_{u0}$，那么其实就是比较这两个式子哪个更加小，利用贪心的临项交换法即可。

然后使用并查集+优先队列即可，处理其实比较简单。