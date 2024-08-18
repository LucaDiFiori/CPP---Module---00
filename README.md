# CPP---MODULE---00
This first module of C++ is designed to help you understand the specifities of the language when compared to C. Time to dive into Object Oriented Programming!

## Description
In this initial series of exercises, we'll cover the basic syntax of C++: explore namespaces, dive into classes, and get familiar with member functions along with a few other key concepts.

# EX00 - MEGAPHONE
The provided C++ program processes command-line arguments by converting each argument to uppercase and printing them separated by spaces. If no arguments are provided, it outputs a default message: * LOUD AND UNBEARABLE FEEDBACK NOISE *.


# THINGS TO KNOW

## NAMESPACE
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


## SCOPE RESOLUTION OPERATOR "::"
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

## STDIO STREAMS
The C++ Standard Library provides a set of standard input and output facilities through a set of classes and functions commonly referred to as "streams." These are part of the <iostream> header. Streams are used to handle input and output operations, and they abstract away the details of how data is read from or written to different types of devices (e.g., keyboards, files, etc.).
Here's a brief overview of the key components:

### 1 Stream Classes
- **std::istream:** This class is used for input operations. It represents the standard input stream (std::cin), but can also be used with other input sources, like files.
- **std::ostream:** This class is used for output operations. It represents the standard output stream (std::cout), but can also be used with other output destinations, like files.
- **std::iostream:** This is a combination of std::istream and std::ostream. It supports both input and output operations. It is typically used for streams that handle both input and output, like file streams.
- **std::ifstream:** This class is derived from std::istream and is used specifically for reading from files.
- **std::ofstream:** This class is derived from std::ostream and is used specifically for writing to files.
- **std::fstream:** This class is derived from std::iostream and can be used for both reading from and writing to files.

### 2 Stream Objects
- **std::cin:** The standard input stream, typically connected to the keyboard.
- **std::cout:** The standard output stream, typically connected to the console.
- **std::cerr:** The standard error stream, used for error messages. It is unbuffered by default.
- **std::clog:** The standard logging stream, used for logging messages. It is buffered by default.

### 3 Basic Usage
- **Input:** To read data from a stream, you use the extraction operator **>>** for formatted input or the getline function for reading whole lines.
```C++
int x;
std::cin >> x; // Read an integer from standard input

std::string line;
std::getline(std::cin, line); // Read a line from standard input
```
- **Output:** To write data to a stream, you use the insertion operator **<<** for formatted output.
```C++
int x = 42;
std::cout << "The value is: " << x << std::endl; // Output to standard output
```

### 4 File Operations
- **Reading from a file**
```C++
std::ifstream infile("example.txt");
if (infile.is_open()) {
    std::string line;
    while (std::getline(infile, line)) {
        std::cout << line << std::endl;
    }
    infile.close();
}
```
- **Writing to a file:**
```C++
std::ofstream outfile("example.txt");
if (outfile.is_open()) {
    outfile << "Hello, file!" << std::endl;
    outfile.close();
}
```

### 5 Error Handling
Streams provide several methods to check their state:
- **good():** Returns true if the stream is in a good state.
- **bad():** Returns true if a serious error occurred.
- **fail():** Returns true if an input or output operation failed.
- **eof():** Returns true if the end of the file has been reached

Ex:
```C++
if (infile.fail()) {
    std::cerr << "Error reading from file" << std::endl;
}
```

### 6 Manipulators
Stream manipulators are special functions that modify the formatting of the output. Some common manipulators include:
- **std::endl:** Inserts a newline character and flushes the stream
- **std::setw(int):** Sets the width of the next input/output field.
- **std::fixed:** Used to set the floating-point format to fixed-point notation
- **std::setprecision(int):** Sets the number of digits after the decimal point for floating-point numbers.

## -----------------------------------------------------------------------------
## CLASS AND INSTANCE
## Class
In C++, a class is a fundamental concept in object-oriented programming (OOP) that allows you to define your own custom data types. A class combines data and functions into a single unit, encapsulating the properties (data members) and behaviors (member functions) that operate on the data.

### Key Components of a Class
#### 1 Class Definition:
- A **class** is defined using the class keyword, followed by the class name and a block of code that contains its members.
```C++
class MyClass {
public:
    int myNumber; // Data member (public)
    void display(); // Member function (public)
private:
    int secret; // Data member (private)
};
```

#### 2 Data Members:
- These are variables that hold the state of the object. They can be public, private, or protected.
  - **Public:** Accessible from outside the class.
  - **Private:** Accessible only within the class.
  - **Protected:** Accessible within the class and by derived classes.

#### 3 Member Functions:
- These are functions defined inside the class that operate on the data members. They can also be public, private, or protected.

#### 4 Constructors and Destructors:
Constructors and destructors are fundamental components of classes in C++. They manage the initialization and cleanup of objects, respectively. 

#### Constructor 
##### Purpose:
A constructor initializes an object when it's created. It sets up the object’s initial state and allocates resources if necessary.

##### Key Characteristics:
- **Name:** The constructor has the same name as the class.
- **No Return Type:** Constructors do not return a value, not even void.
- **Automatic Invocation:** Constructors are called automatically when an object is instantiated.

##### Types of Constructors:
- **Default Constructor:** A constructor that takes no arguments. If no other constructor is provided, the compiler provides a default constructor.
```C++
class MyClass {
public:
    MyClass() {
        // Constructor code
    }
};
```
- **Parameterized Constructor:** A constructor that takes one or more arguments to initialize the object with specific values.
```C++
class MyClass {
public:
    MyClass(int a, double b) {
        // Constructor code using a and b
    }
};
```
- **Copy Constructor:** A constructor that initializes a new object as a copy of an existing object. It is called when an object is passed by value or explicitly copied.
```C++
class MyClass {
public:
    MyClass(const MyClass& other) {
        // Copy constructor code
    }
};
```

#### Destructor
##### Purpose: 
A destructor cleans up resources when an object is destroyed. It deallocates memory and performs other cleanup tasks.

##### Key Characteristics:
- **Name:** The destructor has the same name as the class, preceded by a tilde (~).
- **No Parameters:** Destructors do not take any arguments.
- **No Return Type:** Destructors do not return a value.
- **Automatic Invocation:** Destructors are called automatically when an object goes **out of scope or is explicitly deleted.

```C++
class MyClass {
public:
    // Constructor
    MyClass() {
        // Initialization code
    }
    // Destructor
    ~MyClass() {
        // Cleanup code
    }
};
```
##### Key Points:
- **Destructor Call:** When an object is destroyed, the destructor is called automatically to perform any necessary cleanup.
- **Order of Destruction:** If a class contains other objects, their destructors are called before the destructor of the containing class.
- **Resource Management:** Destructors are crucial for managing resources like dynamically allocated memory, file handles, or network connections.

**Example with Dynamic Memory:**
```C++
class MyClass {
private:
    int* data;

public:
    // Constructor
    MyClass(int size) {
        data = new int[size]; // Allocate memory
    }

    // Destructor
    ~MyClass() {
        delete[] data; // Deallocate memory
    }
};
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