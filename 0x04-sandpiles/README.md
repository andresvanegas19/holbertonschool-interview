Sandpiles - Numberphile

Write a function that computes the sum of two sandpiles

Prototype: void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
You can assume that both grid1 and grid2 are individually stable
A sandpile is considered stable when none of its cells contains more than 3 grains
When your function is done, grid1 must be stable
grid1 must be printed before each toppling round, only if it is unstable (See example)
You’re not allowed to allocate memory dynamically

# logic
Add up the raw matrices

While there is a number still above 3 loop:
Pad the entire matrix with 0s around it
Calculate Floor[values/4], this is done using quotient, and gives a matrix of the number that can be toppled, and how many times it can be toppled.
Subtract 4 times this matrix.
Add shifted version of this matrix to redistribute the sand to the neighbours (using RotateLeft).
Remove the padding again using Arraypad[..., -1]

The Abelian sandpile model, also known as the Bak–Tang–Wiesenfeld model, was the first discovered example of a dynamical system displaying self-organized criticality. It was introduced by Per Bak, Chao Tang and Kurt Wiesenfeld in a 1987 paper.[1]

The model is a cellular automaton. In its original formulation, each site on a finite grid has an associated value that corresponds to the slope of the pile. This slope builds up as "grains of sand" (or "chips") are randomly placed onto the pile, until the slope exceeds a specific threshold value at which time that site collapses transferring sand into the adjacent sites, increasing their slope. Bak, Tang, and Wiesenfeld considered process of successive random placement of sand grains on the grid; each such placement of sand at a particular site may have no effect, or it may cause a cascading reaction that will affect many sites.

The model has since been studied on the infinite lattice, on other (non-square) lattices, and on arbitrary graphs (including directed multigraphs).[2] It is closely related to the dollar game, a variant of the chip-firing game introduced by Biggs

Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 14.04 LTS
Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
All your files should end with a new line
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
The prototypes of all your functions should be included in your header file called sandpiles.h
Don’t forget to push your header file
All your header files should be include guarded
