# C++ Interview Preparation

My notes and coding exercises for learning C++ and preparing for interviews.

Read in English first. Short Chinese notes help clarify difficult concepts.（先读英文，中文辅助理解。）

## Quick Links

- [Code Examples](scripts/README.md): browse and run exercises.
- [Interview Notes & Questions](interview/README.md): review concepts and practise interview answers.

## Topics

### Standard Library Containers

| Topic | Notes & Interview Questions | Code Example | Date |
| --- | --- | --- | --- |
| Vector: a dynamic array | [Vector Notes](interview/containers/vector/README.md) | [Update scores and calculate a total](scripts/vector/scores.cpp) | 2026-10-03 |

### C++ Basics & Compilation

- [Compile and Run](interview/containers/vector/README.md#1-compile-and-run)
- [Range-based For Loops](interview/containers/vector/README.md#4-loops-and-accumulation)

### Algorithm Complexity

- [Time Complexity of Vector Operations](interview/containers/vector/README.md#6-time-complexity)
- [Interview Questions: Time and Space Complexity](interview/containers/vector/README.md#interview-questions)

## Run the Vector Example

Run these commands from the repository root:

```sh
mkdir -p build
clang++ -std=c++17 -Wall -Wextra -pedantic scripts/vector/scores.cpp -o build/vector-scores
./build/vector-scores
```

## Writing Guidelines

Use English for headings, explanations, and interview answers in every README. Add brief Chinese explanations only where they help understanding. Practise explaining each topic in English before checking the Chinese notes.

中文用于辅助理解；复习时先尝试用英文解释。
