#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

int V, E; // 정점 개수, 간선 개수
int dist[20001];
vector<pair<int, int>> map[20001];

void dijkstra(int s){
    priority_queue<pair<int, int>> pq; // 값이 클수록 더 높은 우선순위를 가짐
    pq.push({0, s});
    dist[s] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first; // 음수로 저장되어있으므로 양수로 변환
        int cur = pq.top().second;
        pq.pop();

        for(int i=0; i<map[cur].size(); i++){
            int next = map[cur][i].first;
            int ncost = map[cur][i].second;

            if(dist[next] > cost + ncost){
                dist[next] = cost + ncost;
                pq.push({-dist[next], next}); // pq의 성질 때문에 음수로 저장
            }
        }
    }
}

int main(){
    int K;    // 시작 정점
    int u, v, w;    // u에서 v로 가는 가중치 w인 간선

    // map 초기화
    cin >> V >> E >> K;
    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        map[u].push_back({v, w});
    }
    for(int i=1; i<=V; i++){
        dist[i] = INF;
    }

    dijkstra(K);
    for(int i=1; i<=V; i++){
        if(dist[i] == INF){
            cout << "INF\n";
        }else{
            cout << dist[i] << "\n";
        }
    }    
    return 0;
}