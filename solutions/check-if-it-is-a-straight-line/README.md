
# [缀点成线](https://leetcode-cn.com/problems/check-if-it-is-a-straight-line)

## 题目描述

<p>给定一个数组&nbsp;<code>coordinates</code>&nbsp;，其中&nbsp;<code>coordinates[i] = [x, y]</code>&nbsp;，<meta charset="UTF-8" />&nbsp;<code>[x, y]</code>&nbsp;表示横坐标为 <code>x</code>、纵坐标为 <code>y</code>&nbsp;的点。请你来判断，这些点是否在该坐标系中属于同一条直线上。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<p><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/19/untitled-diagram-2.jpg" /></p>

<pre>
<strong>输入：</strong>coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
<strong>输出：</strong>true
</pre>

<p><strong>示例 2：</strong></p>

<p><strong><img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2019/10/19/untitled-diagram-1.jpg" /></strong></p>

<pre>
<strong>输入：</strong>coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
<strong>输出：</strong>false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;=&nbsp;coordinates.length &lt;= 1000</code></li>
	<li><code>coordinates[i].length == 2</code></li>
	<li><code>-10^4 &lt;=&nbsp;coordinates[i][0],&nbsp;coordinates[i][1] &lt;= 10^4</code></li>
	<li><code>coordinates</code>&nbsp;中不含重复的点</li>
</ul>


## 题解

### cpp [🔗](check-if-it-is-a-straight-line.cpp) 
```cpp
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        // (y-y1)/(x-x1) = (y-y2)/(x-x2)
        // (y-y1)*(x-x2) = (y-y2)*(x-x1)
        int x = coordinates[0][0];
        int y = coordinates[0][1];
        for (int i = 1; i < coordinates.size(); i++) {
            int f1 = (y - coordinates[i-1][1]) * (x - coordinates[i][0]);
            int f2 = (y - coordinates[i][1]) * (x - coordinates[i-1][0]);
            if (f1 != f2) return false;
        }
        return true;
    }
};
```


## 相关话题

- [几何](../../tags/geometry.md) 
- [数组](../../tags/array.md) 
- [数学](../../tags/math.md) 


## 相似题目



## Links

- [Prev](../the-dining-philosophers/README.md) 
- [Next](../traffic-light-controlled-intersection/README.md) 

