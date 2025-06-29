#include "tratamento.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Tabelas de mapeamento de caracteres acentuados para não acentuados em Português
static const char *acentos_entrada = "ÁÀÂÃÉÈÊÍÌÎÓÒÔÕÚÙÛÇáàâãéèêíìîóòôõúùûç";
static const char *acentos_saida   = "AAAAEEEIIIOOOOUUUCAAAAEEEIIIOOOOUUUc";

// Remove acentos e cedilha (ç), e converte para minusculo
static void remover_acentos_e_conversao(char* str) {
    for (int i = 0; str[i]; i++) {
        // Procura em acentos_entrada
        const char* p = strchr(acentos_entrada, (unsigned char)str[i]);
        if (p) {
            size_t idx = p - acentos_entrada;
            str[i] = acentos_saida[idx];
        }
        // Cedilha tratado acima (Ç->C e ç->c)
        // Converter para minusculo
        str[i] = (char) tolower((unsigned char)str[i]);
    }
}

// Limpa caracteres especiais: mantém apenas letras e dígitos
static void remover_caracteres_invalidos(char* str) {
    int j = 0;
    for (int i = 0; str[i]; i++) {
        if (isalnum((unsigned char)str[i])) {
            str[j++] = str[i];
        }
        // substituir outros por fim de string, mas aqui apenas ignora
    }
    str[j] = '\0';
}

char* normalizar_palavra(const char* palavra, int idioma) {
    if (!palavra) return NULL;
    // Copia palavra para buffer
    size_t len = strlen(palavra);
    char* temp = malloc(len + 1);
    if (!temp) return NULL;
    strcpy(temp, palavra);

    // Para inglês: apenas converter para minusculo e remover pontuação
/*    if (idioma == 0) {
        for (size_t i = 0; i < len; i++) {
            temp[i] = (char) tolower((unsigned char) temp[i]);
        }
        remover_caracteres_invalidos(temp);*/ //ainda vendo como vai ficar
    } else {
        // Portugues: remover acentos, cedilha(ç) e converte p/ minusculo
        remover_acentos_e_conversao(temp);
        remover_caracteres_invalidos(temp);
    }
    return temp;
}
