# CPP---MODULE---00
This first module of C++ is designed to help you understand the specifities of the language when compared to C. Time to dive into Object Oriented Programming!

## Description
In this initial series of exercises, we'll cover the basic syntax of C++: explore namespaces, dive into classes, and get familiar with member functions along with a few other key concepts.

# EX00 - MEGAPHONE
The provided C++ program processes command-line arguments by converting each argument to uppercase and printing them separated by spaces. If no arguments are provided, it outputs a default message: * LOUD AND UNBEARABLE FEEDBACK NOISE *.


# THINGS TO KNOW

## Namespace
In C++, a namespace is a declarative region that provides a scope to identifiers such as variables, functions, classes, etc., to avoid name conflicts. Namespaces help organize code and prevent naming collisions, especially when using large libraries or multiple codebases with common names.

To create your own namespace in C++, use the namespace keyword followed by the name of the namespace, and enclose the declarations (variables, functions, classes, etc.) inside curly braces {}.

```C++
#include <stdo.h>

//declaring a global variable and a function
int gl_var = 1;
int f(void) {return 2;}

// Creating a custom namespace named "Foo"
namespace Foo {
  int gl_var = 3;
  int f(void) {return 4;}
}

// Creating a custom namespace named "Bar"
namespace Foo {
  int gl_var = 5;
  int f(void) {return 6;}
}
```
*Note: In C++, having three variables with the same name is not an issue because they belong to different scopes. The global gl_var is in the global scope, while the others are in the Foo namespace. C++ resolves variable names based on their scope, so there won't be any compilation conflicts.
You can then access, for example, the gl_var in the Foo namespace like so: Foo::gl_var.

### Namespace aliasing
Namespace aliasing in C++ allows you to create a shorter or more convenient name (alias) for an existing namespace. This is useful when you're dealing with long or nested namespaces, as it makes the code more readable and easier to manage.

You can create a namespace alias using the namespace keyword followed by the alias name, an equals sign =, and the existing namespace.
```C++
namespace VeryLongNamespaceName {
    void display() {
        std::cout << "Inside VeryLongNamespaceName!" << std::endl;
    }
}

// Create a shorter alias for the namespace
namespace VLN = VeryLongNamespaceName;

int main() {
    // Using the alias to access the display function
    VLN::display();  // Equivalent to VeryLongNamespaceName::display()
}
```
## <u>Scope resolution operator "::"</u>
The scope resolution operator in C++ is :: and is used to specify which scope an identifier (such as a variable, function, or class) belongs to. It helps disambiguate identifiers with the same name that exist in different scopes or namespaces.
### Key Uses of the Scope Resolution Operator
#### 1 Accessing Global Variables or Functions:
- When a local variable or function hides a global variable or function, you can use the scope resolution operator to access the global version.
```C++
int value = 10; // Global variable

void function() {
    int value = 20; // Local variable
    std::cout << "Local value: " << value << std::endl; // Prints 20
    std::cout << "Global value: " << ::value << std::endl; // Prints 10
}
```
#### 2 Defining Member Functions Outside a Class:
- The scope resolution operator is used to define member functions of a class outside the class definition.
```C++
class MyClass {
public:
    void display();
};

void MyClass::display() {
    std::cout << "Display function" << std::endl;
}
```
#### 3 Accessing Namespace Members:
- When dealing with namespaces, the scope resolution operator helps access elements within a specific namespace.
```C++
namespace MyNamespace {
    int value = 30;
}

int main() {
    std::cout << MyNamespace::value << std::endl; // Accesses MyNamespace::value
    return 0;
}
```
#### 4 Accessing Nested Namespaces:
```C++
namespace Outer {
    namespace Inner {
        int value = 40;
    }
}

int main() {
    std::cout << Outer::Inner::value << std::endl; // Accesses Outer::Inner::value
    return 0;
}
```







# C++ PROJECT GUIDELINES

## 1. Compilation
- Compile your code with `c++` and the flags `-Wall`, `-Wextra`, `-Werror`:
- Your code must still compile if you add the flag `-std=c++98`:

## 2. Formatting and Naming Conventions
- The exercise directories must be named as follows: `ex00`, `ex01`, ..., `exn`:

- Name your files, classes, functions, member functions, and attributes according to the guidelines

- Write class names in **UpperCamelCase** format

- Files containing class code must be named according to the class name:
  - If you have a class named `BrickWall`, the corresponding files should be `BrickWall.hpp` (or `.h` for the header) and `BrickWall.cpp` for the implementation.

- Unless otherwise specified, all output messages must end with a newline character and be displayed to the standard output

- No specific coding style is enforced (unlike **Norminette** in C)

## 3. Allowed/Forbidden
- **You are not coding in C anymore; it’s time for C++**:
  - You must use C++ features instead of sticking to what you already know from C.

- You can use almost everything from the **C++ Standard Library**:
  - It’s allowed to use the C++ Standard Library (e.g., strings, streams, etc.).

- **External libraries are not allowed**:
  - You cannot use external libraries outside of the C++ Standard Library. Specifically, **C++11** (and later versions) and **Boost libraries** are forbidden.

- The following functions are forbidden: `*printf()`, `*alloc()`, and `free()`

## 4. C++ Concepts
- **Namespaces, classes, member functions, input/output streams (stdio), initialization lists, static, const, and other basic C++ concepts**:

- The keywords `using namespace <namespace_name>` and `friend` are forbidden:
  - You cannot use `using namespace` to avoid naming conflicts, nor can you use `friend` to gain direct access to private members of a class.

- You can only use the **STL** (Standard Template Library) in **modules 08 and 09**:
  - Until modules 08 and 09, you are **not allowed** to use containers like `vector`, `list`, `map`, or algorithms included in the `<algorithm>` header. If you use them before these modules, you will receive a grade of **-42**.

## 5. Design Requirements
- **Memory leaks occur in C++ too**:
  - When you allocate memory using `new`, you must properly deallocate it (using `delete`) to avoid memory leaks.

- From **module 02 to module 09**, your classes must follow the **Orthodox Canonical Form**:
  - This means your classes must implement the following "big four" methods: a default constructor, copy constructor, assignment operator, and destructor.

- **Placing function implementations in a header file** (except for templates) will result in a score of 0 for the exercise:
  - Functions must be implemented in `.cpp` files, not in header (`.hpp`) files unless they're template functions.

- Each header must be usable independently of others:
  - Your `.hpp` files must include all necessary dependencies and use include guards (or `#pragma once`) to avoid double inclusions. If an include guard is missing, the exercise will receive a grade of 0.