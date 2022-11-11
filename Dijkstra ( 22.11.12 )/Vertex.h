#pragma once
#include <iostream>
using namespace std;

struct Vertex {
	Vertex* next_vertex = 0;
	int num = 0;
	int check = 0;
	int weight = 9999999;
};

void make_Vertex(Vertex* v, int n) { //정점 생성
	while (v->next_vertex != nullptr) {
		v = v->next_vertex;
	}
	v->next_vertex = new Vertex;
	v->num = n;
}

void check_Vertex(Vertex* v) { //정점 현재 정보 표시
	cout << endl;
	cout << "Vertex Check------------------" << endl;
	while (v->next_vertex != nullptr) {
		cout << v->num << " : check : " << v->check << "     weight : " << v->weight << "     " << endl;
		v = v->next_vertex;
	}
}

void Vertex_Weight(Vertex* v, int num, int weight, int pre_weight, int mx) { //가중치 업데이트, 순환횟수 체크
	int c = 0;
	while (v->next_vertex != nullptr) {
		if (v->num == num) {
			c = 1;
			break;
		}
		v = v->next_vertex;
	}

	if (c == 1 && v->check != mx) {
		v->check++;
		if (v->weight > weight + pre_weight) v->weight = weight + pre_weight;
	}
	return;
}