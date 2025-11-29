# 42 C++ Modules

![Language](https://img.shields.io/badge/Language-C%2B%2B98-00599C?style=for-the-badge&logo=c%2B%2B)
![School](https://img.shields.io/badge/School-42-000000?style=for-the-badge&logo=42)
![Status](https://img.shields.io/badge/Status-Completed-success?style=for-the-badge)

## 📝 Description

This repository contains all the C++ modules completed as part of the 42 School curriculum.
The goal of this project series is to transition from imperative programming (C) to **Object-Oriented Programming (OOP)**, while strictly adhering to the **C++98** standard.

Each module addresses a specific concept of the language, ranging from basic syntax to advanced usage of the STL (Standard Template Library).

## 🛠️ Concepts & Technologies

* **Orthodox Canonical Form** (Constructor, Destructor, Copy, Assignment) is mandatory for all classes starting from CPP02.
* **Compilation:** `c++ -Wall -Wextra -Werror -std=c++98`.

## 📚 Module List

| Module | Main Subject | Key Concepts Covered |
| :--- | :--- | :--- |
| **CPP 00** | Introduction | Class basics, Member functions, Stdio streams, Init lists. |
| **CPP 01** | Memory & Pointers | `new`/`delete`, References vs Pointers, File streams. |
| **CPP 02** | Ad-hoc Polymorphism | Operator Overloading, Orthodox Canonical Form. |
| **CPP 03** | Inheritance | Single and multiple inheritance, Diamond problem (`virtual`). |
| **CPP 04** | Polymorphism | Subtyping, Abstract classes, Interfaces, Virtual destructors. |
| **CPP 05** | Robustness | Exceptions (`try`/`catch`), Custom exception classes. |
| **CPP 06** | Casts | `static_cast`, `dynamic_cast`, `reinterpret_cast`. |
| **CPP 07** | Templates | Function and class templates. |
| **CPP 08** | STL (Basic) | Containers (`vector`, `list`, `map`), Algorithms, Iterators. |
| **CPP 09** | STL (Advanced) | Adapted containers (`stack`, `deque`), Complex algorithms. |

## 🚀 Usage

Each module contains its own `Makefile`. To test a specific exercise:

1. Enter the module and exercise directory:
   ```bash
   cd CPP0X/ex0Y
   make
   ./[executable_name]
   ```