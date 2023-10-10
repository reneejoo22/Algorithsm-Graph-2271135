//인접 행렬을 이용한 그래프 구현>> adj_mat

#include <stdio.h>
#include <stdlib.h>

#define max_vertices 50

typedef struct GraphType {
	int vertexNum; //정점의 갯수
	int adj_mat[max_vertices][max_vertices];	//인접행렬의 이름
}GraphType;

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


//인접 행렬 출력 함수
void print_adjMat(GraphType* g) {

	for (int i = 0; i < g->vertexNum; i++) {
		for (int j = 0; j < g->vertexNum; j++) {
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}

void main() {

	GraphType* myGraph;

	myGraph = (GraphType*)malloc(sizeof(GraphType));

	init(myGraph);

	for (int i = 0; i < 4; i++) 	//4개의 정점을 삽입할 것
		insertVertex(myGraph, i);

	insert_edge(myGraph, 0, 1);	//0이랑 1은 붙어있음
	insert_edge(myGraph, 0, 2);	//행렬의 [0][2] 자리와 [2][0]자리에 1을 넣음
	insert_edge(myGraph, 0, 3);	//행렬의 [0][3] 자리와 [3][0]자리에 1을 넣음
	insert_edge(myGraph, 1, 2);
	insert_edge(myGraph, 2, 3);

	print_adjMat(myGraph);

	free(myGraph);
}

//    g->vertexNum = v; 를 사용하지 않는 이유는 앞에 이프 조건문 때문에

/*
//정점 삽입 함수
void insertVertex(GraphType* g, int v) {

	if ((v + 1) > max_vertices) {
		fprintf(stderr, "그래프의 정점의 개수를 초과함");
		return;
	}
	g->vertexNum = v;
}
//이렇게 사용하면 메인 함수에서 반복문 안써도 될 것 같다
//틀릴시 추후 수정할 예정
*/
