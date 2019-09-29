// Solución (parcial) al ejercicio 1

// autor: Alberto Hamilton Castro
// fecha: 2019-09-24

#include <iostream>   // std::cout std::cerr std::endl
#include <fstream>    // std::ifstream
#include <vector>     // std::vector<>
#include <string>     // std::string

int cuentaMayores(const std::vector<int>& datos, int pivote = 10) {
  int cuenta = 0;

  for(std::size_t i = 0; i < datos.size(); i++) {
    std::cerr << "Considerando elemento " << i
      << " con valor " << datos[i] << std::endl;
    if(datos[i] > pivote) {
      std::cerr << " es mayor que el pivote " << pivote << std::endl;
      cuenta++;
    }
  }

  return cuenta;
}

int main(int argc, char* argv[]) {

  if (argc < 2) {
    std::cout << "Necesario al menos un párametro con el nombre "
        << "del fichero" << std::endl;
    // Tenemos que salir del programa, para ello basta con
    //  salir del main (return) el valor devuelto, por convenio,
    //  debe ser distinto de 0 para indicar un problema
    return 1;
  }

  std::string nombre = argv[1];
  std::cerr << "Fichero a abrir: '" << nombre << "'" << std::endl;

  int pivote = 10;
  if (argc >= 3)
    pivote = std::stoi(argv[2]);
  std::cerr << "Pivote considerado: " << pivote << std::endl;

  std::ifstream fent(nombre);

  if (fent.fail()) {
    std::cout << "No se pudo abrir el fichero" << std::endl;
    return 2;
  }

  //fichero abierto correctamente
  std::vector<int> datos;
  int valor;

  fent >> valor;
  while(fent.good()) {
    datos.push_back(valor);
    std::cerr << "Leido dato " << valor << std::endl;
    fent >> valor;
  }
  std::cerr << "Se han leido " << datos.size() << " datos." << std::endl;

  int numMayores = cuentaMayores(datos, pivote);

  std::cout << "Pivote: " << pivote << std::endl;
  std::cout << "Resultado: " << numMayores << std::endl;

}
