#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    
    for(int i=0; i<26; i++){
        string temp = "";
        temp += (char)('A'+i);
        dict[temp] = i+1; //���� �빮�� ���� �ʱ�ȭ
    }
    
    map<string, int>::iterator found;
    
    int i=0, j;
    
    while(j < msg.size() ){
        string curr;
        curr += msg[i];
        string before = "";
    
        if(j == msg.size()-1){ //���� �� w�� ã�� �ʿ� ���� �� ��ü�� ���� �� ���
            answer.push_back(dict.find(curr)->second);
            break;
        }
        
        for(j = i+1; j < msg.size(); j++){
            before = curr;
            curr += msg[j];
            found = dict.find(curr);
            
            if( found != dict.end() ){
                if(j == msg.size()-1){ //���̻� ã�� �� �ִ� ������ ��� ���
                    answer.push_back(dict.find(curr)->second);
                }                
                continue; //���� �� w�� ã�� ���ؼ�
            }
            else{
                answer.push_back(dict.find(before)->second);
                i = j;
                dict[curr] = dict.size()+1;
                break;
            }
        }   
    }
       
    return answer;
}