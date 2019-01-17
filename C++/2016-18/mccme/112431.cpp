#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Shop {
  string name;
  string street;
  int fat;
  int price;
};

using namespace std;

int main(int argc, char const *argv[]) {

  int counter, min15 = 65535, min20 = 65535, min25 = 65535, cnt15 = 0, cnt20 = 0, cnt25 = 0;
  cin >> counter;

  Shop shop;

  for (size_t i = 0; i < counter; i++) {
    cin >> shop.name >> shop.street >> shop.fat >> shop.price;
    switch (shop.fat) {
      case 15: if (shop.price < min15) {
                  min15 = shop.price;
                  cnt15 = 1;
               }
               else if (shop.price == min15)
                cnt15++;
               break;
      case 20: if (shop.price < min20) {
                  min20 = shop.price;
                  cnt20 = 1;
               }
               else if (shop.price == min20)
                cnt20++;
               break;
      case 25: if (shop.price < min25) {
                  min25 = shop.price;
                  cnt25 = 1;
               }
               else if (shop.price == min25)
                cnt25++;
               break;
    }
  }

  cout << cnt15 << ' ' << cnt20 << ' ' << cnt25 << endl;
  
  return 0;
}
