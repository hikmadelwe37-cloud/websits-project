#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <complex>
#include <stdexcept>
using namespace std;
//using namespace std::complex_literals;
class ScientificCalculator {
private:
double memory;
public:
ScientificCalculator() : memory(0) {}
// Basic arithmetic operations
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) {
if (b == 0) throw runtime_error("Error: Division by zero!");
return a / b;
}
double power(double base, double exponent) { return pow(base, exponent); }
double squareRoot(double x) {
if (x < 0) throw runtime_error("Error: Square root of negative number!");
return sqrt(x);
}
double square(double x) { return x * x; }
double cube(double x) { return x * x * x; }
double log10(double x) {
if (x <= 0) throw runtime_error("Error: Logarithm of non-positive number!");
return ::log10(x);
}
double naturalLog(double x) {
if (x <= 0) throw runtime_error("Error: Logarithm of non-positive number!");
return log(x);
}
double exponential(double x) { return exp(x); }
double modulo(double a, double b) { return fmod(a, b); }
double percentage(double value, double percent) { return (value * percent) / 100.0; }
double nthRoot(double x, double n) {
if (n == 0) throw runtime_error("Error: Root degree cannot be zero!");
if (x < 0 && fmod(n, 2) == 0) throw runtime_error("Error: Even root of negative
number!");
return pow(x, 1.0/n);
}
// Trigonometric functions (angles in radians)
double sine(double angle) { return sin(angle); }
double cosine(double angle) { return cos(angle); }
double tangent(double angle) { return tan(angle); }
double inverseSine(double value) {
if (value < -1 || value > 1) throw runtime_error("Error: Value out of range [-1, 1] for
inverse sine!");
return asin(value);
}
double inverseCosine(double value) {
if (value < -1 || value > 1) throw runtime_error("Error: Value out of range [-1, 1] for
inverse cosine!");
return acos(value);
}
double inverseTangent(double value) { return atan(value); }
// Hyperbolic functions
double hyperbolicSine(double x) { return sinh(x); }
double hyperbolicCosine(double x) { return cosh(x); }
double hyperbolicTangent(double x) { return tanh(x); }
// Factorial
long long factorial(int n) {
if (n < 0) throw runtime_error("Error: Factorial of negative number!");
if (n > 20) throw runtime_error("Error: Number too large for factorial!");
long long result = 1;
for (int i = 2; i <= n; i++) {
result *= i;
}
return result;
}
// Matrix operations for 2x2 matrices
class Matrix2x2 {
public:
double data[2][2];
Matrix2x2() {
for (int i = 0; i < 2; i++)
for (int j = 0; j < 2; j++)
data[i][j] = 0;
}
Matrix2x2(double a, double b, double c, double d) {
data[0][0] = a; data[0][1] = b;
data[1][0] = c; data[1][1] = d;
}
void display() {
cout << fixed << setprecision(2);
for (int i = 0; i < 2; i++) {
cout << "[ ";
for (int j = 0; j < 2; j++) {
cout << setw(8) << data[i][j] << " ";
}
cout << "]" << endl;
}
}
Matrix2x2 add(const Matrix2x2& other) {
return Matrix2x2(
data[0][0] + other.data[0][0],
data[0][1] + other.data[0][1],
data[1][0] + other.data[1][0],
data[1][1] + other.data[1][1]
);
}
Matrix2x2 subtract(const Matrix2x2& other) {
return Matrix2x2(
data[0][0] - other.data[0][0],
data[0][1] - other.data[0][1],
data[1][0] - other.data[1][0],
data[1][1] - other.data[1][1]
);
}
Matrix2x2 multiply(const Matrix2x2& other) {
return Matrix2x2(
data[0][0]*other.data[0][0] + data[0][1]*other.data[1][0],
data[0][0]*other.data[0][1] + data[0][1]*other.data[1][1],
data[1][0]*other.data[0][0] + data[1][1]*other.data[1][0],
data[1][0]*other.data[0][1] + data[1][1]*other.data[1][1]
);
}
double determinant() {
return data[0][0]*data[1][1] - data[0][1]*data[1][0];
}
Matrix2x2 inverse() {
double det = determinant();
if (det == 0) throw runtime_error("Error: Matrix is not invertible!");
return Matrix2x2(
data[1][1]/det, -data[0][1]/det,
-data[1][0]/det, data[0][0]/det
);
}
};
// Complex number operations
class ComplexNumber {
public:
double real, imag;
ComplexNumber(double r = 0, double i = 0) : real(r), imag(i) {}
void display() {
cout << fixed << setprecision(2);
if (imag >= 0)
cout << real << " + " << imag << "i";
else
cout << real << " - " << -imag << "i";
}
ComplexNumber add(const ComplexNumber& other) {
return ComplexNumber(real + other.real, imag + other.imag);
}
ComplexNumber subtract(const ComplexNumber& other) {
return ComplexNumber(real - other.real, imag - other.imag);
}
ComplexNumber multiply(const ComplexNumber& other) {
return ComplexNumber(
real*other.real - imag*other.imag,
real*other.imag + imag*other.real
);
}
ComplexNumber divide(const ComplexNumber& other) {
double denominator = other.real*other.real + other.imag*other.imag;
if (denominator == 0) throw runtime_error("Error: Division by zero complex
number!");
return ComplexNumber(
(real*other.real + imag*other.imag)/denominator,
(imag*other.real - real*other.imag)/denominator
);
}
double magnitude() {
return sqrt(real*real + imag*imag);
}
double phase() {
return atan2(imag, real);
}
};
// Memory functions
void memoryStore(double value) { memory = value; }
double memoryRecall() { return memory; }
void memoryClear() { memory = 0; }
void memoryAdd(double value) { memory += value; }
void memorySubtract(double value) { memory -= value; }
// Display menu
void displayMenu() {
cout << "\n===== SCIENTIFIC CALCULATOR =====\n";
cout << "1. Basic Arithmetic (+, -, *, /)\n";
cout << "2. Power (x^y)\n";
cout << "3. Square Root\n";
cout << "4. Square (x^2)\n";
cout << "5. Cube (x^3)\n";
cout << "6. Logarithm (log10)\n";
cout << "7. Natural Logarithm (ln)\n";
cout << "8. Exponential (e^x)\n";
cout << "9. Modulo (%)\n";
cout << "10. Percentage\n";
cout << "11. Nth Root\n";
cout << "12. Trigonometric Functions\n";
cout << "13. Hyperbolic Functions\n";
cout << "14. Factorial\n";
cout << "15. Matrix Calculator (2x2)\n";
cout << "16. Complex Numbers\n";
cout << "17. Memory Functions\n";
cout << "18. Exit\n";
cout << "=================================\n";
}
};
int main() {
ScientificCalculator calc;
int choice;
bool running = true;
cout << fixed << setprecision(6);
while (running) {
calc.displayMenu();
cout << "Enter your choice (1-18): ";
cin >> choice;
try {
switch (choice) {
case 1: {
// Basic arithmetic
double a, b;
char op;
cout << "Enter first number: ";
cin >> a;
cout << "Enter operator (+, -, *, /): ";
cin >> op;
cout << "Enter second number: ";
cin >> b;
double result;
switch (op) {
case '+': result = calc.add(a, b); break;
case '-': result = calc.subtract(a, b); break;
case '*': result = calc.multiply(a, b); break;
case '/': result = calc.divide(a, b); break;
default: throw runtime_error("Invalid operator!");
}
cout << "Result: " << result << endl;
break;
}
case 2: {
// Power
double base, exponent;
cout << "Enter base: ";
cin >> base;
cout << "Enter exponent: ";
cin >> exponent;
cout << "Result: " << calc.power(base, exponent) << endl;
break;
}
case 3: {
// Square root
double x;
cout << "Enter number: ";
cin >> x;
cout << "Square root: " << calc.squareRoot(x) << endl;
break;
}
case 4: {
// Square
double x;
cout << "Enter number: ";
cin >> x;
cout << "Square: " << calc.square(x) << endl;
break;
}
case 5: {
// Cube
double x;
cout << "Enter number: ";
cin >> x;
cout << "Cube: " << calc.cube(x) << endl;
break;
}
case 6: {
// Log10
double x;
cout << "Enter number: ";
cin >> x;
cout << "Log10: " << calc.log10(x) << endl;
break;
}
case 7: {
// Natural log
double x;
cout << "Enter number: ";
cin >> x;
cout << "Natural log: " << calc.naturalLog(x) << endl;
break;
}
case 8: {
// Exponential
double x;
cout << "Enter exponent: ";
cin >> x;
cout << "e^" << x << " = " << calc.exponential(x) << endl;
break;
}
case 9: {
// Modulo
double a, b;
cout << "Enter first number: ";
cin >> a;
cout << "Enter second number: ";
cin >> b;
cout << "Modulo: " << calc.modulo(a, b) << endl;
break;
}
case 10: {
// Percentage
double value, percent;
cout << "Enter value: ";
cin >> value;
cout << "Enter percentage: ";
cin >> percent;
cout << percent << "% of " << value << " = " << calc.percentage(value, percent)
<< endl;
break;
}
case 11: {
// Nth root
double x, n;
cout << "Enter number: ";
cin >> x;
cout << "Enter root degree: ";
cin >> n;
cout << n << "th root of " << x << " = " << calc.nthRoot(x, n) << endl;
break;
}
case 12: {
// Trigonometric functions
int trigChoice;
cout << "1. Sine\n2. Cosine\n3. Tangent\n";
cout << "4. Inverse Sine\n5. Inverse Cosine\n6. Inverse Tangent\n";
cout << "Enter choice: ";
cin >> trigChoice;
double value;
cout << "Enter value (angles in radians for sin/cos/tan): ";
cin >> value;
switch (trigChoice) {
case 1: cout << "sin(" << value << ") = " << calc.sine(value) << endl; break;
case 2: cout << "cos(" << value << ") = " << calc.cosine(value) << endl;
break;
case 3: cout << "tan(" << value << ") = " << calc.tangent(value) << endl;
break;
case 4: cout << "asin(" << value << ") = " << calc.inverseSine(value) << endl;
break;
case 5: cout << "acos(" << value << ") = " << calc.inverseCosine(value) <<
endl; break;
case 6: cout << "atan(" << value << ") = " << calc.inverseTangent(value) <<
endl; break;
default: cout << "Invalid choice!\n";
}
break;
}
case 13: {
// Hyperbolic functions
int hypChoice;
cout << "1. Hyperbolic Sine\n2. Hyperbolic Cosine\n3. Hyperbolic Tangent\n";
cout << "Enter choice: ";
cin >> hypChoice;
double value;
cout << "Enter value: ";
cin >> value;
switch (hypChoice) {
case 1: cout << "sinh(" << value << ") = " << calc.hyperbolicSine(value) <<
endl; break;
case 2: cout << "cosh(" << value << ") = " << calc.hyperbolicCosine(value) <<
endl; break;
case 3: cout << "tanh(" << value << ") = " << calc.hyperbolicTangent(value)
<< endl; break;
default: cout << "Invalid choice!\n";
}
break;
}
case 14: {
// Factorial
int n;
cout << "Enter integer (0-20): ";
cin >> n;
cout << n << "! = " << calc.factorial(n) << endl;
break;
}
case 15: {
// Matrix calculator
ScientificCalculator::Matrix2x2 m1, m2;
int matrixChoice;
cout << "Enter first matrix (a b c d): ";
cin >> m1.data[0][0] >> m1.data[0][1] >> m1.data[1][0] >> m1.data[1][1];
cout << "Enter second matrix (a b c d): ";
cin >> m2.data[0][0] >> m2.data[0][1] >> m2.data[1][0] >> m2.data[1][1];
cout << "1. Add\n2. Subtract\n3. Multiply\n4. Determinant\n5. Inverse\n";
cout << "Enter choice: ";
cin >> matrixChoice;
switch (matrixChoice) {
case 1: {
ScientificCalculator::Matrix2x2 result = m1.add(m2);
cout << "Sum:\n"; result.display();
break;
}
case 2: {
ScientificCalculator::Matrix2x2 result = m1.subtract(m2);
cout << "Difference:\n"; result.display();
break;
}
case 3: {
ScientificCalculator::Matrix2x2 result = m1.multiply(m2);
cout << "Product:\n"; result.display();
break;
}
case 4: {
cout << "Determinant of matrix 1: " << m1.determinant() << endl;
cout << "Determinant of matrix 2: " << m2.determinant() << endl;
break;
}
case 5: {
cout << "Inverse of matrix 1:\n";
m1.inverse().display();
cout << "Inverse of matrix 2:\n";
m2.inverse().display();
break;
}
default: cout << "Invalid choice!\n";
}
break;
}
case 16: {
// Complex numbers
ScientificCalculator::ComplexNumber c1, c2;
int complexChoice;
cout << "Enter first complex number (real imag): ";
cin >> c1.real >> c1.imag;
cout << "Enter second complex number (real imag): ";
cin >> c2.real >> c2.imag;
cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Magnitude\n6. Phase\n";
cout << "Enter choice: ";
cin >> complexChoice;
switch (complexChoice) {
case 1: {
ScientificCalculator::ComplexNumber result = c1.add(c2);
cout << "Sum: "; result.display(); cout << endl;
break;
}
case 2: {
ScientificCalculator::ComplexNumber result = c1.subtract(c2);
cout << "Difference: "; result.display(); cout << endl;
break;
}
case 3: {
ScientificCalculator::ComplexNumber result = c1.multiply(c2);
cout << "Product: "; result.display(); cout << endl;
break;
}
case 4: {
ScientificCalculator::ComplexNumber result = c1.divide(c2);
cout << "Quotient: "; result.display(); cout << endl;
break;
}
case 5: {
cout << "Magnitude of first: " << c1.magnitude() << endl;
cout << "Magnitude of second: " << c2.magnitude() << endl;
break;
}
case 6: {
cout << "Phase of first: " << c1.phase() << " radians" << endl;
cout << "Phase of second: " << c2.phase() << " radians" << endl;
break;
}
default: cout << "Invalid choice!\n";
}
break;
}
case 17: {
// Memory functions
int memChoice;
cout << "1. Store to Memory\n2. Recall from Memory\n";
cout << "3. Add to Memory\n4. Subtract from Memory\n5. Clear Memory\n";
cout << "Enter choice: ";
cin >> memChoice;
if (memChoice == 2 || memChoice == 5) {
if (memChoice == 2)
cout << "Memory value: " << calc.memoryRecall() << endl;
else
calc.memoryClear();
} else {
double value;
cout << "Enter value: ";
cin >> value;
switch (memChoice) {
case 1: calc.memoryStore(value); break;
case 3: calc.memoryAdd(value); break;
case 4: calc.memorySubtract(value); break;
default: cout << "Invalid choice!\n";
}
}
break;
}
case 18:
running = false;
cout << "Thank you for using the Scientific Calculator!\n";
break;
default:
cout << "Invalid choice! Please try again.\n";
}
} catch (const exception& e) {
cout << e.what() << endl;
}
if (running) {
cout << "\nPress Enter to continue...";
cin.ignore();
cin.get();
}
}
return 0;
}
