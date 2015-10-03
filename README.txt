*** Definition ***
Code for finding N2_vertex_coloring of K_regular graphs.
In all programs, "K" sets in program body. "N" is number of vertices.

*** Inputs ***
We obtain our inputs from http://www.mathe2.uni-bayreuth.de/markus/reggraphs.html .
After changing their format to Adjacency List, We store all K-regular graphs in "Kregular.txt" file.

*** Programs ***
N2_Coloring_Console:    
- Read input from console
- Input: N, List of adjacent vertices to i-th vertex ( K = 3, you can change it in program body! ) 
- Output: N2_vertex_coloring for graph, and colors of its vertices.

N2_Coloring_File:       
- Read input from "Kregular.txt" files
- Input: like above
- Output: In "Kregular_output.txt" files

Convert2MinMax:		
- Reading "Kregular_output.txt" file and telling Min and Max N2_vertex_coloring for K-regular graphs find for specific N.
- Input: "Kregular_output.txt" files
- Output: Min and Max N2_coloring number for those K-regular graphs
