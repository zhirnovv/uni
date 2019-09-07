<...>
k = 0;
for (i = 1; i < N; i++) {
  if (a[i] % 4 == 0 && a[i-1] % 4 == 0) {
    k++;
  }
}

cout << k;
return 0;
