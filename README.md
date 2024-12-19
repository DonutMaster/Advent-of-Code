# My Advent of Code Solutions!
## 2024:
### Day 18:
**Part 1:**
Just a simple BFS with a Seen array/map to see if you have gone to that location before.

**Part 2:**
Just do a BFS for each new location. My code does take around 10 seconds or more to finish, but it doesn't take too long.
### Day 19:
**Part 1:**
Simple Brute Force. You can use a queue and a seen array for each position of each string/design and see if there is a way to create that design.

**Part 2:**
Pretty simple DP. Instead of using a queue, just use a vector and go through all the positions from left to right of each design and, in the end, see how many different ways there are to create the design.
