# acyclic-paths-brute-force-enumeration
A module that does nothing but count acyclic paths on a grid (./paths &lt;length>)
The module counts the number of ways you may move on a grid without revisiting a spot you've been before.

# compiling
> $ gcc -o acyclic acyclic.c
# running
```
 $ acyclic <maximum path length>
```
# warning
This module will lock your computer by using all available memory if you choose a path length that is too high. 16 is a good starting value if you want to see how far your computer can go in increments.
