# Esperanto-Programo-Tradukilaro (ept)
Esperanto program translate tool set. Translate a program written in Esperanto
to a usable one in English! Languages currently planned are C and C++.
This project is planned for GNU/Linux, BSD, Windows, and OS X.
The goal of this project is to enable the programmer to write their programs
in Esperanto, and have those programs be more than text files. I'm looking
for (positive or negative) feedback on this whole project so don't be afraid!
My email is olivia.may@tuta.io. <br>
Pull requests and making issues are welcome!

## File Names
".ceo" C source file <br>
".heo" C header file <br>

".cppeo" ".c++eo" ".cxxeo" ".cceo" C++ source file. <br>
".hppeo" ".h++eo" ".hxxeo" ".hheo" ".heo" C++ header file <br>

## C-Esperanto-Programo-Tradukilo (cept)
Translate C code written in Esperanto to compilable C code. <br>
Usage: <br>
`cept programo.ceo` <br>

## C++-Esperanto-Programo-Tradukilo (cept++)
Translate C++ code written in Esperanto to compilable C++ code. <br>
Usage: <br>
`cept++ programo.cppeo` <br>

## Build from Source
### Dependencies
You will need Meson.

### Compile
`meson setup build` <br>
`cd build` <br>
`ninja` <br>
`./src/cept` <br>
