#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
class Vector
{
public:
    Vector(int size);

    double calculateNorm();

    void inputValues();

    void displayValues();

    void add(Vector first, Vector second);

    void subtract(Vector first, Vector second);

    void calculateScalarProduct(Vector first, Vector second);

    void multiplyByScalar(Vector vec, double scalar);

    void elementwiseMultiply(Vector vec, double scalar);

private:
    std::vector<double> values;
    int size;
};

Vector::Vector(int size1) : values(size1), size(size1) {}

void Vector::add(Vector a, Vector b)
{
    for (int i = 0; i < values.size(); i++)
    {
        values[i] = a.values[i] + b.values[i];
        std::cout << values[i] << " ";
    }
    std::cout << "\n";
}

void Vector::subtract(Vector a, Vector b)
{
    for (int i = 0; i < values.size(); i++)
    {
        values[i] = a.values[i] - b.values[i];
        std::cout << values[i] << " ";
    }
    std::cout << "\n";
}

void Vector::calculateScalarProduct(Vector a, Vector b)
{
    double dotProduct = 0;

    for (int i = 0; i < values.size(); i++)
    {
        dotProduct += a.values[i] * b.values[i];
    }

    std::cout << dotProduct << "\n";
}

void Vector::multiplyByScalar(Vector vec, double scalar)
{
    for (int i = 0; i < values.size(); i++)
    {
        values[i] = vec.values[i] * scalar;
        std::cout << values[i] << " ";
    }
    std::cout << "\n";
}

void Vector::elementwiseMultiply(Vector vec, double scalar)
{
    for (int i = 0; i < values.size(); i++)
    {
        values[i] = vec.values[i] * scalar;
        std::cout << values[i] << " ";
    }
    std::cout << "\n";
}

double Vector::calculateNorm()
{
    double norm = 0;

    for (int i = 0; i < values.size(); i++)
    {
        norm += pow(values[i], 2);
    }

    norm = sqrt(norm);

    return norm;
}

void Vector::inputValues()
{
    for (int i = 0; i < values.size(); i++)
    {
        std::cin >> values[i];
    }
}

void Vector::displayValues()
{
    for (int i = 0; i < values.size(); i++)
    {
        std::cout << values[i] << " ";
    }
}

int main()
{
    int size;

    double scalar;

    std::cin >> size;

    Vector vector1(size);
    Vector vector2(size);
    Vector vector3(size);

    vector1.inputValues();
    vector2.inputValues();

    std::cin >> scalar;

    std::cout << "vector1= ";
    vector1.displayValues();
    std::cout << "norma= " << vector1.calculateNorm() << "\n";

    std::cout << "vector2= ";
    vector2.displayValues();
    std::cout << "norma= " << vector2.calculateNorm() << "\n";

    std::cout << "summa= ";
    vector3.add(vector1, vector2);

    std::cout << "raznost= ";
    vector3.subtract(vector1, vector2);

    std::cout << "scalar= ";
    vector3.calculateScalarProduct(vector1, vector2);

    std::cout << "mult chislo * Vector1= ";
    vector3.multiplyByScalar(vector1, scalar);

    std::cout << "mult chislo * Vector2= ";
    vector3.elementwiseMultiply(vector2, scalar);

    if (vector1.calculateNorm() == vector2.calculateNorm())
    {
        std::cout << "norma(Vector1) = norma(Vector2)" << "\n";
    }

    if (vector1.calculateNorm() > vector2.calculateNorm())
    {
        std::cout << "norma(Vector1) > norma(Vector2)" << "\n";
    }

    if (vector1.calculateNorm() < vector2.calculateNorm())
    {
        std::cout << "norma(Vector1) < norma(Vector2)" << "\n";
    }

    return 0;
}
