#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string encryptMessage(string key, string message) {
	// Eliminar espacios en el mensaje
	message.erase(remove(message.begin(), message.end(), ' '), message.end());
	
	// Calcular la longitud de la clave
	int key_length = key.length();
	
	// Agregar caracteres de relleno si la longitud del mensaje no es un múltiplo de la longitud de la clave
	if (message.length() % key_length != 0) {
		message += string(key_length - message.length() % key_length, ' ');
	}
	
	// Crear un vector para almacenar el mensaje cifrado
	vector<vector<char>> matrix(key_length, vector<char>(message.length() / key_length));
	
	// Llenar la matriz con el mensaje cifrado
	for (int i = 0; i < message.length(); i++) {
		matrix[i % key_length][i / key_length] = message[i];
	}
	
	// Ordenar las columnas de la matriz según la clave
	vector<int> sorted_columns(key_length);
	for (int i = 0; i < key_length; i++) {
		sorted_columns[i] = i;
	}
	sort(sorted_columns.begin(), sorted_columns.end(), [&key](int a, int b) {return key[a] < key[b];});
	
	// Concatenar los caracteres de las columnas ordenadas para formar el mensaje cifrado
	string encrypted_message;
	for (int i = 0; i < matrix[0].size(); i++) {
		for (int j = 0; j < key_length; j++) {
			encrypted_message += matrix[sorted_columns[j]][i];
		}
	}
	
	return encrypted_message;
}

int main() {
	// Pedir la clave y el mensaje al usuario
	string key, message;
	cout << "Introduce la clave: ";
	getline(cin, key);
	cout << "Introduce el mensaje a cifrar: ";
	getline(cin, message);
	
	// Cifrar el mensaje con la clave dada
	string encrypted_message = encryptMessage(key, message);
	
	// Imprimir el mensaje cifrado
	cout << "Mensaje cifrado: " << encrypted_message << endl;
	
	return 0;
}
