
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
	void ir::NumerosAposta::inserir_numero(int num, int pos){	
		numeros_aposta[pos] = num;
		// std::cout << numeros_aposta[pos] << std::endl;
	}
	
	void ir::NumerosAposta::alocar_array(){	
		numeros_aposta = new int[total_numeros_aposta];
	}

	void ir::NumerosAposta::liberar_array(){	
		delete[] numeros_aposta;
	}
	

	bool ir::NumerosAposta::into_array_aposta(int num){
		for (int i = 0; i < total_numeros_aposta; ++i){
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

	void ir::NumerosAposta::set_valor_aposta(int valor){
		valor_aposta = valor;
	}

	int ir::NumerosAposta::get_valor_aposta(){
		return valor_aposta;
	}

	int* ir::NumerosAposta::get_numeros_aposta(){
		return numeros_aposta;
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

	void ir::Tabuleiro::print_tabuleiro(Sorteio sorteio, NumerosAposta aposta){
		std::cout << "\n" <<  std::endl;
		for (int i = 0; i < 8; ++i){
			std::cout << "   ";
			for (int j = 0; j < 10; ++j){
				if(sorteio.into_sorteio(tabuleiro[i][j]) && aposta.into_array_aposta(tabuleiro[i][j])){
					std::cout << "|*" << tabuleiro[i][j] << "*|";
				}else{
					if(aposta.into_array_aposta(tabuleiro[i][j])){
						std::cout << " *" << tabuleiro[i][j] << "* ";
					}else{
						if(sorteio.into_sorteio(tabuleiro[i][j])){
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

	//// ----------------- Tabuleiro fim -----------------

	bool ir::Sorteio::into_sorteio(int num){
		for (int i = 0; i < 20; ++i){
			if(lista_sorteio[i] == num){
				return true;
			}
		}
		return false;
	}

	void ir::Sorteio::gerar_sorteio(){
		int aux_sorteio[80];
		int posicao_aleatoria(0);
		int total_preenchido(0);

		for (int i = 0; i < 80; ++i){
			aux_sorteio[i] = i + 1;
		}
		

		for (int i = 0; i < 20; ++i){
			// srand(time(NULL));
			posicao_aleatoria = (rand() % (80 - total_preenchido));
			lista_sorteio[total_preenchido] = aux_sorteio[posicao_aleatoria];
			std::swap(aux_sorteio[posicao_aleatoria], aux_sorteio[80 - total_preenchido]);
			total_preenchido += 1;
		}
		
	}

	void ir::Sorteio::print_lista_sorteio(){
		for (int i = 0; i < 20; ++i){
			std::cout << lista_sorteio[i] << " ";
		}
		std::cout << "" << std::endl;
	}

	int* ir::Sorteio::get_lista_sorteio(){
		return lista_sorteio;
	}


	//total disponível para cada barco
	// int total5(1);
	// int total4(2);
	// int total3(3);
	// int total2(3);
	// int total1(1);

 // 	int total_tabuleiros(0); // total de tabuleiros no arquivo e gerado
	// int linhas = 10; // linhas do tabuleiro
	// int colunas = 10; // colunas do tabuleiro
	// int **matriz; //matriz do tabuleiro
	// double*tabuleiros_array; // array com todos os tabuleiros em formato de string;

	// int total_barcos = total5 + total4 + total3 + total2 + total1;
	// int total_barcos_fixo = total_barcos;
	// int m_barcos[10][3]; // matriz com os barcos do tabuleiro

	// void inicializa_matriz(){  // Aloca memória para a matriz do tabuleiro
		

	// }



	// void liberar(){ // aloca memória para a matriz do tabuleiro
	//     for(int i = 0; i < linhas; i++)
	//         free(matriz[i]);

	//     free(matriz);
	//     free(tabuleiros_array);
	// }

	// void zera_matriz(){ // //reinicia o tabuleiro zerando as posições
	// 	for (int i = 0; i < linhas; i++) {
	//         for (int j = 0; j < colunas; j++) {
	//             matriz[i][j] = 0; 
	//         }
	//     }

	//     for (int i = 0; i < 10; i++) {
	//         for (int j = 0; j < 2; j++) {
	//             m_barcos[i][j] = 0; 
	//         }
	//     }

	//     total5 = 1;
	// 	total4 = 2;
	// 	total3 = 3;
	// 	total2 = 3;
	// 	total1 = 1;
	// 	total_barcos = total5 + total4 + total3 + total2 + total1;
	// 	total_barcos_fixo = total_barcos;

	// }

	// void salvar_barco(){ // Salva o array de barcos no arquivo	
	// 	std::ofstream out;
	// 	out.open("tabuleiros", std::ios::out | std::ios::app ); 
	// 	out << linhas << " " << colunas << std::endl;

	// 	for (int i = 1; i <= total_barcos_fixo; ++i){
	//         out << m_barcos[i][0] << " " << m_barcos[i][1] << " " << m_barcos[i][2] << std::endl;
	//     }
	//     out << " 9999 " << std::endl; //indica o final de um tabuleiro
	// 	out.close();
		 
	// }		


	// // função principal que gera o tabuleiro
	// // retorna true, se conseguir gerar um tabuleiro
 //    bool principal(){
 //    	int posicoes_livres[linhas * colunas][2]; // matriz que guarda cada coordenada coluna x linha
 //   		int cont_posicao(0); // Contador para preencher a matriz posições livres
	//    	int posicao_aleatoria_casa(0); // Posição aleatória da coordenada da casa
	//    	int barco_aleatorio(0); // Posição o barco aleatório
	//    	int linha_vez(0); // linha sorteada
	//    	int coluna_vez(0); // coluna sorteada
	//    	int limite_aleatorio = (linhas * colunas) - 1 ; // Limite de coordenadas possíveis linha x coluna
 //  		bool teste_posicao_livre(false); // teste para verificar se a coordenada está livre para um barco

 //  		int barcos[10]; // array com os possíveis barcos
 //  		int barco_limite(0); // até onde foi preenchido o array barcos
  		


 //   		for (int i = 0; i < linhas; i++){ // preenche as corrdenadas na matriz posições livres
	//         for (int j = 0; j < colunas; j++) {
	//             posicoes_livres[cont_posicao][0] = i; // linha
	//             posicoes_livres[cont_posicao][1] = j; // coluna
	//             cont_posicao++; // próxima posição
	//         }
	//     }

        
 //        while(total_barcos > 0){ // enquanto houver barcos isponíveis
			
    
	// 	    while(teste_posicao_livre == false){ // até encontrar uma posicao que seja possível colocar barco
	//     		// srand(time(NULL));
	// 	    	if(limite_aleatorio == 0 ){ // Caso 0, significa que todas as posições estão indisponíveis
	// 	    		// std::cout << "\n Erro! não conseguiu achar uma solução";
	// 	    		return false;
	// 	    	}

	// 		    posicao_aleatoria_casa = (rand() % (limite_aleatorio)); // gera um número aleatório até a posição limite de corrdenadas
	// 		   	linha_vez = posicoes_livres[posicao_aleatoria_casa][0]; // linha aleatória
	// 		   	coluna_vez = posicoes_livres[posicao_aleatoria_casa][1]; // coluna aleatória
			    
	// 		     // std::cout << "\n linha vez = " << matriz[linha_vez][coluna_vez];

	// 		    if(total5 > 0){ // se ainda há barco com 5 casas
	// 			    if(ir::verifica_barco(linha_vez, coluna_vez, 51) == true){ 
	// 			    	// verifica se o barco 51 pode ser colocado na linha x coluna sorteada
	// 					teste_posicao_livre = true; // encontrou um barco disponível para a posição linha x coluna
	// 					barcos[barco_limite] = 51; // adiciona o barco no array barcos
	// 				 	barco_limite++; // próxima posição dos barcos
	// 			    }

	// 			    if(ir::verifica_barco(linha_vez, coluna_vez, 5) == true){
	// 					teste_posicao_livre = true;
	// 					barcos[barco_limite] = 5;
	// 					barco_limite++;
	// 			    }
	// 			}

	// 		    if(total4 > 0){// se ainda há barco com 4 casas
	// 			    if(ir::verifica_barco(linha_vez, coluna_vez, 41) == true){
	// 					teste_posicao_livre = true;
	// 					barcos[barco_limite] = 41;
	// 					barco_limite++;
	// 			    }

	// 			    if(ir::verifica_barco(linha_vez, coluna_vez, 4) == true){
	// 					teste_posicao_livre = true;
	// 					barcos[barco_limite] = 4;
	// 					barco_limite++;
	// 			    }
	// 			}


	// 		    if(total3 > 0){// se ainda há barco com 3 casas
	// 			    if(ir::verifica_barco(linha_vez, coluna_vez, 31) == true){
	// 					teste_posicao_livre = true;
	// 					barcos[barco_limite] = 31;
	// 					barco_limite++;
	// 			    }
				
	// 			    if(ir::verifica_barco(linha_vez, coluna_vez, 3) == true){
	// 					teste_posicao_livre = true;
	// 					barcos[barco_limite] = 3;
	// 					barco_limite++;
	// 			    }
	// 			}


	// 		    if(total2 > 0){// se ainda há barco com 2 casas
	// 			    if(ir::verifica_barco(linha_vez, coluna_vez, 21) == true){
	// 					teste_posicao_livre = true;
	// 					barcos[barco_limite] = 21;
	// 					barco_limite += 1;
	// 			    }
				
	// 			    if(ir::verifica_barco(linha_vez, coluna_vez, 2) == true){
	// 					teste_posicao_livre = true;
	// 					barcos[barco_limite] = 2;
	// 					barco_limite += 1;
	// 			    }
	// 			}


	// 		    if(total1 > 0){// se ainda há barco com 1 casa
	// 			    if(ir::verifica_barco(linha_vez, coluna_vez, 1) == true){
	// 					teste_posicao_livre = true;
	// 					barcos[barco_limite] = 1;
	// 					barco_limite += 1;
	// 			    }
	// 		    }


	// 		    if(teste_posicao_livre == true){ // Se econtrou pelo menos um barco para linha x coluna
	// 		    	// std::cout << "\n aqui111 = "<< barco_limite << std::endl;

	// 		    	barco_aleatorio = (rand() % (barco_limite)); // Sorteia um número entre 0 e o total de barcos para a posição

	// 		    	// Verifica qual barco foi sorteado para a posição e diminui 1 no total do tipo de barco
	// 		    	if(barcos[barco_aleatorio] == 1)  total1 -= 1;
	// 		    	if(barcos[barco_aleatorio] == 2)  total2 -= 1;
	// 		    	if(barcos[barco_aleatorio] == 21) total2 -= 1;
	// 		    	if(barcos[barco_aleatorio] == 3)  total3 -= 1;
	// 		    	if(barcos[barco_aleatorio] == 31) total3 -= 1;
	// 		    	if(barcos[barco_aleatorio] == 4)  total4 -= 1;
	// 		    	if(barcos[barco_aleatorio] == 41) total4 -= 1;
	// 		    	if(barcos[barco_aleatorio] == 5)  total5 -= 1;
	// 		    	if(barcos[barco_aleatorio] == 51) total5 -= 1;


	// 			   	// std::cout << "\n coluna vez = " << coluna_vez << std::endl;
	// 			    // std::cout << "\n linha vez = " << linha_vez << std::endl;
	// 		    	// std::cout << "\n barco da vez = "<< barcos[barco_aleatorio] << std::endl;

	// 		    	// Preenche na matriz m_matriz cada barco preenchido, para salvar no arquivo, no final
	// 		    	m_barcos[total_barcos][0] = linha_vez; 	
	// 		    	m_barcos[total_barcos][1] = coluna_vez;
	// 		    	m_barcos[total_barcos][2] = barcos[barco_aleatorio];

	// 		    				    		// std::cout << "\n aqio" << barco_aleatorio << std::endl;


	// 		    	// preenche a matriz de barcos com o barco encontrado e a posição
	// 		    	preencher_barco(linha_vez, coluna_vez, barcos[barco_aleatorio], 1); 

	// 		    	total_barcos -= 1; // Menos um barco disponível
			    	
	// 		    	// std::cout << "\n barco1 " << total1<< std::endl;;
	// 		    	// std::cout << "\n barco2 " << total2<< std::endl;;
	// 		    	// std::cout << "\n barco3 " << total3<< std::endl;;
	// 		    	// std::cout << "\n barco4 " << total4<< std::endl;;

	// 		    	// std::cout << "\n linha_vez " << linha_vez;
	// 		    	// std::cout << "\n coluna_vez " << coluna_vez;
	// 		    	// std::cout << "\n total de barcos " << total_barcos;
	// 		    	// std::cout << "\n barco vez " << barcos[barco_aleatorio];
	// 		    	// std::cout << "\n" << std::endl;
	// 		    }else{
	// 		    	// Caso não encontre barco para a linha x coluna do sorteio
	// 		    	// A corrdenada linha x coluna é jogada para o final do array de posições livres
	// 		    	// É retirado 1 de limite_aleatorio para que essa coordenada não entre mais no sorteio

	// 		    	std::swap(* posicoes_livres[posicao_aleatoria_casa], * posicoes_livres[limite_aleatorio]);
	// 		    	limite_aleatorio -= 1;
			    	
	// 		    }
	// 		    barco_limite = 0; // Zera até onde foi preenchido o array de barcos para uma posição qualquer.
	// 	    }

	// 	    teste_posicao_livre = false; // Para iniciar um novo teste
		
	// 	}

 //     //    std::cout << "\n" << std::endl;
 //     //    for (int i = 0; i < linhas; ++i){
	//     //     for (int j = 0; j < colunas; ++j){
	//     //     	if(matriz[i][j] == 1){
	//     //     		 std::cout << "- ";
	//     //     		}else{
	//     //     			 std::cout << matriz[i][j] << " ";
	//     //     	}
	//     //     }
	//     //     std::cout << "\n" << std::endl;
	//     // }

	// 	if(verifica_tabuleiro_existe()){
 //    		salvar_barco();
	// 	}else{
	// 		return false;
	// 	}

	//     return true;

 //    }
    

	// bool verifica_barco(int linha, int coluna, int tipo_barco){ // retorna true se pode colocar o barco
	// 	if(tipo_barco == 1){ // se barco for do tipo 1
	// 		// verifica se a casa está disponível para preenchder o barco
	// 		if(verifica_casa_existe(linha, coluna) == 1) return false; 

	// 		// Verifica se as casas perto não existem ou estão vazias
	// 		if(verifica_casa_vazia(linha + 1, coluna) == 1) return false; // inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // superior
	// 		if(verifica_casa_vazia(linha, coluna + 1) == 1) return false; // direita
	// 		if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda

	// 		if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // diagonal direita inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // diagonal direita superior
	// 		if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // diagonal esquerda inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior
	// 	}

	// 	if(tipo_barco == 2){
	// 		if(verifica_casa_existe(linha, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha, coluna + 1) == 1) return false;

	// 		if(verifica_casa_vazia(linha + 1, coluna) == 1) return false; // casa 1 inferior
	// 		if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // casa 2 inferior

	// 		if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 supeior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // casa 2 superior
			

	// 		if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
	// 		if(verifica_casa_vazia(linha, coluna + 2) == 1) return false; // direita da casa 2

	// 		if(verifica_casa_vazia(linha + 1, coluna + 2) == 1) return false; // diagonal direita inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 2) == 1) return false; // diagonal direita superior
	// 		if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // diagonal esquerda inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior
	// 	}

		
	// 	if(tipo_barco == 21){
	// 		if(verifica_casa_existe(linha, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha + 1, coluna) == 1) return false;

	// 		if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 supeior
	// 		if(verifica_casa_vazia(linha + 2, coluna) == 1) return false; // casa 2 inferior

	// 		if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
	// 		if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // esquerda da casa 2

	// 		if(verifica_casa_vazia(linha, coluna + 1) == 1) return false; // direita da casa 1
	// 		if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // direita da casa 2

	// 		if(verifica_casa_vazia(linha + 2, coluna + 1) == 1) return false; // diagonal direita inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // diagonal direita superior
	// 		if(verifica_casa_vazia(linha + 2, coluna - 1) == 1) return false; // diagonal esquerda inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior
	// 	}

	// 	if(tipo_barco == 3){
	// 		if(verifica_casa_existe(linha, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha, coluna + 1) == 1) return false;
	// 		if(verifica_casa_existe(linha, coluna + 2) == 1) return false;

	// 		if(verifica_casa_vazia(linha + 1, coluna) == 1) return false; // casa 1 inferior
	// 		if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // casa 2 inferior
	// 		if(verifica_casa_vazia(linha + 1, coluna + 2) == 1) return false; // casa 3 inferior


	// 		if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 superior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // casa 2 superior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 2) == 1) return false; // casa 3 superior
			

	// 		if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
	// 		if(verifica_casa_vazia(linha, coluna + 3) == 1) return false; // direita da casa 2
			


	// 		if(verifica_casa_vazia(linha + 1, coluna + 3) == 1) return false; // diagonal direita inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 3) == 1) return false; // diagonal direita superior
	// 		if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // diagonal esquerda inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior

	// 	}

	// 	if(tipo_barco == 31){
	// 		if(verifica_casa_existe(linha, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha + 1, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha + 2, coluna) == 1) return false;

	// 		if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 supeior
	// 		if(verifica_casa_vazia(linha + 3, coluna) == 1) return false; // casa 3 inferior

	// 		if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
	// 		if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // esquerda da casa 2
	// 		if(verifica_casa_vazia(linha + 2, coluna - 1) == 1) return false; // esquerda da casa 3

	// 		if(verifica_casa_vazia(linha, coluna + 1) == 1) return false; // direita da casa 1
	// 		if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // direita da casa 2
	// 		if(verifica_casa_vazia(linha + 2, coluna + 1) == 1) return false; // direita da casa 3
			
	// 		if(verifica_casa_vazia(linha + 3, coluna + 1) == 1) return false; // diagonal direita inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // diagonal direita superior
	// 		if(verifica_casa_vazia(linha + 3, coluna - 1) == 1) return false; // diagonal esquerda inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior
	// 	}


	// 	if(tipo_barco == 4){
	// 		if(verifica_casa_existe(linha, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha, coluna + 1) == 1) return false;
	// 		if(verifica_casa_existe(linha, coluna + 2) == 1) return false;
	// 		if(verifica_casa_existe(linha, coluna + 3) == 1) return false;

	// 		if(verifica_casa_vazia(linha + 1, coluna) == 1) return false; // casa 1 inferior
	// 		if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // casa 2 inferior
	// 		if(verifica_casa_vazia(linha + 1, coluna + 2) == 1) return false; // casa 3 inferior
	// 		if(verifica_casa_vazia(linha + 1, coluna + 3) == 1) return false; // casa 4 inferior


	// 		if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 superior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // casa 2 superior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 2) == 1) return false; // casa 3 superior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 3) == 1) return false; // casa 3 superior
			

	// 		if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
	// 		if(verifica_casa_vazia(linha, coluna + 4) == 1) return false; // direita da casa 4
			


	// 		if(verifica_casa_vazia(linha + 1, coluna + 4) == 1) return false; // diagonal direita inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 4) == 1) return false; // diagonal direita superior
	// 		if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // diagonal esquerda inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior

	// 	}

	// 	if(tipo_barco == 41){
	// 		if(verifica_casa_existe(linha, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha + 1, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha + 2, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha + 3, coluna) == 1) return false;

	// 		if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 supeior
	// 		if(verifica_casa_vazia(linha + 4, coluna) == 1) return false; // casa 3 inferior

	// 		if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
	// 		if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // esquerda da casa 2
	// 		if(verifica_casa_vazia(linha + 2, coluna - 1) == 1) return false; // esquerda da casa 3
	// 		if(verifica_casa_vazia(linha + 3, coluna - 1) == 1) return false; // esquerda da casa 4

	// 		if(verifica_casa_vazia(linha, coluna + 1) == 1) return false; // direita da casa 1
	// 		if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // direita da casa 2
	// 		if(verifica_casa_vazia(linha + 2, coluna + 1) == 1) return false; // direita da casa 3
	// 		if(verifica_casa_vazia(linha + 3, coluna + 1) == 1) return false; // direita da casa 4
			
	// 		if(verifica_casa_vazia(linha + 4, coluna + 1) == 1) return false; // diagonal direita inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // diagonal direita superior
	// 		if(verifica_casa_vazia(linha + 4, coluna - 1) == 1) return false; // diagonal esquerda inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior
	// 	}

	// 	if(tipo_barco == 51){
	// 		if(verifica_casa_existe(linha, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha + 1, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha + 2, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha + 3, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha + 4, coluna) == 1) return false;

	// 		if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 supeior
	// 		if(verifica_casa_vazia(linha + 5, coluna) == 1) return false; // casa 5 inferior

	// 		if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
	// 		if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // esquerda da casa 2
	// 		if(verifica_casa_vazia(linha + 2, coluna - 1) == 1) return false; // esquerda da casa 3
	// 		if(verifica_casa_vazia(linha + 3, coluna - 1) == 1) return false; // esquerda da casa 4
	// 		if(verifica_casa_vazia(linha + 4, coluna - 1) == 1) return false; // esquerda da casa 5

	// 		if(verifica_casa_vazia(linha, coluna + 1) == 1) return false; // direita da casa 1
	// 		if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // direita da casa 2
	// 		if(verifica_casa_vazia(linha + 2, coluna + 1) == 1) return false; // direita da casa 3
	// 		if(verifica_casa_vazia(linha + 3, coluna + 1) == 1) return false; // direita da casa 4
	// 		if(verifica_casa_vazia(linha + 4, coluna + 1) == 1) return false; // direita da casa 5
			
	// 		if(verifica_casa_vazia(linha + 5, coluna + 1) == 1) return false; // diagonal direita inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // diagonal direita superior
	// 		if(verifica_casa_vazia(linha + 5, coluna - 1) == 1) return false; // diagonal esquerda inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior
	// 	}

		

	// 	if(tipo_barco == 5){
	// 		if(verifica_casa_existe(linha, coluna) == 1) return false;
	// 		if(verifica_casa_existe(linha, coluna + 1) == 1) return false;
	// 		if(verifica_casa_existe(linha, coluna + 2) == 1) return false;
	// 		if(verifica_casa_existe(linha, coluna + 3) == 1) return false;
	// 		if(verifica_casa_existe(linha, coluna + 4) == 1) return false;

	// 		if(verifica_casa_vazia(linha + 1, coluna) == 1) return false; // casa 1 inferior
	// 		if(verifica_casa_vazia(linha + 1, coluna + 1) == 1) return false; // casa 2 inferior
	// 		if(verifica_casa_vazia(linha + 1, coluna + 2) == 1) return false; // casa 3 inferior
	// 		if(verifica_casa_vazia(linha + 1, coluna + 3) == 1) return false; // casa 4 inferior
	// 		if(verifica_casa_vazia(linha + 1, coluna + 4) == 1) return false; // casa 5 inferior


	// 		if(verifica_casa_vazia(linha - 1, coluna) == 1) return false; // casa 1 superior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 1) == 1) return false; // casa 2 superior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 2) == 1) return false; // casa 3 superior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 3) == 1) return false; // casa 3 superior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 4) == 1) return false; // casa 3 superior	

	// 		if(verifica_casa_vazia(linha, coluna - 1) == 1) return false; // esquerda da casa 1
	// 		if(verifica_casa_vazia(linha, coluna + 5) == 1) return false; // direita da casa 5
			


	// 		if(verifica_casa_vazia(linha + 1, coluna + 5) == 1) return false; // diagonal direita inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna + 5) == 1) return false; // diagonal direita superior
	// 		if(verifica_casa_vazia(linha + 1, coluna - 1) == 1) return false; // diagonal esquerda inferior
	// 		if(verifica_casa_vazia(linha - 1, coluna - 1) == 1) return false; // diagonal esquerda superior

	// 	}

	// 	return true; // O barco está disponível, pois passou em todos os testes
	// }

	// int verifica_casa_vazia(int linha, int coluna){ // verifica se a coordenada linha x coluna está vazia e existe
	// 	if((linha < linhas) && (coluna < colunas) && (linha >= 0) && (coluna >= 0)){ 
	// 		if(matriz[linha][coluna] == 1){
	// 			return 1; // 1 se está preenchida
	// 		}
	// 	}
	// 	return 0; // 0 se tá livre ou não existe
	// }

	// int verifica_casa_existe(int linha, int coluna){  // verifica se a coordenada linha x coluna existe e se está livre
	// 	if((linha < linhas) && (coluna < colunas) && (linha >= 0) && (coluna >= 0)){ 
	// 		if(matriz[linha][coluna] == 1){
	// 			return 1; // retorna 1 se está ocupada
	// 		}else{
	// 			return 0; // retorna 0 existe e está livre
	// 		}
	// 	}
	// 	return 1; // 1 se não existe
	// }
	

	// // Preenche as casas do barco
	// void preencher_barco(int linha, int coluna, int tipo_barco, int valor_preencher){
	// 	if(tipo_barco == 1){
	// 		matriz[linha][coluna] = valor_preencher;
	// 	}

	// 	if(tipo_barco == 2){
	// 		matriz[linha][coluna] = valor_preencher;
	// 		matriz[linha][coluna + 1] = valor_preencher;
	// 	}

	// 	if(tipo_barco == 21){
	// 		matriz[linha][coluna] = valor_preencher;
	// 		matriz[linha + 1][coluna] = valor_preencher;
	// 	}

	// 	if(tipo_barco == 3){
	// 		matriz[linha][coluna] = valor_preencher;
	// 		matriz[linha][coluna + 1] = valor_preencher;
	// 		matriz[linha][coluna + 2] = valor_preencher;
	// 	}

	// 	if(tipo_barco == 31){
	// 		matriz[linha][coluna] = valor_preencher;
	// 		matriz[linha + 1][coluna] = valor_preencher;
	// 		matriz[linha + 2][coluna] = valor_preencher;
	// 	}

	// 	if(tipo_barco == 4){
	// 		matriz[linha][coluna] = valor_preencher;
	// 		matriz[linha][coluna + 1] = valor_preencher;
	// 		matriz[linha][coluna + 2] = valor_preencher;
	// 		matriz[linha][coluna + 3] = valor_preencher;
	// 	}

	// 	if(tipo_barco == 41){
	// 		matriz[linha][coluna] = valor_preencher;
	// 		matriz[linha + 1][coluna] = valor_preencher;
	// 		matriz[linha + 2][coluna] = valor_preencher;
	// 		matriz[linha + 3][coluna] = valor_preencher;
	// 	}

	// 	if(tipo_barco == 5){
	// 		matriz[linha][coluna] = valor_preencher;
	// 		matriz[linha][coluna + 1] = valor_preencher;
	// 		matriz[linha][coluna + 2] = valor_preencher;
	// 		matriz[linha][coluna + 3] = valor_preencher;
	// 		matriz[linha][coluna + 4] = valor_preencher;
	// 	}

	// 	if(tipo_barco == 51){
	// 		matriz[linha][coluna] = valor_preencher;
	// 		matriz[linha + 1][coluna] = valor_preencher;
	// 		matriz[linha + 2][coluna] = valor_preencher;
	// 		matriz[linha + 3][coluna] = valor_preencher;
	// 		matriz[linha + 4][coluna] = valor_preencher;
	// 	}


	
	// }


 // 	//carrega o tabuleiro do arquivo
 // 	bool carrega_tabuleiro(int tabuleiro){ 			
	// 	int lin(0);
	// 	int col(0);
	// 	int barc(0);
	// 	int cont(1);

	// 	std::ifstream leitura;
	// 	leitura.open("tabuleiros", std::ios_base::in);
		
	// 	while(cont < tabuleiro){ // move o ponteiro até o tabuleir oescolhido
	// 		if(leitura.eof()){
	// 			std::cout << "Digite um tabuleiro válido" << std::endl;
	// 			return false;
	// 		}
	// 		leitura.get();
	// 		leitura >> lin;
	// 		if(lin == 9999){
	// 			cont++;
	// 		}
	// 	}
	// 	leitura >> linhas;
	// 	leitura.get();
	// 	leitura >> colunas;

	// 	ir::inicializa_matriz(linhas, colunas); // inicializa a matriz para o tabuleiro
	// 	ir::zera_matriz(); // zera os elementos

	// 	for (int i = 0; i < 10; ++i){ // carrega a matriz no tabuleiro
	// 		if(leitura.eof()){
	// 			std::cout << "Digite um tabuleiro válido" << std::endl;
	// 			return false;
	// 		}
	// 		leitura.get(); // carrega a linha
	// 		leitura >> lin;

	// 		leitura.get(); // carrega a coluna
	// 		leitura >> col;

	// 		leitura.get(); // carrega o barco
	// 		leitura >> barc;
	// 		preencher_barco(lin, col, barc, barc); // passa as coordenadas para preencher o barco

			
	// 	}

	// 	return true;
	//  	// retorna false se não houver esse tabuleiro
	//  	// caso contrário, retorna true e carrega o tabuleiro na matriz
 // 	}

 // 	void iniciar_jogo(){
 // 		int jogadas(0);
 // 		int lin(-1);
 // 		int col(-1);
 // 		int erros(0);
 // 		int acertos(0);
 // 		int barcos_restantes = total5 + total4 + total3 + total2 + total1;
 		
 // 		bool final(false);

 // 		while(!final){ // enquanto restar barcos
 // 			system("clear");

	//  		std::cout << "\nNúmero de jogadas: "<< jogadas;
	//  		std::cout << " |||||| Número de erros: "<< erros;
	//  		std::cout << " |||||| Número de acertos: "<< acertos;
	//  		std::cout << " |||||| Barcos restantes: "<< barcos_restantes << std::endl;

	// 		std::cout << "\nBarcos: ";
	//  		std::cout << "\nA - Com 5 casas na horizontal";
	//  		std::cout << "\nB - Com 5 casas na vertical";
	//  		std::cout << "\n\nC - Com 4 casas na horizontal";
	//  		std::cout << "\nD - Com 4 casas na vertical: ";
	//  		std::cout << "\n\nE - Com 3 casas na horizontal";
	//  		std::cout << "\nF - Com 3 casas na vertical";
	//  		std::cout << "\n\nG - Com 2 casas na horizontal";
	//  		std::cout << "\nH - Com 2 casas na vertical";
	//  		std::cout << "\n\nI - Com 1 casa na horizontal";
	 		
	//  		// início do print do tabuleiro
	//  		std::cout << "\n" << std::endl;		
	//  		std::cout << " ";
	// 		for (int i = 0; i < linhas; ++i){
	//  			std::cout << "  " << i;
	//  		}	 
	//  		std::cout << "\n" << std::endl;		
	 		

	//  		for (int i = 0; i < linhas; ++i){
	//  			std::cout << i << "  ";
	// 	        for (int j = 0; j < colunas; ++j){

	// 	        	switch (matriz[i][j]){
	// 				    case 52: // Caso seja 52, esse barco será representado por A
	// 				   		std::cout << "A  ";
	// 				    break;

	// 				    case 512:
	// 				   		std::cout << "B  ";
	// 				    break;
					    
	// 				    case 42:
	// 				   		std::cout << "C  ";
	// 				    break;

	// 				    case 412:
	// 				   		std::cout << "D  ";
	// 				    break;

	// 				    case 32:
	// 				   		std::cout << "E  ";
	// 				    break;

	// 				    case 312:
	// 				   		std::cout << "F  ";
	// 				    break;

	// 				    case 22:
	// 				   		std::cout << "G  ";
	// 				    break;

	// 				    case 212:
	// 				   		std::cout << "H  ";
	// 				    break;

	// 				    case 12:
	// 				   		std::cout << "I  ";
	// 				    break;

	// 				    case -1:
	// 				   		std::cout << "0  ";
	// 				    break;

	// 				    default:
	// 				    	std::cout << "-  ";
	// 				}

	// 	        }
	// 	        std::cout << "\n" << std::endl;
	// 	    }
	// 	    // fim do print do tabuleiro

	// 	    if(barcos_restantes == 0){
	// 	    	std::cout << "\nFim!" << std::endl;
	// 	    	final = true;
	// 	    }else{
	// 	 		std::cout << "\nDigite a linha em que deseja atirar: " << std::endl;
	// 	 		std::cin >> lin;
	// 	 		while((lin < 0) || ( lin > linhas)){ // linha válida
	// 	 			std::cout << "\nLINHA INVÁLIDA" << std::endl;
	// 	 			std::cin >> lin;
	// 	 		}

	// 	 		std::cout << "Digite a coluna em que deseja atirar: " << std::endl;
	// 	 		std::cin >> col;
	// 	 		while((col < 0) || ( col > colunas)){ // coluna válida
	// 	 			std::cout << "\nCOLUNA INVÁLIDA" << std::endl;
	// 	 			std::cin >> col;
	// 	 		}


	// 	 		jogadas++;

	// 	 		if(matriz[lin][col] != 0){ // Caso acerte em um barco
		 			
	// 		 		switch (matriz[lin][col]){ // Verifica qual barco acertou
	// 				    case 5:
	// 				    	acertos ++;
	// 				   		matriz[lin][col] = 52; // Ao acertar o barco, a posição na matriz vira 52 e não mais 5
	// 				    	if(verifica_barco_tiro(lin, col, 52)) barcos_restantes -= 1; 
	// 				    	// verifica se o barco teve todas as casas atingidas
	// 				    break;

	// 				    case 51:
	// 				    	acertos ++;
	// 				   		matriz[lin][col] = 512;
	// 				   		if(verifica_barco_tiro(lin, col, 512)) barcos_restantes -= 1;
	// 				    break;
					    
	// 				    case 4:
	// 				    	acertos ++;
	// 				   		matriz[lin][col] = 42;
	// 				   		if(verifica_barco_tiro(lin, col, 42)) barcos_restantes -= 1;
	// 				    break;

	// 				    case 41:
	// 				    	acertos ++;
	// 				   		matriz[lin][col] = 412;
	// 				   		if(verifica_barco_tiro(lin, col, 412)) barcos_restantes -= 1;
	// 				    break;

	// 				    case 3:
	// 				    	acertos ++;
	// 				   		matriz[lin][col] = 32;
	// 				   		if(verifica_barco_tiro(lin, col, 32)) barcos_restantes -= 1;
	// 				    break;

	// 				    case 31:
	// 				    	acertos ++;
	// 				   		matriz[lin][col] = 312;
	// 				   		if(verifica_barco_tiro(lin, col, 312)) barcos_restantes -= 1;
	// 				    break;

	// 				    case 2:
	// 				    	acertos ++;
	// 				   		matriz[lin][col] = 22;
	// 				   		if(verifica_barco_tiro(lin, col, 22)) barcos_restantes -= 1;
	// 				    break;

	// 				    case 21:
	// 				    	acertos ++;
	// 				   		matriz[lin][col] = 212;
	// 				   		if(verifica_barco_tiro(lin, col, 212)) barcos_restantes -= 1;
	// 				    break;

	// 				    case 1:
	// 				    	acertos ++;
	// 				   		matriz[lin][col] = 12;
	// 				   		barcos_restantes -= 1;
	// 				    break;

	// 				    default:
	// 				    break;
	// 				}
	// 			}else{
	// 				erros++;
	// 			}
	// 		}

 // 		}

 // 	}

 // 	// retorna se o barco foi destruído por completo
 // 	bool verifica_barco_tiro(int linha, int coluna, int tipo_barco){
 // 		int cont(0);
 		
 // 		// verificação dos barcos horizontais
 // 		// o código percorre cada coluna e vai somando caso encontre um acerto próximo, caso não encontre ele para a verificação
 // 		if((tipo_barco == 52) || (tipo_barco == 42) || (tipo_barco == 32) || (tipo_barco == 22)){
	// 		for(int i = 0; (i < 5) && ((i + coluna) < colunas); ++i){ // colunas pra direita
	// 			if(matriz[linha][coluna + i] == tipo_barco){
	// 				cont += 1; // encontrou uma casa atingida e igual ao tipo_barco
	// 			}else{
	// 				i = 999;// encontrou uma casa não atingida, para a verificação
	// 			}
	// 		}

	// 		for(int i = 0; (i < 5) && ((coluna - i) >= 0); ++i){ // colunas para a esquerda
	// 			if(matriz[linha][coluna - i] == tipo_barco){
	// 				cont += 1; // encontrou uma casa atingida e igual ao tipo_barco
	// 			}else{ // encontrou uma casa não atingida, para a verificação
	// 				i = 999;
	// 			}
	// 		}
 // 		}
 // 		//verificação dos barcos na vertical
 // 		if((tipo_barco == 512) || (tipo_barco == 412) || (tipo_barco == 312) || (tipo_barco == 212)){
	// 		for(int i = 0; (i < 5) && ((i + linha) < colunas); ++i){
	// 			if(matriz[linha + i][coluna] == tipo_barco){
	// 				cont += 1;
	// 			}else{
	// 				i = 999;
	// 			}
	// 		}

	// 		for(int i = 0; (i < 5) && ((linha - i) >= 0); ++i){
	// 			if(matriz[linha - i][coluna] == tipo_barco){
	// 				cont += 1;
	// 			}else{
	// 				i = 999;
	// 			}
	// 		}
 // 		}

	// 	cont -= 1; // ajuste, pois a corrdenada do barco é somada duas vezes

	// 	if((cont == 5) && ((tipo_barco == 52) || (tipo_barco == 512))){
	// 		//se o barco 5 teve 5 tiros ao seu lado, então ele foi derrotado
	// 		return true;
	// 	}
	// 	if((cont == 4) && ((tipo_barco == 42) || (tipo_barco == 412))){
	// 		return true;
	// 	}
	// 	if((cont == 3) && ((tipo_barco == 32) || (tipo_barco == 312))){
	// 		return true;
	// 	}
	// 	if((cont == 2) && ((tipo_barco == 22) || (tipo_barco == 212))){
	// 		return true;
	// 	}
	// 	if((cont == 1) && (tipo_barco == 12)){
	// 		return true;
	// 	}
		
 // 		return false;

 // 	}

 // 	void carrega_strings_tabuleiro(){
 // 		//Percorre os tabuleiros do arquivo e transforma cada tabuleiro em uma string, depois salva com ddouble em tabuleiros_array
 // 		int num(0);
	// 	std::string cont_tabuleiro_temp = ""; // string para o tabuleiro

 //        std::ifstream leitura;
 //        leitura.open("tabuleiros", std::ios_base::in);
                
 //        if(leitura.is_open()){ // obtem cada linha, coluna e barco do tabuleiro e concatena em cont_tabuleiro_temp
 //            while(leitura.eof() == 0){
 //                leitura.get();
 //                leitura >> num;
 //                if(num == 9999){
 //                    total_tabuleiros += 1 ;
 //                    tabuleiros_array = (double*) realloc(tabuleiros_array, total_tabuleiros * sizeof(double*));
 //                    tabuleiros_array[total_tabuleiros - 1] = std::atof(cont_tabuleiro_temp.c_str());
 //                    cont_tabuleiro_temp = ""; // limpa a string do tabuleiro
 //                }else{
 //                    cont_tabuleiro_temp = cont_tabuleiro_temp + std::to_string(num); // concatena os itens do tabuleiro
 //                }
 //            }
 //        	leitura.close();
 //        }
 // 	}


 // 	// verifica se o tabuleiro já existe
	// bool verifica_tabuleiro_existe(){
	// 	//Verifica se o tabuleiro gerado já foi gerado antes no arquivo
	// 	std::string cont_tabuleiro_temp = "";  // string para o tabuleiro

	// 	for (int i = 1; i <= total_barcos_fixo; ++i){
	// 		cont_tabuleiro_temp = cont_tabuleiro_temp + std::to_string(m_barcos[i][0]) + std::to_string(m_barcos[i][1]) + std::to_string(m_barcos[i][2]);
	//     }

	//     for (int i = 0; i < total_tabuleiros; ++i){
	//     	if(tabuleiros_array[i] == std::atof(cont_tabuleiro_temp.c_str())){
	//     		return false; // já existe
	//     	}
	//     }	
	//     // Adiciona o tabuleiro no array tabuleiros_array
	//     total_tabuleiros += 1; 
	//     tabuleiros_array = (double*) realloc(tabuleiros_array, total_tabuleiros * sizeof(double*));
	//     tabuleiros_array[total_tabuleiros - 1] = std::atof(cont_tabuleiro_temp.c_str());
	//         return true; // tabuleiro não repetido
	//     }


}


