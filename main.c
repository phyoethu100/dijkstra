// Author: Phyoe Thu
// Dijkstra lab
#include<stdio.h>
#include<stdlib.h>

void dijkstra(int matrix[8][8], int vertice, int source_node, int destination_node);
int readmatrix(size_t rows, size_t cols, int (*a)[cols], const char* filename);

int main()
{
    int vertice; // Declare int variables and matrix with maximum of ten elements
    int matrix[8][8];
    int a = 0;
    int b = 0;
    
    char source;
    char destination;

    printf("Enter the number of nodes: "); // Ask the user to enter number of vertices
    scanf("%d", &vertice);
    printf("\n");

    readmatrix(8, 8, matrix, "/Users/phyoethu/Documents/matrix.txt");
    
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
            printf("%-3d ", matrix[i][j]);
        puts("");
    }

    do {
        
        printf("\nEnter the source & destination node between a to h OR");
        printf("\nEnter 'q' for the source node to exit the program!\n");
        
        printf("\nEnter the source node: "); // Ask the user to enter the source node
        scanf("%s", &source);
    
        switch (source) {
            case 'a':
                a = 0;
                break;
            case 'b':
                a = 1;
                break;
            case 'c':
                a = 2;
                break;
            case 'd':
                a = 3;
                break;
            case 'e':
                a = 4;
                break;
            case 'f':
                a = 5;
                break;
            case 'g':
                a = 6;
                break;
            case 'h':
                a = 7;
                break;
            case 'q':
                return -1;
        }
       
        printf("\nEnter the destination node: "); // Ask the user to enter the destination node
        scanf("%s", &destination);
    
        switch (destination) {
            case 'a':
                b = 0;
                break;
            case 'b':
                b = 1;
                break;
            case 'c':
                b = 2;
                break;
            case 'd':
                b = 3;
                break;
            case 'e':
                b = 4;
                break;
            case 'f':
                b = 5;
                break;
            case 'g':
                b = 6;
                break;
            case 'h':
                b = 7;
                break;
        }
        
        printf("\nResults:\n");
        dijkstra(matrix, vertice, a, b); // Call the dijkstra function with four parameters
        printf("\n-----------------------------------------------------\n");
        
    } while ((source != 'q'));
        
    return 0;
}

int readmatrix(size_t rows, size_t cols, int (*a)[cols], const char* filename)
{
    
    FILE *file;
    file = fopen (filename, "r");
    if (file == NULL)
        return 0;
    
    for(int i = 0; i < rows; ++i)
    {
        for(int j = 0; j < cols; ++j)
            fscanf(file, "%d", a[i] + j);
    }
    
    fclose (file);
    return 1;
}

void dijkstra(int matrix[8][8], int vertice, int source_node, int destination_node)
{
    
    int cost[10][10], distance[10], previous_node[10], visited_node[10], count, min_distance, next_node = 0, i, j;
    
    for(i = 0; i < vertice; i++)
        for(j = 0; j < vertice; j++)
            if(matrix[i][j] == 0)
                cost[i][j] = 1000;
            else
                cost[i][j] = matrix[i][j];
    
    for(i = 0; i < vertice; i++)
    {
        distance[i] = cost[source_node][i];
        previous_node[i] = source_node;
        visited_node[i] = 0;
    }
    
    distance[source_node] = 0;
    visited_node[source_node] = 1;
    count = 1;
    
    while(count < vertice - 1)
    {
        min_distance = 1000;
        
        // next_node gives the node at minimum distance
        for(i = 0; i < vertice; i++)
            if(distance[i] < min_distance && !visited_node[i])
            {
                min_distance = distance[i];
                next_node = i;
            }
        
        // Check if a better path exists through nextnode
        visited_node[next_node] = 1;
        for(i = 0; i < vertice; i++)
            if(!visited_node[i])
                if(min_distance + cost[next_node][i] < distance[i])
                {
                    distance[i] = min_distance + cost[next_node][i];
                    previous_node[i] = next_node;
                }
        count++;
    }
    
    // Print the shortest path and cost of the source node to destination node
    for(i = 0; i < vertice; i++)
        if((i == destination_node) && (i != source_node))
        {
            char c = '\0';
            
            switch (i) {
                case 0:
                    c = 'A';
                    break;
                case 1:
                    c = 'B';
                    break;
                case 2:
                    c = 'C';
                    break;
                case 3:
                    c = 'D';
                    break;
                case 4:
                    c = 'E';
                    break;
                case 5:
                    c = 'F';
                    break;
                case 6:
                    c = 'G';
                    break;
                case 7:
                    c = 'H';
                    break;
            }
            
            printf("\nShortest path: %c", c);
            
            j = i;
            
            do
            {
                j = previous_node[j];
                
                char d = '\0';
        
                switch (j) {
                    case 0:
                        d = 'A';
                        break;
                    case 1:
                        d = 'B';
                        break;
                    case 2:
                        d = 'C';
                        break;
                    case 3:
                        d = 'D';
                        break;
                    case 4:
                        d = 'E';
                        break;
                    case 5:
                        d = 'F';
                        break;
                    case 6:
                        d = 'G';
                        break;
                    case 7:
                        d = 'H';
                        break;
                }
                        
                printf(" <- %c", d);
       
            } while(j != source_node);
    
            printf("\n\nCost of node: %d", distance[i]);
        }
    
    printf("\n");
}
