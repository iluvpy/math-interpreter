# math-interpreter
a fun little math project for interpretation and compilation of math expression, its pretty buggy 

# dependencies
- ninja
- a C compiler (clang in my case but any would do)

## compilation
install the used compiler see dependencies
and then just run `ninja` in the main dir
you can also change the $cc variable in the build file
to a compiler you like (needs to support C11)


## Usage
type in `./mathc` in the console after compiling 

then something looking like a console should pop up
where you can start typing your math expressions and commands

## Commands
- cls - to clear the console
- h - to open up the help menu
- q - to quit

## Syntax
- operators
you can use `+ - * / ^`



## TODO
fix the memory leaks created by the recursive calling of the interpreter

need to "attach" the minus operator to the number in the lexing step,
example:
`432 - 53 - 3 - 53 * 2 - 2 * 7 - 2 = 254`
but the interpreter thinks its 175. Why? Because - (52 * 2) - (2 * 7) is interpreted as 104 - 14 instead of -104 - 14 because the minus is interpreted as a unique token and not as part of the number.
So, to solve that i need to make the minus become a OP:* INT:-1 OP:* so that 104 would multiply by -1 to become -104, or timply just make the 
number directly -104 and add OP:+ before it instead of OP:- in the lexing step 
