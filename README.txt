*** Definition ***
Code for finding maximum number of colors for N2_vertex_coloring of K_regular graphs.
In all programs, "K" sets in program body. "N" is the number of vertices.

*** Inputs ***
We obtained our inputs from http://www.mathe2.uni-bayreuth.de/markus/reggraphs.html .
After changing their format to Adjacency List, We stored all K-regular graphs in "Kregular.txt" file.

*** Programs ***
N2_Coloring_Console:    
- Reads input from console
- Input: N, List of adjacent vertices to i-th vertex ( K = 3, you can change it in body of program! ) 
- Output: colors assigned to vertices in N2-vertex coloring of graph with maximum possible number of colors.

N2_Coloring_File:       
- Reads input from "Kregular.txt" files
- Input: same as above
- Output: In "Kregular_output.txt" files

Convert2MinMax:		
- Reading "Kregular_output.txt" file and telling Min and Max possible number of colors in N2_vertex_coloring for K-regular graphs find for specific N.
- Input: "Kregular_output.txt" files
- Output: Min and Max of number of colors in N2-vertex_coloring for those K-regular graphs
