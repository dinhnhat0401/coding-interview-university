#include <cstdio>
#include <string>

using namespace std;
void quicksort(char* s, int low, int hi);
int partition(char* s, int low, int hi);
void print_char(char *s, int N);

int main(void){
  int N,Q,i,j;

  scanf("%d%d", &N, &Q);

  char* s = (char*)malloc(sizeof(char) * N);
  for(i = 0; i < N; i++) s[i] = (char)('A' + i);

  quicksort(s, 0, N - 1);

  print_char(s, N);

  return 0;
}

void print_char(char *s, int N) {
  printf("! ");
  for (int i = 0; i < N; i++) {
    printf("%c", s[i]);
  }
  printf("\n");
  fflush(stdout);
}

void quicksort(char* s, int low, int hi) {
  int p = partition(s, low, hi);
  if (p >= 0) {
    quicksort(s, low, p - 1);
    quicksort(s, p + 1, hi);
  }
}

int partition(char* s, int low, int hi) {
  if (low >= hi) return -1;

  int i = low + 1;
  int j = hi;

  while (true) {
    while(i < hi) {
      printf("? %c %c\n", s[i], s[low]);
      fflush(stdout);
      char ans;
      scanf(" %c", &ans);
      if(ans == '<') i++;
      else break;
    }

    while (j > low) {
      printf("? %c %c\n", s[j], s[low]);
      fflush(stdout);
      char ans1;
      scanf(" %c", &ans1);
      if(ans1 == '>') j--;
      else break;
    }

    if (i > j) break;
    swap(s[i], s[j]);
  }
  swap(s[low], s[j]);
  return j;
}
