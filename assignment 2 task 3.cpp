#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumber {
private:
    int* real;
    int* imaginary;

public:
    // Default constructor
    ComplexNumber() : real(new int(0)), imaginary(new int(0)) {
        cout << "Default Constructor Called: " << *real << " + " << *imaginary << "i" << endl;
    }

    // Parameterized constructor
    ComplexNumber(int r, int i) : real(new int(r)), imaginary(new int(i)) {
        cout << "Parameterized Constructor Called: " << *real << " + " << *imaginary << "i" << endl;
    }

    // Destructor
    ~ComplexNumber() {
        delete real;
        delete imaginary;
        cout << "Destructor Called: " << *real << " + " << *imaginary << "i" << endl;
    }

    // Setter for real part
    void setReal(int r) {
        *real = r;
    }

    // Setter for imaginary part
    void setImaginary(int i) {
        *imaginary = i;
    }

    // Getter for real part
    int getReal() {
        return *real;
    }

    // Getter for imaginary part
    int getImaginary() {
        return *imaginary;
    }

    // Copy constructor
    ComplexNumber(const ComplexNumber& other) : real(new int(*other.real)), imaginary(new int(*other.imaginary)) {
        cout << "Copy Constructor Called: " << *real << " + " << *imaginary << "i" << endl;
    }

    // Input function
    void Input() {
        cout << "Enter real part: ";
        cin >> *real;
        cout << "Enter imaginary part: ";
        cin >> *imaginary;
    }

    // Output function
    void Output() {
        cout << *real << " + " << *imaginary << "i" << endl;
    }

    // Magnitude function
    float Magnitude() {
        return sqrt(pow(*real, 2) + pow(*imaginary, 2));
    }
};

int main() {
    // Task 2
    ComplexNumber c1;
    c1.Input();
    c1.Output();

    // Task 3
    ComplexNumber* cPtr;
    // No implicit constructor call

    // Task 4
    cPtr = new ComplexNumber(3, 5);
    cPtr->Output();

    // Task 5
    ComplexNumber cArray[5];
    for (int i = 0; i < 5; i++) {
        cArray[i].Input();
        cArray[i].Output();
        cout << "Magnitude: " << cArray[i].Magnitude() << endl;
    }

    // Task 6
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    ComplexNumber* dynamicArray = new ComplexNumber[size];
    for (int i = 0; i < size; i++) {
        dynamicArray[i].Input();
        dynamicArray[i].Output();
        cout << "Magnitude: " << dynamicArray[i].Magnitude() << endl;
    }
    delete[] dynamicArray;

    return 0;
}