# C++ Interview Preparation

记录我的 C++ 学习过程、代码练习和面试知识。笔记以中文解释为主，同时积累英文面试表达。

## 2026-10-03：编译、vector 与时间复杂度

### 1. 编译与运行

- `main.cpp` 是源代码（source code），由人编写。
- `main` 是编译器生成的可执行文件（executable）。
- 修改源代码后，需要重新编译，运行的程序才会包含最新修改。

在项目目录中运行：

```sh
clang++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o main
./main
```

编译参数：

| 参数 | 含义 |
| --- | --- |
| `-std=c++17` | 使用 C++17 标准 |
| `-Wall -Wextra` | 开启常用及额外编译警告 |
| `-pedantic` | 对不符合所选标准的用法提供诊断 |
| `-o main` | 将输出的可执行文件命名为 `main` |

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

完整代码见 [main.cpp](main.cpp)。练习步骤：

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
