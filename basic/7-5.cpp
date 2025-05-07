#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

ostream& currency(ostream& os) {
    return os << "$";
}

int main() {
    vector<pair<string,double>> v = {{"shreeja", 12345.67}, {"vishwa", 890.12}};
    cout << left << setw(10) << "Name" << right << setw(10) << "Fee" << endl;
    for (auto &p : v) {
        cout << left << setw(10) << p.first << right << setw(1);
        currency(cout) << fixed << setprecision(2) << setw(9) << p.second << endl;
    }
    return 0;
}