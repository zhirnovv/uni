// #include <iostream>
// #include <vector>
// #include <cmath>
// #include <algorithm>
//
// using namespace std;
//
// struct Point {
//   int x;
//   int y;
// };
//
// struct QuarterProperties {
//   int counter = 0;
//   int xmin = 65535;
//   int ymin = 65535;
// };
//
// int main(int argc, char const *argv[]) {
//
//   int counter, k, m=0, r;
//   cin >> counter;
//
//   std::vector<QuarterProperties> cnt(4);
//
//   Point I;
//
//   for (size_t i = 0; i < counter; i++) {
//     cin >> I.x >> I.y;
//     if (I.x > 0 && I.y > 0)
//     {
//       cnt[0].counter++;
//       if (abs(I.x) < cnt[0].xmin) {
//         cnt[0].xmin = I.x;
//       }
//       if (abs(I.y) < cnt[0].ymin) {
//         cnt[0].ymin = I.y;
//       }
//     }
//     else if (I.x < 0 && I.y > 0)
//     {
//       cnt[1].counter++;
//       if (abs(I.x) < cnt[1].xmin) {
//         cnt[1].xmin = I.x;
//       }
//       if (abs(I.y) < cnt[1].ymin) {
//         cnt[1].ymin = I.y;
//       }
//     }
//     else if (I.x < 0 && I.y < 0) {
//       cnt[2].counter++;
//       if (abs(I.x) < cnt[2].xmin) {
//         cnt[2].xmin = abs(I.x);
//       }
//       if (abs(I.y) < cnt[2].ymin) {
//         cnt[2].ymin = abs(I.y);
//       }
//     }
//     else if (I.x > 0 && I.y < 0) {
//       cnt[3].counter++;
//       if (abs(I.x) < cnt[3].xmin) {
//         cnt[3].xmin = abs(I.x);
//       }
//       if (abs(I.y) < cnt[3].ymin) {
//         cnt[3].ymin = abs(I.y);
//       }
//     }
//   }
//
//   for (size_t i = 0; i < 3; i++) {
//     if (cnt[i].counter > m)
//     {
//       k = i+1;
//       m = cnt[i].counter;
//     }
//     else if (cnt[i].counter == m)
//     {
//       int temp_k;
//       for (size_t j = 0; j < i; j++) {
//         if (cnt[j].counter == m)
//           temp_k = j+1;
//       }
//       if (cnt[i].xmin > cnt[temp_k].xmin || cnt[i].ymin > cnt[temp_k].ymin)
//         k = temp_k;
//     }
//   }
//
//   switch (k) {
//     case 2:cnt[k-1].xmin *= -1;
//     case 3:cnt[k-1].xmin *= -1;
//            cnt[k-1].ymin *= -1;
//     case 4:cnt[k-1].ymin *= -1;
//   }
//
//   if (abs(cnt[k-1].xmin) > abs(cnt[k-1].ymin))
//     r = abs(cnt[k-1].ymin);
//   else r = abs(cnt[k-1].xmin);
//
//   cout << "K = " << k << endl
//        << "M = " << m << endl
//        << "A = (" << cnt[k].xmin << ", " << cnt[k].ymin << ')' << endl
//        << "R = " << r << endl;
//
//   return 0;
// }

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minimal(int m1, int r1, int m2, int r2){
    if(m1 > m2 || (m1 == m2 && r1 <= r2)){
        return 1;
    }else{
        return 2;
    }
}

int main(){
    int n;
    cin >> n;
    int m1 = 0, m2 = 0, m3 = 0, m4 = 0;
    int xx1 = 999999999, yy1 = 999999999, r1 = 999999999;
    int xx2 = 999999999, yy2 = 999999999, r2 = 999999999;
    int xx3 = 999999999, yy3 = 999999999, r3 = 999999999;
    int xx4 = 999999999, yy4 = 999999999, r4 = 999999999;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(x > 0 && y > 0){
            m1++;
            if(abs(x) < r1 || abs(y) < r1){
                xx1 = x;
                yy1 = y;
                r1 = min(abs(x), abs(y));
            }
        }
        if(x < 0 && y > 0){
            m2++;
            if(abs(x) < r2 || abs(y) < r2){
                xx2 = x;
                yy2 = y;
                r2 = min(abs(x), abs(y));
            }
        }
        if(x < 0 && y < 0){
            m3++;
            if(abs(x) < r3 || abs(y) < r3){
                xx3 = x;
                yy3 = y;
                r3 = min(abs(x), abs(y));
            }
        }
        if(x > 0 && y < 0){
            m4++;
            if(abs(x) < r4 || abs(y) < r4){
                xx4 = x;
                yy4 = y;
                r4 = min(abs(x), abs(y));
            }
        }
    }
    //cout << m1 << " " << m2 << " " << m3 << " " << m4 << endl;

    int k;
    if(minimal(m1, r1, m2, r2) == 1){
        k = 1;
        if(minimal(m1, r1, m3, r3) == 1){
            k = 1;
            if(minimal(m1, r1, m4, r4) == 1){
                k = 1;
            }else{
                k = 4;
            }
        }else{
            k = 3;
            if(minimal(m3, r3, m4, r4) == 1){
                k = 3;
            }else{
                k = 4;
            }
        }
    }else{
        k = 2;
        if(minimal(m2, r2, m3, r3) == 1){
            k = 2;
            if(minimal(m2, r2, m4, r4) == 1){
                k = 2;
            }else{
                k = 4;
            }
        }else{
            k = 3;
            if(minimal(m3, r3, m4, r4) == 1){
                k = 3;
            }else{
                k = 4;
            }
        }
    }



    if(k == 1){
        cout << "K = " << 1 << endl;
        cout << "M = " << m1 << endl;
        cout << "A = (" << xx1 << ", " << yy1 << ")" << endl;
        cout << "R = " << r1 << endl;
        return 0;
    }
    if(k == 2){
        cout << "K = " << 2 << endl;
        cout << "M = " << m2 << endl;
        cout << "A = (" << xx2 << ", " << yy2 << ")" << endl;
        cout << "R = " << r2 << endl;
        return 0;
    }
    if(k == 3){
        cout << "K = " << 3 << endl;
        cout << "M = " << m3 << endl;
        cout << "A = (" << xx3 << ", " << yy3 << ")" << endl;
        cout << "R = " << r3 << endl;
        return 0;
    }
    if(k == 4){
        cout << "K = " << 4 << endl;
        cout << "M = " << m4 << endl;
        cout << "A = (" << xx4 << ", " << yy4 << ")" << endl;
        cout << "R = " << r4 << endl;
        return 0;
    }
    return 0;
}
 
