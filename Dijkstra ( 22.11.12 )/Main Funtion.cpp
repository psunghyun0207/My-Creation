#include <iostream>
#include "Edge.h"
#include "Vertex.h"
#include "Dijkstra.h"

using namespace std;

int main() {
	Edge* e = new Edge;
	Vertex* v = new Vertex;

	int start_p, desti_p, horizon, vertical;

	//간선 데이터 입력

	cin >> start_p >> desti_p;
	cin >> horizon >> vertical;
	int** map = new int* [horizon];
	for (int i = 0; i < horizon; i++) map[i] = new int[vertical];
	for (int i = 0; i < horizon; i++) for (int j = 0; j < vertical; j++) cin >> map[i][j];

	for (int i = 0; i < horizon; i++) for (int j = 0; j < i; j++) {
		if (map[i][j] != 0) make_Edge(e, i + 1, j + 1, map[i][j]);
	}

	//정점 개수 체크

	for (int i = 1; i <= max(horizon, vertical); i++) {
		make_Vertex(v, i);
	}

	//몇번 반복 할지 ( Vertex수 - 1 )

	int iter = max(horizon, vertical) - 1;

	//Dijkstra 실행

	view_Edge(e);
	check_Vertex(v);
	set_StartPos(e, v, start_p);
	check_Vertex(v);

	while (Search_All_Vertex(v, iter) == false) {
		int *a = Search_Edge(e, v, iter);
		Search_Edge2(e, v, a[0], a[1], iter);
		check_Vertex(v);
	}

	//최종 결과값 출력

	view_result(e, v, start_p, desti_p);
}