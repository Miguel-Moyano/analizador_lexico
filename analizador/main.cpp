#include <iostream>
#include <fstream>
#include <map>
using namespace std;
bool funcion(std::string cadena, int matriz[][3], int estInicial = 0, int estFinal = 1);
int main()
{
    std::map<std::string,std::string> palabrasReservadas;
    palabrasReservadas.insert(std::make_pair("var","Palabra reservada var"));
    palabrasReservadas.insert(std::make_pair("else","Palabra reservada else"));
    palabrasReservadas.insert(std::make_pair("if","Palabra reservada if"));
    int matriz[3][3]; // 0 -> DÃ­gito; 1 -> Letra; 2 -> Otro
    matriz[0][0] = 2; matriz[0][1] = 1; matriz[0][2] = 2;
    matriz[1][0] = 1; matriz[1][1] = 1; matriz[1][2] = 2;
    matriz[0][0] = 2; matriz[0][1] = 2; matriz[0][2] = 2;

    std::ifstream archivo("codigo.txt");
    if (archivo.is_open()){
        std::string linea,palabra;
        int espacio;
        while (!archivo.eof()){
            getline(archivo,linea);
            espacio = 0;
            while (espacio != -1){
                espacio = linea.find(" ");
                palabra = linea.substr(0,espacio);
                linea = linea.substr(espacio+1,linea.size()-espacio);
                //std::cout<<palabra<<std::endl;
                if (palabrasReservadas.count(palabra)){  //antes podria preguntar si es un igual por ejemplo, y ver si despues viene otro igual
                    std::cout<<"Palabra reservada: "<<palabra<<" -> "<<palabrasReservadas.find(palabra)->second<<std::endl;
                }
                else if (funcion(palabra,matriz)){
                    std::cout<<"Identificador Valido -> "<<palabra<<std::endl;
                }
            }
        }
    }
    return 0;
}

bool funcion(std::string cadena, int matriz[][3], int estInicial, int estFinal){
    if (cadena[0]>122 or (cadena[0]<97 and cadena[0]>90) or cadena[0]<65){
        return false;
    }
    else{
        int estado = estInicial;
        for (int c=0; c<int(cadena.size()); c++){
            if ((cadena[c]>64 and cadena[c]<91) or (cadena[c]>96 and cadena[c]<123) or (cadena[c]>47 and cadena[c]<58)){ //si es una letra
                estado = matriz[1][estado];
            }
            else return false;
        }
    }
    return true;
    return 0;
}
