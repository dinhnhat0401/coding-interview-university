#include<iostream>

const int MAXN = 100000;

int find(int i);
bool merge(int L, int R, int D);

int id[MAXN + 1];
int distance[MAXN + 1];

int main(void){
  int N,M;

  std::cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    id[i] = i;
    distance[i] = 0;
  }

  for (int i = 1; i <= M; i++) {
    int L, R, D;
    std::cin >> L >> R >> D;

    if (!merge(L, R, D)) {
      std::cout << "No";
      return 0;
    }
  }
  std::cout << "Yes";
  return 0;
}

bool merge(int L, int R, int D) {
  int originL = find(L);
    int originR = find(R);
    if (originL == originR) {
      return (distance[L] + D) == distance[R];
    } else {
      distance[originR] = distance[L] + D - distance[R];
      id[originR] = originL;
      return true;
    }
}

int find(int i) {
  int tmp = i;
  while(id[i] != i) {
    i = id[i];
    distance[tmp] += distance[i];
  }
  id[tmp] = i;
  return i;
}
