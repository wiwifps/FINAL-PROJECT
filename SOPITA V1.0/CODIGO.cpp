#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

#define cantidadPalabras 50

void CompletarSopaLetras(char matriz[10][10]) {
	Random dado;
	char letra;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matriz[i][j] = '#';
		}
	}
}

int ContarPalabra(char palabras[cantidadPalabras][11], int numeroDePalabra) {
	int cantidadLetras = 0;
	for (int i = 0; i < 10; i++) {
		if (palabras[numeroDePalabra][i] != '\0') {
			cantidadLetras++;
		}
	}
	return cantidadLetras;
}

bool PuedePonerPalabraHorizontal(char matriz[10][10], int comienzo, int numeroDePalabra, int fila, int cantidadLetras) {
	for (int j = comienzo; j < comienzo + cantidadLetras; j++) {
		if (matriz[fila][j] != '#') {
			return false;
		}
	}
	return true;
}

bool PuedePonerPalabraVertical(char matriz[10][10], int comienzo, int numeroDePalabra, int columna, int cantidadLetras) {
	for (int i = comienzo; i < comienzo + cantidadLetras; i++) {
		if (matriz[i][columna] != '#') {
			return false;
		}
	}
	return true;
}

void PalabraHorizontal(char palabras[cantidadPalabras][11], char matriz[10][10], int comienzo, int numeroDePalabra, int fila) {
	int contador = 0;
	for (int j = comienzo; j < 10; j++) {
		if (palabras[numeroDePalabra][contador] == '\0') {
			break;
		}
		else {
			matriz[fila][j] = palabras[numeroDePalabra][contador];
			contador++;
		}
	}
}

void PalabraVertical(char palabras[cantidadPalabras][11], char matriz[10][10], int comienzo, int numeroDePalabra, int columna) {
	int contador = 0;
	for (int i = comienzo; i < 10; i++) {
		if (palabras[numeroDePalabra][contador] == '\0') {
			break;
		}
		else {
			matriz[i][columna] = palabras[numeroDePalabra][contador];
			contador++;
		}
	}
}

void YaSeColocoPalabra(char palabras[cantidadPalabras][11], int numeroDePalabra, char PalabrasColocadas[5][11], int indice) {
	int i = 0;
	while (i < 10 && palabras[numeroDePalabra][i] != '\0') {
		PalabrasColocadas[indice][i] = palabras[numeroDePalabra][i];
		i++;
	}
	PalabrasColocadas[indice][i] = '\0';
}

bool LaPalabraFueColocada(char palabras[cantidadPalabras][11], int numeroDePalabra, char PalabrasColocadas[5][11], int totalGuardadas) {
	for (int k = 0; k < totalGuardadas; k++) {
		int i = 0;
		bool iguales = true;

		while (palabras[numeroDePalabra][i] != '\0' || PalabrasColocadas[k][i] != '\0') {
			if (palabras[numeroDePalabra][i] != PalabrasColocadas[k][i]) {
				iguales = false;
				break;
			}
			i++;
		}

		if (iguales) return true;
	}
	return false;
}

void MostrarMatriz(char matriz[10][10]) {
	for (int i = 0; i < 10; i++) {
		if (i == 0) {
			cout << "[F/C]";
			for (int j = 0; j < 10; j++) {
				cout << "\tC" << j + 1;
			}
			cout << endl << endl;
		}
		cout << "F" << i + 1;
		for (int j = 0; j < 10; j++) {
			cout << "\t" << matriz[i][j];
		}
		cout << endl << endl;
	}
}

bool SonIguales(char a[], char b[]) {
	int i = 0;
	while (a[i] != '\0' && b[i] != '\0') {
		if (a[i] != b[i]) {
			return false;
		}
		i++;
	}
	return (a[i] == '\0' && b[i] == '\0');
}

bool EstaEnArray(char palabras[cantidadPalabras][11], char palabraBuscada[]) {
	for (int i = 0; i < cantidadPalabras; i++) {
		if (SonIguales(palabras[i], palabraBuscada)) {
			return true;
		}
	}
	return false;
}

void BuscarPalabra(int cantidadMax, char encontradaPalabra[], char matriz[10][10], int c1, int c2, int f1, int f2) {
	if (c1 - 1 == c2 - 1) {
		for (int i = 0; i < cantidadMax; i++) {
			encontradaPalabra[i] = '\0';
		}

		int indice = 0;
		for (int j = f1 - 1; j <= f2 - 1; j++) {
			encontradaPalabra[indice] = matriz[j][c1 - 1];
			indice++;
		}
		encontradaPalabra[indice] = '\0';

		cout << "Palabra encontrada: " << encontradaPalabra << endl;
	}
	else if (f1 - 1 == f2 - 1) {
		for (int i = 0; i < cantidadMax; i++) {
			encontradaPalabra[i] = '\0';
		}

		int indice = 0;
		for (int j = c1 - 1; j <= c2 - 1; j++) {
			encontradaPalabra[indice] = matriz[f1 - 1][j];
			indice++;
		}
		encontradaPalabra[indice] = '\0';

		cout << "Palabra encontrada: " << encontradaPalabra << endl;
	}
	else {
		cout << "Coordenadas invalidas. ";
	}
}

int main() {

	cout << R"( 
	 ____    _____   ____    ______  ______  ______     
	/\  _`\ /\  __`\/\  _`\ /\__  _\/\__  _\/\  _  \    
	\ \,\L\_\ \ \/\ \ \ \L\ \/_/\ \/\/_/\ \/\ \ \L\ \   
	 \/_\__ \\ \ \ \ \ \ ,__/  \ \ \   \ \ \ \ \  __ \  
	   /\ \L\ \ \ \_\ \ \ \/    \_\ \__ \ \ \ \ \ \/\ \ 
	   \ `\____\ \_____\ \_\    /\_____\ \ \_\ \ \_\ \_\
	    \/_____/\/_____/\/_/    \/_____/  \/_/  \/_/\/_/                                       

)" << endl;

	Random dado;
	char matriz[10][10];

	char palabras[cantidadPalabras][11] = {
		"CASA", "PERRO", "GATO", "LAPIZ", "MANZANA",
		"CONFIANZA", "TECLADO", "MONITOR", "CUADERNO", "PROGRAMA",
		"JUEGO", "MESA", "SILLA", "BIBLIA", "COLEGIO",
		"PRESIDENTE", "ARQUITECTO", "MARIPOSA", "CARRO", "TELEVISOR",
		"SOL", "MAR", "PEZ", "RIO", "FLOR",
		"NUBE", "CIELO", "FUEGO", "ROCA", "NIEVE",
		"HOJA", "RANA", "MONO", "PIANO", "AVE",
		"AGUA", "CAMINO", "LIBRO", "ZAPATO", "VENTANA",
		"PUERTA", "RELOJ", "BOTELLA", "PLANTA", "CULTURA",
		"PAPEL", "CELULAR", "MUNDO", "TIEMPO", "FAMILIA"
	};

	CompletarSopaLetras(matriz);

	int veces = dado.Next(3, 6);
	int bucles = 0;

	char PalabrasColocadas[5][11];
	int NumeroDePalabrasPorEncontrar = 0;

	cout << "PALABRAS POR BUSCAR: " << endl;

	while (bucles < veces) {
		int numeroDePalabra = dado.Next(0, cantidadPalabras); //Generar el numero de Palabra aleatoriamente
		int cantidadLetras = ContarPalabra(palabras, numeroDePalabra); //Funcion para saber la cantidad de letras de la palabra escogida
		bool verOhori = dado.Next(0, 2); //Generar si la palabra va horizontal o verticalmente
		int comienzo = dado.Next(0, 11 - cantidadLetras); //Generar el comienzo de la palabra dependiendo de la cantidad de letras que tenga

		if (verOhori == true) {
			int fila = dado.Next(0, 10);
			if (!PuedePonerPalabraHorizontal(matriz, comienzo, numeroDePalabra, fila, cantidadLetras)) {
				continue;
			}
			else if (LaPalabraFueColocada(palabras, numeroDePalabra, PalabrasColocadas, NumeroDePalabrasPorEncontrar)) {
				continue;
			}
			else {
				YaSeColocoPalabra(palabras, numeroDePalabra, PalabrasColocadas, NumeroDePalabrasPorEncontrar);
				NumeroDePalabrasPorEncontrar++;
				PalabraHorizontal(palabras, matriz, comienzo, numeroDePalabra, fila);
			}
		}

		else {
			int columna = dado.Next(0, 10);
			if (!PuedePonerPalabraVertical(matriz, comienzo, numeroDePalabra, columna, cantidadLetras)) {
				continue;
			}
			else if (LaPalabraFueColocada(palabras, numeroDePalabra, PalabrasColocadas, NumeroDePalabrasPorEncontrar)) {
				continue;
			}
			else {
				YaSeColocoPalabra(palabras, numeroDePalabra, PalabrasColocadas, NumeroDePalabrasPorEncontrar);
				NumeroDePalabrasPorEncontrar++;
				PalabraVertical(palabras, matriz, comienzo, numeroDePalabra, columna);
			}
		}
		bucles++;
		cout << " " << bucles << ". " << palabras[numeroDePalabra] << endl;
	}

	MostrarMatriz(matriz);

	int cantidadMax = 10;
	char posPalabra[10];
	char encontradaPalabra[10];
	int f1 = 0, c1 = 0, f2 = 0, c2 = 0;

	do {
		cout << "Ingrese la palabra encontrada: "; cin >> posPalabra;
		if (!EstaEnArray(palabras, posPalabra)) {
			cout << "La palabra no es valida. Intente nuevamente." << endl;
			continue;
		}
		cout << "---POSICION DE INICIO (Fx, Cy)---" << endl;
		cout << "Ingrese la coordenada Fx: F"; cin >> f1;
		cout << "Ingrese la coordenada Cy: C"; cin >> c1;
		cout << "---POSICION DE FINAL (Fx, Cy)---" << endl;
		cout << "Ingrese la coordenada Fx: F"; cin >> f2;
		cout << "Ingrese la coordenada Cy: C"; cin >> c2;
		if (f1 < 1 || f1 > 10 || f2 < 1 || f2 > 10 || c1 < 1 || c1 > 10 || c2 < 1 || c2 > 10) {
			cout << "Coordenadas inválidas. Intente nuevamente." << endl;
			continue;
		}
	} while (!EstaEnArray(palabras, posPalabra));

	BuscarPalabra(cantidadMax, encontradaPalabra, matriz, c1, c2, f1, f2);

	if (SonIguales(posPalabra, encontradaPalabra)) {
		cout << "La palabra es correcta!" << endl;
	}
	else {
		cout << "La palabra es incorrecta!" << endl;
	}

	_getch();
}