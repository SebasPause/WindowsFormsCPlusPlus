// pch.cpp: el archivo de código fuente correspondiente al encabezado precompilado

#include "PrimeraVersionLib.h"
#include <fstream>
#include <cstring>
#include <iostream>

// Cuando se utilizan encabezados precompilados, se requiere este archivo de código fuente para que la compilación se realice correctamente.
namespace PrimeraVersionLib {
    bool CompressFile(const char* src, const char* dst) {
        // Abre el archivo de origen en modo binario
        std::ifstream inFile(src, std::ios::binary);
        if (!inFile) {
            return false;
        }

        // Abre el archivo de destino en modo binario
        std::ofstream outFile(dst, std::ios::binary);
        if (!outFile) {
            return false;
        }

        // Tamaño del buffer (128 KB)
        const int bufferSize = 128 * 1024;
        char inBuffer[bufferSize];
        char outBuffer[bufferSize];

        // Leer y escribir en bloques hasta alcanzar el final del archivo
        while (inFile) {
            // Leer un bloque del archivo de origen
            inFile.read(inBuffer, bufferSize);
            std::streamsize bytesRead = inFile.gcount(); // Número de bytes leídos

            // Verifica si leímos algo antes de escribir
            if (bytesRead > 0) {
                // Copia el contenido del inBuffer a outBuffer si es necesario
                std::copy(inBuffer, inBuffer + bytesRead, outBuffer);

                // Escribir los bytes leídos al archivo de destino
                outFile.write(outBuffer, bytesRead);
            }

            // Manejar cualquier error de escritura
            if (!outFile.good()) {
                std::cerr << "Error: Ocurrió un problema al escribir en el archivo de destino." << std::endl;
                return false;
            }
        }

        // Cerrar los archivos
        inFile.close();
        outFile.close();

        return true;
    }
}