#pragma once

#include "linkedlist.h"

//Fun��o auxiliar que troca '\n' por '\0' (thx @Yarquen! :D)
void remove_newline_ch(char* line) {
	int new_line = strlen(line) - 1;
	if (line[new_line] == '\n')
	{
		line[new_line] = '\0';
	}
}

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma Playlist na mem�ria
* @return novaPlaylist, a nova Playlist com os apontamentos de mem�ria para o in�cio, fim e atual apontando para NULL
*/
Playlist* llcriaPlaylist() {

	Playlist* novaPlaylist = (Playlist*)malloc(sizeof(Playlist));

	novaPlaylist->inicio = NULL;
	novaPlaylist->atual = NULL;
	novaPlaylist->fim = NULL;

	return novaPlaylist;
}


/**
* @brief Fun��o que aloca um espa�o do tamanho de uma lista de PalavraChave na mem�ria 
* @return novaPalavrasChave, a nova lista de PalavraChave com os apontamentos de mem�ria para o in�cio e fim apontando para NULL
*/
PalavrasChave* criaPalavrasChave() {

	PalavrasChave* novaPalavrasChave = (PalavrasChave*)malloc(sizeof(PalavrasChave));

	novaPalavrasChave->inicio = NULL;
	novaPalavrasChave->fim = NULL;

	return novaPalavrasChave;
}

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma PalavraChave na mem�ria (dados dessa PalavraChave ser�o pedidos nessa fun��o)
* @return novaPalavrasChave, a nova PalavraChave com os apontamentos de mem�ria para o pr�ximo apontando para NULL
*/
PalavraChave* criaPalavraChave() {
	
	PalavraChave* novaPalavraChave = (PalavraChave*)malloc(sizeof(PalavraChave));

	printf("\nPalavra-chave: ");
	fgets(novaPalavraChave->categoria, 64, stdin);
	remove_newline_ch(novaPalavraChave->categoria);

	novaPalavraChave->proxima = NULL;

	return novaPalavraChave;
}

/**
* @brief Fun��o que aloca um espa�o do tamanho de um Podquest na mem�ria (dados desse Podquest ser�o pedidos nessa fun��o)
* @return novoPodquest, a nova Playlist com os apontamentos de mem�ria para o pr�ximo e anterior apontando para NULL
*/
Podquest criaPodquest() {

}