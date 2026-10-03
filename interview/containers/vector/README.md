# Vector：学习笔记与面试问答

[返回首页](../../../README.md) · [面试主题目录](../../README.md) · [查看例子](../../../scripts/vector/scores.cpp)

## 2026-10-03：编译、vector 与时间复杂度

### 1. 编译与运行

- `scores.cpp` 是源代码（source code），由人编写。
- `build/vector-scores` 是编译器生成的可执行文件（executable）。
- 修改源代码后，需要重新编译，运行的程序才会包含最新修改。

在仓库根目录中运行：

```sh
mkdir -p build
clang++ -std=c++17 -Wall -Wextra -pedantic scripts/vector/scores.cpp -o build/vector-scores
./build/vector-scores
```

编译参数：

| 参数 | 含义 |
| --- | --- |
| `-std=c++17` | 使用 C++17 标准 |
| `-Wall -Wextra` | 开启常用及额外编译警告 |
| `-pedantic` | 对不符合所选标准的用法提供诊断 |
| `-o build/vector-scores` | 指定生成的可执行文件路径 |

本次编译没有输出诊断，程序成功运行。

### 2. std::vector：可变长度数组

`std::vector` 可以在运行过程中增加元素，使用时需要包含 `<vector>`。

```cpp
std::vector<int> scores{72, 85, 91};
scores.push_back(88);
```

- `int` 表示整数类型；这个 vector 的元素都是整数。
- `push_back(88)` 在末尾添加 `88`。
- `scores.size()` 返回元素数量，此时是 `4`。

英文表达：

> `std::vector<int>` creates a vector of integers.

### 3. 下标从 0 开始

| 表达式 | 添加 88 后的值 |
| --- | --- |
| `scores[0]` | 72 |
| `scores[1]` | 85 |
| `scores[2]` | 91 |
| `scores[3]` | 88 |

```cpp
scores[1] = 90;
```

这条语句把第二个元素从 `85` 改为 `90`。使用 `[]` 时必须确保下标有效，它不会自动检查是否越界。

### 4. 循环与累加

```cpp
int total = 0;

for (int score : scores)
{
    total += score;
}
```

- 这是范围 for 循环（range-based for loop），逐个访问 vector 中的元素。
- `total` 从 `0` 开始，保存累计的总和。
- `total += score;` 等价于 `total = total + score;`。

### 5. 今天完成的练习

完整代码见 [scores.cpp](../../../scripts/vector/scores.cpp)。练习步骤：

1. 创建 `{72, 85, 91}`。
2. 使用 `push_back` 添加 `88`。
3. 将第二个元素改为 `90`。
4. 用循环求和。
5. 打印每个分数、总和与元素数量。

输出（每个分数后还有一个空格）：

```text
72 90 91 88
Total: 341

Count: 4
```

### 6. 面试知识：时间复杂度

假设 vector 中有 `n` 个元素：

| 操作 | 时间复杂度 | 原因 |
| --- | --- | --- |
| `scores[1] = 90` | O(1) | 通过下标直接访问 |
| `scores.size()` | O(1) | 返回已记录的元素数量 |
| 遍历求和 | O(n) | 每个元素访问一次 |
| 遍历打印 | O(n) | 每个元素访问一次（按每个整数输出成本固定计） |
| `push_back` | 均摊 O(1)，单次最坏 O(n) | 容量不足时可能重新分配存储并移动元素 |

两个循环的总复杂度为 `O(n) + O(n) = O(n)`；忽略常数因子。这里分析的是元素数量可变时的算法，而不只是固定四个数字的例子。

英文面试表达：

> The program has linear time complexity because it iterates through the vector twice. We ignore the constant factor, so the overall complexity is O(n).

### 7. 英文词汇

| 中文 | English |
| --- | --- |
| 整数 | integer |
| 程序 | program |
| 程序员 | programmer |
| 源代码 | source code |
| 编译器 | compiler |
| 下标 | index |
| 元素 | element |
| 时间复杂度 | time complexity |
| 线性时间复杂度 | linear time complexity |

## 学习进度

- [x] 编译并运行 C++17 程序
- [x] 创建整数 vector
- [x] 使用 push_back 和 size
- [x] 使用下标修改元素
- [x] 使用范围 for 循环遍历与求和
- [x] 理解 O(1) 和 O(n)，忽略常数因子

## 面试问答

### Q1. `std::vector<int>` 是什么？

它是元素类型为 `int` 的可变长度数组；使用时需要包含 `<vector>`。

**English:** A vector of integers is a dynamic array that can grow as elements are added.

### Q2. 为什么 `scores[1]` 是第二个元素？

C++ 下标从 `0` 开始，所以第一个元素是 `scores[0]`，第二个是 `scores[1]`。

**English:** Vector indices start at zero, so index one refers to the second element.

### Q3. `push_back` 和 `size()` 分别做什么？

`push_back` 在末尾添加元素，`size()` 返回当前元素数量。添加 `88` 后，本例有四个元素。

**English:** `push_back` appends an element, and `size` returns the number of elements.

### Q4. 两个连续的 for 循环为什么是 O(n)？

每个循环遍历 `n` 个元素，总操作次数与 `2n` 成正比。忽略常数因子后是 O(n)。两个循环若嵌套，并且各执行 `n` 次，则通常是 O(n²)。

**English:** Each loop takes linear time. Two sequential loops still take O(n) time because constant factors are ignored.

### Q5. `push_back` 总是 O(1) 吗？

不是。通常追加元素的成本很低，但容量不足时需要重新分配存储并移动已有元素，单次最坏为 O(n)。将多次追加的成本平均后，均摊时间复杂度为 O(1)。

**English:** Appending has amortized constant time complexity, but a single append can take O(n) when reallocation is needed.

### Q6. 这个练习的空间复杂度是多少？

存储 `n` 个分数的 vector 占 O(n) 空间。求和过程只使用 `total`、`score` 等固定数量的变量，因此额外空间为 O(1)。

**English:** The vector uses O(n) space, while the summation uses O(1) auxiliary space.

## 复习考点

- 能解释 `vector<int>`、`push_back`、`size()` 的作用。
- 能根据从 0 开始的下标修改元素，并避免越界。
- 能独立写出遍历与求和代码，预测输出。
- 能解释下标访问 O(1)、遍历 O(n) 和追加的均摊 O(1)。
- 能区分连续循环与嵌套循环，以及总空间与额外空间。
