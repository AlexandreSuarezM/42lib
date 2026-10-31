*This project has been created as part of the 42 curriculum by asuarez, <>


// only root repo
// listas enlazadas 1 no me prreocupo de posiciones ni dimensions
// no me muevo tan comodo.
// 

# Description
Given a stack of *Z* with no dupes and an empty stack we want to sort them.
To sort them we will use :
. Simple algorithm (O(n2 )):
Implement at least one baseline algorithm in the O(n2 ) class. Examples include:
• Insertion sort adaptation
• Selection sort adaptation
• Bubble sort adaptation
• Simple min/max extraction methods
√
2. Medium algorithm (O(n n)):
√
Implement at least one algorithm in the O(n n) class. Examples include:
√
• Chunk-based sorting (divide into n chunks)
• Block-based partitioning methods
√
• Bucket sort adaptations with n buckets
• Range-based sorting strategies
3. Complex algorithm (O(n log n)):
Implement at least one algorithm in the O(n log n) class. Examples include:
• Radix sort adaptation (LSD or MSD)
• Merge sort adaptation using two stacks
• Quick sort adaptation with stack partitioning
• Heap sort adaptation
• Binary indexed tree approaches
4. Custom adaptive algorithm (learner’s design): Design an adaptive strategy
that selects different internal methods depending on the measured disorder. You
are not constrained to any specific named algorithm; the internal techniques are
entirely up to you. However, your design must respect the following complexity
targets per regime (in the Push_swap operation model):
Low disorder: if disorder < 0.2, your chosen method must run in O(n2) time.
Medium√disorder: if 0.2 ≤ disorder < 0.5, your chosen method must run in
O(n n) time.
High disorder: if disorder ≥ 0.5, your chosen method must run in O(n log n)
time.
You must document in your repository (e.g., README.md) the rationale for your
thresholds, the internal techniques used in each regime, and a brief complexity
argument (upper bounds) for time and space within the Push_swap model

for testig amke a main that rsorts 

Allowed operations : 
sa (swap a): Swap the first two elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first two elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
9Push_swap
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by one.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by one.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by one.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by one.
The last element becomes the first one.
rrr : rra and rrb at the same time

Probide a 0 - 1 

Tasks : 
Make the main (srand + show)
Make the operations 
Split the algotitms 
Make the benchamrk
Do the makefile



# Instructions

# Resources 
https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
IA:
summarize wiki content.

# Usage / examples / feature / tchoices

# Miscellania

