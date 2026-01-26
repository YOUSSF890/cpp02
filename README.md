# C++ - Module 02

## Description

This project is part of the 42 C++ modules.

Module 02 introduces:

* Ad-hoc polymorphism
* Operator overloading
* Orthodox Canonical Class Form

The goal is to understand how classes work deeply in C++, how operators can be overloaded, and how to design clean and correct classes using C++98.

---

## Compilation

All code is compiled using:

```
c++ -Wall -Wextra -Werror -std=c++98
```

Each exercise contains its own `Makefile`.

---

## General Rules

* Each exercise is in its own folder: `ex00`, `ex01`, `ex02`, `ex03`
* Class names use **UpperCamelCase**
* One class = one header (`.hpp`) and one source file (`.cpp`)
* No memory leaks are allowed
* No external libraries
* C++11 and newer features are forbidden
* `printf`, `malloc`, `free` are forbidden
* `using namespace` and `friend` are forbidden unless stated
* STL is forbidden in this module

---

## Orthodox Canonical Form

From this module on, every class must implement:

* Default constructor
* Copy constructor
* Copy assignment operator
* Destructor

---

## Exercise 00 – Fixed (Canonical Form)

**Directory:** `ex00/`

Create a `Fixed` class that represents a fixed-point number.

### Features

* Stores a raw integer value
* Uses 8 fractional bits
* Implements canonical form
* Getter and setter for raw value

---

## Exercise 01 – Fixed Conversions

**Directory:** `ex01/`

Extend the `Fixed` class:

* Construct from `int`
* Construct from `float`
* Convert to `int` and `float`
* Overload `<<` operator

---

## Exercise 02 – Operator Overloading

**Directory:** `ex02/`

Add operator overloads:

* Comparison operators
* Arithmetic operators
* Increment and decrement operators

Add static functions:

* `min()`
* `max()`

---

## Submission

* Push all files to your Git repository
* Only submitted files will be evaluated
* Be ready to explain and modify your code during defense

---

## Author

Login: **ylagzoul**

42 Network
