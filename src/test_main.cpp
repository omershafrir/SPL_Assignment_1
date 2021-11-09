#include <iostream>
#include <vector>

using namespace std;
vector<int>* convert(string s);
void deleteVector(vector<int>* v);
int main() {
    string st ="4";
    vector<int> *a = convert(st);
    for (int x: *a) {
        cout << x << " ";
    }
    deleteVector(a);
}
