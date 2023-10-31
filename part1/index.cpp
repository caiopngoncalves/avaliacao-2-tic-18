#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data {
    int dia, mes, ano;

public:
    static int compara(Data d1, Data d2) {
        if (d1.ano < d2.ano)
            return -1;
        else if (d1.ano > d2.ano)
            return 1;
        else if (d1.mes < d2.mes)
            return -1;
        else if (d1.mes > d2.mes)
            return 1;
        else if (d1.dia < d2.dia)
            return -1;
        else if (d1.dia > d2.dia)
            return 1;
        else
            return 0;
    }

    Data(int _dia, int _mes, int _ano) {
        dia = _dia;
        mes = _mes;
        ano = _ano;
    }

    // Sobrecarga do operador de saída
    friend ostream& operator<<(ostream& os, const Data& data) {
        os << data.dia << "/" << data.mes << "/" << data.ano;
        return os;
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
            cout << "A mediana da lista de nomes: " << mediana1 << " e " << mediana2 << endl;
        }
        else
        {
            int meio = tamanho / 2;
            string mediana = listaOrdenada[meio];
            cout << "A mediana da lista de nomes: " << mediana << endl;
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
            cout << "O primeiro nome alfabeticamente: " << menorNome << endl;
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
            cout << "O ultimo nome alfabeticamente: " << maiorNome << endl;
        }
    }
};

class ListaDatas : public Lista {
    vector<Data> lista;

public:
    ListaDatas() {} // Construtor padrão

    void entradaDeDados() override {
        int n;
        cout << "Deseja inserir quantas datas? " << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int dia, mes, ano;
            cout << "Digite o dia (1-31): ";
            cin >> dia;
            cout << "Digite o mes (1-12): ";
            cin >> mes;
            cout << "Digite o ano: ";
            cin >> ano;
            Data data(dia, mes, ano);
            lista.push_back(data);
        }
    }

    void mostraMediana() override {
        if (lista.empty()) {
            cout << "A lista de datas esta vazia." << endl;
        } else {
            // Ordena a lista de datas e exibe a data do meio (mediana)
            sort(lista.begin(), lista.end(), Data::compara);
            int meio = lista.size() / 2;
            cout << "A mediana da lista de datas: " << lista[meio] << endl;
        }
    }

 void mostraMenor() override {
        if (lista.empty()) {
            cout << "A lista de datas esta vazia." << endl;
        } else {
            // Ordena a lista de datas e exibe a primeira data cronologicamente
            sort(lista.begin(), lista.end(), Data::compara);
            cout << "A primeira data na ordem cronologica: " << lista[0] << endl;
        }
    }

    void mostraMaior() override {
        if (lista.empty()) {
            cout << "A lista de datas esta vazia." << endl;
        } else {
            // Ordena a lista de datas em ordem reversa e exibe a última data cronologicamente
            sort(lista.rbegin(), lista.rend(), Data::compara);
            cout << "A ultima data na ordem cronologica: " << lista[0] << endl;
        }
    }

};

class ListaSalarios : public Lista
{
	vector<float> lista;

public:
	
	void entradaDeDados()
	{int num;
		do {
        std::cout << "Digite um salario: (0 para sair): ";
        std::cin >> num;
		lista.push_back(num);
    } while(num != 0);
	}

	void mostraMediana()
	{   int auxiliar;                                                
		int tamanhoVetor=lista.size();
		if (tamanhoVetor %2 == 0){ 
		auxiliar = tamanhoVetor/2;
		auxiliar = (lista[auxiliar] + lista[auxiliar-1])/2; 
		cout<< "Mediana da lista de salarios: "<<auxiliar<<endl; 
		}
else {
			auxiliar= (tamanhoVetor-1)/2;
			cout<< "Mediana da lista de salarios: "<<lista[auxiliar]<<endl;
		}
	
	}

	void mostraMenor()
	{
		int menor=0; 
		for (int elemento : lista) {
			if (elemento<=menor){
				menor = elemento;
			}
    }
		cout<< "O menor salario: "<<menor<<endl;
		
	}
	void mostraMaior()
	{
		int maior=0; 
		for (int elemento : lista) {
			if (elemento>=maior){
				maior = elemento;
			}
    }
	cout<< "O maior salario: "<<maior<<endl;
	
	}
};

class ListaIdades : public Lista
{
	vector<int> lista;

public:

	void entradaDeDados()
	{
		int num;
		do {
        cout << "Digite uma idade (0 para sair): ";
        cin >> num;
		lista.push_back(num);
    } while(num != 0);

	}

	void mostraMediana()
	{
		int tamanhoVetor=lista.size();
		if (tamanhoVetor %2 == 0){ 
		int auxiliar = tamanhoVetor/2;
		auxiliar = (lista[auxiliar] + lista[auxiliar-1])/2; 
		cout<< "Mediana da lista de idades: "<<auxiliar<<endl; 
		} else {
			int auxiliar= (tamanhoVetor-1)/2;
			cout<< "Mediana da lista de idades: "<<lista[auxiliar]<<endl;
		}
	}

	void mostraMenor()
	{

		int menor=0; 
		for (int elemento : lista) {
			if (elemento<=menor){
				menor = elemento;
			}
    }
		cout<< "A menor idade: "<<menor<<endl;
	}
	void mostraMaior()
	{
		int maior=0; 
		for (int elemento : lista) {
			if (elemento>=maior){
				maior = elemento;
			}
    }
	cout<< "A maior idade: "<<maior<<endl;
	}
};

int main()
{
	vector<Lista *> listaDeListas;
    cout<<"LISTA DE IDADES:"<< endl;
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);

    cout<<"LISTA DE DATAS:"<< endl;
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);

     cout<<"LISTA DE SALARIOS:"<< endl;
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);

     cout<<"LISTA DE IDADES:"<< endl;
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);

	for (Lista *l : listaDeListas)
	{   cout<<endl;
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
}
