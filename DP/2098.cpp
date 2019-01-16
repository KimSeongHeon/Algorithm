#include<iostream>

using namespace std;

int N;
int W[17][17];
int dp[16][1<<16];

int TSP(int curr, int visited){ //���� ��� ° ������ ��ġ�ϴ���, ��� ������ �湮�ϰ� �Դ���
	int result;
	int ret = dp[curr][visited];

	if(ret != 0) //�̹� ���� �� �ִٸ�
		return ret;

	if(visited == (1<<N)-1){ //��� ���� �湮���� ��
		if(W[curr][0] != 0){ //0�� ������ �� �� ���� ��
			return W[curr][0];
		}
		return 1000000000; //�Ұ��� �ϵ��� �ſ� ū ���� return
	}

	ret = 1000000000;

	for(int i=0; i<N; i++){
		if((visited & 1<<i) || (W[curr][i] == 0)) //i��° visited �� Ȯ���ϱ� ���� bit ����
			continue;	
		result = TSP(i ,(visited | 1<<i))+W[curr][i];
		if(result < ret)
			ret = result;
	}
	dp[curr][visited] = ret;

	return ret;

}
int main(){

	scanf("%d", &N);
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &W[i][j]);
		}
	}

	printf("%d\n", TSP(0, 1));

	return 0;
}