# C. Bertown Subway

求最大的两个环。

# D. Boxes And Balls

哈夫曼树，扩展版，每个节点有 $a$ 个儿子。

需要满足 $n = 1 + ka, k \in Z$，满足时，直接用优先队列跑哈夫曼树即可，不满足时，在序列后补0，使得 $n$ 满足。

# E. Binary Matrix

卡内存并查集。

求连通块数量，将每个点看成一个独立的，每加一条边，数量减一，这样比较容易计数。

同时并查集向下合并，容易进行替换，即模拟滚动操作。

# F. Anti-Palindromize

费用流。

源点向字符建边，费用为 $0$，容量为出现次数。

字符向位置建边，如果与对应位置相等，建立相应的费用边，容量为 $1$。此时由于每个位置对应的时原来的两个位置，所以会有两个字符相等，如何这两个字符相同，取最大价值建边。（样例很仁慈，给的很好）


位置向汇点建边，费用为 $0$，容量为 $2$。