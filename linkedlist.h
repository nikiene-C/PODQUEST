#pragma once

#include <stdio.h>
#include <stdlib.h>

//Defini��o das palavras-chave, cada uma vai ter uma string e um apontamento para uma pr�xima, caso existir
typedef struct palavrasChave
{
	char categoria[64];
	struct palavrasChave* outraCategoria;
} PalavrasChave;

//Defini��o do meu podcast, vai possuir um id, uma string nome(podcast), uma string nome(epis�dio) e um numero do epis�dio
//TODO: implementar as palavras-chave
typedef struct podcast
{
	int podcastId;
	char nomePodcast[64];
	char nomeEpisodio[64];
	int numeroEpisodio;

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