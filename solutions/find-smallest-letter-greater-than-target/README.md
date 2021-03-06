
# [寻找比目标字母大的最小字母](https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target)

## 题目描述

<p>给你一个排序后的字符列表 <code>letters</code> ，列表中只包含小写英文字母。另给出一个目标字母&nbsp;<code>target</code>，请你寻找在这一有序列表里比目标字母大的最小字母。</p>

<p>在比较时，字母是依序循环出现的。举个例子：</p>

<ul>
	<li>如果目标字母 <code>target = 'z'</code> 并且字符列表为&nbsp;<code>letters = ['a', 'b']</code>，则答案返回&nbsp;<code>'a'</code></li>
</ul>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre>
<strong>输入: </strong>letters = ["c", "f", "j"]，target = "a"
<strong>输出:</strong> "c"
</pre>

<p><strong>示例 2:</strong></p>

<pre>
<strong>输入:</strong> letters = ["c","f","j"], target = "c"
<strong>输出:</strong> "f"
</pre>

<p><strong>示例 3:</strong></p>

<pre>
<strong>输入:</strong> letters = ["c","f","j"], target = "d"
<strong>输出:</strong> "f"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>2 &lt;= letters.length &lt;= 10<sup>4</sup></code></li>
	<li><code>letters[i]</code>&nbsp;是一个小写字母</li>
	<li><code>letters</code> 按非递减顺序排序</li>
	<li><code>letters</code> 最少包含两个不同的字母</li>
	<li><code>target</code> 是一个小写字母</li>
</ul>


## 题解

### cpp [🔗](find-smallest-letter-greater-than-target.cpp) 
```cpp
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size();
        while (lo < hi) {
            int m = (lo + hi) >> 1;
            if (letters[m] <= target) {
                lo = m + 1;
            } else {
                hi = m;
            }
        }
        if (hi == letters.size()) hi = 0;
        return letters[hi];
    }
};
```
### golang [🔗](find-smallest-letter-greater-than-target.go) 
```golang
func nextGreatestLetter(letters []byte, target byte) byte {
    lo, hi := 0, len(letters)
    for lo < hi {
        m := (lo + hi) >> 1
        if letters[m] <= target {
            lo = m + 1
        } else {
            hi = m
        }
    }
    if lo == len(letters) {
        lo = 0
    }
    return letters[lo]
}
```


## 相关话题

- [数组](../../tags/array.md) 
- [二分查找](../../tags/binary-search.md) 


## 相似题目



## Links

- [Prev](../to-lower-case/README.md) 
- [Next](../convert-binary-search-tree-to-sorted-doubly-linked-list/README.md) 

