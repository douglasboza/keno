#ifndef RANGE_LIB_H
#define RANGE_LIB_H

#include <iterator> // distance
#include <algorithm> // swap

namespace ir {
	class MatrizPontos{
		float matriz_pontos[16][16];
		public:
			void inicializa_matriz_pontos();
			float fator_mult(int total_jogadas, int acertos);
	};

	class NumerosAposta {
	    int *numeros_aposta;
	    int total_numeros_aposta;
	    double valor_aposta;
	    int acertos;
	  	public: 
	  		NumerosAposta();
	  		void set_acertos(int num);
	  		int get_acertos();
	  		void add_acertos();
	  		int* get_numeros_aposta();
	  		void set_valor_aposta(double valor);
	  		double get_valor_aposta();
	  		void set_total_numeros_aposta(int valor);
	  		int get_total_numeros_aposta();
	  		void alocar_array();
	  		void liberar_array();
	  		void inserir_numero(int num, int pos);
		    bool into_array_aposta(int num); // verifica se num está dentro do array numeros_aposta
	};



	class Sorteio{
		int lista_sorteio[20];
		public:
			int* get_lista_sorteio();
			void print_lista_sorteio();
			void gerar_sorteio();
			bool into_sorteio(int num); // verifica se num está no array do sorteio
	};

	class Tabuleiro{
		int tabuleiro[8][10];
		public:
			void inicializa_tabuleiro();
			void print_tabuleiro(Sorteio* sorteio, NumerosAposta* aposta);
	};


    // Aloca memória para a matriz do tabuleiro
    // void inicializa_matriz();

  //   //libera a memória da matriz do tabuleiro
  //   void liberar();

  //   //verifica se um barco pode ser colocado em uma casa
  //   bool verifica_barco(int linha, int coluna, int tipo_barco);
 	
 	// //função principal que gera o tabuleiro
 	// bool principal();

 	// //preenche o barco no tabuleiro
 	// void preencher_barco(int linha, int coluna, int tipo_barco, int valor_preencher);
 	
 	// //verifica se linha x coluna existe no tabuleiro
 	// int verifica_casa_existe(int linha, int coluna);
 	
 	// //verifica se as casas perto do linha x coluna estão vazias
 	// int verifica_casa_vazia(int linha, int coluna);

 	// //reinicia o tabuleiro
 	// void zera_matriz();

 	// //salva o tabuleiro no arquivo
 	// void salvar_barco();

 	// //carrega o tabuleiro do arquivo
 	// bool carrega_tabuleiro(int tabuleiro);
 	// // retorna false se não houver esse tabuleiro
 	// // caso contrário, retorna true e carrega o tabuleiro na matriz

 	// //inicia o jogo
 	// void iniciar_jogo();

 	// //retorna se o barco foi destruído por completo
 	// bool verifica_barco_tiro(int linha, int coluna, int tipo_barco);

 	// // verifica se o tabuleiro já existe
 	// bool verifica_tabuleiro_existe();

 	// // carrega todos os tabuleiros em uma matriz de string;
 	// void carrega_strings_tabuleiro();

}

#endif
