#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

int FunctionForCheck();
string FunctionForSpaces();
double FunctionForDouble();

namespace Menu
{
	int AutorizationMenu1()
	{
		int i = 0;
		cin.exceptions(cin.failbit);
		cout << "Этап авторизации\nВыберите:\n";
		cout << "1. Регистрация\n2. Вход\n3. Выход\n";
		i = FunctionForCheck();
		return i;
	}
	int AutorizationMenu2()
	{
		int i = 0;
		cout << "Выберите:\n1. Зарегистрироваться как администратор\n"
			 << "2. Зарегистрироваться как поставщик\n3. Зарегистрироваться как клиент\n4. Предыдущее меню\n";
		cin.clear();
		i = FunctionForCheck();
		return i;
	}
	int AutorizationMenu3()
	{
		int i = 0;
		cout << "Выберите:\n1. Войти как администратор\n2. Войти как поставщик\n3. Войти как клиент\n4. Предыдущее меню\n";
		cin.clear();
		i = FunctionForCheck();
		return i;
	}
	int AdminMenu()
	{
		int i = 0;
		cout << "Выбирайте:\n1. Просмотр товаров на складе\n2. Сортировка товаров по количеству\n3. Просмотр списка администраторов\n"
			 << "4. Просмотр списка клиентов\n5. Просмотр списка поставщиков\n6. Удаление информации об администраторе из базы\n"
			 << "7. Удаление информации о клиенте из базы\n8. Удаление информации о поставщике из базы\n"
			 << "9. Просмотреть личную информацию\n10. Изменить личную информацию\n11. Выход\n";
		cin.clear();
		i = FunctionForCheck();
		return i;
	}
	int SupplierMenu()
	{
		int i = 0;
		cout << "Выбирайте:\n1. Поставка товаров на склад\n2. Просмотр товаров на складе\n3. Изменить информацию о товаре\n"
			 << "4. Удалить информацию о товаре\n5. Сортировка товаров по количеству\n6. Просмотреть личную информацию\n"
			 << "7. Изменить личную информацию\n8. Выход\n";
		cin.clear();
		i = FunctionForCheck();
		return i;
	}
	int ClientMenu()
	{
		int i = 0;
		cout << "Выбирайте:\n1. Просмотр товаров на складе\n2. Добавить товар в корзину\n3. Удалить товар из корзины\n"
			<< "4. Просмотреть корзину\n5. Оформить заказ\n6. Получить копию чека\n7. Просмотреть личную информацию\n8. Изменить личную информацию\n9. Выход\n";
		cin.clear();
		i = FunctionForCheck();
		return i;
	}
}

using namespace Menu;

class Authorization
{
protected:
	string login, password, org, fio, tel, email;
    string loginR, passwordR, Check;
    bool complite = false;
public:
    bool check(string Check)
    {
        if (Check.find(loginR) >= 0 && Check.find(loginR) < 1000)
        {
            if (Check.find(passwordR) >= 0 && Check.find(passwordR) < 1000) { return true; }
        }
        return false;
    }
	bool reg(string login, string password, int type)
	{
        ofstream fout;
        string File_name;
		if (type == 1) { File_name = "admin.txt"; }
		else if (type == 2) { File_name = "suplier.txt"; }
        else if (type == 3) { File_name = "client.txt"; }
        fout.open(File_name, ios::app);
		if (fout.is_open())
		{
			fout << login << " " << password << endl;
			fout.close();
			return true;
		}
		else
		{
			cout << "\nФайл пуст!\n";
			return false;
		}        
	}
	bool log(string login, string password, int type)
	{
        string File_name;
        this->loginR = login;
        this->passwordR = password;
        if (type == 1) { File_name = "admin.txt"; }
        else if (type == 2) { File_name = "suplier.txt"; }
        else if (type == 3) { File_name = "client.txt"; }
        ifstream fin(File_name);
        while (getline(fin, Check)) 
        {
            if (check(Check)) 
            {
                complite = true;
                break;
            }
            else 
            {
                complite = false;
            }
        }
        return complite;
	}
    void set(string login, string password)
    {
        loginR = login;
        passwordR = password;
    }
    void wtofc()
    {
        ofstream fout;
        fout.open("client.txt", ios::app);
		if (fout.is_open())
		{
			fout << loginR << " " << passwordR << endl;
			fout.close();
		}
    }
	void wtofs()
	{
		ofstream fout;
		fout.open("suplier.txt", ios::app);
		if (fout.is_open())
		{
			fout << loginR << " " << passwordR << endl;
			fout.close();
		}
	}
	void wtofa()
	{
		ofstream fout;
		fout.open("admin.txt", ios::app);
		if (fout.is_open())
		{
			fout << loginR << " " << passwordR << endl;
			fout.close();
		}
	}
	string RetFIO() { return fio; }
	friend ostream& operator<<(ostream& stream, Authorization obj)
	{
		stream << obj.login << "\t";
		stream << obj.password << "\t";
		return stream;
	}
};

class Good
{
protected:
	string name, firm, suplierlog;
	int amount = 0;
	double cost = 0;
public:
	Good() {};
	virtual void set(string, string, string, string, int, double, string) = 0;
	virtual void add() = 0;
	virtual void writeInBas(string) = 0;
	virtual void view(int) const = 0;
	virtual void viewAll() = 0;
	virtual void viewBusket(string) = 0;
	virtual void viewForSup(string) = 0;
	virtual void del(int, string) = 0;
	virtual void change(int, string) =0;
	virtual void sort()=0;
	virtual void filter(double)=0;
	virtual void addToBasket(string)=0;
	virtual void order(string)=0;
	virtual bool search() = 0;
	virtual void getOrder(string) = 0;
};

class Prod : public Good
{
private:
	string date1, date2;
public:
	Prod() : Good() {};
	void set(string n, string f, string d1, string d2, int a, double c, string s)
	{
		this->name = n;
		this->firm = f;
		this->date1 = d1;
		this->date2 = d2;
		this->amount = a;
		this->cost = c;
		this->suplierlog = s;
	}
	void add()
	{
		ofstream fout;
		fout.open("ProdGoods.txt", ios::app);
		if (fout.is_open())
		{
			fout << endl;
			fout << name << "\t" << firm << "\t" << date1 << '\t' << date2 << "\t" << amount << "\t"
				<< cost << "\t" << suplierlog;
			fout.close();
		}
	}
	void writeInBas(string clientlog)
	{
		ofstream fout;
		fout.open("ClientBasket.txt", ios::app);
		if (fout.is_open())
		{
			fout << endl;
			fout << name << "\t" << firm << "\t" << date1 << "\t" << date2 << "\t" << amount << "\t"
				<< cost << "\t" << suplierlog << "\t" << clientlog;
			fout.close();
		}
	}
	void view(int counter) const
	{
		cout.setf(ios::left);
		cout << counter++ << ". " << setw(25) << name << setw(25) << firm << setw(19)
			<< date1 << setw(11) << date2 << setw(10) << right << amount << "  " << left << setw(6) << cost << " BYN " << endl;
	} 
	void viewAll()
	{
		ifstream fin;
		int countOfGoods = 1;
		fin.open("ProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			cout << "\nПроизводственные товары: " << endl;
			cout.setf(ios::left);
			cout << setw(28) << "Наименование товара " << setw(25) << "Фирма " << setw(19) << "Дата изготовления "
				<< setw(11) << "Годен до   " << setw(12) << "Количество " << setw(6) << "Цена" << endl;
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplierlog)
			{
				view(countOfGoods++);
			}
			cout << endl;
			fin.close();
		}
		if (countOfGoods == 1)
		{
			cout << "Товаров на складе нет.\n";
		}
	}
	void viewBusket(string clientlog)
	{
		ifstream fin;
		string log;
		int countOfGoods = 1;
		fin.open("ClientBasket.txt", ios::in);
		if (fin.is_open())
		{
			cout << "\nПроизводственные товары: " << endl;
			cout.setf(ios::left);
			cout << setw(28) << "Наименование товара " << setw(25) << "Фирма " << setw(19) << "Дата изготовления "
				<< setw(11) << "Годен до   " << setw(12) << "Количество " << setw(6) << "Цена" << endl;
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplierlog >> log)
			{
				if (log == clientlog)
					view(countOfGoods++);
			}
			cout << endl;
			fin.close();
		}
		if (countOfGoods == 1)
		{
			cout << "В корзине нет товаров.\n";
		}
	}
	void viewForSup(string suplog)
	{
		ifstream fin;
		string log;
		int countOfGoods = 1;
		fin.open("ProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			cout << "\nПроизводственные товары: " << endl;
			cout.setf(ios::left);
			cout << setw(28) << "Наименование товара " << setw(25) << "Фирма " << setw(19) << "Дата изготовления "
				<< setw(11) << "Годен до   " << setw(12) << "Количество " << setw(6) << "Цена" << endl;
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplierlog)
			{
				if (suplierlog == suplog)
					view(countOfGoods++);
			}
			cout << endl;
			fin.close();
		}
		if (countOfGoods == 1)
		{
			cout << "На складе нет ваших товаров.\n";
		}
	}
	void del(int countToDel, string log)
	{
		ifstream fin;
		int newCounter = 0;
		countToDel--;
		Prod ToDel;
		vector<Prod> pr;
		fin.open("ProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplierlog)
			{
				if (suplierlog != log)
				{
					ToDel.set(name, firm, date1, date2, amount, cost, suplierlog);
					pr.push_back(ToDel);
				}
				else
				{
					if (newCounter != countToDel)
					{
						ToDel.set(name, firm, date1, date2, amount, cost, suplierlog);
						pr.push_back(ToDel);
					}
					newCounter++;
				}
			}
			fin.close();
		}		
		ofstream fout;
		fout.open("ProdGoods.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].add();
			}
			pr.clear();
			fout.close();
			cout << "Удаление прошло успешно" << endl;
		}
	}
	void delAll(string log)
	{
		ifstream fin;
		Prod ToDel;
		vector<Prod> pr;
		fin.open("ProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplierlog)
			{
				if (suplierlog != log)
				{
					ToDel.set(name, firm, date1, date2, amount, cost, suplierlog);
					pr.push_back(ToDel);
				}
			}
			fin.close();
		}
		ofstream fout;
		fout.open("ProdGoods.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].add();
			}
			pr.clear();
			fout.close();
			cout << "Удаление производственных товаров поставщика прошло успешно" << endl;
		}
	}
	void change(int countToChange, string log)
	{
		ifstream fin;
		int newCounter = 0;
		countToChange--;
		Prod ToChange;
		vector<Prod> pr;
		fin.open("ProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplierlog)
			{
				if (suplierlog != log)
				{
					ToChange.set(name, firm, date1, date2, amount, cost, suplierlog);
					pr.push_back(ToChange);
				}
				else
				{
					if (newCounter != countToChange)
					{
						ToChange.set(name, firm, date1, date2, amount, cost, suplierlog);
						pr.push_back(ToChange);
					}
					else
					{
						name[0] = '\0'; firm[0] = '\0';
						date1[0] = '\0'; date2[0] = '\0';
						cin.ignore();
						while (name[0] == '\0')
						{
							cout << "Введите новые данные.\nНаименование: ";
							getline(cin, name);
						}
						while (firm[0] == '\0')
						{
							cout << "Фирма: ";
							getline(cin, firm);
						}
						while (date1[0] == '\0')
						{
							cout << "Дата изготовления (в формате 01.01.2022): ";
							date1 = FunctionForSpaces();
						}
						while (date2[0] == '\0')
						{
							cout << "Годен до (в формате 01.01.2022): ";
							date2 = FunctionForSpaces();
						}
						cout << "Количество: ";
						amount = FunctionForCheck();
						cout << "Цена: ";
						cost = FunctionForDouble();
						ToChange.set(name, firm, date1, date2, amount, cost, suplierlog);
						pr.push_back(ToChange);
					}
					newCounter++;
				}
			}
			fin.close();
		}
		ofstream fout;
		fout.open("ProdGoods.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].add();
			}
			pr.clear();
			fout.close();
			cout << "Редактирование прошло успешно" << endl;
		}
	}
	void sort()
	{
		ifstream fin;
		Prod ToChange;
		vector<Prod> pr;
		fin.open("ProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplierlog)
			{
				ToChange.set(name, firm, date1, date2, amount, cost, suplierlog);
				pr.push_back(ToChange);
			}
			fin.close();
		}
		for (auto i = 1; i < pr.size(); i++)
			for (auto j = pr.size() - 1; j >= i; j--)
				if (pr[j - 1] > pr[j])
				{
					Prod temp;
					temp = pr[j - 1];
					pr[j - 1] = pr[j];
					pr[j] = temp;
				}
		ofstream fout;
		fout.open("ProdGoods.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].add();
			}
			fout.close();
		}
		pr.clear();
		cout << "Сортировка производственных товаров прошла успешно" << endl;
	}
	void filter(double maxcost)
	{
		ifstream fin;
		Prod ToFilt;
		vector<Prod> pr, temp;
		bool j = 0;
		string tmp;
		fin.open("ProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplierlog)
			{
				ToFilt.set(name, firm, date1, date2, amount, cost, suplierlog);
				pr.push_back(ToFilt);
			}
			fin.close();
		}
		cout << "Фильтрация прошла успешно.\nВаш отфильтрованный список товаров:\n";
		cout.setf(ios::left);
		cout << setw(28) << "Наименование товара " << setw(25) << "Фирма " << setw(19) << "Дата изготовления "
			<< setw(11) << "Годен до   " << setw(12) << "Количество " << setw(6) << "Цена" << endl;
		for (auto i = 0; i < pr.size(); i++)
		{
			if (pr[i].cost <= maxcost)
			{
				j = 1;
				cout.setf(ios::left);
				cout << i+1 << ". " /*<< setw(25) << pr[i].name << setw(25) << pr[i].firm << setw(19) << pr[i].date1 << setw(11)
					<< pr[i].date2 << setw(10) << right << pr[i].amount << setw(6) << pr[i].cost << left << " BYN " << endl*/;
				cout << pr[i];
			}
			else if (j == 0) cout << "Подходящик товаров на складе нет.\n";
		}
		pr.clear();
	}
	bool search()
	{
		ifstream fin;
		Prod ToSearch;
		vector<Prod> pr, temp;
		int i = 0;
		bool t = false;
		string nameForSearch;
		cout << "Введите наименование искомого товара: ";
		cin.ignore();
		getline(cin,nameForSearch);
		fin.open("ProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplierlog)
			{
				ToSearch.set(name, firm, date1, date2, amount, cost, suplierlog);
				pr.push_back(ToSearch);
			}
			fin.close();
		}
		for (auto i = 0; i < pr.size(); i++)
		{
			if (pr[i].name == nameForSearch)
			{
				t = true;
				cout << "Поиск прошёл успешно.\n";
				cout.setf(ios::left);
				cout << setw(28) << "Наименование товара " << setw(25) << "Фирма " << setw(19) << "Дата изготовления "
					<< setw(11) << "Годен до   " << setw(12) << "Количество " << setw(4) << "Цена" << endl;
				cout.setf(ios::left);
				cout << i + 1 << ". " << setw(25) << pr[i].name << setw(25) << pr[i].firm << setw(19) << pr[i].date1 << setw(11)
					<< pr[i].date2 << setw(10) << right << pr[i].amount << setw(6) << pr[i].cost << left << " BYN " << endl;
			}
			else if (i == pr.size()) cout << "Подходящик товаров на складе нет.\n";
		}
		pr.clear();
		return t;
	}
	void addToBasket(string clientlog)
	{
		Prod pr;
		Prod Added;
		vector<Prod> Rewrite;
		int countAdd = 0, currentcount = 0, am = 0;
		ifstream fin;
		fin.open("ProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			cout << "Введите номер товара для добавления его в корзину" << endl;
			cin >> countAdd;
			countAdd--;
			cout << "В каком количестве: ";
			cin >> am;
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplierlog)
			{
				if (countAdd == currentcount++)
				{
					Added.set(name, firm, date1, date2, amount, cost, suplierlog);
					Rewrite.push_back(Added);
				}
				else
				{
					pr.set(name, firm, date1, date2, amount, cost, suplierlog);
					Rewrite.push_back(pr);
				}
			}
			fin.close();
		}
		ofstream fout;
		fout.open("ProdGoods.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < Rewrite.size(); i++)
			{
				Rewrite[i].add();
			}
			fout.close();
		}
		if (Added.amount < am)
			cout << "Данного товара в таком количестве нет!\n";
		else
		{
			fout.open("ClientBasket.txt", ios::app);
			if (fout.is_open())
			{
				fout << endl;
				fout << Added.name << "\t" << Added.firm << "\t" << Added.date1
					<< "\t" << Added.date2 << "\t" << am << "\t" << Added.cost << "\t" << Added.suplierlog << "\t" << clientlog;
				fout.close();
				cout << "Добавление прошло успешно!" << endl;
			}
		}
		Rewrite.clear();
	}
	void order(string clientlog)
	{
		Prod pr, temp;
		string log;
		double all = 0, all2 = 0;
		vector<Prod> v, t;
		ifstream fin;
		fin.open("ClientBasket.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplierlog >> log)
			{
				if (log == clientlog)
				{
					pr.set(name, firm, date1, date2, amount, cost, suplierlog);
					v.push_back(pr);
				}
			}
			fin.close();
		}
		cout << "Ваши покупки из производственных товаров:\n";
		for (auto i = 0; i < v.size(); i++)
		{
			cout.setf(ios::left);
			cout << setw(25) << v[i].name << setw(25) << v[i].firm << setw(19) << v[i].date1 << setw(11)
				<< v[i].date2 << setw(10) << right << v[i].amount << setw(6) << v[i].cost << left << " BYN " << endl;
			all += v[i].amount * v[i].cost;
		}
		cout << "Общей стоимостью: " << all << " BYN " << endl << endl;

		ofstream fout;
		fout.open("ClientsOrder.txt", ios::app);
		for (auto i = 0; i < v.size(); i++)
		{
			fout.setf(ios::left);
			fout << endl;
			fout << v[i].name << '\t' << v[i].firm << '\t' << v[i].date1 << '\t'
				<< v[i].date2 << '\t' << right << v[i].amount << '\t' << v[i].cost << '\t' << all << '\t' << clientlog;
		}
		fout.close();

		fin.open("ProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplierlog)
			{
				for (auto j = 0; j < v.size(); j++)
				{
					if (name == v[j].name)
					{
						amount -= v[j].amount;
					}
				}
				temp.set(name, firm, date1, date2, amount, cost, suplierlog);
				t.push_back(temp);
			}
			fin.close();
		}
		
		fout.open("ProdGoods.txt");
		if (fout.is_open())
		{
			/*fout << endl;*/
			for (auto i = 0; i < t.size(); i++)
			{
				/*fout << t[i];*/
				t[i].add();
			}
			fout.close();
		}
	}
	void getOrder(string clientlog)
	{
		ifstream fin;
		string log;
		double all = 0;
		fin.open("ClientsOrder.txt");
		if (fin.is_open())
		{
			cout << "Ваши покупки из производственных товаров:\n";
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> all >> log)
			{
				if (clientlog == log)
				{
					cout.setf(ios::left);
					cout << setw(25) << name << setw(25) << firm << setw(19) << date1 << setw(11)
						<< date2 << setw(10) << right << amount << setw(6) << cost << left << " BYN " << endl;
				}
			}
			fin.close();
		}
	}

	friend bool operator>(const Prod& obj1, const Prod& obj2)
	{
		return obj1.amount > obj2.amount;
	}
	friend bool operator==(Prod a, Prod b) 
	{ return ((a.name) == (b.name) && ((a.cost) == (b.cost)) && ((a.suplierlog) == (b.suplierlog))); }
	friend ostream& operator<<(ostream& stream, Prod obj)
		{
			stream << setw(25);
			stream << obj.name << setw(25);
			stream << obj.firm << setw(19);
			stream << obj.date1 << setw(11);
			stream << obj.date2 << setw(10) << right;
			stream << obj.amount << setw(6);
			stream << obj.cost << left << " BYN " << endl;
			//stream << obj.suplierlog << "\n";
			return stream;
		}
};

class NonProd : public Good
{
private:
	string size, date;
	double l = 0, w = 0, h = 0;
public:
	NonProd() : Good() {};
	void set(string n, string f, string d, string sz, int a, double c, string s)
	{
		this->name = n;
		this->firm = f;
		this->date = d;
		this->size = sz;
		this->amount = a;
		this->cost = c;
		this->suplierlog = s;
	}
	void add()
	{
		ofstream fout;
		fout.open("NonProdGoods.txt", ios::app);
		if (fout.is_open())
		{
			fout << endl;
			fout << name << "\t" << firm << "\t" << date << "\t" << size << '\t' << amount << "\t" << cost << "\t" << suplierlog;
			fout.close();
		}
	}
	void writeInBas(string clientlog)
	{
		ofstream fout;
		fout.open("ClientBasket2.txt", ios::app);
		if (fout.is_open())
		{
			fout << endl;
			fout << name << "\t" << firm << "\t" << date << "\t" << size << '\t' << amount << "\t"
				<< cost << "\t" << suplierlog << "\t" << clientlog;
			fout.close();
		}
	}
	void view(int counter) const
	{
		cout.setf(ios::left);
		cout << counter++ << ". " << setw(25) << name << setw(25) << firm << setw(19) << date << setw(16)
			<<  size << setw(10) << right << amount << "  " << setw(6) << left << cost << " BYN " << endl;
	}
	void viewAll()
	{
		ifstream fin;
		int countOfGoods = 1;
		fin.open("NonProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			cout << "\nНепроизводственные товары: " << endl;
			cout.setf(ios::left);
			cout << setw(28) << "Наименование товара " << setw(25) << "Фирма " << setw(19) << "Дата изготовления "
				<< setw(16) << "Размер" << setw(12) << "Количество  " << setw(6) << "Цена" << endl;
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplierlog)
			{
				view(countOfGoods++);
			}
			cout << endl;
			if (countOfGoods == 1)
			{
				cout << "Товаров на складе нет.\n";
			}
			fin.close();
		}
	}
	void viewBusket(string clientlog)
	{
		ifstream fin;
		string log;
		int countOfGoods = 1;
		fin.open("ClientBasket2.txt", ios::in);
		if (fin.is_open())
		{
			cout << "\nНепроизводственные товары: " << endl;
			cout.setf(ios::left);
			cout << setw(28) << "Наименование товара " << setw(25) << "Фирма " << setw(19) << "Дата изготовления "
				<< setw(16) << "Размер" << setw(12) << "Количество  " << setw(6) << "Цена" << endl;
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplierlog >> log)
			{
				if (log == clientlog)
					view(countOfGoods++);
			}
			cout << endl;
			if (countOfGoods == 1)
			{
				cout << "В корзине нет товаров.\n";
			}
			fin.close();
		}
	}
	void viewForSup(string suplog)
	{
		ifstream fin;
		string log;
		int countOfGoods = 1;
		fin.open("NonProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			cout << "\nНепроизводственные товары: " << endl;
			cout.setf(ios::left);
			cout << setw(28) << "Наименование товара " << setw(25) << "Фирма " << setw(19) << "Дата изготовления "
				<< setw(16) << "Размер" << setw(12) << "Количество " << setw(6) << "Цена" << endl;
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplierlog)
			{
				if (suplierlog == suplog)
					view(countOfGoods++);
			}
			cout << endl;
			if (countOfGoods == 1)
			{
				cout << "На складе нет ваших товаров.\n";
			}
			fin.close();
		}
	}
	void del(int countToDel, string log)
	{
		ifstream fin;
		int newCounter = 0;
		countToDel--;
		NonProd ToDel;
		vector<NonProd> pr;
		fin.open("NonProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplierlog)
			{
				if (suplierlog != log)
				{
					ToDel.set(name, firm, date, size, amount, cost, suplierlog);
					pr.push_back(ToDel);
				}
				else
				{
					if (newCounter != countToDel)
					{
						ToDel.set(name, firm, date, size, amount, cost, suplierlog);
						pr.push_back(ToDel);
					}
					newCounter++;
				}
			}
			fin.close();
		}


		ofstream fout;
		fout.open("NonProdGoods.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].add();
			}
			pr.clear();
			fout.close();
			cout << "Удаление прошло успешно" << endl;
		}

	}
	void delAll(string log)
	{
		ifstream fin;
		NonProd ToDel;
		vector<NonProd> pr;
		fin.open("NonProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplierlog)
			{
				if (suplierlog != log)
				{
					ToDel.set(name, firm, date, size, amount, cost, suplierlog);
					pr.push_back(ToDel);
				}
			}
			fin.close();
		}

		ofstream fout;
		fout.open("NonProdGoods.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].add();
			}
			pr.clear();
			fout.close();
			cout << "Удаление производственных товаров поставщика прошло успешно" << endl;
		}

	}
	void change(int countToChange, string log)
	{
		ifstream fin;
		int newCounter = 0;
		countToChange--;
		NonProd ToChange;
		vector<NonProd> pr;
		fin.open("NonProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplierlog)
			{
				if (suplierlog != log)
				{
					ToChange.set(name, firm, date, size, amount, cost, suplierlog);
					pr.push_back(ToChange);
				}
				else
				{
					if (newCounter != countToChange)
					{
						ToChange.set(name, firm, date, size, amount, cost, suplierlog);
						pr.push_back(ToChange);
					}
					else
					{
						name[0] = '\0'; firm[0] = '\0';
						date[0] = '\0';
						cin.ignore();
						cout << "Введите новые данные.";
						while (name[0] == '\0')
						{
							cout << "\nНаименование: ";
							getline(cin, name);
						}
						while (firm[0] == '\0')
						{
							cout << "Фирма: ";
							getline(cin, firm);
						}
						while (date[0] == '\0')
						{
							cout << "Дата изготовления: ";
							cin >> date;
						}
						cout << "Размер: \n Длина: ";
						l = FunctionForDouble();
						cout << "Ширина: ";
						w = FunctionForDouble();
						cout << "Высота: ";
						h = FunctionForDouble();
						size = NumToStr(l) + 'x' + NumToStr(w) + 'x' + NumToStr(h);
						cout << "Количество: ";
						amount = FunctionForCheck();
						cout << "Цена: ";
						cost = FunctionForDouble();
						ToChange.set(name, firm, date, size, amount, cost, suplierlog);
						pr.push_back(ToChange);
					}
					newCounter++;
				}
			}
			fin.close();
		}


		ofstream fout;
		fout.open("NonProdGoods.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].add();
			}
			pr.clear();
			fout.close();
			cout << "Редактирование прошло успешно" << endl;
		}

	}
	void sort()
	{
		ifstream fin;
		NonProd ToChange;
		vector<NonProd> pr;
		fin.open("NonProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplierlog)
			{
				ToChange.set(name, firm, date, size, amount, cost, suplierlog);
				pr.push_back(ToChange);
			}
			fin.close();
		}


		for (auto i = 1; i < pr.size(); i++)
			for (int j = pr.size() - 1; j >= i; j--)
				if (pr[j - 1] > pr[j])
				{
					NonProd temp;
					temp = pr[j - 1];
					pr[j - 1] = pr[j];
					pr[j] = temp;
				}

		ofstream fout;
		fout.open("NonProdGoods.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].add();
			}
			fout.close();
			pr.clear();
			cout << "Сортировка непроизводственных товаров прошла успешно" << endl;
		}

	}
	void filter(double maxcost)
	{
		ifstream fin;
		NonProd ToFilt;
		vector<NonProd> pr, temp;
		bool j = 0;
		fin.open("NonProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplierlog)
			{
				ToFilt.set(name, firm, date, size, amount, cost, suplierlog);
				pr.push_back(ToFilt);
			}
			fin.close();
		}

		cout << "Фильтрация прошла успешно.\nВаш отфильтрованный список товаров:\n";
		cout.setf(ios::left);
		cout << setw(28) << "Наименование товара " << setw(25) << "Фирма " << setw(19) << "Дата изготовления "
			<< setw(16) << "Размер" << setw(12) << "Количество " << setw(6) << "Цена" << endl;
		for (auto i = 0; i < pr.size(); i++)
		{
			if (pr[i].cost <= maxcost)
			{
				j = 1;
				cout.setf(ios::left);
				cout << i+1 << ". " /*<< setw(25) << pr[i].name << setw(25) << pr[i].firm << setw(19) << pr[i].date << setw(11)
					<< pr[i].size << setw(10) << right << pr[i].amount << setw(6) << pr[i].cost << left << " BYN " << endl*/;
				cout << pr[i];
			}
			else if (j == 0) cout << "Подходящик товаров на складе нет.\n";
		}
		pr.clear();
	}
	bool search()
	{
		ifstream fin;
		NonProd ToSearch;
		vector<NonProd> pr, temp;
		int i = 0;
		bool t = false;
		string nameForSearch;
		cout << "Введите наименование искомого товара: ";
		cin.ignore();
		getline(cin, nameForSearch);
		fin.open("NonProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplierlog)
			{
				ToSearch.set(name, firm, date, size, amount, cost, suplierlog);
				pr.push_back(ToSearch);
			}
			fin.close();
		}
		for (auto i = 0; i < pr.size(); i++)
		{
			if (pr[i].name == nameForSearch)
			{
				t = true;
				cout << "Поиск прошёл успешно.\n";
				cout.setf(ios::left);
				cout << setw(28) << "Наименование товара " << setw(25) << "Фирма " << setw(19) << "Дата изготовления "
					<< setw(11) << "Годен до   " << setw(12) << "Количество " << setw(4) << "Цена" << endl;
				cout.setf(ios::left);
				cout << i + 1 << ". " << setw(25) << pr[i].name << setw(25) << pr[i].firm << setw(19) << pr[i].date << setw(11)
					<< pr[i].size << setw(10) << right << pr[i].amount << setw(6) << pr[i].cost << left << " BYN " << endl;
			}
			else if (i == pr.size() - 1) cout << "Подходящик товаров на складе нет.\n";
		}
		pr.clear();
		return t;
	}
	void addToBasket(string clientlog)
	{
		NonProd pr;
		NonProd Added;
		vector<NonProd> Rewrite;
		int countAdd = 0, currentcount = 0, am = 0;
		ifstream fin;
		fin.open("NonProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			cout << "Введите номер товара для добавления его в корзину" << endl;
			cin >> countAdd;
			countAdd--;
			cout << "В каком количестве: ";
			cin >> am;
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplierlog)
			{
				if (countAdd == currentcount++)
				{
					Added.set(name, firm, date, size, amount, cost, suplierlog);
					Rewrite.push_back(Added);
				}
				else
				{
					pr.set(name, firm, date, size, amount, cost, suplierlog);
					Rewrite.push_back(pr);
				}
			}
			fin.close();
		}

		ofstream fout;
		fout.open("NonProdGoods.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < Rewrite.size(); i++)
			{
				Rewrite[i].add();
			}
			fout.close();
		}

		if (Added.amount < am)
			cout << "Данного товара в таком количестве нет!\n";
		else
		{
			fout.open("ClientBasket2.txt", ios::app);
			fout << endl;
			fout << Added.name << "\t" << Added.firm << "\t" << Added.date
				<< "\t" << Added.size << "\t" << am << "\t" << Added.cost << "\t" << Added.suplierlog << "\t" << clientlog;
			fout.close();
			cout << "Добавление прошло успешно!" << endl;
		}
		Rewrite.clear();
	}
	void order(string clientlog)
	{
		NonProd pr, temp;
		string log;
		double all = 0;
		vector<NonProd> v, t;
		ifstream fin;
		fin.open("ClientBasket2.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplierlog >> log)
			{
				if (log == clientlog)
				{
					pr.set(name, firm, date, size, amount, cost, suplierlog);
					v.push_back(pr);
				}
			}
			fin.close();
			cout << "Ваши покупки из непроизводственных товаров:\n";

			for (auto i = 0; i < v.size(); i++)
			{
				cout.setf(ios::left);
				cout << setw(25) << v[i].name << setw(25) << v[i].firm << setw(19) << v[i].date << setw(11)
					<< v[i].size << setw(10) << right << v[i].amount << setw(6) << v[i].cost << left << " BYN " << endl;
				all += v[i].amount * v[i].cost;
			}
			cout << "Общей стоимостью: " << all << " BYN " << endl << endl;
		}

		ofstream fout;
		fout.open("ClientsOrder2.txt", ios::app);
		if (fout.is_open())
		{
			for (auto i = 0; i < v.size(); i++)
			{
				fout << endl;
				fout.setf(ios::left);
				fout << v[i].name << '\t' << v[i].firm << '\t' << v[i].date << '\t'
					<< v[i].size << '\t' << right << v[i].amount << '\t' << v[i].cost << '\t' << all << '\t' << clientlog;
			}
			fout.close();
		}

		fin.open("NonProdGoods.txt", ios::in);
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplierlog)
			{
				for (auto j = 0; j < v.size(); j++)
				{
					if (name == v[j].name)
					{
						amount -= v[j].amount;
					}
				}
				temp.set(name, firm, date, size, amount, cost, suplierlog);
				t.push_back(temp);
			}
			fin.close();
		}

		fout.open("NonProdGoods.txt");
		if (fout.is_open())
		{
			/*fout << endl;*/
			for (auto i = 0; i < t.size(); i++)
			{
				/*fout << t[i];*/
				t[i].add();
			}
			fout.close();
		}
	}
	void getOrder(string clientlog)
	{
		ifstream fin;
		string log;
		double all = 0;
		fin.open("ClientsOrder2.txt");
		if (fin.is_open())
		{
			cout << "Ваши покупки из непроизводственных товаров:\n";
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> all >> log)
			{
				if (clientlog == log)
				{
					cout.setf(ios::left);
					cout << setw(25) << name << setw(25) << firm << setw(19) << date << setw(11)
						<< size << setw(10) << right << amount << setw(6) << cost << left << " BYN " << endl;
				}
			}
			fin.close();
		}
	}

	static string NumToStr(double num)
	{
		ostringstream ost;
		ost << num;
		return ost.str();
	}

	friend bool operator>(const NonProd& obj1, const NonProd& obj2)
	{
		return obj1.amount > obj2.amount;
	}
	friend bool operator==(NonProd a, NonProd b)
	{
		return ((a.name) == (b.name) && ((a.cost) == (b.cost)) && ((a.suplierlog) == (b.suplierlog)));
	}
	friend ostream& operator<<(ostream& stream, NonProd obj)
	{		
		stream << setw(25);
		stream << obj.name << setw(25);
		stream << obj.firm << setw(19);
		stream << obj.date << setw(11);
		stream << obj.size << setw(10) << right;
		stream << obj.amount << setw(6);
		stream << obj.cost << left << " BYN " << endl;
		/*stream << obj.suplierlog << "\n";*/
		return stream;
	}
};

class Client : public Authorization
{
public:
	Client() {};
	void set(string l, string o, string f, string t, string e)
	{
		this->login = l;
		this->org = o;
		this->fio = f;
		this->tel = t;
		this->email = e;
	}
	void viewInfo()
	{
		cout.setf(ios::left);
		cout << setw(17) << "Организация: " << this->org << endl;
		cout << setw(17) << "ФИО: " << this->fio << endl;
		cout << setw(17) << "Номер телефона: " << this->tel << endl;
		cout << setw(17) << "Почта: " << this->email << endl;
	}
	void wtof()
	{
		ofstream fout;
		fout.open("InfoClient.txt", ios::app);
		if (fout.is_open())
		{
			fout << login << "\t" << org << "\t" << fio << "\t" << tel << "\t" << email << '\n';
			fout.close();
		}
	}
	void rfromf(string l)
	{

		ifstream fin;
		fin.open("InfoClient.txt");
		if (fin.is_open())
		{
			while (fin >> login && fin.ignore() && getline(fin, org, '\t') && getline(fin, fio, '\t') && fin >> tel >> email)
			{
				if (login == l) break;
			}
			fin.clear();
			fin.close();
		}
	}
	void deleteFromBasket(int counterToDel, string cllog)
	{
		ifstream fin;
		Prod ToDel;
		vector<Prod> pr;
		string name, date1, date2, firm, log, suplog;
		int amount, newCounter = 0;
		counterToDel--;
		double cost;
		fin.open("ClientBasket.txt");
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplog >> log)
			{
				if (log == cllog)
				{
					if (newCounter != counterToDel)
					{
						ToDel.set(name, firm, date1, date2, amount, cost, suplog);
						pr.push_back(ToDel);
					}
					newCounter++;
				}
				else
				{
					ToDel.set(name, firm, date1, date2, amount, cost, suplog);
					pr.push_back(ToDel);
				}
			}
			fin.close();
		}
		if (newCounter == 0) { cout << "Корзина пуста" << endl; }

		ofstream fout;
		fout.open("ClientBasket.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].writeInBas(cllog);
			}
			fout.close();
			pr.clear();
			cout << "Удаление прошло успешно" << endl;
		}
	}
	void deleteFromBasket2(int counterToDel, string cllog)
	{
		ifstream fin;
		Prod ToDel;
		vector<Prod> pr;
		string name, date, size, firm, log, suplog;
		int amount, newCounter = 0;
		double cost;
		fin.open("ClientBasket2.txt");
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplog >> log)
			{
				if (log == cllog)
				{
					if (newCounter != counterToDel)
					{
						ToDel.set(name, firm, date, size, amount, cost, suplog);
						pr.push_back(ToDel);
					}
					newCounter++;
				}
				else
				{
					ToDel.set(name, firm, date, size, amount, cost, suplog);
					pr.push_back(ToDel);
				}
			}
			fin.close();
		}
		if (newCounter == 0) { cout << "Корзина пуста" << endl; }

		ofstream fout;
		fout.open("ClientBasket2.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].writeInBas(cllog);
			}
			fout.close();
			pr.clear();
			cout << "Удаление прошло успешно" << endl;
		}
	}
	void clearBasket(string clientname)
	{
		ifstream fin;
		string name, date1, date2, firm, log, suplog, date, size;
		double cost;
		int amount;
		vector<Prod> toStay;
		vector<string> clientnames;
		Prod pr;
		fin.open("ClientBasket.txt");
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date1 >> date2 >> amount >> cost >> suplog >> login)
			{
				if (login != clientname)
				{
					pr.set(name, firm, date1, date2, amount, cost, suplog);
					toStay.push_back(pr);
					clientnames.push_back(clientname);
				}
			}
			fin.close();
		}
		else cout << "\nВаша корзина пуста!\n";

		ofstream fout;
		fout.open("ClientBasket.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < toStay.size(); i++)
			{
				log = clientnames[i];
				toStay[i].writeInBas(log);
			}
			fout.close();
			toStay.clear();
			clientnames.clear();
		}

		fin.open("ClientBasket2.txt");
		if (fin.is_open())
		{
			while (fin.ignore() && getline(fin, name, '\t') && getline(fin, firm, '\t') && fin >> date >> size >> amount >> cost >> suplog >> login)
			{
				if (login != clientname)
				{
					pr.set(name, firm, date, size, amount, cost, suplog);
					toStay.push_back(pr);
					clientnames.push_back(clientname);
				}
			}
			fin.close();
		}
		else cout << "\nВаша корзина пуста!\n";

		fout.open("ClientBasket2.txt");
		if (fout.is_open())
		{
			for (auto i = 0; i < toStay.size(); i++)
			{
				log = clientnames[i];
				toStay[i].writeInBas(log);
			}
			fout.close();
			toStay.clear();
			clientnames.clear();
		}
		cout << "Корзина успешно очищена!\n";
	}
	void change(string log)
	{
		ifstream fin;
		int newCounter = 0;
		Client ToChange;
		vector<Client> pr;
		fin.open("InfoClient.txt", ios::in);
		if (fin.is_open())
		{
			while (fin >> login && fin.ignore() && getline(fin, org, '\t') && getline(fin, fio, '\t') && fin >> tel >> email)
			{
				if (login != log)
				{
					ToChange.set(login, org, fio, tel, email);
					pr.push_back(ToChange);
				}
				else
				{
					org[0] = '\0'; fio[0] = '\0';
					tel[0] = '\0'; email[0] = '\0';
					cin.ignore();
					while (org[0] == '\0')
					{
						cout << "Введите новые данные\nВведите наименование вашей организации: ";
						getline(cin, org);
					}
					while (fio[0] == '\0')
					{
						cout << "Введите ваше ФИО: ";
						getline(cin, fio);
					}
					while (tel[0] == '\0')
					{
						cout << "Введите ваш номер телефона: ";
						tel = FunctionForSpaces();
					}
					while (email[0] == '\0')
					{
						cout << "Введите вашу почту: ";
						email = FunctionForSpaces();
					}
					ToChange.set(login, org, fio, tel, email);
					pr.push_back(ToChange);
				}
			}
			fin.close();
		}

		ofstream fout;
		fout.open("InfoClient.txt", ios::trunc);
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].wtof();
			}
			pr.clear();
			fout.close();
			cout << "Редактирование прошло успешно" << endl;
		}
	}

	template <class T> void viewAll()
	{
		T pr;
		pr.viewAll();
	}
};
template void Client::viewAll<Prod>();
template void Client::viewAll<NonProd>();

class Supplier : public Authorization
{
public:
	Supplier() {};
	void set(string l, string o, string f, string t, string e)
	{
		this->login = l;
		this->org = o;
		this->fio = f;
		this->tel = t;
		this->email = e;
	}
	void viewInfo()
	{
		cout.setf(ios::left);
		cout << setw(17) << "Организация: " << this->org << endl;
		cout << setw(17) << "ФИО: " << this->fio << endl;
		cout << setw(17) << "Номер телефона: " << this->tel << endl;
		cout << setw(17) << "Почта: " << this->email << endl;
	}
	void wtof()
	{
		ofstream fout;
		fout.open("InfoSuplier.txt", ios::app);
		if (fout.is_open())
		{
			fout << endl;
			fout << login << "\t" << org << "\t" << fio << "\t" << tel << "\t" << email;
			fout.close();
		}
	}
	void rfromf(string log)
	{
		ifstream fin;
		fin.open("InfoSuplier.txt");
		if (fin.is_open())
		{
			while (fin >> login && fin.ignore() && getline(fin, org, '\t') && getline(fin, fio, '\t') && fin >> tel >> email)
			{
				if (login == log) break;
			}
			fin.close();
		}
	}
	void change(string log)
	{
		ifstream fin;
		int newCounter = 0;
		Supplier ToChange;
		vector<Supplier> pr;
		fin.open("InfoSuplier.txt", ios::in);
		if (fin.is_open())
		{
			while (fin >> login && fin.ignore() && getline(fin, org, '\t') && getline(fin, fio, '\t') && fin >> tel >> email)
			{
				if (login != log)
				{
					ToChange.set(login, org, fio, tel, email);
					pr.push_back(ToChange);
				}
				else
				{
					org[0] = '\0'; fio[0] = '\0';
					tel[0] = '\0'; email[0] = '\0';
					cin.ignore();
					while (org[0] == '\0')
					{
						cout << "Введите новые данные\nВведите наименование вашей организации: ";
						getline(cin, org);
					}
					while (fio[0] == '\0')
					{
						cout << "Введите ваше ФИО: ";
						getline(cin, fio);
					}
					while (tel[0] == '\0')
					{
						cout << "Введите ваш номер телефона: ";
						tel = FunctionForSpaces();
					}
					while (email[0] == '\0')
					{
						cout << "Введите вашу почту: ";
						email = FunctionForSpaces();
					}
					ToChange.set(login, org, fio, tel, email);
					pr.push_back(ToChange);
				}
			}
			fin.close();
		}

		ofstream fout;
		fout.open("InfoSuplier.txt", ios::trunc);
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].wtof();
			}
			pr.clear();
			fout.close();
			cout << "Редактирование прошло успешно" << endl;
		}
	}

	template <class T> void viewForSup(string suplog)
	{
		T pr;
		pr.viewForSup(suplog);
	}
};
template void Supplier::viewForSup<Prod>(string suplog);
template void Supplier::viewForSup<NonProd>(string suplog);

class Admin : public Authorization
{
private:
	string post;
public:
	Admin() {};
	void set(string l, string f, string p)
	{
		this->login = l;
		this->fio = f;
		this->post = p;
	}
	void wtof()
	{
		ofstream fout;
		fout.open("InfoAdmin.txt", ios::app);
		if (fout.is_open())
		{
			fout << endl;
			fout << login << '\t' << fio << '\t' << post;
			fout.close();
		}
	}
	void rfromf(string l)
	{
		ifstream fin;
		fin.open("InfoAdmin.txt");
		if (fin.is_open())
		{
			while (fin >> login && fin.ignore() && getline(fin, fio, '\t') && getline(fin, post, '\n'))
			{
				if (login == l) break;
			}
			fin.close();
		}
	}
	void viewInfo()
	{
		cout.setf(ios::left);
		cout << setw (11) << "ФИО: " << this->fio << endl;
		cout << setw(11) << "Должность: " << this->post << endl;
	}
	void viewAdmins()
	{
		Admin a;
		ifstream fin;
		fin.open("InfoAdmin.txt");
		if (fin.is_open())
		{
			string clientlog, clientFIO, clientpost;
			int count = 1;
			while (fin >> clientlog && fin.ignore() && getline(fin, clientFIO, '\t') && getline(fin, clientpost, '\n'))
			{
				a.set(clientlog, clientFIO, clientpost);
				cout << endl;
				cout << "Администратор " << count++ << endl;
				a.viewInfo();
				cout << endl;
			}
			fin.close();
		}
	}
	void viewClients()
	{
		Client c;
		ifstream fin;
		fin.open("InfoClient.txt");
		if (fin.is_open())
		{
			string clientlog, clientorg, clientFIO, clienttel, clientemail;
			int count = 1;
			while (fin >> clientlog && fin.ignore() && getline(fin, clientorg, '\t') && getline(fin, clientFIO, '\t') && fin >> clienttel >> clientemail)
			{
				c.set(clientlog, clientorg, clientFIO, clienttel, clientemail);
				cout << endl;
				cout << "Клиент " << count++ << endl;
				c.viewInfo();
				cout << endl;
			}
			fin.close();
		}
	}
	void viewSupliers()
	{
		Supplier s;
		ifstream fin;
		fin.open("InfoSuplier.txt");
		if (fin.is_open())
		{
			string clientlog, clientorg, clientFIO, clienttel, clientemail;
			int count = 1;
			while (fin >> clientlog && fin.ignore() && getline(fin, clientorg, '\t') && getline(fin, clientFIO, '\t') && fin >> clienttel >> clientemail)
			{
				s.set(clientlog, clientorg, clientFIO, clienttel, clientemail);
				cout << endl;
				cout << "Поставщик " << count++ << endl;
				s.viewInfo();
				cout << endl;
			}
			fin.close();
		}
	}
	void deleteAdmins()
	{
		ifstream fin;
		Admin clientDel;
		vector<Admin> admins;
		int countToDel = 0, i;
		string LogToDel;
		string Log, Pass;
		string client_log, client_fio, client_post;
		viewAdmins();
		cout << "Введите номер администратора для удаления: ";
		cin >> i;
		i--;
		fin.open("InfoAdmin.txt");
		if (fin.is_open())
		{
			while (fin >> client_log && fin.ignore() && getline(fin, client_fio, '\t') && getline(fin, client_post, '\n'))
			{
				if (countToDel++ != i)
				{
					clientDel.set(client_log, client_fio, client_post);
					admins.push_back(clientDel);
				}
				else { LogToDel = client_log; }
			}
			fin.close();
			fin.clear();
		}

		ofstream fout;
		fout.open("InfoAdmin.txt", ios::trunc);
		if (fout.is_open())
		{
			for (auto j = 0; j < admins.size(); j++)
			{
				admins[j].wtof();
			}
			fout.close();
			fout.clear();
			admins.clear();
		}

		vector<Authorization> vecA;
		Authorization admin;
		fin.open("admin.txt");
		if (fin.is_open())
		{
			while (fin >> Log >> Pass)
			{
				if (Log != LogToDel)
				{
					admin.set(Log, Pass);
					vecA.push_back(admin);
				}
			}
			fin.close();
		}

		fout.open("admin.txt", ios::trunc);
		if (fout.is_open())
		{
			for (auto i = 0; i < vecA.size(); i++)
			{
				vecA[i].wtofa();
			}
			cout << "Удаление прошло успешно!" << endl;
		}
	}
	string deleteClient()
	{
		ifstream fin;
		Client clientDel;
		vector<Client> clients;
		int countToDel = 0, i;
		string LogToDel;
		string Log, Pass;
		string client_log, client_org, client_fio, client_tel, client_mail;
		viewClients();
		cout << "Введите номер клиента для удаления: ";
		cin >> i;
		i--;
		fin.open("InfoClient.txt");
		if (fin.is_open())
		{
			while (fin >> client_log && fin.ignore() && getline(fin, client_org, '\t') && getline(fin, client_fio, '\t') && fin >> client_tel >> client_mail)
			{
				if (countToDel++ != i)
				{
					clientDel.set(client_log, client_org, client_fio, client_tel, client_mail);
					clients.push_back(clientDel);
				}
				else { LogToDel = client_log; }
			}
			fin.close();
		}

		ofstream fout;
		fout.open("InfoClient.txt", ios::trunc);
		if (fout.is_open())
		{
			for (auto j = 0; j < clients.size(); j++)
			{
				clients[j].wtof();
			}
			fout.close();
			clients.clear();
		}

		vector<Authorization> vecA;
		Authorization client;
		fin.open("client.txt");
		if (fin.is_open())
		{
			while (fin >> Log >> Pass)
			{
				if (Log != LogToDel)
				{
					client.set(Log, Pass);
					vecA.push_back(client);
				}
			}
			fin.close();
		}

		fout.open("client.txt", ios::trunc);
		if (fout.is_open())
		{
			for (auto i = 0; i < vecA.size(); i++)
			{
				vecA[i].wtofc();
			}
			cout << "Удаление прошло успешно!" << endl;
		}
		return LogToDel;
	}
	string deleteSuplier() 
	{
		ifstream fin;
		Supplier suplierDel;
		vector<Supplier> supliers;
		int countToDel = 0, i;
		string LogToDel;
		string Log, Pass;
		string sup_log, sup_org, sup_fio, sup_tel, sup_mail;
		viewSupliers();
		cout << "Введите номер поставщика для удаления: ";
		cin >> i;
		i--;
		fin.open("InfoSuplier.txt");
		if (fin.is_open())
		{
			while (fin >> sup_log && fin.ignore() && getline(fin, sup_org, '\t') && getline(fin, sup_fio, '\t') && fin >> sup_tel >> sup_mail)
			{
				if (countToDel++ != i)
				{
					suplierDel.set(sup_log, sup_org, sup_fio, sup_tel, sup_mail);
					supliers.push_back(suplierDel);
				}
				else { LogToDel = sup_log; }
			}
			fin.close();
		}

		ofstream fout;
		fout.open("InfoSuplier.txt", ios::trunc);
		if (fout.is_open())
		{
			for (auto j = 0; j < supliers.size(); j++)
			{
				supliers[j].wtof();
			}
			fout.close();
			supliers.clear();
		}

		vector<Authorization> vecA;
		Authorization suplier;
		fin.open("suplier.txt");
		if (fin.is_open())
		{
			while (fin >> Log >> Pass)
			{
				if (Log != LogToDel)
				{
					suplier.set(Log, Pass);
					vecA.push_back(suplier);
				}
			}
			fin.close();
		}

		fout.open("suplier.txt", ios::trunc);
		if (fout.is_open())
		{
			for (auto i = 0; i < vecA.size(); i++)
			{
				vecA[i].wtofs();
			}
			fout.close();
			vecA.clear();
			cout << "Удаление прошло успешно!" << endl;
		}
		return LogToDel;
	}
	void change(string log)
	{
		ifstream fin;
		Admin ToChange;
		vector<Admin> pr;
		fin.open("InfoAdmin.txt", ios::in);
		if (fin.is_open())
		{
			while (fin >> login && fin.ignore() && getline(fin, fio, '\t') && getline(fin, post, '\n'))
			{
				if (login != log)
				{
					ToChange.set(login, fio, post);
					pr.push_back(ToChange);
				}
				else
				{
					fio[0] = '\0'; post[0] = '\0';
					cin.ignore();
					while (fio[0] == '\0')
					{
						cout << "Введите ваше ФИО: ";
						getline(cin, fio);
					}
					while (post[0] == '\0')
					{
						cout << "Введите вашу должность: ";
						getline(cin, post);
					}
					ToChange.set(login, fio, post);
					pr.push_back(ToChange);
				}
			}
			fin.close();
		}

		ofstream fout;
		fout.open("InfoAdmin.txt", ios::trunc);
		if (fout.is_open())
		{
			for (auto i = 0; i < pr.size(); i++)
			{
				pr[i].wtof();
			}
			pr.clear();
			fout.close();
			cout << "Редактирование прошло успешно" << endl;
		}
	}
	
	template <class T> void viewAll()
	{
		T pr;
		pr.viewAll();
	}
	template<class T> void sort()
	{
		T pr;
		pr.sort();
	}
};
template void Admin::viewAll<Prod>();
template void Admin::viewAll<NonProd>();
template void Admin::sort<Prod>();
template void Admin::sort<NonProd>();

template<class T> struct Status 
{
	T* ptr;
	int counter = 0;
};

template<class T> class SmartPointer 
{
private:
	Status<T>* smartPtr;
public:
	SmartPointer(T* ptr = 0)
	{
		if (!ptr) smartPtr = NULL;
		else 
		{
			smartPtr = new Status<T>;
			smartPtr->ptr = ptr;
			smartPtr->counter = 1;
		}
	}
	SmartPointer(const SmartPointer& obj)
	{
		smartPtr = obj.smartPtr;
		if (smartPtr)
			smartPtr->counter++;
	}
	~SmartPointer()
	{
		if (smartPtr) {
			smartPtr->counter--;
			if (smartPtr->counter <= 0) {
				delete smartPtr->ptr;
				delete smartPtr;
			}
		}
	}
	SmartPointer& operator=(const SmartPointer& obj)
	{
		if (smartPtr) {
			smartPtr->counter--;
			if (smartPtr->counter <= 0) {
				delete smartPtr->ptr;
				delete smartPtr;
			}
		}
		smartPtr = obj.smartPtr;
		if (smartPtr) smartPtr->counter++;
		return *this;
	}
	T* operator->() const
	{
		if (smartPtr) return smartPtr->ptr;
		else return NULL;
	}
	void showCounter() { cout << smartPtr->counter; }
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SmartPointer<Client> client = new Client();
	SmartPointer<Admin> admin = new Admin();
	SmartPointer<Supplier> suplier = new Supplier();
	SmartPointer<Authorization> autorization = new Authorization();
	SmartPointer<Prod> prod = new Prod();
	SmartPointer<NonProd> nonprod = new NonProd();

	hash<string> hasher;

	string log, pass, name, org, fio, tel, em, post;
	string goodname, firm, date1, date2, size, date;
	string templog;
	int amount;
	double cost, l=0, w=0, h=0, tmp;
	int k = 0, t = 0;
	static int type;
	bool temp = false;
	size_t hash;

	while (true)
	{
		while (temp == false)
		{
			log = '\0';	pass = '\0'; fio = '\0';
			post = '\0'; org = '\0'; tel = '\0'; em = '\0';
			switch (AutorizationMenu1())
			{
			case 1:
				switch (AutorizationMenu2())
				{
				case 1:
					cin.ignore();
					type = 1;
					while (log[0] == '\0')
					{
						cout << "Введите логин (без пробелов, они будут удалены): ";
						log = FunctionForSpaces();
					}
					while (pass[0] == '\0')
					{
						cout << "Введите пароль (без пробелов, они будут удалены): ";
						pass = FunctionForSpaces();
					}
					hash = hasher(pass);
					pass = to_string(hash);
					temp = autorization->reg(log, pass, 1);
					while (fio[0] == '\0')
					{
						cout << "Введите ваше ФИО: ";
						getline(cin, fio);
					}
					while (post[0] == '\0')
					{
						cout << "Введите вашу должность: ";
						getline(cin, post);
					}
					admin->set(log, fio, post);
					admin->wtof();
					break;
				case 2:
					cin.ignore();
					type = 2;
					while (log[0] == '\0')
					{
						cout << "Введите логин (любые буквы и цифры без пробелов): ";
						log = FunctionForSpaces();
					}
					while (pass[0] == '\0')
					{
						cout << "Введите пароль (любые буквы и цифры без пробелов): ";
						pass = FunctionForSpaces();
					}
					hash = hasher(pass);
					pass = to_string(hash);
					temp = autorization->reg(log, pass, 2);
					while (org[0] == '\0')
					{
						cout << "Введите наименование вашей организации: ";
						getline(cin, org);
					}
					while (fio[0] == '\0')
					{
						cout << "Введите ваше ФИО: ";
						getline(cin, fio);
					}
					while (tel[0] == '\0')
					{
						cout << "Введите ваш номер телефона (цифры без пробелов): ";
						tel = FunctionForSpaces();
					}
					while (em[0] == '\0')
					{
						cout << "Введите вашу почту (любые буквы и цифры без пробелов): ";
						em = FunctionForSpaces();
					}
					suplier->set(log, org, fio, tel, em);
					suplier->wtof();
					break;
				case 3:
					cin.ignore();
					type = 3;
					while (log[0] == '\0')
					{
						cout << "Введите логин: ";
						log = FunctionForSpaces();
					}
					while (pass[0] == '\0')
					{
						cout << "Введите пароль: ";
						pass = FunctionForSpaces();
					}
					hash = hasher(pass);
					pass = to_string(hash);
					temp = autorization->reg(log, pass, 3);
					while (org[0] == '\0')
					{
						cout << "Введите наименование вашей организации: ";
						getline(cin, org);
					}
					while (fio[0] == '\0')
					{
						cout << "Введите ваше ФИО: ";
						getline(cin, fio);
					}
					while (tel[0] == '\0')
					{
						cout << "Введите ваш номер телефона: ";
						tel = FunctionForSpaces();
					}
					while (em[0] == '\0')
					{
						cout << "Введите вашу почту: ";
						em = FunctionForSpaces();
					}
					client->set(log, org, fio, tel, em);
					client->wtof();
					break;
				case 4:
					break;
				default: cout << "Опции под таким номером нет. Повторите ввод.\n";
				}
				break;
			case 2:
				switch (AutorizationMenu3())
				{
				case 1:
					cin.ignore();
					while (log[0] == '\0')
					{
						cout << "Введите логин: ";
						log = FunctionForSpaces();
					}
					while (pass[0] == '\0')
					{
						cout << "Введите пароль: ";
						pass = FunctionForSpaces();
					}
					hash = hasher(pass);
					pass = to_string(hash);
					temp = admin->log(log, pass, 1);
					if (temp == false) cout << "Ошибка! Неверный логин или пароль.\n";
					type = 1;
					admin->rfromf(log);
					fio = admin->RetFIO();
					break;
				case 2:
					cin.ignore();
					while (log[0] == '\0')
					{
						cout << "Введите логин: ";
						log = FunctionForSpaces();
					}
					while (pass[0] == '\0')
					{
						cout << "Введите пароль: ";
						pass = FunctionForSpaces();
					}
					hash = hasher(pass);
					pass = to_string(hash);
					temp = suplier->log(log, pass, 2);
					if (temp == false) cout << "Ошибка! Неверный логин или пароль.\n";
					type = 2;
					suplier->rfromf(log);
					fio = suplier->RetFIO();
					break;
				case 3:
					cin.ignore();
					while (log[0] == '\0')
					{
						cout << "Введите логин: ";
						log = FunctionForSpaces();
					}
					while (pass[0] == '\0')
					{
						cout << "Введите пароль: ";
						pass = FunctionForSpaces();
					}
					hash = hasher(pass);
					pass = to_string(hash);
					temp = client->log(log, pass, 3);
					if (temp == false) cout << "Ошибка! Неверный логин или пароль.\n";
					type = 3;
					client->rfromf(log);
					fio = client->RetFIO();
					break;
				case 4:
					break;
				default: cout << "Опции под таким номером нет. Повторите ввод.\n";
				}
				break;
			case 3:
				exit(0);
			default: cout << "\nОпции под таким номером нет. Повторите ввод.\n";
			}
		}
		cout << "\nДобро пожаловать, " << fio << "!\n";
		while (temp)
		{
			switch (type)
			{
			case 1:
				switch (AdminMenu())
				{
				case 1:
					admin->viewAll<Prod>();
					admin->viewAll<NonProd>();
					break;
				case 2:
					admin->sort<Prod>();
					admin->sort<NonProd>();
					admin->viewAll<Prod>();
					admin->viewAll<NonProd>();
					break;
				case 3:
					admin->viewAdmins();
					break;
				case 4:
					admin->viewClients();
					break;
				case 5:
					admin->viewSupliers();
					break;
				case 6:
					admin->deleteAdmins();
					break;
				case 7:
					templog = admin->deleteClient();
					client->clearBasket(templog);
					break;
				case 8:
					templog = admin->deleteSuplier();
					prod->delAll(templog);
					nonprod->delAll(templog);
					break;
				case 9:
					admin->viewInfo();
					break;
				case 10:
					admin->change(log);
					admin->rfromf(log);
					admin->viewInfo();
					break;
				case 11:
					temp = false;
					break;
				default: cout << "\nОпции под таким номером нет. Повторите ввод.\n";
				}
				break;
			case 2:
				switch (SupplierMenu())
				{
				case 1:
					cout << "\nВыберите вид товаров:\n1. Производственные\n2. Непроизводственные\n3. Предыдущее меню\n";
					k = FunctionForCheck();
					switch (k)
					{
					case 1:
						cout << "\nСколько товаров вы хотите добавить?\n";
						t = FunctionForCheck();
						for (int i = 0; i < t; i++)
						{
							name[0] = '\0'; firm[0] = '\0';
							date1[0] = '\0'; date2[0] = '\0';
							cin.ignore();
							cout << "\nВведите данные:\nТовар " << i + 1 << endl;
							while (name[0] == '\0')
							{
								cout << "Наименование товара: ";
								getline(cin, name);
							}
							while (firm[0] == '\0')
							{
								cout << "Фирма-производитель: ";
								getline(cin, firm);
							}
							while (date1[0] == '\0')
							{
								cout << "Дата изготовления: ";
								date1 = FunctionForSpaces();
							}
							while (date2[0] == '\0')
							{
								cout << "Годен до: ";
								date2 = FunctionForSpaces();
							}
							cout << "Поставляемое количество: ";
							amount = FunctionForCheck();
							cout << "Цена за штуку: ";
							cost = FunctionForDouble();
							prod->set(name, firm, date1, date2, amount, cost, log);
							prod->add();
						}
						break;
					case 2:
						cout << "\nСколько товаров вы хотите добавить?\n";
						t = FunctionForCheck();
						for (int i = 0; i < t; i++)
						{
							name[0] = '\0'; firm[0] = '\0';
							date[0] = '\0';
							cin.ignore();
							cout << "\nВведите данные:\nТовар " << i + 1 << endl;
							while (name[0] == '\0')
							{
								cout << "Наименование товара: ";
								getline(cin, name);
							}
							while (firm[0] == '\0')
							{
								cout << "Фирма: ";
								getline(cin, firm);
							}
							while (date[0] == '\0')
							{
								cout << "Дата изготовления: ";
								cin >> date;
							}
							cout << "Размер: \n Длина: ";
							l = FunctionForDouble();
							cout << "Ширина: ";
							w = FunctionForDouble();
							cout << "Высота: ";
							h = FunctionForDouble();
							size = nonprod->NumToStr(l) + 'x' + nonprod->NumToStr(w) + 'x' + nonprod->NumToStr(h);
							cout << "Количество: ";
							amount = FunctionForCheck();
							cout << "Цена: ";
							cost = FunctionForDouble();
							nonprod->set(name, firm, date, size, amount, cost, log);
							nonprod->add();
						}
						break;
					case 3:
						break;
					default: cout << "\nОпции под таким номером нет. Повторите ввод.\n";
					}
					break;
				case 2:
					suplier->viewForSup<Prod>(log);
					suplier->viewForSup<NonProd>(log);
					break;
				case 3:
					cout << "\nВыберите вид товаров для изменения:\n1. Производственные\n2. Непроизводственные\n3. Предыдущее меню\n";
					k = FunctionForCheck();
					switch (k)
					{
					case 1:
						suplier->viewForSup<Prod>(log);
						cout << "\nНомер товара для изменения: ";
						t = FunctionForCheck();
						prod->change(t, log);
						break;
					case 2:
						suplier->viewForSup<NonProd>(log);
						cout << "\nНомер товара для изменения: ";
						t = FunctionForCheck();
						nonprod->change(t, log);
						break;
					case 3:
						break;
					}
					break;
				case 4:
					cout << "\nВыберите вид товаров для удаления:\n1. Производственные\n2. Непроизводственные\n3. Предыдущее меню\n";
					k = FunctionForCheck();
					switch (k)
					{
					case 1:
						suplier->viewForSup<Prod>(log);
						cout << "\nНомер товара для удаления: ";
						t = FunctionForCheck();
						prod->del(t, log);
						break;
					case 2:
						suplier->viewForSup<NonProd>(log);
						cout << "\nНомер товара для удаления: ";
						t = FunctionForCheck();
						nonprod->del(t, log);
						break;
					case 3:
						break;
					}
					break;
				case 5:
					prod->sort();
					nonprod->sort();
					suplier->viewForSup<Prod>(log);
					suplier->viewForSup<NonProd>(log);
					break;
				case 6:
					suplier->viewInfo();
					break;
				case 7:
					suplier->change(log);
					suplier->rfromf(log);
					suplier->viewInfo();
					break;
				case 8: 
					temp = false;
					break;
				default: cout << "\nОпции под таким номером нет. Повторите ввод.\n";
				}
				break;
			case 3:
				switch (ClientMenu())
				{
				case 1:
					cout << "\nВыберите:\n1. Просмотреть все товары\n2. Просмотреть только производственные товары\n"
						<< "3. Просмотреть только непроизводственные товары\n4. Предыдущее меню\n";
					k = FunctionForCheck();
					switch (k)
					{
					case 1:
						client->viewAll<Prod>();
						client->viewAll<NonProd>();
						break;
					case 2:
						client->viewAll<Prod>();
						break;
					case 3:
						client->viewAll<NonProd>();
						break;
					case 4: break;
					default: cout << "\nОпции под таким номером нет. Повторите ввод.\n";
					}
					break;
				case 2:
					cout << "\nВыберите вид товара для добавления в корзину:\n1. Производственный\n2. Непроизводственный\n3. Предыдущее меню\n";
					k = FunctionForCheck();
					switch (k)
					{
					case 1:
						cout << "\nВыберите:\n1. Поиск товара по наименованию\n2. Предварительно отфильтровать с указанием максимальной цены\n3. Добавить без фильтрования\n";
						t = FunctionForCheck();
						switch (t)
						{
						case 1:
							if (prod->search())
								prod->addToBasket(log);
							break;
						case 2:
							cout << "Введите максимальную цену для фильтрации товаров: ";
							cin >> tmp;
							prod->filter(tmp);
							prod->addToBasket(log);
							break;
						case 3:
							prod->viewAll();
							prod->addToBasket(log);
							break;
						default: cout << "Опции под таким номером нет. Повторите ввод.\n";
						}
						break;
					case 2:
						cout << "\nВыберите:\n1. Поиск товара по наименованию\n2. Предварительно отфильтровать с указанием максимальной цены\n3. Добавить без фильтрования\n";
						t = FunctionForCheck();
						switch (t)
						{
						case 1:
							if (nonprod->search())
								nonprod->addToBasket(log);
							break;
						case 2:
							cout << "\nВведите максимальную цену для фильтрации товаров: ";
							cin >> tmp;
							nonprod->filter(tmp);
							nonprod->addToBasket(log);
							break;
						case 3:
							nonprod->viewAll();
							nonprod->addToBasket(log);
							break;
						default: cout << "\nОпции под таким номером нет. Повторите ввод.\n";
						}
						break;
					case 3:
						break;
					default: cout << "\nОпции под таким номером нет. Повторите ввод.\n";
					}
					break;
				case 3:
					cout << "\nВыберите вид товара, который вы хотите удалить из корзины:\n"
						<< "1. Производственный\n2. Непроизводственный\n3. Предыдущее меню\n";
					k = FunctionForCheck();
					switch (k)
					{
					case 1:
						prod->viewBusket(log);
						cout << "Введите номер товара для удаления из корзины: ";
						t = FunctionForCheck();
						client->deleteFromBasket(t, log);
						break;
					case 2:
						nonprod->viewBusket(log);
						cout << "Введите номер товара для удаления из корзины: ";
						t = FunctionForCheck();
						client->deleteFromBasket2(t, log);
						t = 0;
						break;
					case 3: break;
					}
					break;
				case 4:
					prod->viewBusket(log);
					nonprod->viewBusket(log);
					break;
				case 5:
					prod->order(log);
					nonprod->order(log);
					client->clearBasket(log);
					break;
				case 6:
					prod->getOrder(log);
					nonprod->getOrder(log);
					break;
				case 7:
					client->viewInfo();
					break;
				case 8:
					client->change(log);
					client->rfromf(log);
					client->viewInfo();
					break;
				case 9: 
					temp = false;
					break;
				default: cout << "\nОпции под таким номером нет. Повторите ввод.\n";
				}
				break;
			default: exit(0);
			}
		}
	}
	return 0;
}

int FunctionForCheck()
{
	int i = 0;
	double d;
	while (i == 0)
	{
		try
		{
			cin >> d;
			i = d;
			if (i != d) throw 0.1;
			if (i <= 0) throw 10;
			if (cin.fail()) throw "aaa";
			if (!cin) throw "aaa";
		}
		catch (double)
		{
			cin.clear();
			cin.ignore(10, '\n');
			cout << "Вы ввели не целое число. Повторите ввод." << endl;
			i = 0;
		}
		catch (int)
		{
			cin.clear();
			cin.ignore(10, '\n');
			cout << "Вы ввели отрицательное число или 0. Повторите ввод." << endl;
			i = 0;
		}
		catch (exception&)
		{
			cin.clear();
			cin.ignore(10, '\n');
			cout << "Вы ввели символ вместо числа. Повторите ввод." << endl;
			i = 0;
		}
		catch (...)
		{
			cin.clear();
			cin.ignore(10, '\n');
			cout << "Ошибка ввода. Повторите ввод." << endl;
			i = 0;
		}
	}
	return i;
}

string FunctionForSpaces()
{
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			s.erase(i, 1);
			i--;
		}
	}
	return s;
}

double FunctionForDouble()
{
	double d;
	while (!(cin >> d) || d <= 0)
	{
		cin.clear();
		cout << "Error... Enter again!" << endl;
		while (cin.get() != '\n');
	}
	return d;
}