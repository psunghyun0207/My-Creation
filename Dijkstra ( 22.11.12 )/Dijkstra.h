#pragma once
#include "Edge.h"
#include "Vertex.h"

using namespace std;

void set_StartPos(Edge* e, Vertex* v, int s) { //Dijkstra 초기 시작지점 세팅
	while (v->next_vertex != nullptr) {
		if (v->num == s) break;
		v = v->next_vertex;
	}
	v->check = 1;
	v->weight = 0;
}

void Search_Edge2(Edge* e, Vertex* v, int Search, int weight, int mx) {
	while (e->next_edge != nullptr) {
		if (e->start == Search) {
			Vertex_Weight(v, e->end, e->weight, weight, mx);
		}
		else if (e->end == Search) {
			Vertex_Weight(v, e->start, e->weight, weight, mx);
		}

		e = e->next_edge;
	}
}

int* Search_Edge(Edge* e, Vertex* v, int mx) {
	int Search = 0;
	while (v->next_vertex != nullptr) {
		if (v->weight != 9999999 && v->check < mx) {
			Search = v->num;
			v->check++;
			break;
		}
		v = v->next_vertex;
	}
	int a[2] = { Search, v->weight };
	return a;
}

bool Search_All_Vertex(Vertex* v, int mx) { //모든 정점 조사 후 프로그램 종료여부 결정
	while (v->next_vertex != nullptr) {
		if (v->weight == 9999999 || v->check != mx) return false;
		v = v->next_vertex;
	}
	return true;
}

void view_result(Edge* e, Vertex* v, int start, int desti) { //최종 결과값 계산
	cout << "\n\n\n\n\n";
	cout << start << " -> " << desti << " : ";
	while (v->next_vertex != nullptr) {
		if (v->num == desti) break;
		v = v->next_vertex;
	}
	cout << v->weight;
}