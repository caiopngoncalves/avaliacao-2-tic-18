#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Data
{
	int dia, mes, ano;

public:
	static int compara(Data d1, Data d2)
	{
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

class ListaNomes : public Lista
{
	vector<string> lista;

public:
	void entradaDeDados()
	{
		int n;
		cout << "Deseja inserir quantos nomes? " << endl;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string nome;
			cout << "Digite o nome: ";
			cin >> nome;
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

		int meio = tamanho / 2;
		string mediana = listaOrdenada[meio];
		cout << "A mediana e: " << mediana << endl;
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
	ListaDatas() {} // Construtor padrão

	void entradaDeDados() override
	{
		int n;
		cout << "Deseja inserir quantas datas? " << endl;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int dia, mes, ano;
			cout << "Digite o dia (1-31): ";
			cin >> dia;
			cout << "Digite o mês (1-12): ";
			cin >> mes;
			cout << "Digite o ano: ";
			cin >> ano;
			Data data(dia, mes, ano);
			lista.push_back(data);
		}
	}

	void mostraMediana() override
	{
		if (lista.empty())
		{
			cout << "A lista de datas está vazia." << endl;
		}
		else
		{
			sort(lista.begin(), lista.end(), [](const Data &d1, const Data &d2)
				 { return Data::compara(d1, d2) < 0; });

			int meio = lista.size() / 2;
			cout << "A mediana é: " << lista[meio].toString() << endl;
		}
	}

	void mostraMenor() override
	{
		if (lista.empty())
		{
			cout << "A lista de datas está vazia." << endl;
		}
		else
		{
			sort(lista.begin(), lista.end(), [](const Data &d1, const Data &d2)
				 { return Data::compara(d1, d2) < 0; });

			cout << "A primeira data cronologicamente é: " << lista.front().toString() << endl;
		}
	}

	void mostraMaior() override
	{
		if (lista.empty())
		{
			cout << "A lista de datas está vazia." << endl;
		}
		else
		{
			sort(lista.begin(), lista.end(), [](const Data &d1, const Data &d2)
				 { return Data::compara(d1, d2) > 0; });

			cout << "A última data cronologicamente é: " << lista.front().toString() << endl;
		}
	}
};

class ListaSalarios : public Lista
{
	vector<float> lista;

public:
	void entradaDeDados() override
	{
		float num;
		int n;
		cout << "Deseja inserir quantos salarios? " << endl;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Digite um salario: ";
			cin >> num;
			lista.push_back(num);
		}
	}

	void mostraMediana() override
	{
		cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
		int tamanhoVetor = lista.size();
		if (tamanhoVetor == 0)
		{
			cout << "A lista de salários está vazia." << endl;
			return;
		}

		sort(lista.begin(), lista.end());

		if (tamanhoVetor % 2 == 0)
		{
			int meio1 = tamanhoVetor / 2 - 1;
			int meio2 = tamanhoVetor / 2;
			float mediana = (lista[meio1] + lista[meio2]) / 2.0;
			cout << "O valor da mediana eh: " << mediana << endl;
		}
		else
		{
			int meio = tamanhoVetor / 2;
			cout << "O valor da mediana eh: " << lista[meio] << endl;
		}
	}

	void mostraMenor() override
	{
		cout << "Aqui vai mostrar o menor dos salarios" << endl;
		if (lista.empty())
		{
			cout << "A lista de salários está vazia." << endl;
		}
		else
		{
			float menorSalario = *min_element(lista.begin(), lista.end());
			cout << "O menor salario eh: " << menorSalario << endl;
		}
	}

	void mostraMaior() override
	{
		cout << "aqui vai mostrar o maior dos salarios" << endl;
		if (lista.empty())
		{
			cout << "A lista de salários está vazia." << endl;
		}
		else
		{
			float maiorSalario = *max_element(lista.begin(), lista.end());
			cout << "O maior salario eh: " << maiorSalario << endl;
		}
	}
};

class ListaIdades : public Lista
{
	vector<int> lista;

public:
	void entradaDeDados() override
	{
		int num;
		int n;
		cout << "Deseja inserir quantas idades? " << endl;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Digite uma idade: ";
			cin >> num;
			lista.push_back(num);
		}
	}

	void mostraMediana() override
	{
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
		int tamanhoVetor = lista.size();
		if (tamanhoVetor == 0)
		{
			cout << "A lista de idades está vazia." << endl;
			return;
		}

		sort(lista.begin(), lista.end());

		if (tamanhoVetor % 2 == 0)
		{
			int meio1 = tamanhoVetor / 2 - 1;
			int meio2 = tamanhoVetor / 2;
			int mediana = (lista[meio1] + lista[meio2]) / 2;
			cout << "O valor da mediana eh: " << mediana << endl;
		}
		else
		{
			int meio = tamanhoVetor / 2;
			cout << "O valor da mediana e: " << lista[meio] << endl;
		}
	}

	void mostraMenor() override
	{
		cout << "Aqui vai mostrar a menor das idades" << endl;
		if (lista.empty())
		{
			cout << "A lista de idades está vazia." << endl;
		}
		else
		{
			int menorIdade = *min_element(lista.begin(), lista.end());
			cout << "A menor idade eh: " << menorIdade << endl;
		}
	}

	void mostraMaior() override
	{
		cout << "aqui vai mostrar a maior das idades" << endl;
		if (lista.empty())
		{
			cout << "A lista de idades está vazia." << endl;
		}
		else
		{
			int maiorIdade = *max_element(lista.begin(), lista.end());
			cout << "A maior idade eh: " << maiorIdade << endl;
		}
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
