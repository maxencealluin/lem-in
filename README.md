# lem-in
Algorithmic project part of the cursus at 42 Paris. The goal of the project is to propose a solution to a non-trivial optimization problem.

## Description

Lem-in is an algorithmic project whose is to guide a variable number of ants through a network of 'boxes' in the most efficient way as possible.
The program takes a map as input which is of the following form:
* number of ants
* boxes (one per line)
* links between boxes (one per line)

Boxes syntax : box-name box-x_coordinate box-y_coordinate
Links syntax : box_a-box_b (works both ways)
Start and end box are indicated by a comment on the preceding line (##start or ##end)

### Example map:

3<br/>
1 0 2<br/>
##start<br/>
0 2 0<br/>
##end<br/>
4 2 6<br/>
2 4 2<br/>
3 4 4<br/>
0-1<br/>
0-2<br/>
2-3<br/>
3-4<br/>
4-1

The program will use the map to calculate a solution, the rules are the following:
* The program may send as much ants per turn as there are boxes linked with the starting boxes
* Each ant may move to another box each turn
* There may be only one ant per box at a given time (except end box)

## Implementation

The problem has a high algorithmic complexity and bruteforcing the solution is not feasible on the larger maps (5000+ boxes).
Our implementation is based on Augmenting path algorithm and mainly on Edmonds–Karp algorithm with modifications to fit the particular constraints of the subject. 
The main difference is that these algorithms usually assume you always want to maximize your flow, which is not always the case here as we have a limited supply of ants.
The subject also has a time constraint therefore a special attention has been paid to adopt efficient data structure for reading, writing and solving the problem.
Solving on larger maps (4k boxes) should be done in around 0.5 secs. 

![Alt text](http://g.recordit.co/kGl0bHfCaU.gif "Implementation")



## Installation
To install the terminal-output version, simply type:<br/>
`make`

#### Experimental:
To install the graphic-output version, you should install SDL2 on your computer, provide the appropriate path in the makefile and then type:<br/>
`make visu`

## usage
Main usage:<br/>
`./lem-in < <map_file>`

For visualizer (only small maps):<br/>
`./lem-in < <map_file> | ./visualizer/visu`
