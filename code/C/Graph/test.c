#include "test.h"
#include "graph.c"

void testGetFile() {
    FILE *fp = fopen("input1.txt", "r");
    size_t len = 255;
    char *delim = " ";
    char *token;
    char *line = malloc(sizeof(char) * len);
    if (fp == NULL) {
        printf("can open file input1.txt!");
        return;
    }
    while(fgets(line, len, fp) != NULL) {
        printf("%s\n", line);
        char *tmp = line;
        while ((token = strsep(&tmp, delim)) != NULL) {
            printf("%s\n", token);
        }
        free(token);
    }
    free(line);
}

void test_add_edge() {
    Graph *g;
    FILE *fp = fopen("input1.txt", "r");
    size_t len = 255;
    char *delim = " ";
    char *token;
    char line[len];
    int counter = 0;
    if (fp == NULL) {
        printf("can open file input1.txt!");
        return;
    }
    while(fgets(line, len, fp) != NULL) {
        if (counter == 0) {
            int vertice_number = strtol(line, (char **)NULL, 10);
            g = initialize(vertice_number);
            counter++;
        } else if (counter == 1) {
            counter++;
        } else {
            char *tmp = line;
            int arr[2];
            int sub_counter = 0;
            while ((token = strsep(&tmp, delim)) != NULL) {
                arr[sub_counter] = strtol(token, (char **)NULL, 10);
                if (arr[sub_counter++] < 0) {
                    printf("Check input file please!\n");
                    return;
                }
            }
            addEdge(g, arr[0], arr[1]);
            free(token);
            counter++;
        }
    }
    fclose(fp);
    printGraph(g);
    bool visited[g->vertice_number];
    bool exposed[g->vertice_number];
    for (int i = 0; i < g->vertice_number; i++) {
        visited[i] = false;
        exposed[i] = false;
    }
    dfs_recusive(g, 5, visited, exposed);
    destroyGraph(g);
}
