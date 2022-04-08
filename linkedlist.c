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
PalavrasChave* llcriaPalavrasChave() {

	PalavrasChave* novaPalavrasChave = (PalavrasChave*)malloc(sizeof(PalavrasChave));

	novaPalavrasChave->inicio = NULL;
	novaPalavrasChave->fim = NULL;

	return novaPalavrasChave;
}

/**
* @brief Fun��o que aloca um espa�o do tamanho de uma PalavraChave na mem�ria (dados dessa PalavraChave ser�o pedidos nessa fun��o)
* @return novaPalavrasChave, a nova PalavraChave com os apontamentos de mem�ria para o pr�ximo apontando para NULL
*/
PalavraChave* llcriaPalavraChave() {
	
	PalavraChave* novaPalavraChave = (PalavraChave*)malloc(sizeof(PalavraChave));

	printf("\nPalavra-chave: ");
	fgets(novaPalavraChave->categoria, 64, stdin);
	remove_newline_ch(novaPalavraChave->categoria);

	novaPalavraChave->proxima = NULL;
	novaPalavraChave->anterior = NULL;

	return novaPalavraChave;
}

/**
* @brief adiciona uma palavra-chave no fim da lista de palavras-chave
* @param palavrasChave -> Lista de palavras-chave
*/
void adicionaPalavraChave(PalavrasChave* palavrasChave) {

	PalavraChave* novaPalavraChave = llcriaPalavraChave();

	if (palavrasChave->inicio == NULL)
	{
		palavrasChave->inicio = novaPalavraChave;
		palavrasChave->fim = novaPalavraChave;

		return;
	}

	palavrasChave->fim->proxima = novaPalavraChave;
	novaPalavraChave->anterior = palavrasChave->fim;
	palavrasChave->fim = novaPalavraChave;
}

/**
* @brief Fun��o que aloca um espa�o do tamanho de um Podquest na mem�ria (dados desse Podquest ser�o pedidos nessa fun��o)
* @return novoPodquest, a nova Playlist com os apontamentos de mem�ria para o pr�ximo e anterior apontando para NULL
*/
Podquest llcriaPodquest() {

	Podquest novoPodquest = (Podquest)malloc(sizeof(Podcast));

	printf("\nId do Podcast: ");
	scanf_s("%d", &novoPodquest->podcastId);
	getchar();

	printf("\nNome do Podcast: ");
	fgets(novoPodquest->nomePodcast, 64, stdin);
	remove_newline_ch(novoPodquest->nomePodcast);

	printf("\nNome do Episodio: ");
	fgets(novoPodquest->nomeEpisodio, 64, stdin);
	remove_newline_ch(novoPodquest->nomeEpisodio);

	printf("\nNumero do Episodio: ");
	scanf_s("%d", &novoPodquest->numeroEpisodio);
	getchar();


	PalavrasChave* novaListaPalavrasChave = llcriaPalavrasChave();
	novoPodquest->palavrasChave = novaListaPalavrasChave;

	int continuar = 1;
	while (continuar)
	{
		printf("\nDeseja inserir mais uma palavra-chave para esse podquest? \n| 1 - Sim  \n| 0 - Nao\n");
		scanf_s("%d", &continuar);

		if (continuar)
		{
			adicionaPalavraChave(novaListaPalavrasChave);
		}
	}

	novoPodquest->proximo = NULL;
	novoPodquest->anterior = NULL;

	return novoPodquest;
}

/**
* @brief adiciona um Podquest na Playlist ordenado pelo ID
* @param playlist -> Lista de Podquest
*/
void llInserePodquest(Playlist* playlist) {

	Podquest novoPodquest = llcriaPodquest();
	
	if (playlist->inicio == NULL)
	{
		playlist->inicio = novoPodquest;
		playlist->fim = novoPodquest;

		return;
	}
	else if (novoPodquest->podcastId > playlist->fim->podcastId)
	{
		playlist->fim->proximo = novoPodquest;
		novoPodquest->anterior = playlist->fim;
		playlist->fim = novoPodquest;

		return;
	}
	else
	{
		Podquest aux = playlist->inicio;

		while (aux->proximo->podcastId <= novoPodquest->podcastId)
		{
			aux = aux->proximo;
		}

		novoPodquest->proximo = aux->proximo;
		aux->proximo = novoPodquest;
		novoPodquest->anterior = aux;
	}
}