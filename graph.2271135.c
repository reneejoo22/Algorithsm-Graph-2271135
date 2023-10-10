//인접 리스트를 이용한 그래프 구현>> adj_list

#include <stdio.h>
#include <stdlib.h>

#define True 1
#define False 0
#define max_vertices 50

typedef struct GraphType {
	int vertexNum; //정점의 갯수
	int adj_mat[max_vertices][max_vertices];	//인접행렬의 이름
}GraphType;

int visited[max_vertices];

//그래프 초기화
void init(GraphType* g) {

	int r, c;

	g->vertexNum = 0;	//멤버변수_정점의 갯수 0으로 초기화
	for (r = 0; r < max_vertices; r++) {	//멤버변수_인접행렬 0으로 초기화 
		for (c = 0; c < max_vertices; c++) {
			g->adj_mat[r][c] = 0;
		}
	}

}

//정점 삽입 함수
void insertVertex(GraphType* g, int v) {

	if ((g->vertexNum) + 1 > max_vertices) {
		fprintf(stderr, "그래프의 정점의 개수를 초과함");
		return;
	}
	g->vertexNum++;
}

//간선 삽입
void insert_edge(GraphType* g, int start, int end) {

	if (start >= g->vertexNum || end >= g->vertexNum) {	//start <= vertexNum <= end 
		fprintf(stderr, "그래프 정점 번호 오류");	//vertexNum은 start랑 end보다 같지 않고 커야됨
		return;
	}
	g->adj_mat[start][end] = 1;
	g->adj_mat[end][start] = 1;
}

//인접 행렬로 표현된 그래프의 깊이 우선 탐색
void dfs_mat(GraphType* g, int v) {

	int w;
	visited[v] = True;
	printf("정점 %d -> ", v);

	for (w = 0; w < g->vertexNum; w++) {
		if (g->adj_mat[v][w] && !visited[w])	//visited가 true이고 adj_mat에 값이 잇을때
			//v와 정점 w 사이에 간선이 있고, 정점 w가 방문되지 않았다면, 해당 조건이 참
			dfs_mat(g, w);
	}

}

int main(void) {

	GraphType* myGraph;
	myGraph = (GraphType*)malloc(sizeof(GraphType));
	init(myGraph);

	for (int i = 0; i < 4; i++) 	//4개의 정점을 삽입할 것
		insertVertex(myGraph, i);

	insert_edge(myGraph, 0, 1);	
	insert_edge(myGraph, 0, 2);		
	insert_edge(myGraph, 0, 3);		
	insert_edge(myGraph, 1, 2);		
	insert_edge(myGraph, 2, 3);

	printf("깊이 우선 탐색\n");
	dfs_mat(myGraph, 0);
	printf("\n");

	free(myGraph);
}


