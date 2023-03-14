#include <iostream>
#include <cmath>

using namespace std;
/*My first commit to main branch Nikolaenko*/

int main() {
    double a, b, c, discriminant, root1, root2;
    cout << "Enter coefficients a, b and c: ";
    cin >> a >> b >> c;

    discriminant = b * b - 4 * a * c;
/*ejdoweopwe*/
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and different." << endl;
        cout << "Root 1 = " << root1 << endl;
        cout << "Root 2 = " << root2 << endl;
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        cout << "Roots are real and same." << endl;
        cout << "Root 1 = Root 2 = " << root1 << endl;
    } else {
        cout << "Roots are complex and different." << endl;
        cout << "Root 1 = (-" << b << " + i" << sqrt(-discriminant) << ") / " << 2*a << endl;
        cout << "Root 2 = (-" << b << " - i" << sqrt(-discriminant) << ") / " << 2*a << endl;
    }

    return 0;
}
