# BFS Maze Algorithm


### Description:
Given an input file with an ASCII maze, this program uses a breadth-first-search algorithm and a queue class to find the shortest path from start to finish. <br><br>


### Input:
The format of the input files is as follows:
The number of rows and the number of columns on the first line seperated by whitespace;
S = start cell;
F = finish cell;
. = cell where a path can go;
#= wall/cell where a route cannot go;
The input file mazes must be rectangular;

An example is: <br>
10 12 <br>
...###.#.... <br>
##.#...####. <br>
...#.#.#.... <br>
#.####.####. <br>
#F..#..#.##. <br>
###.#....#S. <br>
#.#.####.##. <br>
....#.#...#. <br>
.####.#.#.#. <br>
........#... <br>


The program will output this maze with "*" instead of "." where the shortest path was found (if applicable);
For the above example, the output to the standard input stream is: <br>
10 12 <br>
...###.#.... <br>
##.#...####. <br>
...#.#.#.... <br>
#.####.####. <br>
#F**#..#.##. <br>
###*#....#S* <br>
#.#*####.##* <br>
****#.#***#* <br>
*####.#*#*#* <br>
********#*** <br>


### To run the program:
- Compile with "make maze" and run with "./maze " and the file name of the maze. 
- maze1.in and maze2.in are included as example mazes, and maze3.in and maze4.in are included as examples of mazes that are not formatted properly. 
