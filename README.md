This repo contains tested solutions to riddles.

# Stuff to remember
- Start with a brute force solution and optimize.

- Reducing the problem size in recursion can be done in more than one way. ("recursive permutations")

- Try and describe the recurrence relation in words to make sure it is logically sound.

- Consider solving bottom up (dynamic programming). Compute the answer for the basic case, store it and use the stored
answer to calculate the answer for a more complex case ("cake thief", "smallest multiple")

- Consider solving in stages - first solve a simplified problem, then use the solution for the simplified problem to
solve the original.

- A ^ A = 0 ("breakfast drone")

- When restricted to O(1) space and need to find a number in an array without 
modifying it the trivial solution is O(n^2), the clever one is O(nlog(n)) by
 doing binary search on the range and counting numbers within it that
 satisfy something ("find repeat" (pigeonhole), "ksmallest")

- Consider BFS to find shortest route when all edge weights are equal. ("mesh message")

- Consider fast/slow runner for lists ("find repeat beast")

- Consider versioning instead of actually manipulating data("RWC")