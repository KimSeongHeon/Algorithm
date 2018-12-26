#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> s;
    
    for(int i=0; i<arrangement.size(); i++)
        if(arrangement[i] == '(' && i+1< arrangement.size() 
           && arrangement[i+1] == ')' ){ //�������� ���
            i++;
            answer += s.size();
        }
        else if(arrangement[i] == '(' && i+1< arrangement.size() 
           && arrangement[i+1] != ')' ){ //�踷��� ����
            s.push('(');
        }
        else if(arrangement[i] == ')'){ //�踷��� ��
            s.pop();
            answer++;
        }
    
    return answer;
}