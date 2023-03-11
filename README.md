### C-a Esperanta Tradukisto
'cet' is the name of the translator,
a command line program that takes a file as input, translates it, then prints it to the standard output.

### '.ce' and 'ke' files
Source '.ce' (C-o Esperanta) and header '.ke' (Kapo Esperanta) files.
A sort of new programming language, using Esperanto words. Depends on 'cet'.

### This Project
The goal of this project is to enable the programmer to write their programs in an Esperanto-like version of C.
I'm planning to add support for more languages, like C++, and Spanish.
I'm looking for (positive or negative) feedback on this whole project so don't be afraid! My email is olmay@tuta.io.
Pull requests and making issues are welcome!

### Install
Git clone this repository:
`git clone https://github.com/olivia-livs/cet`

Change to the project's directory
`cd cet`

With root access type:
`make install`

Might work for other platforms, will work on GNU/Linux.

### Fun Stuff
First:
`git clone https://github.com/olivia-livs/cet`

#### To translate and run a hello world program:
`make saluton_mondo`

#### To show that the translator won't crash horribly:
`make`
Then:
`./cet testo.txt`

#### Compile and run program:
`make run`
