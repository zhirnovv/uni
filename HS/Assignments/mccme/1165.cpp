#include <iostream>

using namespace std;

class HEAP {
    public:
    int *heapp;
    int size;

    HEAP(unsigned int n) {
        size = 0;
        heapp = new int[n];
    }
    ~HEAP() {
        if(heapp) delete [] heapp;
    }
    int add(int x) {
        heapp[++size] = x;
        sift_up(size);
        return 1;
    }
    int extract_min(unsigned int *x) {
        if(size == 0) return 0;
        *x = heapp[1];
        heapp[1] = heapp[size--];
        sift_down(1);
        return 1;
    }

    void sift_up(int element) {
        int p;
        p = element / 2;
        if(p == 0)return;
        if(heapp[p] < heapp[element]) {
            int tmp;
            tmp = heapp[p]; heapp[p] = heapp[element]; heapp[element] = tmp;
            sift_up(p);
        }
    }

    int sift_down(int p) {
        int element;
        element = 2 * p;
        if(element > size) return p;
        if(element + 1 <= size && heapp[element + 1] > heapp[element]) element++;
        if(heapp[element] > heapp[p]) {
            int tmp;
            tmp = heapp[element]; heapp[element] = heapp[p]; heapp[p] = tmp;
            sift_down(element);
        }
        else return p;
    }
};

int main() {
    HEAP heap(100000);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int key;
        cin >> key;
        heap.add(key);
    }
    int num; cin >> num;
    for(int i = 0; i < num; i++){
        int x, y; cin >> x >> y;
        heap.heapp[x] -= y;
        cout  << heap.sift_down(x) << endl;
    }
    for(int i = 1; i <= heap.size; i++) cout << heap.heapp[i] << " ";
    return 0;
}
