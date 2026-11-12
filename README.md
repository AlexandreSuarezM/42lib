// the struct is a double linked list to acces fast the queue element
== and miinimize the big loops
//compresed indexation becauses cba
// atoi is kanker so i parse the char and use string compare.
//nodes are freed no malloc is needed .
// argc is the index max
// need to chckk for edge cases 

Objective
Use sorting algortims on a pseudostack with operations ow swaping swinch and rotate
Numbers are not restricted to ints, cant be reppeated, and failed inputs are modestly handled. 
Report the benchmark 
And make a checker


Instruction:
Main at the bottom 
Tests for null voids .
Checkers.
Run make on the make file 
Get the .a 
Compialtion:
Each one handles a diferent complexity algoritm
** make main

./exe --simple


checkers benchmakr




To handle the sorting problem 
We chose a set upt with bidirectional links that loops.
This way we only need to take care to never lose the top of the stack
We did the basic operations
Took the numbers not as ints but has a char
With  that char we made a comparation of wich representation is bigger
By looping this relation of order we made a coordinated compresion
Getting a N U {0} list 
That way we can identify not only the numbers by size but also by 
relative size 
And locate maximums faster gaining extra information while exploring the pile
The first algortim is simple search the fastest way to the max 
If not achieven in the first half send to the next 
Then repeat so b has all the pushes inverted
In the end revert the whole b stack 
The algoritm of radix
has an interesting concept
Use the bit representation of numbers to sort them bit by bit by filtering the order.
Each step moves to stack a te bigger number 
and revertes them 
That way if a number is small it doesnt get moved around and if its big it does 
The more you move the more you stay on top 
Simple efective and with a nlog(n) convergence.

Resources:
IA explication of the sorting algortims 
Debugging
Using for optimal learning and sharting with peers



Concerns 

Moulinete i dont know the moulinete test 
so i dont know if it will look for intefers int the struct 
if it does it will ko and need to swap it for atoi  and the comparation becoms int comp 

If it does not ok 


 my push swap structs handle chars instead of numbers 
it clears the number like atoi 
but keepts the char numerical representation 
allowing bigger numbers tha ints to be sorted 
and moving them efitiently via coordinated compresion 
but i dont know if moulinette will lookk for integers and ko 



feedback propuesto

incosistencies in the subjects numbers ->> ints 
either redundanci elimination or congruene between orders   A - B 



Biddirectional looped list
to acces easily bottom 
insetead of storing it and doint the whole llop to find it

