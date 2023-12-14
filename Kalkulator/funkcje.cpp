#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

double calculateNaturalLog(double x) {
    if (x <= 0) {
        cerr << "Błąd: Logarytm naturalny jest zdefiniowany tylko dla x > 0." << endl;
        return 0.0;
    }
    return log(x);
}

double calculateStandardDeviation(const vector<double>& values) {
    if (values.size() < 2) {
        cerr << "Błąd: Potrzebujesz co najmniej dwóch wartości do obliczenia odchylenia standardowego." << endl;
        return 0.0;
    }

    double mean = accumulate(values.begin(), values.end(), 0.0) / values.size();
    double variance = 0.0;

    for (const auto& value : values) {
        variance += pow(value - mean, 2);
    }

    variance /= values.size();

    return sqrt(variance);
}

double calculateExponent(double x) {
    return exp(x);
}

int main() {
    cout << "Podaj trzy liczby rzeczywiste oddzielone spacjami: ";

    double x, y, z;
    cin >> x >> y >> z;

    double logResult = calculateNaturalLog(x);
    double stdDeviation = calculateStandardDeviation({ x, y, z });
    double exponentResult = calculateExponent(z);

    cout << fixed << setprecision(4);
    cout << "Logarytm naturalny z " << x << " wynosi: " << logResult << endl;
    cout << "Odchylenie standardowe wynosi: " << stdDeviation << endl;
    cout << "Wartosc exponentu dla " << z << " wynosi: " << exponentResult << endl;

    return 0;
}
