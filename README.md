# Arbitrary Precision Calculator

## 📌 Project Overview

The Arbitrary Precision Calculator is a C-based application that performs arithmetic operations on integers of unlimited size, overcoming the limitations of built-in data types. It uses linked lists to represent large numbers, enabling accurate computation of values that exceed the range of standard integer types.

## ✨ Features

- Addition of large integers
- Subtraction of large integers
- Multiplication of large integers
- Division of large integers
- Supports numbers of virtually unlimited length
- Handles positive and negative integers
- Efficient digit-by-digit arithmetic using linked lists
- Menu-driven command-line interface

## 🛠 Technologies Used

- C Programming
- GCC Compiler
- Makefile
- Linked Lists
- Abstract Data Types (ADT)
- Dynamic Memory Allocation
- Modular Programming
- Linux / Git Bash

## 📂 Project Structure

```
ARBITRARY_PRECISION_CALCULATOR

├── main.c
├── add.c
├── subtract.c
├── multiply.c
├── divide.c
├── list.c
├── *.h
├── Makefile
└── README.md
```

> **Note:** File names may vary slightly depending on your implementation.


## 📷 Sample Output

The following screenshot demonstrates arithmetic operations on large integers using the Arbitrary Precision Calculator.

![Sample Output](screenshots/sample_output.png)

## ▶️ How to Compile

```bash
make
```

## ▶️ How to Run

```bash
./apc <operand1> <operator> <operand2>
```

> *(Replace `apc` with your executable name if it's different.)*

## 📷 Sample Input

```
Enter first number: 987654321987654321987654321
Enter second number: 123456789123456789123456789
Choose operation: +
```

## 📷 Sample Output

```
Result:
1111111111111111111111111110
```

## 🎯 Learning Outcomes

- Implementation of arbitrary precision arithmetic
- Linked list manipulation
- Dynamic memory management
- Modular programming in C
- Algorithm design for large integer operations
- Efficient handling of numbers beyond built-in data type limits
