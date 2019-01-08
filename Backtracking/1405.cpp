#include<iostream>

using namespace std;

int N;
double percent[4]; //���� : ��, ��, ��, ��
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int visited[29][29];
double total;

void backtracking(pair<int, int> now, int curr, double result){

	int nextx, nexty;

	if(curr == N+1){
		total += result;
		return ;
	}

	visited[now.first][now.second] = 1; //�湮

	for(int i=0; i<4; i++){
		nextx = now.first+dx[i];
		nexty = now.second+dy[i];
		
		if(visited[nextx][nexty] == 0){ //�湮�� �� ���ٸ�
			backtracking(make_pair(nextx, nexty), curr+1, result*percent[i]);
		}
	}

	visited[now.first][now.second] = 0; //�湮���� ���� ��ó�� �ʱ�ȭ

}
int main(){

	scanf("%d", &N);

	for(int i=0; i<4; i++){
		scanf("%lf", &percent[i]);
		percent[i] /= 100.0;
	}

	backtracking(make_pair(14, 14), 1, 1.0);

	printf("%.10lf\n", total);
	
	return 0;
}