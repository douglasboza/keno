
#include "../include/functions.h"
#include <iostream> // cout, endl
#include <fstream> // incluir 
#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif
#include <string>  


namespace ir{

	//// ----------------- NumerosAposta -----------------
	
	ir::NumerosAposta::NumerosAposta(){	
		acertos = 0;
	}

	void ir::NumerosAposta::add_acertos(){	
		acertos += 1;
	}

	void ir::NumerosAposta::set_acertos(int num){	
		acertos = num;
	}

	void ir::NumerosAposta::inserir_numero(int num, int pos){	
		numeros_aposta[pos] = num;
		// std::cout << numeros_aposta[pos] << std::endl;
	}
	
	void ir::NumerosAposta::alocar_array(){	
		// std::cout << "\naaaa" << total_numeros_aposta << std::endl;
		numeros_aposta = new int[total_numeros_aposta];
	}

	void ir::NumerosAposta::liberar_array(){	
		delete[] numeros_aposta;
	}
	

	bool ir::NumerosAposta::into_array_aposta(int num){
		for (int i = 0; i < total_numeros_aposta; ++i){
			
			// std::cout << "\naaaa" << std::endl;
			// std::cout << numeros_aposta[i] << std::endl;
			// std::cout << num << std::endl;
			// std::cout << "bbbbb \n" << std::endl;

			if( numeros_aposta[i] == num){
				return true;
			}
		}
		return false;
	} 

	void ir::NumerosAposta::set_total_numeros_aposta(int valor){
		total_numeros_aposta = valor;
	}

	int ir::NumerosAposta::get_total_numeros_aposta(){
		return total_numeros_aposta;
	}

	void ir::NumerosAposta::set_valor_aposta(double valor){
		valor_aposta = valor;
	}

	double ir::NumerosAposta::get_valor_aposta(){
		return valor_aposta;
	}

	int* ir::NumerosAposta::get_numeros_aposta(){
		return numeros_aposta;
	}

	int ir::NumerosAposta::get_acertos(){
		return acertos;
	}
	
	//// ----------------- NumerosAposta fim -----------------


	//// ----------------- Tabuleiro -----------------

	void ir::Tabuleiro::inicializa_tabuleiro(){
		for (int i = 0; i < 8; ++i){
			for (int j = 0; j < 10; ++j){
				tabuleiro[i][j] = 1 + j + 10*i;
			}
		}
	}

	void ir::Tabuleiro::print_tabuleiro(Sorteio *sorteio, NumerosAposta* aposta){
		std::cout << "\n" <<  std::endl;
		for (int i = 0; i < 8; ++i){
			std::cout << "   ";
			for (int j = 0; j < 10; ++j){
				if((sorteio->into_sorteio(tabuleiro[i][j])) && (aposta->into_array_aposta(tabuleiro[i][j]))){
					aposta->add_acertos();
					std::cout << "|*" << tabuleiro[i][j] << "*|";
				}else{
					if(aposta->into_array_aposta(tabuleiro[i][j])){
						std::cout << " *" << tabuleiro[i][j] << "* ";
					}else{
						if(sorteio->into_sorteio(tabuleiro[i][j])){
							std::cout << " |" << tabuleiro[i][j] << "| ";
						}else{
							std::cout << "  " <<tabuleiro[i][j] << "  ";
						}
					}
				}

				if( i == 0){
					std::cout << " ";
				}
			}
			std::cout << "\n" <<  std::endl;
		}	
		std::cout << "\n" <<  std::endl;


	}

	//// ----------------- Tabuleiro fim -----------

	//// ----------------- Sorteio -----------------

	bool ir::Sorteio::into_sorteio(int num){
		for (int i = 0; i < 20; ++i){
			if(lista_sorteio[i] == num){
				return true;
			}
		}
		return false;
	}

	void ir::Sorteio::gerar_sorteio(){
		int aux_sorteio[80] = {};
		int posicao_aleatoria(0);
		int total_preenchido(0);

		for (int i = 0; i < 80; ++i){
			aux_sorteio[i] = i + 1;
		}
		

		for (int i = 0; i < 20; ++i){
			srand(time(NULL));
			posicao_aleatoria = (rand() % (79 - total_preenchido));

			lista_sorteio[total_preenchido] = aux_sorteio[posicao_aleatoria];
			std::swap(aux_sorteio[posicao_aleatoria], aux_sorteio[79 - total_preenchido]);
	        	        
			
			total_preenchido += 1;

		}
		
	}

	void ir::Sorteio::print_lista_sorteio(){
		for(int i = 0; i < 20; ++i){
			std::cout << lista_sorteio[i] << " ";
		}
		std::cout << "" << std::endl;
	}

	int* ir::Sorteio::get_lista_sorteio(){
		return lista_sorteio;
	}

	//// ----------------- Sorteio fim -----------------


	//// ----------------- MatrizPontos -----------------
	float ir::MatrizPontos::fator_mult(int total_jogadas, int acertos){
		return matriz_pontos[total_jogadas][acertos];
	}

	void ir::MatrizPontos::inicializa_matriz_pontos(){
		for (int i = 0; i < 16; ++i){
			for (int j = 0; i < 16; ++i){
				matriz_pontos[i][j] = -1;		
			}
		}
		// [número de apostas][acertos]
		matriz_pontos[1][0] = 0;
		matriz_pontos[1][1] = 3;

		matriz_pontos[2][0] = 0;
		matriz_pontos[2][1] = 1;
		matriz_pontos[2][2] = 9;

		matriz_pontos[3][0] = 0;
		matriz_pontos[3][1] = 1;
		matriz_pontos[3][2] = 2;
		matriz_pontos[3][3] = 16;

		matriz_pontos[4][0] = 0;
		matriz_pontos[4][1] = 0.5;
		matriz_pontos[4][2] = 2;
		matriz_pontos[4][3] = 6;
		matriz_pontos[4][4] = 12;

		matriz_pontos[5][1] = 0;
		matriz_pontos[5][2] = 0.5;
		matriz_pontos[5][3] = 1;
		matriz_pontos[5][4] = 3;
		matriz_pontos[5][5] = 15;
		matriz_pontos[5][6] = 50;

		matriz_pontos[6][0] = 0;
		matriz_pontos[6][1] = 0.5;
		matriz_pontos[6][2] = 1;
		matriz_pontos[6][3] = 2;
		matriz_pontos[6][4] = 3;
		matriz_pontos[6][5] = 30;
		matriz_pontos[6][6] = 75;

		matriz_pontos[7][0] = 0;
		matriz_pontos[7][1] = 0.5;
		matriz_pontos[7][2] = 0.5;
		matriz_pontos[7][3] = 1;
		matriz_pontos[7][4] = 6;
		matriz_pontos[7][5] = 12;
		matriz_pontos[7][6] = 36;
		matriz_pontos[7][7] = 100;

		matriz_pontos[8][0] = 0;
		matriz_pontos[8][1] = 0.5;
		matriz_pontos[8][2] = 0.5;
		matriz_pontos[8][3] = 1;
		matriz_pontos[8][4] = 3;
		matriz_pontos[8][5] = 6;
		matriz_pontos[8][6] = 19;
		matriz_pontos[8][7] = 90;
		matriz_pontos[8][8] = 720;

		matriz_pontos[9][0] = 0;
		matriz_pontos[9][1] = 0.5;
		matriz_pontos[9][2] = 0.5;
		matriz_pontos[9][3] = 1;
		matriz_pontos[9][4] = 2;
		matriz_pontos[9][5] = 4;
		matriz_pontos[9][6] = 8;
		matriz_pontos[9][7] = 20;
		matriz_pontos[9][8] = 80;
		matriz_pontos[9][9] = 1200;

		matriz_pontos[10][0] = 0;
		matriz_pontos[10][1] = 0;
		matriz_pontos[10][2] = 0.5;
		matriz_pontos[10][3] = 1;
		matriz_pontos[10][4] = 2;
		matriz_pontos[10][5] = 3;
		matriz_pontos[10][6] = 5;
		matriz_pontos[10][7] = 10;
		matriz_pontos[10][8] = 30;
		matriz_pontos[10][9] = 600;
		matriz_pontos[10][10] = 1800;

		matriz_pontos[11][0] = 0;
		matriz_pontos[11][1] = 0;
		matriz_pontos[11][2] = 0.5;
		matriz_pontos[11][3] = 1;
		matriz_pontos[11][4] = 1;
		matriz_pontos[11][5] = 2;
		matriz_pontos[11][6] = 6;
		matriz_pontos[11][7] = 15;
		matriz_pontos[11][8] = 25;
		matriz_pontos[11][9] = 180;
		matriz_pontos[11][10] = 1000;
		matriz_pontos[11][11] = 3000;

		matriz_pontos[12][0] = 0;
		matriz_pontos[12][1] = 0;
		matriz_pontos[12][2] = 0;
		matriz_pontos[12][3] = 0.5;
		matriz_pontos[12][4] = 1;
		matriz_pontos[12][5] = 2;
		matriz_pontos[12][6] = 4;
		matriz_pontos[12][7] = 24;
		matriz_pontos[12][8] = 72;
		matriz_pontos[12][9] = 250;
		matriz_pontos[12][10] = 500;
		matriz_pontos[12][11] = 2000;
		matriz_pontos[12][12] = 4000;

		matriz_pontos[13][0] = 0;
		matriz_pontos[13][1] = 0;
		matriz_pontos[13][2] = 0;
		matriz_pontos[13][3] = 0.5;
		matriz_pontos[13][4] = 0.5;
		matriz_pontos[13][5] = 3;
		matriz_pontos[13][6] = 4;
		matriz_pontos[13][7] = 5;
		matriz_pontos[13][8] = 20;
		matriz_pontos[13][9] = 80;
		matriz_pontos[13][10] = 240;
		matriz_pontos[13][11] = 500;
		matriz_pontos[13][12] = 3000;
		matriz_pontos[13][13] = 6000;


		matriz_pontos[14][0] = 0;
		matriz_pontos[14][1] = 0;
		matriz_pontos[14][2] = 0;
		matriz_pontos[14][3] = 0.5;
		matriz_pontos[14][4] = 0.5;
		matriz_pontos[14][5] = 2;
		matriz_pontos[14][6] = 3;
		matriz_pontos[14][7] = 5;
		matriz_pontos[14][8] = 12;
		matriz_pontos[14][9] = 50;
		matriz_pontos[14][10] = 150;
		matriz_pontos[14][11] = 500;
		matriz_pontos[14][12] = 1000;
		matriz_pontos[14][13] = 2000;
		matriz_pontos[14][14] = 7500;


		matriz_pontos[15][0] = 0;
		matriz_pontos[15][1] = 0;
		matriz_pontos[15][2] = 0;
		matriz_pontos[15][3] = 0.5;
		matriz_pontos[15][4] = 0.5;
		matriz_pontos[15][5] = 1;
		matriz_pontos[15][6] = 2;
		matriz_pontos[15][7] = 5;
		matriz_pontos[15][8] = 15;
		matriz_pontos[15][9] = 50;
		matriz_pontos[15][10] = 150;
		matriz_pontos[15][11] = 300;
		matriz_pontos[15][12] = 600;
		matriz_pontos[15][13] = 1200;
		matriz_pontos[15][14] = 2500;
		matriz_pontos[15][15] = 10000;

	}
	//// ----------------- MatrizPontos fim -----------------
}