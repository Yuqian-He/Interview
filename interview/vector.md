# Vector: Learning Notes & Interview Questions

[Home](../README.md) · [Code Example](../scripts/vector.cpp)

## Learning Session: 2026-10-03

### 1. Compile and Run

```sh
mkdir -p build
clang++ -std=c++17 -Wall -Wextra -pedantic scripts/vector.cpp -o build/vector
./build/vector
```

| Flag | Meaning |
| --- | --- |
| `-std=c++17` | Use the C++17 standard |
| `-Wall -Wextra` | Enable common and additional compiler warnings |
| `-pedantic` | Diagnose uses that do not conform to the selected standard |
| `-o build/vector` | Set the output executable path |

The example compiled without diagnostics and ran successfully.

### 2. Time Complexity

Assume the vector contains `n` elements.

| Operation | Time Complexity | Reason |
| --- | --- | --- |
| `scores[1] = 90` | O(1) | Direct access by index |
| `scores.size()` | O(1) | Returns the stored element count |
| Summation loop | O(n) | Visits each element once |
| Printing loop | O(n) | Visits each element once, assuming fixed cost per integer output |
| `push_back` | Amortized O(1); O(n) for a single worst-case append | Reallocation may move existing elements |

Two sequential loops take `O(n) + O(n) = O(n)` time. Constant factors are ignored. This analysis describes how the algorithm scales with the number of elements, rather than only the fixed four-element example.

连续的两个循环仍是 O(n)；追加操作均摊 O(1)，扩容时单次可能为 O(n)。

> The program has linear time complexity because it iterates through the vector twice. We ignore the constant factor, so the overall complexity is O(n).

## Interview Questions
### Q1. What is `std::vector<int>`?

A vector of integers is a dynamic array that can grow as elements are added. Its element type is `int`, and it requires the `<vector>` header.
元素类型为整数的可变长度数组。

### Q2. Why does `scores[1]` refer to the second element?

Vector indices start at zero, so index one refers to the second element.
从 0 开始计数。

### Q3. What do `push_back` and `size()` do?

`push_back` appends an element, and `size()` returns the number of elements. After appending `88`, this example contains four elements.
末尾添加；返回元素数量。

### Q4. Why do two sequential for loops take O(n) time?

Each loop visits `n` elements. Together, they perform work proportional to `2n`, which is O(n) because constant factors are ignored. Two nested loops that each run `n` times typically take O(n²) time.
连续循环相加；嵌套循环通常相乘。

### Q5. Is `push_back` always O(1)?

Appending has amortized constant time complexity, but a single append can take O(n) when reallocation is needed. Averaging the cost over many appends gives O(1) amortized time.
均摊复杂度不等于每一次操作的复杂度。

### Q6. What is the space complexity of this exercise?

The vector uses O(n) space to store `n` scores. The summation uses O(1) auxiliary space because it needs only a fixed number of variables, such as `total` and `score`.
vector 存储占 O(n)；求和的额外空间为 O(1)。

## Review Checklist

- Explain `vector<int>`, `push_back`, and `size()` in English.
- Update elements using zero-based indices without going out of bounds.
- Write the iteration and summation code independently and predict its output.
- Explain O(1) indexing, O(n) iteration, and amortized O(1) appending.
- Distinguish sequential loops from nested loops, and total space from auxiliary space.
