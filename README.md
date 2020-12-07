Given an input file with an ASCII maze, this program uses a breadth-first-search algorithm and a queue class to find the shortest path from start to finish. 

The format of the input files is as follows:
The number of rows and the number of columns on the first line seperated by whitespace;
S = start cell;
F = finish cell;
. = cell where a path can go;
#= wall/cell where a route cannot go;
The input file mazes must be rectangular;

An example is:
10 12
...###.#.... 
##.#...####.
...#.#.#....
#.####.####.
#F..#..#.##.
###.#....#S.
#.#.####.##.
....#.#...#.
.####.#.#.#.
........#...


The program will output this maze with "*" instead of "." where the shortest path was found (if applicable);
For the above example, the output to the standard input stream is:
10 12
...###.#....
##.#...####.
...#.#.#....
#.####.####.
#F**#..#.##.
###*#....#S*
#.#*####.##*
****#.#***#*
*####.#*#*#*
********#***

