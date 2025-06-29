// tratamento.h
#ifndef TRATAMENTO_H
#define TRATAMENTO_H

#include <stddef.h>

// Idioma: 0 = Ingles, 1 = Portugues.

// Normaliza palavra conforme idioma: converte minusculas, trata acentos e cedilha (ç)
// Deve retornar uma string alocada dinamicamente (free() apos uso)
char* normalizar_palavra(const char* palavra, int idioma);

#endif 

