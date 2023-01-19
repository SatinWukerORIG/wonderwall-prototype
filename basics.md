# Wonderwall
The toil of writing efficient code is the job of compilers, not programmers
Lasiness is always better than trying hard
Lazy and smart, that is what a compiler should be like


# HELLO, WORLD!
```
store msg "Hello, world!"
print msg
```

# DATA STRUCTURES
### Scalar:
**char**: 'a'

**string**: "this is a string"

**bool**: true, false

**u8, u16, u32, u64, u128**
<br>
**i8, i16, i32, i64, i128**
<br>
**f32 f64**

**uindex, iindex**
* used for indexes in arrays, vectors, etc.
* represents indefinite size

### Compound:
**tuple**: (0, 'a', "abc")
* fixed size & elements, can have multiple types of element

**array**: [0, 5, 10]
* size and elements are known in compile time

**list**: [0, 'a', "abc"]
* dynamic array, can be resized and elements can be added
* size are known in run time
* can have elements in different types

**set**: {'a', 'b', 'c', 1, 2, 3}
* collection of unduplicated objects
* dynamic, elements can be added & removed in run time
* unordered, (value of element) unchangeable, and unindexed.

### Examples
```
store num1:u8 10
store num2 12 # compiler can get type automatically
store num3 num1 + num2
```

# LOGICAL STATEMENTS
## Conditional Statements
### if statement
```
if [condition]
    [stmts]
elif [condition]
    [stmts]
else
    [stmts]
```
ps. a condition returns a boolean value
1. if a == b # instructional expression
2. if (a == b) # functional expression
the two statements are semantically equivalent

## Loops
### while statement
```
while [condition]
    [stmts]
```

### for statement
```
for [element] [iterator]
    [stmts]
```

1. for i 0..10 # instructional
2. for(i, 0..10) # functional

### dead loop
`while true`

### in-loop instructions
`break`
interrupt & stop the loop

`continue`
stop the current iteration & start the next iteration

# INSTRUCTIONS & FUNCTIONS
A **function** takes in inputs and returns one or more output. Functions in *wonderwall* are pure functions, meaning that they do not have side effect and global state modification.

An **instruction** takes in inputs but does not have an output.

Without passing to an instruction, an expression of a function would not be evaluated!

## Defining
let's make a print-line instruction
```
define println msg
    print msg + "\n"
```
and we use this instrucion
`println "Hello, World!"`
Output:
`Hello, World!`

## Details & Theories
*Wonderwall* prohibits making side-effects in instructions and functions, unlike the object-oriented languages. The instructions do not change the input values or any other variables throughout the program in order to produce less-bug codes and an efficient debugging process.

# SPACE
creates modules, libraries, for grouping instructions
<br>
`std`, wonderwall standard library, is an example of a space.
syntax: `space [space name]`
let's create a space for my own standard library
```
space MyStd
    # let's define an instruction
    define myprint msg
        print "myprint: " + msg
    
# this is the main scope
use MyStd
MyStd::myprint "hi mom!"
```

# ALGORITHMS
## Bubble Sort
```
use std
store arr:array [10, 5, 4, 7, 9]

define bubble_sort arr:array
    store arr_len std::len(arr)
    for(i, arr_len)
        for(j, arr_len - i)
            std.switch(arr[j], arr[j - 1])
    return arr
```
