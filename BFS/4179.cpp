#include<iostream>
#include<queue>

using namespace std;
int R, C;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int map[1001][1001];
queue<pair<int, int>> fire;

int BFS(pair<int, int> start){
	int success = 0, cnt=0, jsize, fsize;
	pair<int, int> curr;
	int nextx, nexty;
	queue<pair<int, int>> J;

	J.push(start);

	while(success == 0 && (!J.empty() || !fire.empty())){

		jsize = J.size();
		fsize = fire.size();

		for(int i=0; i<jsize; i++){
			curr = J.front();
			J.pop(); 
			if(map[curr.first][curr.second] == 3) //�̹� 3�� ���� ���� ���������� �� �� ���� ���
				continue;

			map[curr.first][curr.second] = 3; //������������

			if( curr.first == 0 || curr.first == R-1 || curr.second == 0 || curr.second == C-1){
				success = 1; 
				break;
			}
			for(int j=0; j<4; j++){
				nextx = curr.first + dx[j];
				nexty = curr.second + dy[j];

				if(nextx < 0 || nexty < 0 || nextx >= R || nexty >=C || map[nextx][nexty] != 0)
					continue;

				map[nextx][nexty] = 2; //�����̰� �������� �ִ� == ���� cnt���� �����̰� �ִ� ��
				J.push(make_pair(nextx, nexty));
			}
		}

		for(int i=0; i<fsize; i++){
			curr = fire.front();
			fire.pop(); 
			
			for(int j=0; j<4; j++){
				nextx = curr.first + dx[j];
				nexty = curr.second + dy[j];

				if(nextx < 0 || nexty < 0 || nextx >= R || nexty >=C || map[nextx][nexty] == 1)
					continue;
				if(map[nextx][nexty] == 2){ //�����̰� ���� �ִ� ���ε� �� ��δ� �� �� ����
					map[nextx][nexty] = 3;
				}else{
					map[nextx][nexty] = 1; //���� ������ ��(3�̾ ������ �� ����)
				}
				fire.push(make_pair(nextx, nexty));
			}
		}

		cnt++;

	}

	if(success != 1)
		return -1;

	return cnt;
	
}

int main(){

	char input;
	pair<int, int> start;

	scanf("%d %d", &R, &C);

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf(" %c", &input);
			if(input == '#'){
				map[i][j] = 1; //���������� ��
			}else if(input == '.'){
				map[i][j] = 0;//������ �� �ִ� ��
			}else if(input == 'J'){
				start.first = i;
				start.second = j;
			}else{
				map[i][j] = 1;
				fire.push(make_pair(i, j));
			}
		}
	}

	int result = BFS(start);
	if( result == -1)
		printf("IMPOSSIBLE\n");
	else{
		printf("%d\n", result);
	}

	return 0;
}