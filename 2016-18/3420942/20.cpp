#define N 25
int A[25];
int i, j, min;
for (i = 0; i < N; i++) {
  cin >> a[i];
}
min = 51;
for (i = 0; i < N; i++) {
  if (a[i] > 40 && a[i] < min) {
    min = a[i];
  }
}
cout << min;
return 0;
