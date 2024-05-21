LeetCode 题目及解法汇总：

| 题目                                           |  难度  |                             方法                             | 要注意的地方                                                 | 代码                                                         |
| ---------------------------------------------- | :----: | :----------------------------------------------------------: | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 1. 两数之和                                    |  Easy  |                            哈希表                            | 寻找和返回时用的是 `t`，插入时用的是 `nums[i]`。             | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00001_Two%20Sum) |
| 2. 两数相加                                    | Medium |                          高精度加法                          |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00002_Add%20Two%20Numbers) |
| 3. 无重复字符的最长子串                        | Medium |                       经典的滑动窗算法                       |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00003_Longest%20Substring%20Without%20Repeating%20Characters) |
| 5. 最长回文子串                                | Medium | 方法一：动态规划<br />方法二：在每个可能的中心处进行 `expand()` |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00005_Longest%20Palindromic%20Substring) |
| 6. Z 字形变换                                  | Medium |             使用方向变量 direction 进行逐行枚举              | （1）主体代码处理不了 `numRows = 1` 的情形。<br />（2）`vector<string> rows(numRows);` 在初始化时必须指定长度。 | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00006_Zigzag%20Conversion) |
| 7. 整数反转                                    | Medium |                           整数反转                           | 整数反转的代码同样也适用于负数，所以不需要将输入数据转换为正数。 | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00007_Reverse%20Integer) |
| 8. 字符串转换整数（atoi）                      | Medium |                            模拟题                            |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00008_String%20to%20Integer(atoi)) |
| 9. 回文数                                      |  Easy  |                     数学（需要特判边界）                     | 注意本题的边界情况有两个：<br />（1）`x < 0`，则一定不是回文数；<br />（2）`x > 0 && x % 10 == 0`，则一定不是回文数。<br />这两个边界条件需要提前判断，主体代码处理不了。 | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00009_Palindrome%20Number) |
| 10. 正则表达式匹配                             |  Hard  |                           动态规划                           | 当 `p[j] == '*'` 时，状态转移方程为：<br />`dp[i][j] = dp[i][j - 2] ||i && dp[i - 1][j] && (s[i] == p[j - 1] ||p[j - 1] == '.') `，注意后一条件里当 `p[j - 1] == '.'` 也是可以的。 |                                                              |
| 11. 盛水最多的容器                             | Medium |                             贪心                             |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00011_Container%20With%20Most%20Water) |
| 12. 整数转罗马数字                             | Medium |                     新定义的进制转换问题                     |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00012_Integer%20to%20Roman) |
| 13. 罗马数字转整数                             |  Easy  |                            模拟题                            |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00013_Roman%20to%20Integer) |
| 14. 最长公共前缀                               |  Easy  |                         暴力做法即可                         |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00014_Longest%20Common%20Prefix) |
| 15. 三数之和                                   | Medium |                     排序 + 双指针 + 去重                     | 本题要注意两个地方：<br />（1）使用双指针之前要先排序；<br />（2）内层的 while 循环里，l 和 r 去完重之后可能有 l >= r，因此要加一个特判：`if (l < r)`。 | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00015_3Sum) |
| 16. 最接近的三数之和                           | Medium |                     排序 + 双指针 + 去重                     | 不要忘记去完重之后的条件：`if (l < r)`。                     | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00016_3Sum%20Closest) |
| 17. 电话号码的字母组合                         | Medium |                      简单的 DFS + 回溯                       | 注意：主体代码处理不了输入为空串的情况，故需加一个对空串的特判。 | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00017_Letter%20Combinations%20of%20a%20Phone%20Number) |
| 18. 四数之和                                   | Medium |                     排序 + 双指针 + 去重                     | （1）不要忘记先 sort；<br />（2）本题的四数之和可能会溢出，故要做如下处理：<br />`long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];` | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00018_4Sum) |
| 19. 删除链表的倒数第 N 个结点                  | Medium |              模板题：删除链表的倒数第 N 个结点               |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00019_Remove%20Nth%20Node%20From%20End%20of%20List) |
| 20. 有效的括号                                 |  Easy  |                         栈的简单应用                         |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00020_Valid%20Parentheses) |
| 21. 合并两个有序链表                           |  Easy  |                    以链表为载体的二路归并                    |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00021_Merge%20Two%20Sorted%20Lists) |
| 22. 括号生成                                   | Medium |                       二段 DFS + 回溯                        |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00022_Generate%20Parentheses) |
| 23. 合并 K 个升序链表                          |  Hard  |                        堆 + 链表合并                         |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00023_Merge%20k%20Sorted%20Lists) |
| 24. 两两交换链表中的节点                       | Medium |                   编写 `swapNodes()` 函数                    |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00024_Swap%20Nodes%20in%20Pairs) |
| 26. 删除有序数组中的重复项                     |  Easy  |                     模板题：有序向量去重                     | 注意要先执行 `nums[k++] = nums[i++]`，再执行 i 的增加。      | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00026_Remove%20Duplicates%20from%20Sorted%20Array) |
| 27. 移除元素                                   |  Easy  |                       模板题：移除元素                       | 注意：本题要先执行 `i++`，再进行赋值，和 26 题恰好相反。     | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00027_Remove%20Element) |
| 28. 找出字符串中第一个匹配项的下标             |  Easy  |                       模板题：KMP 算法                       |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00028_Find%20the%20Index%20of%20the%20First%20Occurrence%20in%20a%20String) |
| 29. 两数相除                                   | Medium |                      快速乘 && 边界处理                      | 注意：<br />（1）因为后面被除数和除数都会转换为负数，故被除数与除数是不是 `INT_MAX` 都不重要，只需考虑它们各自为 `INT_MIN` 的情况即可。被除数为 0 的情况也需要特判。<br />（2）在往 base 数组中添加因子时，判断条件是 `dividend - base.back() <= base.back()`。 | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00029_Divide%20Two%20Integers) |
| 30. 串联所有单词的子串                         |  Hard  |                   窗口长度固定的滑动窗问题                   | 本题滑动窗的窗口长度固定。                                   | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00030_Substring%20with%20Concatenation%20of%20All%20Words) |
| 31. 下一个排列                                 | Medium |                           数学推理                           |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00031_Next%20Permutation) |
| 32. 最长有效括号                               |  Hard  |                           栈的应用                           |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00032_Longest%20Valid%20Parentheses) |
| 33. 搜索旋转排序数组                           | Medium |                          二分版本 3                          | （1）`r = nums.size() - 1`；<br />（1）`while (l <= r)`；<br />（2）判断左右二分区间的条件要写成：`if (nums[mid] >= nums[l])`。 | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00033_Search%20in%20Rotated%20Sorted%20Array) |
| 34. 在排序数组中查找元素的第一个和最后一个位置 | Medium |                          二分版本 1                          | （1）`r = nums.size() - 1`；<br />（2）`while (l < r)`。     | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00034_Find%20First%20and%20Last%20Position%20of%20Element%20in%20Sorted%20Array) |
| 35. 搜索插入位置                               |  Easy  |                          二分版本 2                          | （1）`r = nums.size()`；<br />（2）`while (l < r)`。         | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00035_Search%20Insert%20Position) |
| 36. 有效的数独                                 | Medium |                            模拟题                            | （1）需要三个状态数组：`row[9][9]`，`col[9][9]` 和 `block[3][3][9]`；<br />（2）需要使用 `memset` 初始化以上三个数组。 | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00036_Valid%20Sudoku) |
| 37. 解数独                                     |  Hard  |                        二维表格型 DFS                        |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00037_Sudoku%20Solver) |
| 38. 外观数列                                   | Medium |                     模拟题（字符串解析）                     |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00038_Count%20and%20Say) |
| 39. 组合总和                                   | Medium |                             DFS                              | 注意按照选当前数字和不选当前数字来进行分支。                 | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00039_Combination%20Sum) |
| 40. 组合总和 II                                | Medium |                       DFS + prev 去重                        | 注意使用 prev 之前要先排序。                                 | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00040_Combination%20Sum%20II) |
| 41. 缺失的第一个正数                           |  Hard  |                           同秩映射                           | 本题的同秩映射要求参与映射的元素的数值位于 1～n 之间。       | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00041_First%20Missing%20Positive) |
| 42. 接雨水                                     |  Hard  |                        贪心 + 双指针                         |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00042_Trapping%20Rain%20Water) |
| 43. 字符串相乘                                 | Medium |                高精度乘法（高精度 x 高精度）                 |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00043_Multiply%20Strings) |
| 44. 通配符匹配                                 |  Hard  |                     动态规划 + 状态优化                      |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00044_Wildcard%20Matching) |
| 45. 跳跃游戏 II                                | Medium |                             推理                             |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00045_Jump%20Game%20II) |
| 46. 全排列                                     | Medium |                          DFS + 回溯                          | 需要用到 `st[]` 数组                                         | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00046_Permutations) |
| 47. 全排列 II                                  | Medium |                    DFS + 回溯 + prev 去重                    | 需要用到 `st[]` 数组                                         | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00047_Permutations%20II) |
| 48. 旋转图像                                   | Medium |                            trick                             | “先右下再竖，等于顺时针旋转 90 度”                           | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00048_Rotate%20Image) |
| 49. 字母异位词分组                             | Medium |                            哈希表                            |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00049_Group%20Anagrams) |
| 50. Pow(x, n)                                  | Medium |                            快速幂                            |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00050_Pow(x%2C%20n)) |
| 51. N 皇后                                     |  Hard  |                    二维表格型 DFS + 回溯                     |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00051_N-Queens) |
| 52. N 皇后 II                                  |  Hard  |                    二维表格型 DFS + 回溯                     | 不需要再填写棋盘                                             | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00052_N-Queens%20II) |
| 53. 最大子数组和                               | Medium |                           动态规划                           |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00053_Maximum%20Subarray) |
| 54. 螺旋矩阵                                   | Medium |                        方向数组的应用                        | （1）注意总共循环 n*m 步；<br />（2）先试探性地走，如果不对的话再纠正。 | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00054_Spiral%20Matrix) |
| 55. 跳跃游戏                                   | Medium |                       推理（同 45 题）                       |                                                              | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00055_Jump%20Game) |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
| 76. 最小覆盖子串                               |  Hard  |                            滑动窗                            | 注意要及时收缩窗口左端点。                                   | [GitHub](https://github.com/aeoaz/myLeetCode/tree/main/Problems/00076_Minimum%20Window%20Substring) |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |
|                                                |        |                                                              |                                                              |                                                              |



（第 10 题和第 44 题是一类问题，都是“动态规划 + 状态优化”）

（第 3 题、第 30 题、第 76 题是一类问题，都是“滑动窗”）

（第 20 题、第 32 题都是“栈在括号匹配问题中的应用”）

（第 2 题、第 43 题都是“高精度运算”，其中第 2 题是高精度加法，第 43 题是高精度 x 高精度）

（第 15 题、第 16 题、第 18 题都是“双指针”）

（第 17 题、第 22 题、第 39 题、第 40 题、第 37 题 都是“DFS + 回溯”）

（第 33 题、第 34 题、第 35 题是“二分”）
