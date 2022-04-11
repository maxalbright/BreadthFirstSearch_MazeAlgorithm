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
<img width="230" alt="mazeinput" src="https://user-images.githubusercontent.com/70349082/162794999-2169ac42-ecf7-4701-acb5-4bbc7f9e436b.png">



The program will output this maze with "*" instead of "." where the shortest path was found (if applicable); If there is no legal path from start to finish, the program will output "No path could be found!". <br>
For the above example, the output to the standard input stream is: <br>
<img width="169" alt="mazeoutput" src="https://user-images.githubusercontent.com/70349082/162795011-29b505a3-bfc8-4759-9db6-72405be0b371.png">


### To run the program:
- Compile with "make maze" and run with "./maze " and the file name of the maze. 
- maze1.in and maze2.in are included as example mazes, and maze3.in and maze4.in are included as examples of mazes that are not formatted properly. 
