#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int room, room_floor=1, room_position=1, set=1, lower_bound = 1, higher_bound = 1;
    cin >> room;

    while(!(room >= lower_bound && room <= higher_bound)) {
        lower_bound += pow(set, 2);
        higher_bound += pow(set+1, 2);
        room_floor += set;
        set++;
    }

    while(!(room >= lower_bound && room <= lower_bound + set - 1)) {
        lower_bound += set;
        room_floor++;
    }

    while(lower_bound != room) {
        lower_bound++;
        room_position++;
    }
        
    cout << "Floor " << room_floor << endl << "Room " << room_position;
    return 0;
}