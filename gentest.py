#!/usr/bin/env python3

from sys import argv
import random

if len(argv) == 2:
    count = int(argv[1])
elif len(argv) == 3:
    count = random.randint(int(argv[1]), int(argv[2]))
else:
    count = 6

figures = [
    "#...\n"+
    "#...\n"+
    "#...\n"+
    "#...",

    "####\n"+
    "....\n"+
    "....\n"+
    "....",

    "##..\n"+
    "##..\n"+
    "....\n"+
    "....",

    "##..\n"+
    ".#..\n"+
    ".#..\n"+
    "....",
    "..#.\n"+
    "###.\n"+
    "....\n"+
    "....",
    ".#..\n"+
    ".#..\n"+
    ".##.\n"+
    "....",
    "....\n"+
    "###.\n"+
    "#...\n"+
    "....",

    ".##.\n"+
    ".#..\n"+
    ".#..\n"+
    "....",
    "....\n"+
    "###.\n"+
    "..#.\n"+
    "....",
    ".#..\n"+
    ".#..\n"+
    "##..\n"+
    "....",
    "#...\n"+
    "###.\n"+
    "....\n"+
    "....",

    ".#..\n"+
    "###.\n"+
    "....\n"+
    "....",
    "#...\n"+
    "##..\n"+
    "#...\n"+
    "....",
    "###.\n"+
    ".#..\n"+
    "....\n"+
    "....",
    ".#..\n"+
    "##..\n"+
    ".#..\n"+
    "....",

    ".#..\n"+
    "##..\n"+
    "#...\n"+
    "....",
    "##..\n"+
    ".##.\n"+
    "....\n"+
    "....",

    "#...\n"+
    "##..\n"+
    ".#..\n"+
    "...."
]

for i in range(count):
    print(random.choice(figures))
    if i != count - 1:
        print("")