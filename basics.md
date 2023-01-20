# Wonderwall
The toil of writing efficient code is the job of compilers, not programmers
<br>
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
store instruction: assigning a value to a variable, and is able to change the defined variable
```
store num1:u8 2007
store num2 2008 # compiler can get type automatically
store num3 num1 + num2
```
remain instruction: assigningg a alue to a constant, defined in runtime
```
remain COOL_NUMS [8, 12, 7, 14]
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
1. let's make a print-line instruction
```
define println msg
    print msg + "\n"
```
and we use this instrucion
`println "Hello, World!"`
Output:
`Hello, World!`

2. lets make a component of calculating height
```
use std;
define to_inches(cm:u16)
    store inches:u16 cm/2.54
    store ft inches / 12
    return to_string(ft) + "ft " + to_string(inches - temp * 12) + "inches"
define cal_height(cm:string)
    return to_inches(to_u16(cm))

# Main scope
store inp:string std::io::input()
cal_height(inp)
```
Notice that in this case, the compiler would only read & execute through `store inp...`
<br>
*Wonderwall* does not execute through any function unless it is **stored in a variable** or **passed to an instruction**
<br>
All the functions are pure and has no side-effect, thus they are not doing anything at all unless the data they returned are used.
<br>
Of course dead functions are eliminated in optimization through dead code elimination, yet this trait helps compiler to solve this problem in semantic analysis.
```
# so in this case bot cal_height() and to_inches() would be executed
println(cal_height(inp))
# OR
store my_height:u16 cal_height(inp)
```

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
