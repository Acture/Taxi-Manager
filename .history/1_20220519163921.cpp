#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_set>
using namespace std;


class Car{
	private:
	int _carID;
	string _driver1Name;
	string _driver2Name;
	string _payment;

	public:
	void setId(int x){_carID = x;};
	void SetDriver1Name(string x){ _driver1Name = x; };
	void SetDriver2Name(string x){ _driver2Name = x; };
	void SetPayment(string x){ _payment = x; };

	int getID(){return _carID;};
	string getDriver1Name(){return _driver1Name;};
	string getDriver2Name(){return _driver2Name;};
	string getPayment(){return _payment;};

	bool operator==(Car & rec) const{
		return this->_carID == rec.getID();
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
	unordered_set<int> carIDs;
    unordered_set<int> driverIDs;
	
	int input = 0;

	public:
	void MainMenu(){
		printf("*************************\n");
        printf(" * 1: manager            *\n");
        printf(" * 2: customer           *\n");
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

		NewCar.setId(id);
		NewCar.SetDriver1Name(name1);
		NewCar.SetDriver2Name(name2);
		NewCar.SetPayment(payment);

		if(carIDs.count(id) > 0){
			printf("Duplicate id");
		} else
		{
			carIDs.insert(id);
			cars.push_back(NewCar);
		}

		AdminManageCar();
	}

	void AdminDeleteCar(){
		printf("Input a car Id : ");
		scanf("%d", &input);
		printf("Deleted");

		cars.erase(std::remove(cars.begin(), cars.end(), input), cars.end());

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
				printf("%20d", cars[i].getID());
				printf("%20s", cars[i].getDriver1Name().c_str());
                printf("%20s", cars[i].getDriver2Name().c_str());
				printf("%20s", cars[i].getPayment().c_str());
			}
		}
		else{
			for (int i = 0;i<cars.size(); i++){
				if(cars[i].getID()!= input) continue;
				printf("%20d", cars[i].getID());
				printf("%20s", cars[i].getDriver1Name().c_str());
                printf("%20s", cars[i].getDriver2Name().c_str());
				printf("%20s", cars[i].getPayment().c_str());
			}
		}

		AdminManageCar();

	}
	void AdminManageDriver(){}
	void DriverMenu(){}

};

int main(){
	MainProgram m;
	m.MainMenu();

	return 0;
}