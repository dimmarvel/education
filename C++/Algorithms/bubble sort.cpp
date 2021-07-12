#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<int> vec = {1,2,4,3,6,9,7,6};

    for (int i = 0; i < vec.size(); ++i){
        for (int j = 0; j < vec.size(); ++j) {
            if(vec[j] > vec[j+1])
            {
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " " << endl;
    }

    return 0;
}
