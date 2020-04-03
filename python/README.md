This repo contains tested solutions to riddles.

# Stuff to remember
- Memorize the simple math algos: sqrt(square_root), 
modular exponentiation (power_func), primality test (largest_prime_factor)...

- Be able to perfectly implement basic operations on data structures 
in less than 10mins: merge, reverse, add, delete, binary search...

- Start with deeply understanding the problem:
1. Read it twice.
2. Understand the example, why the input produces the output.
3. Clear your head from fixations. If already seen a similar problem,try and 
understand the differences (e.g different data structure, assumptions about 
the input, etc...) They might make the solution completely different.
4. Write test cases for 2 simple instances, a trivial instance (empty list for example)
and two complex instances. Understanding complex instances is key.
5. Starting with the example, try to solve some of the test cases without an algorithm, 
just use intuition.
6. Break down the steps you took solving intuitively.
7. Does the greedy approach work? why not?

- Confront the problem:
1. No solution comes up? try to write a naive solution, without regarding complexity.
2. Consider solving in stages - first solve a simplified problem, then use the solution 
for the simplified problem to solve the original. 

- Enumerate the methods:

- Recursion: Try and describe the recurrence relation in words to make sure it is logically sound.
Reducing the problem size in recursion can be done in more than one correct way. ("recursive permutations")

- Dynamic programming (bottom up): Compute the answer for the basic case, store it and use the stored
answer to calculate the answer for a more complex case ("cake thief", "smallest multiple")

- Divide and Conquer (binary search).

- A xor A = 0 ("breakfast drone")

- When restricted to O(1) space and need to find a number in an array without 
modifying it the trivial solution is O(n^2), the clever one is O(nlog(n)) by
 doing binary search on the range and counting numbers within it that
 satisfy something ("find repeat" (pigeonhole), "ksmallest")

- Consider BFS to find shortest route when all edge weights are equal. ("mesh message")

- Consider fast/slow runner for lists ("find repeat beast")

- Initialize list pointers with dummy values to make the code simpler (and remove
all if x is None)

- Consider unifying problem spaces, a single decorated event list can be easier to handle 
than multiple lists of different types of events ("hotel booking possible)

- Consider versioning instead of actually manipulating data("RWC")
