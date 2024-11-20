# s21_string Library

## Introduction

This project involves the development of a custom implementation of the **string.h** library in the C programming language, with additional functionality such as custom **sprintf** and **sscanf** implementations. The **string.h** library is an essential part of C, providing string manipulation functions. This project focuses on string data processing and reinforcing structured programming techniques.

## Features

The library includes:
1. Full implementation of **string.h** functions with behavior consistent with the standard library.
2. A partial implementation of **sprintf**.
3. Additional features, such as custom string manipulation functions inspired by C#’s `String` class.

---

## Functions Overview

### **Core `string.h` Functions**

The following functions are included:

| Function Name                   | Description                                                                                       |  
|---------------------------------|---------------------------------------------------------------------------------------------------|  
| `s21_memchr`                    | Searches the first occurrence of a byte in a block of memory.                                     |  
| `s21_memcmp`                    | Compares two blocks of memory.                                                                   |  
| `s21_memcpy`                    | Copies memory from source to destination.                                                        |  
| `s21_memset`                    | Fills a block of memory with a specific value.                                                   |  
| `s21_strlen`                    | Calculates the length of a string.                                                               |  
| `s21_strcpy`                    | Copies a string to another buffer.                                                               |  
| `s21_strcat`                    | Appends one string to another.                                                                   |  
| ...                             | (and other essential `string.h` functions)                                                       |  

---

### **Custom Implementations**

#### **sprintf**

A partial implementation of `sprintf` supports:
- **Specifiers**: `c`, `d`, `f`, `s`, `u`, `%`.
- **Flags**: `-`, `+`, ` ` (space).
- **Width**: Numeric values only.
- **Precision**: `.number`.
- **Length Modifiers**: `h`, `l`.

#### **sscanf**

A complete implementation supporting all format specifiers, flags, and modifiers.

---

#### **String Utility Functions**

These functions are inspired by the C# `String` class and extend the basic capabilities of `string.h`:

| Function Name   | Description                                                                                   |  
|------------------|-----------------------------------------------------------------------------------------------|  
| `s21_to_upper`   | Converts a string to uppercase.                                                              |  
| `s21_to_lower`   | Converts a string to lowercase.                                                              |  
| `s21_insert`     | Inserts a substring into a string at a specified index.                                      |  
| `s21_trim`       | Trims specified characters from the beginning and end of a string.                           |  

---

## Testing

```bash

# Run tests  
make test  

# Generate coverage reports  
make gcov_report  

```

### Coverage Reports

Generate HTML reports using `gcov`. The `gcov_report` target should build unit tests with coverage flags enabled.

---

## Additional Tasks

1. **Enhanced `sprintf`**: Implement additional specifiers (`g`, `e`, `x`, `o`) and flags (`#`, `0`).
2. **sscanf**: Develop a full-featured `sscanf` implementation.
3. **Utility Functions**: Expand string manipulation utilities, including trimming, insertion, and case conversion.

---

## File Structure

```plaintext
src/  
├── s21_string.h  
├── s21_string.c  
├── Makefile  
└── tests/  
    ├── test_s21_string.c  
    ├── test_sprintf.c  
    ├── test_sscanf.c  
    └── ...  
```
---

## Building and Running
Use the provided Makefile for building and testing the project:

```bash
# Build the library and tests  
make all  

# Run tests  
make test  

# Generate coverage reports  
make gcov_report  

# Clean build files  
make clean  
```
