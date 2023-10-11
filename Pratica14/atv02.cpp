#include <iostream>

using namespace std;

double ConvertercelsiusParaFahrenheit(double temperaturaCelsius);
double obterTemperaturaCelsius();
void MostrarResultado(double temperaturaCelsius, double temperaturaFahrenheit);
int main() {
    double celsius, fahrenheit;

    celsius = obterTemperaturaCelsius(); 
    fahrenheit = ConvertercelsiusParaFahrenheit(celsius);   
    MostrarResultado(celsius, fahrenheit); 

    return 0;
}

double ConvertercelsiusParaFahrenheit(double temperaturaCelsius) {
    double fahrenhei;
        fahrenhei = (temperaturaCelsius * 9.0 / 5.0) + 32.0;
    return fahrenhei;
}

double obterTemperaturaCelsius() {
    double temperatura;
    cout << "Digite a temperatura em graus Celsius: ";
    cin >> temperatura;
    return temperatura;
}

void MostrarResultado(double temperaturaCelsius, double temperaturaFahrenheit) {
    cout << temperaturaCelsius << " graus Celsius sao equivalentes a " << temperaturaFahrenheit << " graus Fahrenheit." << endl;
}