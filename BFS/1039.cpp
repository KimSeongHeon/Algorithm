#include<iostream>
#include<queue>
#include<map>

using namespace std;

int main(){
	int N, K, M=0, step=0, size; 
	int num[8], result, curr, temp, max_val = -1;

	queue<int> nums;

	scanf("%d %d", &N, &K);

	temp = N;
	while(temp > 0){
		temp /= 10;
		M++; //�ڸ����� Ȯ���ϱ� ���ؼ�
	}
	
	nums.push(N);

	while(!nums.empty() && step < K){
		size = nums.size();
		
		map<int, int> visited;

		for(int t=0; t<size; t++){
			curr = nums.front();
			nums.pop();

			for(int i=M; i > 0; i--){
				num[i] = curr%10;
				curr /= 10;
			}
			
			for(int i=1; i<=M-1; i++){
				if(i == 1 && num[i] == 0)
					continue;

				for(int j=i+1; j<=M; j++){
					if(i == 1 && num[j] == 0) //ù �ڸ��� 0�� �Ǹ� �ȵǱ� ����
						continue;
					
					temp = num[i];
					num[i] = num[j];
					num[j] = temp;

					result = 0;

					for(int a=1; a<=M; a++){
						result = result*10 + num[a];
					} 

					if(visited.find(result) == visited.end()){ //�� step �ȿ����� �ߺ��Ǹ� �ȵ�
						if(step == K-1 && max_val < result)
							max_val = result;
						nums.push(result);
						visited.insert(make_pair(result, 1));
					}

					temp = num[i];
					num[i] = num[j];
					num[j] = temp;
				}
			}
		}
		step++;
	}
	
	if( step != K )
		printf("-1");
	else
		printf("%d\n", max_val);

	return 0;
}