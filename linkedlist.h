#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Defini��o das palavras-chave, cada uma vai ter uma string e um apontamento para uma pr�xima, caso existir
typedef struct palavrasChave
{
	char categoria[64];
	struct palavrasChave* proxima;

} PalavrasChave;

//Defini��o do meu podcast, vai possuir um id, uma string nome(podcast), uma string nome(epis�dio) e um numero do epis�dio
//TODO: implementar as palavras-chave
typedef struct podcast
{
	int podcastId;
	char nomePodcast[64];
	char nomeEpisodio[64];
	int numeroEpisodio;

	PalavrasChave palavrasChave;

	struct podcast* proximo;
	struct podcast* anterior;

} Podcast;

//Definindo que um ponteiro para um Podcast vai se chamar Podquest
typedef Podcast* Podquest;

//Defini��o da minha lista, possuindo 3 ponteiros: in�cio, atual e fim
typedef struct playlist
{
	Podquest inicio;
	Podquest atual;
	Podquest fim;
	
} Playlist;

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma Playlist na mem�ria
* @return novaPlaylist, a nova Playlist com os apontamentos de mem�ria para o in�cio, fim e atual apontando para NULL
*/
Playlist* llcriaPlaylist();

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma PalavrasChave na mem�ria (dados dessa PalavrasChave ser�o pedidos nessa fun��o)
* @return novaPalavrasChave, a nova PalavrasChave com os apontamentos de mem�ria para o pr�ximo apontando para NULL
*/
PalavrasChave* criaPalavrasChave();

/**
* @brief Fun��o que aloca um espa�o do tamanho de um Podquest na mem�ria (dados desse Podquest ser�o pedidos nessa fun��o)
* @return novoPodquest, a nova Playlist com os apontamentos de mem�ria para o pr�ximo e anterior apontando para NULL
*/
Podquest criaPodquest();