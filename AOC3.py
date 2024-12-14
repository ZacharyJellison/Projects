#! /usr/bin/env python3

# Advent of Code 2024 Day _

dirs1 = [(-1,1),(1,1),(1,-1),(-1,-1)]
dirs2 = [(-1,0),(0,1),(1,0),(0,-1)]
# neighbor directions ordered to go clockwise start from right in a
# list-of-lists grid (i.e. (0,0) is top left corner)
adj8 = [(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1),(-1,0),(-1,1)]

import sys, string, math, time, re, itertools, numpy as np
sys.setrecursionlimit(10**6)

infile = sys.argv[1] if len(sys.argv)>=2 else '.in'
p1 = 0
p2 = 0

S = open(infile).read().strip()
#grid conditions
G = S.split('\n')
R,C = len(G),len(G[0])

for line in S.split('\n'):
    pass

print('p1 is ', p1)
print('p2 is ', p2)