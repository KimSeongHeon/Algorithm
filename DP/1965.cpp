#include<iostream>

using namespace std;

int box[1001];
int dp[1001];

int main(){
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++)
		scanf("%d", &box[i]);

	dp[0] = 1;
	int bmax, result=1;

	for(int i=1; i<N; i++){
		bmax = 1; //i��° ������ �׿��ִ� ���ڰ� ���� ���� �����Ƿ� 0�� �ƴ϶� 1�� ����!
		for(int j=0; j<i; j++){
			if(box[j] < box[i] && bmax < dp[j]+1){
				bmax = dp[j]+1;
			}
		}
		dp[i] = bmax;
		if(result < dp[i])
			result = dp[i];
	}

	printf("%d\n",result);
	
	return 0;
}