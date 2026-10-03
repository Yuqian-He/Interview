# C++ Interview Preparation

我的 C++ 学习与面试准备仓库。首页提供主题导航，详细学习笔记、面试问答和代码按主题归档。

## 快速入口

- [代码例子目录](scripts/README.md)：查看和运行练习。
- [面试问答目录](interview/README.md)：学习笔记、考点与英文回答。

## 按分类查找

### 标准库容器（STL Containers）

| 主题 | 学习笔记与面试问答 | 代码例子 | 学习日期 |
| --- | --- | --- | --- |
| Vector：可变长度数组 | [Vector 笔记与考点](interview/containers/vector/README.md) | [分数修改、遍历与求和](scripts/vector/scores.cpp) | 2026-10-03 |

### C++ 基础与编译

- [编译命令与参数](interview/containers/vector/README.md#1-编译与运行)
- [范围 for 循环与累加](interview/containers/vector/README.md#4-循环与累加)

### 算法复杂度

- [Vector 操作的时间复杂度](interview/containers/vector/README.md#6-面试知识时间复杂度)
- [面试问答：时间与空间复杂度](interview/containers/vector/README.md#面试问答)

## 文件布局

```text
.
├── README.md                         # 首页导航
├── scripts/
│   ├── README.md                     # 代码例子索引
│   └── vector/
│       └── scores.cpp                # Vector 练习
└── interview/
    ├── README.md                     # 面试主题索引
    └── containers/
        └── vector/
            └── README.md             # Vector 学习笔记、问答与考点
```

## 运行 Vector 例子

在仓库根目录运行：

```sh
mkdir -p build
clang++ -std=c++17 -Wall -Wextra -pedantic scripts/vector/scores.cpp -o build/vector-scores
./build/vector-scores
```

## 后续整理方式

每个主题的代码放入 `scripts/<主题>/`，学习笔记和面试问答放入 `interview/<分类>/<主题>/README.md`，并在首页和对应目录索引中添加链接。
