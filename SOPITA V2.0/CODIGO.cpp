#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

#define cantidadPalabras 50
#define cantidadMaxLetras 11
#define maximoVeces 5

void CompletarSopaLetras(char matriz[10][10]) {
	Random dado;
	char letra;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matriz[i][j] = ' ';
		}
	}
}

int ContarPalabra(char palabras[cantidadPalabras][cantidadMaxLetras], int numeroDePalabra) {
	int cantidadLetras = 0;
	for (int i = 0; i < 10; i++) {
		if (palabras[numeroDePalabra][i] != '\0') {
			cantidadLetras++;
		}
	}
	return cantidadLetras;
}

bool PuedePonerPalabraHorizontal(char matriz[10][10], int comienzo, int numeroDePalabra, int fila, int cantidadLetras, bool forma) {
	if (forma == false) {
		for (int j = comienzo; j < comienzo + cantidadLetras; j++) {
			if (matriz[fila][j] != ' ') {
				return false;
			}
		}
		return true;
	}
	else {
		for (int j = comienzo; j >= comienzo - cantidadLetras; j--) {
			if (matriz[fila][j] != ' ') {
				return false;
			}
		}
		return true;
	}
}

bool PuedePonerPalabraVertical(char matriz[10][10], int comienzo, int numeroDePalabra, int columna, int cantidadLetras, bool forma) {
	if (forma == false) {
		for (int i = comienzo; i < comienzo + cantidadLetras; i++) {
			if (matriz[i][columna] != ' ') {
				return false;
			}
		}
		return true;
	}
	else {
		for (int i = comienzo; i >= comienzo - cantidadLetras; i--) {
			if (matriz[i][columna] != ' ') {
				return false;
			}
		}
		return true;
	}
}

void PalabraHorizontal(char palabras[cantidadPalabras][11], char matriz[10][10], int comienzo, int numeroDePalabra, int fila, bool forma, int cantidadLetras) {
	int indice = 0;
	if (forma == false) { //0
		for (int j = comienzo; j < comienzo + cantidadLetras; j++) {
			if (palabras[numeroDePalabra][indice] == '\0') {
				break;
			}
			else {
				matriz[fila][j] = palabras[numeroDePalabra][indice];
				indice++;
			}
		}
	}
	else { //1
		for (int j = comienzo; j >= comienzo - cantidadLetras; j--) {
			if (palabras[numeroDePalabra][indice] == '\0') {
				break;
			}
			else {
				matriz[fila][j] = palabras[numeroDePalabra][indice];
				indice++;
			}
		}
	}
}

void PalabraVertical(char palabras[cantidadPalabras][11], char matriz[10][10], int comienzo, int numeroDePalabra, int columna, bool forma, int cantidadLetras) {
	int indice = 0;
	if (forma == false) { //0
		for (int i = comienzo; i < comienzo + cantidadLetras; i++) {
			if (palabras[numeroDePalabra][indice] == '\0') {
				break;
			}
			else {
				matriz[i][columna] = palabras[numeroDePalabra][indice];
				indice++;
			}
		}
	}
	else {
		for (int i = comienzo; i >= comienzo - cantidadLetras; i--) {
			if (palabras[numeroDePalabra][indice] == '\0') {
				break;
			}
			else {
				matriz[i][columna] = palabras[numeroDePalabra][indice];
				indice++;
			}
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
		cout << "F" << i+1;
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

bool EstaEnArray(char array[][11], int totalGuardadas, char palabraBuscada[]) {
	for (int i = 0; i < totalGuardadas; i++) {
		if (SonIguales(array[i], palabraBuscada)) {
			return true;
		}
	}
	return false;
}

void BuscarPalabra(int cantidadMax, char encontradaPalabra[], char matriz[10][10], int c1, int c2, int f1, int f2) {
	if (c1 - 1 == c2 - 1) {
		if (f1 - 1 > f2 - 1) {
			for (int i = 0; i < cantidadMax; i++) {
				encontradaPalabra[i] = '\0';
			}

			int indice = 0;
			for (int j = f1 - 1; j >= f2 - 1; j--) {
				encontradaPalabra[indice] = matriz[j][c1 - 1];
				indice++;
			}
			encontradaPalabra[indice] = '\0';

			cout << "Palabra encontrada: " << encontradaPalabra << endl;
		}
		else {
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
	}
	else if (f1 - 1 == f2 -1) {
		if (c1 - 1 > c2 - 1) {
			for (int i = 0; i < cantidadMax; i++) {
				encontradaPalabra[i] = '\0';
			}

			int indice = 0;
			for (int j = c1 - 1; j >= c2 - 1; j--) {
				encontradaPalabra[indice] = matriz[f1 - 1][j];
				indice++;
			}
			encontradaPalabra[indice] = '\0';

			cout << "Palabra encontrada: " << encontradaPalabra << endl;
		}
		else {
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
	}
	else {
		cout << "Coordenadas invalidas. ";
	}
}

void PasarPalabraRecogida(char palabras[cantidadPalabras][11], char palabrasrecogidas[5][11], int indice, int cantidadRecogidas) {
	for (int j = 0; j < 11; j++) {
		palabrasrecogidas[cantidadRecogidas][j] = palabras[indice][j];
		if (palabras[indice][j] == '\0') break;
	}
}

int colocarPalabrasEnSopa(char matriz[10][10], char palabras[cantidadPalabras][11], char palabrasrecogidas[5][11]) {
	Random dado;
	int veces = dado.Next(3, 6);
	int bucles = 0;
	char PalabrasColocadas[maximoVeces][11];
	int NumeroDePalabrasPorEncontrar = 0;

	cout << "--- PALABRAS POR BUSCAR --- " << endl;

	while (bucles < veces) {
		int numeroDePalabra = dado.Next(0, cantidadPalabras); //Generar el numero de Palabra aleatoriamente
		int cantidadLetras = ContarPalabra(palabras, numeroDePalabra); //Funcion para saber la cantidad de letras de la palabra escogida
		bool verOhori = dado.Next(0, 2); //Generar si la palabra va horizontal o verticalmente | 0 = vertical y 1 = horizontal
		bool normOinvert = dado.Next(0, 2); //Generar si la palabra se pondra normal o invertido| 0 = norm y 1 = inver
		int comienzo = 0;

		if (normOinvert == false) {
			comienzo = dado.Next(0, 11 - cantidadLetras);
		}
		else {
			comienzo = dado.Next(cantidadLetras - 1, 10);
		}

		if (verOhori == true) {
			int fila = dado.Next(0, 10);
			if (!PuedePonerPalabraHorizontal(matriz, comienzo, numeroDePalabra, fila, cantidadLetras, normOinvert)) {
				continue;
			}
			else if (LaPalabraFueColocada(palabras, numeroDePalabra, PalabrasColocadas, NumeroDePalabrasPorEncontrar)) {
				continue;
			}
			else {
				YaSeColocoPalabra(palabras, numeroDePalabra, PalabrasColocadas, NumeroDePalabrasPorEncontrar);
				NumeroDePalabrasPorEncontrar++;
				PalabraHorizontal(palabras, matriz, comienzo, numeroDePalabra, fila, normOinvert, cantidadLetras);
				PasarPalabraRecogida(palabras, palabrasrecogidas, numeroDePalabra, bucles);
			}
		}

		else {
			int columna = dado.Next(0, 10);
			if (!PuedePonerPalabraVertical(matriz, comienzo, numeroDePalabra, columna, cantidadLetras, normOinvert)) {
				continue;
			}
			else if (LaPalabraFueColocada(palabras, numeroDePalabra, PalabrasColocadas, NumeroDePalabrasPorEncontrar)) {
				continue;
			}
			else {
				YaSeColocoPalabra(palabras, numeroDePalabra, PalabrasColocadas, NumeroDePalabrasPorEncontrar);
				NumeroDePalabrasPorEncontrar++;
				PalabraVertical(palabras, matriz, comienzo, numeroDePalabra, columna, normOinvert, cantidadLetras);
				PasarPalabraRecogida(palabras, palabrasrecogidas, numeroDePalabra, bucles);
			}
		}
		cout << " " << bucles + 1 << ". " << palabrasrecogidas[bucles] << endl;
		bucles++;
	}
	return bucles;
}

void LlenarEspaciosVacios(char matriz[10][10]) {
	Random dado;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (matriz[i][j] == ' ')
				matriz[i][j] = char(dado.Next(65, 91)); // A-Z
		}
	}
}

void SopaJugar(char matriz[10][10], char palabrasrecogidas[5][11], int NumeroDePalabrasEnSopa) {
	int cantidadMax = 10;
	char posPalabra[cantidadMaxLetras];
	char encontradaPalabra[cantidadMaxLetras];
	int f1 = 0, c1 = 0, f2 = 0, c2 = 0;
	char palabrasencontradas[maximoVeces][cantidadMaxLetras] = { 0 };//Array donde se meteran las palabras encontradas
	int jugadas = 0; //Cantidad de veces jugadas

	do {
		bool entradaValida;
		do {
			entradaValida = true; // asumimos que todo está bien al inicio

			cout << "Ingrese la palabra encontrada: ";
			cin >> posPalabra;

			if (!EstaEnArray(palabrasrecogidas, NumeroDePalabrasEnSopa, posPalabra)) {
				cout << "La palabra no es valida. Intente nuevamente." << endl;
				entradaValida = false;
				continue; // vuelve a pedir palabra
			}

			cout << "---POSICION DE INICIO (Fx, Cy)---" << endl;
			cout << "Ingrese la coordenada Fx: F"; cin >> f1;
			cout << "Ingrese la coordenada Cy: C"; cin >> c1;
			cout << "---POSICION DE FINAL (Fx, Cy)---" << endl;
			cout << "Ingrese la coordenada Fx: F"; cin >> f2;
			cout << "Ingrese la coordenada Cy: C"; cin >> c2;

			if (f1 < 1 || f1 > 10 || f2 < 1 || f2 > 10 || c1 < 1 || c1 > 10 || c2 < 1 || c2 > 10) {
				cout << "Coordenadas invalidas. Intente nuevamente." << endl;
				entradaValida = false; // marcamos como no válida
			}

		} while (!entradaValida);

		BuscarPalabra(cantidadMax, encontradaPalabra, matriz, c1, c2, f1, f2);
		if (EstaEnArray(palabrasencontradas, jugadas, posPalabra)) {
			cout << "Esta palabra ya fue buscada! Intenta con otra palabra" << endl;
			continue;
		}

		if (SonIguales(posPalabra, encontradaPalabra)) {
			cout << "La palabra es correcta!" << endl;
			for (int j = 0; j < 11; j++) {
				palabrasencontradas[jugadas][j] = posPalabra[j];
				if (posPalabra[j] == '\0') break;
			}
			jugadas++;
		}
		else {
			cout << "La palabra es incorrecta!" << endl;
			continue;
		}

		if (jugadas == NumeroDePalabrasEnSopa) {
			cout << "!FELICIDADES! LOGRASTE GANAR EL JUEGO :)" << endl;
		}
	} while (jugadas < NumeroDePalabrasEnSopa);
}

void EmpezarJugar() {
	Random dado;
	char matriz[10][10];
	char palabrasrecogidas[5][11];

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

	int NumeroDePalabrasEnSopa = colocarPalabrasEnSopa(matriz, palabras, palabrasrecogidas);

	cout << endl;

	LlenarEspaciosVacios(matriz);

	MostrarMatriz(matriz);

	SopaJugar(matriz, palabrasrecogidas, NumeroDePalabrasEnSopa);
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

	int opcion;
	do {
		cout << R"(
     _ _  _  _    
    | | |(/_| ||_|  
                  )" << endl;
		cout << " 1. Jugar sopa de letras" << endl;
		cout << " 2. Ver creditos" << endl;
		cout << " 3. Salir" << endl;
		cout << "Ingrese su opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1:
			cout << R"(

   ____ _  _ ___  _ ____ ___  ____    ____ _        _ _  _ ____ ____ ____   /
   |___ |\/| |__] | |___   /  |__|    |___ |        | |  | |___ | __ |  |  / 
   |___ |  | |    | |___  /__ |  |    |___ |___    _| |__| |___ |__] |__| .  

)" << endl;
			EmpezarJugar();
			break;
		case 2:
			cout << R"(
   _ _ _  _|._|_ _  _
  (_| (/_(_|| | (_)_\           
                      )" << endl;
			cout << "Juego desarrollado por: Joseph Carranza (Wiwi)" << endl;
			cout << "Curso: Lenguaje de Programacion" << endl;
			cout << "Ciclo: 2025-2" << endl;
			break;
		case 3:
			cout << "Saliendo del juego..." << endl;
			break;
		default:
			cout << "Opcion invalida. Intente nuevamente." << endl;
		}
	} while (opcion != 3);

	_getch();
	return 0;
}