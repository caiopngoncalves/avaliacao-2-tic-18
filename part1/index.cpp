#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data
{
	int dia, mes, ano;

public:
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/
	static int compara(Data d1, Data d2)
	{
		return 0;
	}

	Data(int _dia, int _mes, int _ano)
	{
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString()
	{
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista
{
public:
	virtual void entradaDeDados() = 0;
	virtual void mostraMediana() = 0;
	virtual void mostraMenor() = 0;
	virtual void mostraMaior() = 0;
};

class ListaNomes: public Lista{
    vector<string> lista;

public:
    void entradaDeDados()
    {
        while (true)
        {
            string nome;
            cout << "Digite o nome (ou digite 0 para sair): ";
            cin >> nome;
            
            if (nome == "0") {
                break; // Sai do loop quando o usuário digita "0"
            }
            
            lista.push_back(nome);
        }
    }

    void mostraMediana()
    {
        if (lista.empty())
        {
            cout << "A lista esta vazia. Nao e possivel calcular a mediana." << endl;
            return;
        }

        vector<string> listaOrdenada = lista;
        sort(listaOrdenada.begin(), listaOrdenada.end());

        int tamanho = listaOrdenada.size();
        if (tamanho % 2 == 0)
        {
            int meio1 = (tamanho - 1) / 2;
            int meio2 = tamanho / 2;
            string mediana1 = listaOrdenada[meio1];
            string mediana2 = listaOrdenada[meio2];
            cout << "A mediana e: " << mediana1 << " e " << mediana2 << endl;
        }
        else
        {
            int meio = tamanho / 2;
            string mediana = listaOrdenada[meio];
            cout << "A mediana e: " << mediana << endl;
        }
    }

    void mostraMenor()
    {
        if (lista.empty())
        {
            cout << "A lista esta vazia. Nao ha nome para mostrar." << endl;
        }
        else
        {
            string menorNome = *min_element(lista.begin(), lista.end());
            cout << "O primeiro nome alfabeticamente e: " << menorNome << endl;
        }
    }

    void mostraMaior()
    {
        if (lista.empty())
        {
            cout << "A lista esta vazia. Nao ha nome para mostrar." << endl;
        }
        else
        {
            string maiorNome = *max_element(lista.begin(), lista.end());
            cout << "O ultimo nome alfabeticamente e: " << maiorNome << endl;
        }
    }
};

class ListaDatas : public Lista
{
	vector<Data> lista;

public:
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/
	void entradaDeDados()
	{
	}

	void mostraMediana()
	{
		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
	}

	void mostraMenor()
	{
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	void mostraMaior()
	{
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
	}
};

class ListaSalarios : public Lista
{
	vector<float> lista;

public:
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/
	void entradaDeDados()
	{int num;
		do {
        std::cout << "Digite um salario: (0 para sair): ";
        std::cin >> num;
		lista.push_back(num);
    } while(num != 0);
	}

	void mostraMediana()
	{cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
		int tamanhoVetor=lista.size();
		if (tamanhoVetor %2 == 0){ 
		int auxiliar = tamanhoVetor/2;
		int auxiliar = (lista[auxiliar] + lista[auxiliar-1])/2; 
		cout<< "O valor da mediana é: "<<auxiliar; 
		}
else {
			int auxiliar= (tamanhoVetor-1)/2;
			cout<< "O valor da mediana e: "<<lista[auxiliar];
		}
	
	}

	void mostraMenor()
	{cout << "Aqui vai mostrar o menor dos salarios" << endl;
		int menor=0, auxiliar=0; 
		for (int elemento : lista) {
			if (elemento<=menor){
				menor = elemento;
			}
    }
		cout<< "O menor elemento é: "<<menor;
		
	}
	void mostraMaior()
	{cout << "aqui vai mostrar o maior dos salarios" << endl;
		int maior=0, auxiliar=0; 
		for (int elemento : lista) {
			if (elemento>=maior){
				maior = elemento;
			}
    }
	cout<< "O maior elemento é: "<<maior;
	
	}
};

class ListaIdades : public Lista
{
	vector<int> lista;

public:
	/*
O m�todo abaixo pergunta ao usu�rios quantos
elementos v�o existir na lista e depois
solicita a digita��o de cada um deles
*/
	void entradaDeDados()
	{
		int num;
		do {
        std::cout << "Digite uma idade (0 para sair): ";
        std::cin >> num;
		lista.push_back(num);
    } while(num != 0);

	}

	void mostraMediana()
	{
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
		int tamanhoVetor=lista.size();
		if (tamanhoVetor %2 == 0){ 
		int auxiliar = tamanhoVetor/2;
		int auxiliar = (lista[auxiliar] + lista[auxiliar-1])/2; 
		cout<< "O valor da mediana é: "<<auxiliar; 
		} else {
			int auxiliar= (tamanhoVetor-1)/2;
			cout<< "O valor da mediana e: "<<lista[auxiliar];
		}
	}

	void mostraMenor()
	{
		cout << "Aqui vai mostrar a menor das idades" << endl;
		int menor=0, auxiliar=0; 
		for (int elemento : lista) {
			if (elemento<=menor){
				menor = elemento;
			}
    }
		cout<< "O menor elemento é: "<<menor;
	}
	void mostraMaior()
	{
		cout << "aqui vai mostrar a maior das idades" << endl;
		int maior=0, auxiliar=0; 
		for (int elemento : lista) {
			if (elemento>=maior){
				maior = elemento;
			}
    }
	cout<< "O maior elemento é: "<<maior;
	}
};

int main()
{
	vector<Lista *> listaDeListas;

	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);

	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);

	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);

	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);

	for (Lista *l : listaDeListas)
	{
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
}
