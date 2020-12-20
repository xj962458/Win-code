#include "unconnected_graph_search.cpp"
int main()
{
    AdjGraph *G;
    int A[][MAXV] =
        {{0, 0, 1, 0, 0, 1, 0},
         {0, 0, 0, 1, 1, 0, 0},
         {1, 0, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 0, 0, 0},
         {0, 1, 0, 0, 0, 0, 0},
         {1, 0, 0, 0, 0, 0, 0},
         {0, 0, 0, 0, 0, 0, 0}};
    int n = 7, e = 4;
    CreateAdj(G, A, n, e);
    printf("ͼG���ڽӱ�:\n");
    DispAdj(G);
    printf("������ȱ�������Ϊ:\n");
    DFS_NC(G);
    printf("\n");
    printf("������ȱ�������Ϊ:\n");
    BFS_NC(G);
    DestroyAdj(G);
    return 0;
}