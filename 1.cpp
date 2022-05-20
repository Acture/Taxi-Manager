#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_set>
#include <string>
#include <fstream>
using namespace std;

class Car
{
private:
	int _carID;
	string _driver1Name;
	string _driver2Name;
	string _payment;

public:
	Car(){};
	Car(int x) { _carID = x; };
	void SetID(int x) { _carID = x; };
	void SetDriver1Name(string x) { _driver1Name = x; };
	void SetDriver2Name(string x) { _driver2Name = x; };
	void SetPayment(string x) { _payment = x; };

	int GetID() { return _carID; };
	string GetDriver1Name() { return _driver1Name; };
	string GetDriver2Name() { return _driver2Name; };
	string GetPayment() { return _payment; };

	bool operator==(const Car &other)
	{
		return this->_carID == other._carID;
	}

	friend ostream& operator << (ostream& out, const Car& car){
	out << car._carID << " ";
	out << car._driver1Name<< " ";
	out << car._driver2Name << " ";
	out << car._payment << endl;
	return out;
}

};


class Person
{
private:
	string _name;

public:
	void SetName(string x) { _name = x; };
	
	string GetName() { return _name; };
};

class Driver : public Person
{
private:
	int _driverID;
	string _reward;
	string _punishment;

public:
	Driver() {}
	Driver(int x) { _driverID = x; };

	void SetDriverID(int x) { _driverID = x; };
	void SetReward(string x) { _reward = x; };
	void SetPunishment(string x) { _punishment = x; };

	int GetDriverID() { return _driverID; };
	string GetReward() { return _reward; };
	string GetPunishment() { return _punishment; };

	bool operator==(const Driver &other)
	{
		return this->_driverID == other._driverID;
	}

	friend ostream& operator << (ostream& out, const Driver& driver){
	out << driver._driverID << " ";
	out << driver._reward<< " ";
	out << driver._punishment << endl;
	return out;
	}
};

class Admin : public Person
{
private:
	int _password = 114514;

public:
	Admin admin(){};
	Admin admin(int x) { _password = x;}
	void SetPassword(int x) { _password = x; };
	bool CheckPassword(int x)
	{
		if (x == _password)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

class MainProgram
{
private:
	vector<Car> Cars;

	vector<Driver> Drivers;
	Admin admin;
	unordered_set<int> CarIDs;
	unordered_set<int> DriverIDs;

	int input = 0;

public:
	void MainMenu()
	{
		printf(" *************************\n");
		ReadData();
		printf(" *     Taxi Manager      *\n");
		printf(" *************************\n");
		printf(" *************************\n");
		printf(" * 1: Admin Login        *\n");
		printf(" * 2: Driver Login       *\n");
		printf(" * 3: Save and Quit      *\n");
		printf(" *************************\n");
		printf(" Please choose your action: ");

		scanf("%d", &input);

		switch (input)
		{
		case 1:
			AdminLogin();
		case 2:
			DriverLogin();
		case 3:
			SaveData();
			exit(0);
			break;
		default:
			printf(" * Unknown Command *\n");
			MainMenu();
		}
	}

	void ReadData()
	{
		int carid; string driver1; string driver2; string payment;
		ifstream carfile("car.txt");
		while(carfile>> carid >> driver1 >> driver2 >> payment){
			Car ExistingCar(carid);
			ExistingCar.SetDriver1Name(driver1);
			ExistingCar.SetDriver2Name(driver2);
			ExistingCar.SetPayment(payment);
			Cars.push_back(ExistingCar);
			CarIDs.insert(carid);
		carfile.close();

		}
		int driverid;string name; string reward; string punishment;
		ifstream driverfile("driver.txt");
		while(driverfile>> driverid >> name>> reward>> punishment){
			Driver ExistingDriver(driverid);
			ExistingDriver.SetName(name);
			ExistingDriver.SetReward(reward);
			ExistingDriver.SetPunishment(punishment);
			Drivers.push_back(ExistingDriver);
			DriverIDs.insert(driverid);
		}
		driverfile.close();

	}

	void SaveData()
	{
		ofstream carfile("car.txt", ios_base::trunc);
		for(int i = 0; i< Cars.size(); i++){
			carfile << Cars[i];
		}
		carfile.close();

		ofstream driverfile("driver.txt",ios_base::trunc);
		for(int i = 0; i< Drivers.size(); i++){
			driverfile << Drivers[i];
		}
		driverfile.close();

	}

	void AdminLogin()
	{
		printf("\n");
		printf(" Please enter your password:\n");
		scanf("%d", &input);
		if (admin.CheckPassword(input))
		{
			AdminMenu();
		}
		else
		{
			printf("Wrong Password\n");
			MainMenu();
		}
	}

	void AdminMenu()
	{
		printf("\n");
		printf(" *************************\n");
		printf(" * 1: Manage Car         *\n");
		printf(" * 2: Manage Driver      *\n");
		printf(" * 3: Parent Menu        *\n");
		printf(" *************************\n");
		printf(" Please choose your action: ");

		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AdminManageCar();
		case 2:
			AdminManageDriver();
		case 3:
			MainMenu();
		default:
			AdminMenu();
		}
	}

	void AdminManageCar()
	{
		printf("\n");
		printf(" *************************\n");
		printf(" * 1: Add Car            *\n");
		printf(" * 2: Delete Car         *\n");
		printf(" * 3: Check Car          *\n");
		printf(" * 4: Parent Menu        *\n");
		printf(" *************************\n");
		printf(" Please choose your action: ");

		scanf("%d", &input);

		switch (input)
		{
		case 1:
			AdminAddCar();
		case 2:
			AdminDeleteCar();
		case 3:
			AdminCheckCar();
		case 4:
			AdminMenu();
		default:
			AdminManageCar();
		}
	}
	void AdminAddCar()
	{
		Car NewCar;
		int id;
		string name1;
		string name2;
		string payment;

		printf("Car id: ");
		scanf("%d", &id);

		printf("Driver1 name: ");
		cin >> name1;

		printf("Driver2 name: ");
		cin >> name2;

		printf("Payment: ");
		cin >> payment;

		NewCar.SetID(id);
		NewCar.SetDriver1Name(name1);
		NewCar.SetDriver2Name(name2);
		NewCar.SetPayment(payment);

		if (CarIDs.count(id) > 0)
		{
			printf("Duplicate id");
		}
		else
		{
			CarIDs.insert(id);
			Cars.push_back(NewCar);
		}

		AdminManageCar();
	}
	void AdminDeleteCar()
	{
		printf("Input a car Id : ");
		scanf("%d", &input);

		Car CarToDelete(input);

		Cars.erase(std::remove(Cars.begin(), Cars.end(), CarToDelete), Cars.end());
		CarIDs.erase(input);

		printf("Deleted");

		AdminManageCar();
	}
	void AdminCheckCar()
	{
		printf("Input a car Id (input -1 to list all Cars): ");
		scanf("%d", &input);
		printf("%20s", "Car ID");
		printf("%20s", "Driver1Name");
		printf("%20s", "Driver2Name");
		printf("%20s", "Payment\n");

		if (input == -1)
		{
			for (int i = 0; i < Cars.size(); i++)
			{
				printf("%20d", Cars[i].GetID());
				printf("%20s", Cars[i].GetDriver1Name().c_str());
				printf("%20s", Cars[i].GetDriver2Name().c_str());
				printf("%20s", Cars[i].GetPayment().c_str());
				printf("%20s", "\n");
			}
		}
		else
		{
			for (int i = 0; i < Cars.size(); i++)
			{
				if (Cars[i].GetID() != input)
					continue;
				printf("%20d", Cars[i].GetID());
				printf("%20s", Cars[i].GetDriver1Name().c_str());
				printf("%20s", Cars[i].GetDriver2Name().c_str());
				printf("%20s", Cars[i].GetPayment().c_str());
			}
		}

		AdminManageCar();
	}

	void AdminManageDriver()
	{
		printf("\n");
		printf(" *************************\n");
		printf(" * 1: Add Driver         *\n");
		printf(" * 2: Delete Driver      *\n");
		printf(" * 3: Check Driver       *\n");
		printf(" * 4: Parent Menu        *\n");
		printf(" *************************\n");
		printf(" Please choose your action: ");

		scanf("%d", &input);

		switch (input)
		{
		case 1:
			AdminAddDriver();
		case 2:
			AdminDeleteDriver();
		case 3:
			AdminCheckDriver();
		case 4:
			AdminMenu();
		default:
			AdminManageDriver();
		}
	}
	void AdminAddDriver()
	{
		Driver NewDriver;
		int id;
		string name;
		string reward;
		string punishment;

		printf("Driver id: ");
		scanf("%d", &id);

		printf("Driver name: ");
		cin >> name;

		printf("Reward: ");
		cin >> reward;

		printf("Punishment: ");
		cin >> punishment;

		NewDriver.SetDriverID(id);
		NewDriver.SetName(name);
		NewDriver.SetReward(reward);
		NewDriver.SetPunishment(punishment);

		if (DriverIDs.count(id) > 0)
		{
			printf("Duplicate id");
		}
		else
		{
			DriverIDs.insert(id);
			Drivers.push_back(NewDriver);
		}

		AdminManageDriver();
	}
	void AdminDeleteDriver()
	{
		printf("Input a driver Id : ");
		scanf("%d", &input);

		Driver DriverToDelete(input);

		Drivers.erase(std::remove(Drivers.begin(), Drivers.end(), DriverToDelete), Drivers.end());
		DriverIDs.erase(input);

		printf("Deleted");

		AdminManageDriver();
	}
	void AdminCheckDriver()
	{
		printf("Input a driver Id (input -1 to list all Cars): ");
		scanf("%d", &input);
		printf("%20s", "Driver ID");
		printf("%20s", "Driver Name");
		printf("%20s", "Driver Reward");
		printf("%20s", "Driver punishment\n");

		if (input == -1)
		{
			for (int i = 0; i < Drivers.size(); i++)
			{
				printf("%20d", Drivers[i].GetDriverID());
				printf("%20s", Drivers[i].GetName().c_str());
				printf("%20s", Drivers[i].GetReward().c_str());
				printf("%20s", Drivers[i].GetPunishment().c_str());
			}
		}
		else
		{
			for (int i = 0; i < Drivers.size(); i++)
			{
				if (Drivers[i].GetDriverID() != input)
					continue;
				printf("%20d", Drivers[i].GetDriverID());
				printf("%20s", Drivers[i].GetName().c_str());
				printf("%20s", Drivers[i].GetReward().c_str());
				printf("%20s", Drivers[i].GetPunishment().c_str());
			}
		}

		AdminManageDriver();
	}

	void DriverLogin()
	{
		printf("\n");
		printf(" Please enter your id:");
		scanf("%d", &input);
		Driver CurrentDriver(input);
		for (int i = 0; i < Drivers.size(); i++)
		{
			if (CurrentDriver == Drivers[i])
			{
				printf("Welcome");
				DriverMenu(i);
				break;
			}
		}

		printf("Not Found\n");
		MainMenu();
	}

	void DriverMenu(int i)
	{
		printf("\n");
		printf(" *************************\n");
		printf(" * 1: Show Info          *\n");
		printf(" * 2: Parent Menu        *\n");
		printf(" *************************\n");
		printf(" Please choose your action: ");

		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("%20s", "Driver ID");
			printf("%20s", "Driver Name");
			printf("%20s", "Driver Reward");
			printf("%20s", "Driver punishment\n");
			printf("%20d", Drivers[i].GetDriverID());
			printf("%20s", Drivers[i].GetName().c_str());
			printf("%20s", Drivers[i].GetReward().c_str());
			printf("%20s", Drivers[i].GetPunishment().c_str());
			printf("\n");
		case 2:
			MainMenu();
		default:
			DriverMenu(i);
		}
	}
};

int main()
{
	MainProgram m;
	m.MainMenu();

	return 0;
}