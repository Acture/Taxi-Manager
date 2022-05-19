#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_set>
#include<string>
using namespace std;


class Car{
	private:
	int _carID;
	string _driver1Name;
	string _driver2Name;
	string _payment;

	public:
	Car(){};
	Car(int x){_carID = x;};
	void SetID(int x){_carID = x;};
	void SetDriver1Name(string x){ _driver1Name = x; };
	void SetDriver2Name(string x){ _driver2Name = x; };
	void SetPayment(string x){ _payment = x; };

	int GetID(){return _carID;};
	string GetDriver1Name(){return _driver1Name;};
	string GetDriver2Name(){return _driver2Name;};
	string GetPayment(){return _payment;};

	bool operator==(const Car& other){
		return this -> _carID == other._carID;
	}


};

class Person{
	private:
	string _name;

	public:
	void SetName(string x){_name = x;};
};

class Driver: public Person{
	private:
	string _reward;
	string _punishment;
	int _driverID;

	public:
	Driver(){}
	Driver(int x){_driverID = x;};
	void SetReward(string x){_reward.push_back(x);};
	void SetPunishment(string x){_punishment.push_back(x);};
	void SetDriverID(int x){_driverID = x;};

	int GetDriverID(){return _driverID;};
	string GetReward(){return _reward;};
	string GetPunishment(){return _punishment;};


	bool operator==(const Driver& other){
		return this -> _driverID == other._driverID;
	}
};

class Admin: public Person{
	private:
	int _password = 114514;

	public:
	void SetPassword(int x){_password = x;};
	bool CheckPassword(int x){
		if (x == _password){
			return true;
		} else {
			return false;
		}
	}

};

class MainProgram{
	private:
	vector<Car> Cars;

	vector<Driver> Drivers;
	Admin admin;
	unordered_set<int> CarIDs;
    unordered_set<int> DriverIDs;
	
	int input = 0;

	public:
	void MainMenu(){
		printf("*************************\n");
        printf(" * 1: Manager            *\n");
        printf(" * 2: Driver             *\n");
        printf(" * 3: Quit the program   *\n");
        printf(" *************************\n");
        printf(" Please choose your role: ");

		scanf("%d", &input);

		switch(input){
			case 1:
				AdminLogin();
			case 2:
				DriverMenu();
			case 3:
				break;
			default:
				printf(" * Unknown Command *\n");
				MainMenu();
		}
	}

	void AdminLogin(){
		printf("\n");
        printf(" Please enter your password");
		scanf("%d", &input);
		if (admin.CheckPassword(input))
		{
			AdminMenu();
		}
		else {
			MainMenu();
		}
	}

	void AdminMenu(){
		printf("\n");
        printf(" *************************\n");
        printf(" * 1: Manage car         *\n");
        printf(" * 2: Manage driver      *\n");
        printf(" * 3: move to parent menu*\n");
        printf(" *************************\n");

		scanf("%d", &input);
		switch(input){
			case 1:
				AdminManageCar();
			case 2:
				AdminManageDriver();
			case 3:
				MainMenu();
		}
	}

	void AdminManageCar(){
		printf("\n");
        printf(" *************************\n");
        printf(" * 1: Add Car            *\n");
        printf(" * 2: Delete Car         *\n");
        printf(" * 3: Check Car          *\n");
		printf(" * 4: move to parent menu*\n");
        printf(" *************************\n");
		
		scanf("%d", &input);

		switch(input){
			case 1:
				AdminAddCar();
			case 2:
				AdminDeleteCar();
			case 3:
				AdminCheckCar();
			case 4:
				AdminMenu();
		}
	}
	void AdminAddCar(){
		Car NewCar;
		int id; string name1; string name2; string payment;

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

		if(CarIDs.count(id) > 0){
			printf("Duplicate id");
		} else
		{
			CarIDs.insert(id);
			Cars.push_back(NewCar);
		}

		AdminManageCar();
	}
	void AdminDeleteCar(){
		printf("Input a car Id : ");
		scanf("%d", &input);

		Car CarToDelete(input);

		Cars.erase(std::remove(Cars.begin(), Cars.end(), CarToDelete), Cars.end());
		CarIDs.erase(input);

		printf("Deleted");

		AdminManageCar();
	}
	void AdminCheckCar(){
		printf("Input a car Id (input -1 to list all Cars): ");
		scanf("%d", &input);
		printf("%20s", "Car ID");
        printf("%20s", "Driver1Name");
        printf("%20s", "Driver2Name");
        printf("%20s", "Payment\n");

		if (input==-1){
			for (int i = 0;i<Cars.size(); i++){
				printf("%20d", Cars[i].GetID());
				printf("%20s", Cars[i].GetDriver1Name().c_str());
                printf("%20s", Cars[i].GetDriver2Name().c_str());
				printf("%20s", Cars[i].GetPayment().c_str());
			}
		}
		else{
			for (int i = 0;i<Cars.size(); i++){
				if(Cars[i].GetID()!= input) continue;
				printf("%20d", Cars[i].GetID());
				printf("%20s", Cars[i].GetDriver1Name().c_str());
                printf("%20s", Cars[i].GetDriver2Name().c_str());
				printf("%20s", Cars[i].GetPayment().c_str());
			}
		}

		AdminManageCar();

	}

	void AdminManageDriver(){
		printf("\n");
        printf(" *************************\n");
        printf(" * 1: Add Driver            *\n");
        printf(" * 2: Delete Driver         *\n");
        printf(" * 3: Check Driver          *\n");
		printf(" * 4: move to parent menu*\n");
        printf(" *************************\n");
		
		scanf("%d", &input);

		switch(input){
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
	void AdminAddDriver(){
		Driver NewDriver;
		int id; string name; string reward; string punishment;

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

		if(DriverIDs.count(id) > 0){
			printf("Duplicate id");
		} else
		{
			DriverIDs.insert(id);
			Drivers.push_back(NewDriver);
		}

		AdminManageDriver();
	}
	void AdminDeleteDriver(){
		printf("Input a driver Id : ");
		scanf("%d", &input);

		Driver DriverToDelete(input);

		Drivers.erase(std::remove(Drivers.begin(), Drivers.end(), DriverToDelete), Drivers.end());
		DriverIDs.erase(input);

		printf("Deleted");

		AdminManageDriver();
	}
	void AdminCheckDriver(){
		printf("Input a driver Id (input -1 to list all Cars): ");
		scanf("%d", &input);
		printf("%20s", "driver ID");
        printf("%20s", "driver Reward");
        printf("%20s", "dirver punishment");

		if (input==-1){
			for (int i = 0;i<Drivers.size(); i++){
				printf("%20d", Drivers[i].GetDriverID());
				printf("%20s", Drivers[i].GetReward().c_str());
                printf("%20s", Drivers[i].GetPunishment().c_str());
			}
		}
		else{
			for (int i = 0;i<Drivers.size(); i++){
				if(Drivers[i].GetDriverID()!= input) continue;
				printf("%20d", Drivers[i].GetDriverID());
				printf("%20s", Drivers[i].GetReward().c_str());
                printf("%20s", Drivers[i].GetPunishment().c_str());
			}
		}

		AdminManageDriver();
	}

	void DriverLogin(){
		printf("\n");
        printf(" Please enter your id");
		scanf("%d", &input);
		Driver CurretDriver(input);
		for (int i = 0; i < Drivers.size(); i++)
		{
			if (CurretDriver == Drivers[i]){
				printf("Welcome");
				DriverMenu();
				break;
			} else{
				printf("Not Found")
			}
		}
		

	}

	void DriverMenu(){
		printf("\n");
        printf(" *************************\n");
        printf(" * 1: Check Reward         *\n");
        printf(" * 2: Check Punishment      *\n");
        printf(" * 3: move to parent menu*\n");
        printf(" *************************\n");

		scanf("%d", &input);
		switch(input){
			case 1:
				Drivers();
			case 2:
		}
	}



};

int main(){
	MainProgram m;
	m.MainMenu();

	return 0;
}