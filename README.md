This repo contains tested solutions to riddles.

# Stuff to remember
- Before trying to solve recursively, make sure that the problem can actually be divided to smaller sub-problems.
As an example, look at the "cake thief" problem (unbounded knapsack).

- Consider solving bottom up (dynamic programming). Store the answer for the basic case, store it and use the stored
answer to calculate the answer for a more complex case ("cake thief")

- Consider solving in stages - first solve a simplified problem, then use the solution for the simplified problem to
solve the original.

- A ^ A = 0 ("breakfast drone")

- Consider binary search and pigeonhole principle ("find repeat")

- Consider BFS to find shortest route when all edge weights are equal. ("mesh message")

- Consider fast/slow runner for lists ("find repeat beast")