#pragma once

#include "linkedlist.h"

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
* @brief Fun��o que aloca um espa�o do tamanho de uma PalavrasChave na mem�ria (dados dessa PalavrasChave ser�o pedidos nessa fun��o)
* @return novaPalavrasChave, a nova PalavrasChave com os apontamentos de mem�ria para o pr�ximo apontando para NULL
*/
PalavrasChave* criaPalavrasChave() {

}

/**
* @brief Fun��o que aloca um espa�o do tamanho de um Podquest na mem�ria (dados desse Podquest ser�o pedidos nessa fun��o)
* @return novoPodquest, a nova Playlist com os apontamentos de mem�ria para o pr�ximo e anterior apontando para NULL
*/
Podquest criaPodquest() {

}