# math-interpreter
a math interpreter written in C

# dependencies
- ninja
- a C compiler (clang in my case but any would do)

## compilation
install the used compiler see dependencies
and then just run `ninja` in the main dir
you can also change the $cc variable in the build file
to a compiler you like (needs to support C11)


# State 
in development; none of the current syntax is working <br>
![Markdown Logo](https://img.shields.io/badge/state-development-red) <br>
![Markdown Logo](https://img.shields.io/badge/build-unstable-red) <br>
![Markdown Logo](https://tokei.rs/b1/github/iluvpy/mathc) <br>

## Usage
type in `./mathc` in the console after compiling 

then something looking like a console should pop up
where you can start typing your math expressions and commands

## Commands
- cls - to clear the console
- h - to open up the help menu
- q - to quit

## Syntax
- brackets
you can use `() [] {}`

- operators
you can use `+ - * / ^`

- functions
for now you can use `log(base=10, n) pow(x, y) mod(x, y)`

