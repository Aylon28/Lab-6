#include <iostream>
using namespace std;

class Casino{
protected:
	int wonMoney;
	int betMoney;

public:
	Casino(int wonMoney = 0, int betMoney = 0) {
		//cout << "Constructor Casino" << endl;
		this->wonMoney = wonMoney;
		this->betMoney = betMoney;
	}
	~Casino() {
		//cout << "Destructor Casino" << endl;
	}

	void Show();
	void Name();
};

void Casino::Name(){
	cout << "Casino";
}

void Casino::Show(){
	cout << "Bet money: " << betMoney << ", won money: " << wonMoney;
}

class PlaceSettings : public virtual Casino{
protected:
	int tableNumber;
	int amountOfPlaces;

public:
	PlaceSettings(int wonMoney = 0, int betMoney = 0, int tableNumber = 1, int amountOfPlaces = 1) : Casino(wonMoney, betMoney) {
		//cout << "Constructor PlaceSettings" << endl;
		this->tableNumber = tableNumber;
		this->amountOfPlaces = amountOfPlaces;
	}
    ~PlaceSettings() {
		//cout << "Destructor PlaceSettings" << endl;
	}
	void IncPlaces();
	void DecPlaces();
	void Name();
	void Show();
};
void PlaceSettings::IncPlaces(){
	if(amountOfPlaces < 10){
		amountOfPlaces++;
	} else{
		cout << "Too much people!" << endl;
	}
}
void PlaceSettings::DecPlaces(){
	if(amountOfPlaces >= 2){
		amountOfPlaces--;
	} else{
		cout << "Not less than 2!" << endl;
	}
}
void PlaceSettings::Name(){
	cout << "PlaceSettings" << endl;
}
void PlaceSettings::Show(){
	cout << "Bet money: " << betMoney << ", won money: " << wonMoney << ", table number: " << tableNumber << ", amount of places: " << amountOfPlaces << endl;
}

class GameSettings : public virtual Casino{
protected:
	int amountOfCards;
	int amountOfPlayers;

public:
	GameSettings(int wonMoney = 0, int betMoney = 0, int amountOfCards = 1, int amountOfPlayers = 1) : Casino(wonMoney, betMoney) {
		//cout << "Constructor GameSettings" << endl;
		this->amountOfCards = amountOfCards;
		this->amountOfPlayers = amountOfPlayers;
	}
	~GameSettings() {
		//cout << "Destructor GameSettings" << endl;
	}
	void AddPlayers();
	void ChangeAmountOfCards(int newCards);
	void Name();
	void Show();
};
void GameSettings::ChangeAmountOfCards(int newCards){
	if(newCards == 52 || newCards == 72){
		amountOfCards = newCards;
	}else{
		cout << "No such a number of cards!" << endl;
	}
}
void GameSettings::AddPlayers(){
	if(amountOfPlayers < 10){
		amountOfPlayers++;
	} else{
		cout << "Too much players!" << endl;
	}
}
void GameSettings::Name(){
	cout << "GameSettings" << endl;
}
void GameSettings::Show(){
	cout << "Bet money: " << betMoney << ", won money: " << wonMoney << ", amount of cards: " << amountOfCards << ", amount of players: " << amountOfPlayers << endl;
}






//Не переопределён метод "Name()"

class Poker : public PlaceSettings, public GameSettings{
private:
	int score;
	int rate;

public:
	Poker(int wonMoney = 0, int betMoney = 0, int tableNumber = 1, int amountOfPlaces = 1, int amountOfCards = 1, int amountOfPlayers = 1,
			int score = 0, int rate = 1) : Casino(wonMoney, betMoney), PlaceSettings(wonMoney, betMoney,tableNumber, amountOfPlaces),
			GameSettings(wonMoney, betMoney, amountOfCards, amountOfPlayers) {
		//cout << "Constructor Poker" << endl;
		this->score = score;
		this->rate = rate;
	}
	virtual ~Poker() {
		//cout << "Destructor Poker" << endl;
	}
	void MultiplyRate(int num);
    void ResetRate();
	void Show();
};
void Poker::Show(){
	cout << "Bet money: " << betMoney << ", won money: " << wonMoney << ", amount of cards: " << amountOfCards <<
			", amount of players: " << amountOfPlayers << ", table number: " << tableNumber << ", amount of places: " << amountOfPlaces <<
			", score: " << score << ", rate: " << rate << endl;
}
void Poker::MultiplyRate(int num){
	rate *= num;
}
void Poker::ResetRate(){
	rate = 1;
}

bool IsNumber(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}
string IsCorrect(string request){
	string item;
	do{
		cout << request;
		getline(cin, item);
		while(IsNumber(item) == false){
				cout << "\nINCORRECT" << endl;
				cout << request;
				getline(cin, item);
		}
	}while(stoi(item) < 1);
	return item;
}

int main() {
	string players, cards, places, money, paid, score, table, rate;

	cout << "PLACE SETTINGS";
	cout << "\nEnter the correct data: " << endl;

	money = IsCorrect("Amount of won money = ");
	paid = IsCorrect("Bet money = ");
	cards = IsCorrect("Number of cards = ");
	players = IsCorrect("Number of players = ");

	PlaceSettings placeSettings(stoi(money),stoi(paid),stoi(cards),stoi(players));
	placeSettings.Show();
	placeSettings.IncPlaces();
	placeSettings.Show();
	placeSettings.DecPlaces();
	placeSettings.Show();
	placeSettings.Name();

	cout << endl << "GAME SETTINGS";
	cout << "\nEnter the correct data: " << endl;

	money = IsCorrect("Amount of won money = ");
	paid = IsCorrect("Bet money = ");
	table = IsCorrect("Number of table = ");
	places = IsCorrect("Number of places = ");

	GameSettings gameSettings(stoi(money),stoi(paid),stoi(table),stoi(places));
	gameSettings.Show();
	gameSettings.ChangeAmountOfCards(52);
	gameSettings.Show();
	gameSettings.AddPlayers();
	gameSettings.Show();
	gameSettings.Name();

	cout << endl << "POKER";
	cout << "\nEnter the correct data: " << endl;

	money = IsCorrect("Amount of won money = ");
	paid = IsCorrect("Bet money = ");
	table = IsCorrect("Number of table = ");
	places = IsCorrect("Number of places = ");
	cards = IsCorrect("Number of cards = ");
	players = IsCorrect("Number of players = ");
	score = IsCorrect("Score = ");
	rate = IsCorrect("Rate = ");

	Poker poker(stoi(money),stoi(paid),stoi(table),stoi(places),stoi(cards),stoi(players), stoi(score), stoi(rate));
	poker.Show();
	poker.ChangeAmountOfCards(52);
	poker.Show();
	poker.AddPlayers();
	poker.Show();

	poker.GameSettings::Name();
	poker.PlaceSettings::Name();
	poker.Casino::Name();

	return 0;
}

