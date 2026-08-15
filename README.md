# C++ Programming Modules

A comprehensive collection of C++ exercises developed as part of the 42 School curriculum. This repository demonstrates progressive mastery of C++ fundamentals through advanced concepts, including object-oriented programming principles, memory management techniques, template metaprogramming, and Standard Template Library implementation.

## Repository Structure

```
cpp_modules/
├── cpp00/          Module 00: Introduction to C++
├── cpp01/          Module 01: Memory and References
├── cpp02/          Module 02: Operator Overloading
├── cpp03/          Module 03: Inheritance
├── cpp04/          Module 04: Polymorphism
├── cpp05/          Module 05: Exception Handling
├── cpp06/          Module 06: Type Casting
├── cpp07/          Module 07: Templates
├── cpp08/          Module 08: STL Containers
└── cpp09/          Module 09: Advanced STL
```

## Technical Specifications

All code adheres to the following standards:

- **Language Standard**: C++98
- **Compiler**: g++ or clang++
- **Compilation Flags**: `-Wall -Wextra -Werror -std=c++98`
- **Coding Standard**: 42 School Norm compliant
- **Memory Management**: Zero memory leaks, verified with valgrind

## Module Breakdown

### Module 00: Introduction to C++

Foundational concepts establishing the transition from C to C++ programming paradigms.

**Exercise 00: Megaphone**
- Command-line argument processing
- String manipulation and transformation
- Standard output stream operations
- Introduction to C++ syntax and structure

**Exercise 01: PhoneBook Application**
- Class design and encapsulation
- Private data member management
- Interactive command-line interface
- Circular buffer implementation for contact storage
- Formatted output with field truncation
- Input validation and error handling

**Exercise 02: Account Management System**
- Static member variables and methods
- Timestamp generation and formatting
- Banking operations simulation
- Const-correctness implementation
- Class method chaining
- Output matching and test-driven development

### Module 01: Memory Management and References

Deep exploration of memory allocation strategies and reference semantics.

**Exercise 00: Zombie Class - Stack vs Heap**
- Dynamic memory allocation with new/delete
- Stack allocation and automatic destruction
- Constructor and destructor lifecycle
- Memory leak prevention
- Object naming and identification

**Exercise 01: Zombie Horde**
- Array allocation on the heap
- Batch object initialization
- Group deallocation patterns
- Constructor parameter passing
- Memory efficiency considerations

**Exercise 02: Memory Address Comparison**
- Pointer declaration and dereferencing
- Reference creation and usage
- Memory address inspection
- Aliasing demonstration
- Performance implications of references vs pointers

**Exercise 03: Weapon Reference Management**
- Reference member initialization
- Pointer member flexibility
- Object dependency modeling
- Reference binding rules
- Initialization list requirements

**Exercise 04: File Stream Processing**
- File input/output operations
- String search and replace algorithms
- Buffer management
- Error handling for file operations
- Stream state verification

**Exercise 05: Function Pointer Arrays**
- Member function pointers
- Method dispatch tables
- String-to-function mapping
- Encapsulation of behavior selection
- Alternative to switch statements

**Exercise 06: Logging Level Filtering**
- Switch statement with fallthrough
- Hierarchical message filtering
- Enumeration alternatives
- Control flow optimization
- Message severity management

### Module 02: Operator Overloading and Orthodox Canonical Form

Implementation of custom numeric types with proper operator semantics.

**Exercise 00: Fixed-Point Number Class**
- Orthodox Canonical Form implementation
- Default constructor design
- Copy constructor implementation
- Assignment operator overloading
- Destructor management
- Fixed-point arithmetic representation

**Exercise 01: Type Conversion Operators**
- Constructor overloading for int and float
- Conversion operator implementation
- Bitwise shift operations for fixed-point
- Stream insertion operator overload
- Const method qualification

**Exercise 02: Arithmetic and Comparison Operators**
- Binary operator overloading (+, -, *, /)
- Comparison operator suite (<, >, <=, >=, ==, !=)
- Increment and decrement operators (prefix/postfix)
- Static utility functions (min, max)
- Const overload variants

**Exercise 03: Binary Space Partitioning**
- Geometric algorithm implementation
- Point class with const members
- Triangle containment testing
- Cross product calculations
- Coordinate system mathematics

### Module 03: Inheritance Hierarchies

Construction of class hierarchies demonstrating inheritance relationships.

**Exercise 00: ClapTrap Base Class**
- Protected member access
- Public interface design
- State management
- Action validation logic
- Resource tracking (hit points, energy)

**Exercise 01: ScavTrap Derived Class**
- Single inheritance implementation
- Constructor chaining
- Member initialization order
- Virtual function introduction
- Specialized behavior addition

**Exercise 02: FragTrap Derived Class**
- Parallel inheritance branch
- Constructor parameter forwarding
- Attribute customization
- Behavior specialization
- Sibling class relationships

**Exercise 03: DiamondTrap Multiple Inheritance**
- Virtual inheritance to resolve diamond problem
- Constructor initialization ambiguity
- Name hiding and scope resolution
- Virtual base class usage
- Complex inheritance diagram navigation

### Module 04: Polymorphism and Abstract Classes

Runtime polymorphism through virtual functions and abstract base classes.

**Exercise 00: Animal Hierarchy**
- Virtual function declaration
- Dynamic dispatch mechanism
- Virtual destructor necessity
- Polymorphic behavior demonstration
- Wrong implementation comparison

**Exercise 01: Deep Copy with Brain**
- Composition vs inheritance
- Deep copy implementation
- Copy constructor for composed objects
- Assignment operator with dynamic members
- Memory ownership transfer

**Exercise 02: Abstract Animal Class**
- Pure virtual function declaration
- Abstract class instantiation prevention
- Interface enforcement
- Concrete implementation requirements
- Virtual method tables

**Exercise 03: Materia System**
- Interface design patterns
- Abstract factory implementation
- Object cloning mechanism
- Inventory management
- Multiple interface implementation

### Module 05: Exception Handling

Structured error handling using C++ exception mechanisms.

**Exercise 00: Bureaucrat Class**
- Exception class definition
- Throwing exceptions on invalid state
- Try-catch block usage
- Exception inheritance from std::exception
- Grade boundary validation

**Exercise 01: Form Class with Signing**
- Multiple exception types
- Exception specification
- Precondition checking
- State transition validation
- Error message customization

**Exercise 02: Concrete Form Types**
- Abstract form base class
- Polymorphic form execution
- File system operations in ShrubberyCreationForm
- Randomized behavior in RobotomyRequestForm
- Presidential pardon simulation
- Exception handling in derived classes

**Exercise 03: Intern Factory**
- Factory method pattern
- String-based object creation
- Exception on unknown form types
- Encapsulation of instantiation logic
- Dynamic type selection

### Module 06: Type Casting Operators

Explicit and implicit type conversions using C++ cast operators.

**Exercise 00: Scalar Converter**
- Type detection from string literals
- static_cast for numeric conversions
- Special value handling (nan, inf, -inf)
- Precision and range checking
- Impossible conversion identification

**Exercise 01: Serialization with reinterpret_cast**
- Pointer to integer conversion
- Type reinterpretation
- Serialization and deserialization
- Low-level memory manipulation
- Platform-dependent behavior awareness

**Exercise 02: Dynamic Type Identification**
- dynamic_cast for safe downcasting
- Run-Time Type Information (RTTI)
- Null pointer checking after cast
- Reference casting with exceptions
- Type identification through both pointer and reference

### Module 07: Template Programming

Generic programming using function and class templates.

**Exercise 00: Function Templates**
- Template function declaration
- Type parameter deduction
- Generic swap, min, and max functions
- Template instantiation
- Type-independent algorithms

**Exercise 01: Template Iteration**
- Function template accepting function pointers
- Generic array traversal
- Template parameter inference
- Iterator-like functionality
- Callback mechanism implementation

**Exercise 02: Array Template Class**
- Class template design
- Dynamic array encapsulation
- Bounds checking with exceptions
- Template member functions
- Copy semantics for generic types

### Module 08: STL Containers and Iterators

Standard Template Library usage and custom container extension.

**Exercise 00: Algorithm on Containers**
- Template function using iterators
- STL algorithm pattern matching
- Exception throwing for not found
- Generic container compatibility
- Iterator traversal patterns

**Exercise 01: Span Container**
- Integer container with constraints
- Range-based insertion
- Statistical calculations (min/max span)
- Iterator range constructors
- Capacity management

**Exercise 02: MutantStack Extension**
- STL container inheritance
- Iterator implementation
- Stack with traversal capability
- Adapter pattern application
- Iterator category compliance

### Module 09: Advanced STL Applications

Complex data structure manipulation and algorithm implementation.

**Exercise 00: Bitcoin Exchange Database**
- std::map for key-value storage
- Date parsing and validation
- File parsing with error handling
- Range queries on ordered data
- Input validation and sanitization

**Exercise 01: Reverse Polish Notation Calculator**
- std::stack for operand management
- Expression evaluation algorithm
- Operator precedence in RPN
- Error detection in malformed expressions
- Arithmetic operation dispatch

**Exercise 02: Ford-Johnson Merge-Insert Sort**
- std::vector and std::deque comparison
- Hybrid sorting algorithm implementation
- Performance benchmarking
- Container operation efficiency analysis
- Large dataset handling

## Compilation and Execution

Each exercise directory contains a Makefile with standard targets:

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

Example workflow:

```bash
cd cpp00/ex00
make
./megaphone "Hello World"
```

## Learning Objectives

This curriculum progressively develops proficiency in:

1. **Object-Oriented Design**: Encapsulation, inheritance, and polymorphism
2. **Memory Management**: RAII principle, smart ownership, leak prevention
3. **Type Systems**: Static and dynamic typing, type safety, casting
4. **Generic Programming**: Templates, type parameters, code reuse
5. **Standard Library**: Containers, algorithms, iterators
6. **Exception Safety**: Error handling, resource cleanup, exception guarantees
7. **Performance Considerations**: Time/space complexity, cache efficiency

## Development Environment

Recommended tools for development and testing:

- **Compiler**: GCC 4.8+ or Clang 3.4+
- **Debugger**: GDB or LLDB
- **Memory Analysis**: Valgrind for leak detection
- **Build System**: GNU Make
- **Version Control**: Git

## Best Practices Demonstrated

- Orthodox Canonical Form for resource-managing classes
- RAII (Resource Acquisition Is Initialization) principle
- Const-correctness throughout the codebase
- Exception safety guarantees
- Clear separation of interface and implementation
- Defensive programming with validation
- Meaningful variable and function naming
- Comprehensive error handling

## Additional Notes

The exercises deliberately use C++98 standard to ensure understanding of fundamental concepts without modern language conveniences like auto, range-based for loops, smart pointers, or move semantics. This foundation proves essential for understanding the evolution and rationale behind modern C++ features.

All implementations prioritize correctness, clarity, and educational value over optimization. Code follows consistent style guidelines and includes appropriate error handling for robustness.

## Testing Recommendations

For thorough testing of implementations:

1. **Compilation**: Verify clean compilation with strict warning flags
2. **Memory**: Run valgrind to ensure no leaks or invalid accesses
3. **Edge Cases**: Test boundary conditions and invalid inputs
4. **Undefined Behavior**: Check for uninitialized variables and dangling pointers
5. **Const Correctness**: Verify proper const qualifications

Example memory check:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./executable
```

## Acknowledgments

Developed as part of the 42 Network curriculum, emphasizing peer-to-peer learning and practical software engineering skills. The exercises are designed to build both theoretical understanding and hands-on implementation experience with C++ programming.
