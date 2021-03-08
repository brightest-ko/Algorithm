//https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=220620723528&proxyReferer=https%3A%2F%2Fwww.google.co.kr%2F
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for(int t=0; t<T; t++){
        // pre: 선행자의 개수, suc: 후행자의 목록
        int N, K, endpoint, time[1000], pre[1000] = {0};
        vector<int> suc[1000];
        //**hashmap처럼 사용 됌.
        scanf("%d %d", &N, &K);
        for(int i=0; i<N; i++)
            scanf("%d", &time[i]);
        for(int i=0; i<K; i++){
            int X, Y;
            scanf("%d %d", &X, &Y);
            suc[X-1].push_back(Y-1);
            pre[Y-1]++;
        }
        scanf("%d", &endpoint);
        endpoint--;
        
        // result: 해당 건물을 짓기 시작하는 데 걸리는 최소 시간
        int dp[1000] = {0};
        queue<int> Q;
        //**http://egloos.zum.com/dbtlek/v/1136353 queue사용방법
        // 선행자가 하나도 없는 노드들을 먼저 큐에 push
        for(int i=0; i<N; i++)
            if(!pre[i]) Q.push(i);
        
        // W번 건물의 선행자가 하나도 없을 때까지(더 갱신될 여지가 없음)
        while(pre[endpoint] > 0){
            int u = Q.front();
            Q.pop();
            // 모든 후행자 건물의 최소 건설시작시간을 갱신
            for(int next: suc[u]){
                //**vactor값 빼옴.
                dp[next] = max(dp[u]+time[u] , dp[next]); // 처음 이 후행자에 도착하면 dp[u]+time[u]를, 이 후행자의 선행가 여러노드면, 지금까지의 저장된 값과 dp[u]+time[u] 를 비교하여 넣는다.
                if(--pre[next] == 0) Q.push(next); // 선행자가 남아있으면 큐에 담지않고, 선행자가 남아있지 않으면 큐에 담는다.
            }
        }
        // 목표 건물을 짓는 데 걸리는 시간도 더해야 함
        printf("%d\n", dp[endpoint]+time[endpoint]);
    }
}
