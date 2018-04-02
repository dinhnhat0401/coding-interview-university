#include <bits/stdc++.h>
#include <string>

using namespace std;
void print_char(int N);
void mergeSort(int lo, int hi);
void merge(int lo, int mid, int hi);

int N,Q,i,j;
char *arr;
char *aux;
int main(void){
  scanf("%d%d", &N, &Q);

  arr = new char[N];
  for(i = 0; i < N; i++) arr[i] = (char)('A' + i);

  aux = new char[N];
  if (N == 26) {
    mergeSort(0, N - 1);
  } else {
    
  }

  print_char(N);
  return 0;
}

void print_char(int N) {
  printf("! ");
  for (int i = 0; i < N; i++) {
    printf("%c", arr[i]);
  }
  printf("\n");
  fflush(stdout);
}

void mergeSort(int lo, int hi) {
  if (lo >= hi) return;
  int mid = (lo + hi)/2;
  mergeSort(lo, mid);
  mergeSort(mid + 1, hi);
  merge(lo, mid, hi);
}

void merge(int lo, int mid, int hi) {
  int i = lo, j = mid + 1;
  for (int k = lo; k <= hi; k++) { aux[k] = arr[k]; }
  for (int k = lo; k <= hi; k++) {
    if (i > mid) arr[k] = aux[j++];
    else if (j > hi) arr[k] = aux[i++];
    else {
      printf("? %c %c\n", aux[i], aux[j]);
      // count << "? " << aux[i] << " " << aux[j] << "\n"
      fflush(stdout);
      string ans;
      cin >> ans;
      if(ans == ">") {
        arr[k] = aux[j++];
      } else {
        arr[k] = aux[i++];
      }
    }
  }
}
