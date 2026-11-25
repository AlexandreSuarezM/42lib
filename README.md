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




// main sends argv to static void	algo_decision() to redirect to the uncions 
// now add 
// 1 a delete whole 
// a convert and absorve and check 



# explicatin of the code 

User is expected to send flags that determine an algoritms
{--simple, --complex, --medium, --adaptive}
If flag is not provided --adaptive is used
check algoritms for details on the flags :

Becnh option provides a result on the operations and data

The goal is to provide numbers that fit in the integer category
And sort them
Initial atemt took strings of numbers to proces
But subject asks to get rid of overflows
So atoi is used given the numbers

Numbers are provided in list or argumets 

to give freedom to the user

We seek if flags are correct and we dont have to many of them

then we loop argumens parsed skyping flags and calling ft_split on each argument

This gives us a way to recieve lsits and arguments as numbers

Arguments are put on a temporal matrix were each argument gets artoi
send to a node thats created and added to the alist

Atoi is modified to deal with overflows and non numbers

Each exist frees everything.

After te algoritm is done we free.

The linked list is made as a double linked looped list 
This allows for conveniece of accesing the first element of the stack and the last

Operations are clsutered in 4 kinds and called with difefent arguments.
And a print option.

if no arguments the prompt has to be resended this mean exit with nothing 

Algoritms

Select
- looks for minimal element
- looks wich way is faster
- sends to b 
- start over

when done 
- push all b stack to a and it will be sorted

Chunking

Radix.
One element of the list is a intger that compacts all the numbers respecting the order in the [0, total elements] range
This makes the max number of bits lowers
reducing the iterates of radix sort
Radix sort takes the least significative value bite and send it to b stack if its 1 
Then emptyes b stack and repeats

Adaptive
Send to diferent algoritms based on the disorder level*
The disorder is an heuristic that counts the number of mismached pairs
That is take an element compare how many elements are afer that element mistplaced
Each misplaced is 1 mistake a non misplace 1 oportunity 
Do that for each element add it 
And we get a 0 <= disorder <= 1 metric
Consideration on 0 division and precautions are taken account.

For printing the operations operations use the print flag .

///////////////



-- check the errros and the frees

-- check gnl  checkers

-- check bench marlk

-- check teh prints  

THE header 
And the makefile 
ractice complexity

