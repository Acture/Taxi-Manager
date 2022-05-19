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
	vector<string> _reward;
	vector<string> _punishment;

	public:
	void SetReward(string x){_reward.push_back(x);};
	void SetPunishment(string x){_punishment.push_back(x);};
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
	vector<Car> cars;

	vector<Driver> drivers;
	Admin admin;
	unordered_set<int> CarIDs;
    unordered_set<int> DriverIDs;
	
	int input = 0;

	public:
	void MainMenu(){
		printf("*************************\n");
        printf(" * 1: manager            *\n");
        printf(" * 2: driver             *\n");
        printf(" * 3: quit the program   *\n");
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
			cars.push_back(NewCar);
		}

		AdminManageCar();
	}

	void AdminDeleteCar(){
		printf("Input a car Id : ");
		scanf("%d", &input);
		printf("Deleted");

		Car CarToDelete(input);

		cars.erase(std::remove(cars.begin(), cars.end(), CarToDelete), cars.end());

		AdminManageCar();
	}
	void AdminCheckCar(){
		printf("Input a car Id (input -1 to list all cars): ");
		scanf("%d", &input);
		printf("%20s", "Car ID");
        printf("%20s", "Driver1Name");
        printf("%20s", "Driver2Name");
        printf("%20s", "Payment\n");

		if (input==-1){
			for (int i = 0;i<cars.size(); i++){
				printf("%20d", cars[i].GetID());
				printf("%20s", cars[i].GetDriver1Name().c_str());
                printf("%20s", cars[i].GetDriver2Name().c_str());
				printf("%20s", cars[i].GetPayment().c_str());
			}
		}
		else{
			for (int i = 0;i<cars.size(); i++){
				if(cars[i].GetID()!= input) continue;
				printf("%20d", cars[i].GetID());
				printf("%20s", cars[i].GetDriver1Name().c_str());
                printf("%20s", cars[i].GetDriver2Name().c_str());
				printf("%20s", cars[i].GetPayment().c_str());
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
		}
	}
	void AdminAddDriver(){
		Driver NewDriver;
		int id;
		string name; string reward; string punishment;
        
        printf("Driver name: ");
        cin >> name;
        
        printf("Reward: ");
        cin >> reward;
        
        printf("Punishment: ");
        cin >> punishment;

		NewDriver.SetName(name);
		NewDriver.SetReward(reward);
		NewDriver.SetPunishment(punishment);

		if(DriverIDs.count(id) > 0){
			printf("Duplicate id");
		} else
		{
			CarIDs.insert(id);
			cars.push_back(NewCar);
		}

		AdminManageCar();
	}

	void AdminDeleteDriver(){}
	void AdminCheckDriver(){}
	void DriverMenu(){}

};

int main(){
	MainProgram m;
	m.MainMenu();

	return 0;
}