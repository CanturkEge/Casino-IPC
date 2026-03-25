
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	//Vars

	int gameSellection, playerDeck, houseDeck, newGameT, newGame, accBorder, accError, doubleCheck, hitCheck, age, spin, blackAgain;
	float balance, bet;
	string accName, accCreator, choice, slotVar1, slotVar2, slotVar3;
	
	blackAgain = 1;
	newGame = 1;
	accError = 0;
	hitCheck = 0;

	srand(time(0));
	
	cout << "Please enter your age for continue: ";	
	cin >> age;
	if (age < 18 || age > 120) {
		cout << "Sorry. Your age does not meet the requirements. \n\n\n\n";
		return(1);
	}

	cout << "Welcome to casino! \n";

	do {
		
		do{
			cout << "\nDo you have an account? \n" << "0 for create new account, 1 for sign in, 2 for exit: ";
			cin >> accBorder;
		     
			
			switch (accBorder)
			{
			case(1):
			{
				cout << "\nPlease type your account's full name (Example: name_surname.txt): " << endl;
				cin >> accName;

				ifstream acc2(accName);
				if (!acc2) {
					cout << "\nSomething went wrong. Please try again. \n";
					accError = 0;
				}
				else {
					acc2 >> balance;
					acc2.close();

					cout << "\nYour balance is $" << balance << ". Have fun!\n";

					accError = 1;
				}
				break;
			}

			case(0):
			{
				cout << "\nWelcome to 'create a new account'. Starting balance is $100 for new accounts! \n" << "Please type your name and surname for sign up! (Example: name_surname.txt)\nIf you try to create another account with the name of an existing account, your balance will be reset.\n";
				cin >> accCreator;

				ofstream acc(accCreator);

				if (!acc) {
					cout << "\nSomething Went wrong. Please try again later. \n";
					accError = 0;
				}

				acc << 100;
				acc.close();


				cout << "Your account has been created successfully and your account name is (" << accCreator << ")! You are directed to the login page.Please wait for 3 seconds.\n";

				cout << ".\n";
				this_thread::sleep_for(chrono::seconds(3));

				accError = 0;
				break;
			}

			case(2): {
				cout << "Goodbye!";
				this_thread::sleep_for(chrono::seconds(1));
				return (1);
			}

			default:
			{
				cout << "Something went wrong. Please try again. \n";
				accError = 0;
			}

			}

		}while (accError == 0);//account manager


		cout << "\nWelcome to Casino please sellect which game you want to continue: \n" << "*(1)* Roulette \n" << "*(2)* Blackjack \n" << "*(3)* Slot \n" << "*(4)* Dice Game \n" << "*(5)* Dangerous Cave \n" << "*(6)* Dungeon Escape \n" << "*(7)* Exit \n" << endl;
		cin >> gameSellection;

		
		switch (gameSellection)
		{
		case(1): {

			int exitRou = 1;

			do {
				cout << "Welcome to the Roulette! \n\n";
				cout << endl <<
					" ==========================================================" << endl <<
					" / | 3 | 6 | 9 | 12 | 15 | 18 | 21 | 24 | 27 | 30 | 33 | 36 |2to1 R1|" << endl <<
					"|0 | 2 | 5 | 8 | 11 | 14 | 17 | 20 | 23 | 26 | 29 | 32 | 35 |2to1 R2|" << endl <<
					" \\ | 1 | 4 | 7 | 10 | 13 | 16 | 19 | 22 | 25 | 28 | 31 | 34 |2to1 R3|" << endl <<
					" ==========================================================" << endl <<
					" |      1st12     |       2nd12       |       3rd12       |" << endl <<
					" ----------------------------------------------------------" << endl <<
					" | 1to18 |  EVEN  |   RED   |  BLACK  |   ODD   |  19to36 |" << endl <<
					" ----------------------------------------------------------\n\n\n";

				string betClass;
				int betClassLoop, redB = 0, blackB = 0, evenB = 0, oddB = 0, stB = 0, ndB = 0, rdB = 0, row1B = 0, row2B = 0, row3B = 0, to18B = 0, to36B = 0, numberB = 0, totalBet = 0, spinNumber, number, Betamount;

				map<int, int> bets;

				vector<int> red = { 3,32,19,21,25,34,27,36,30,23,5,16,1,14,9,18,7,12 };
				vector<int> black = { 26,15,4,2,17,6,13,11,8,10,24,33,20,31,22,29,28,35 };
				vector<int> even = { 2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36 };
				vector<int> odd = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35 };
				vector<int> st = { 1,2,3,4,5,6,7,8,9,10,11,12 };
				vector<int> nd = { 13,14,15,16,17,18,19,20,21,22,23,24 };
				vector<int> rd = { 25,26,27,28,29,30,31,32,33,34,35,36 };
				vector<int> row1 = { 3,6,9,12,15,18,21,24,27,30,33,36 };
				vector<int> row2 = { 2,5,8,11,14,17,20,23,26,29,32,35 };
				vector<int> row3 = { 1,4,7,10,13,16,19,22,25,28,31,34 };
				vector<int> to18 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };
				vector<int> to36 = { 19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36 };

				while (true) {
					cout << "Where would you like to put your bet? (bets must be an integer), (number, red, black, even, odd, 1st12, 2nd12, 3nd12, 1to18, 19to36, r1, r2, r3). 'end' for finish.\n \n \n \n \n";
					cin >> betClass;


					if (betClass == "number")
					{
						while (true) {

							// Ask user for number and bet amount
							cout << "Enter the number (0-36) to bet on: ";
							cin >> number;

							if (number < 0 || number > 36) {
								cout << "Please enter a number between 0 and 36!" << endl;
								continue;
							}
							cout << "Enter the bet amount: ";
							cin >> Betamount;

							bets[number] = Betamount;
							totalBet += Betamount;

							cout << "Enter '1' to continue or '0' to exit." << endl;
							cin >> number;

							if (number == 0) {

								break;
							}
						}

						cout << "Bets:" << endl;
						for (auto& betN : bets)
						{
							cout << "Number: " << betN.first << " - Bet Amount: $" << betN.second << endl;
						}
					}
					if (betClass == "red")
					{
						cout << "Please place your bet: \n";
						cin >> redB;
						totalBet = totalBet + redB;
					}
					if (betClass == "black")
					{
						cout << "Please place your bet: \n";
						cin >> blackB;
						totalBet = totalBet + blackB;
					}
					if (betClass == "even")
					{
						cout << "Please place your bet: \n";
						cin >> evenB;
						totalBet = totalBet + evenB;
					}
					if (betClass == "odd")
					{
						cout << "Please place your bet: \n";
						cin >> oddB;
						totalBet = totalBet + oddB;
					}
					if (betClass == "1st12")
					{
						cout << "Please place your bet: \n";
						cin >> stB;
						totalBet = totalBet + stB;
					}
					if (betClass == "2nd12")
					{
						cout << "Please place your bet: \n";
						cin >> ndB;
						totalBet = totalBet + ndB;
					}
					if (betClass == "3rd12")
					{
						cout << "Please place your bet: \n";
						cin >> rdB;
						totalBet = totalBet + rdB;
					}
					if (betClass == "1to18")
					{
						cout << "Please place your bet: \n";
						cin >> to18B;
						totalBet = totalBet + to18B;
					}
					if (betClass == "19to36")
					{
						cout << "Please place your bet: \n";
						cin >> to36B;
						totalBet = totalBet + to36B;
					}
					if (betClass == "r1")
					{
						cout << "Please place your bet: \n";
						cin >> row1B;
						totalBet = totalBet + row1B;
					}
					if (betClass == "r2")
					{
						cout << "Please place your bet: \n";
						cin >> row2B;
						totalBet = totalBet + row2B;
					}
					if (betClass == "r3")
					{
						cout << "Please place your bet: \n";
						cin >> row3B;
						totalBet = totalBet + row3B;
					}
					if (betClass == "end")
					{
						break;
					}
				}

				balance = balance - totalBet;

				ofstream acc(accName);
				acc << balance;
				acc.close();

				cout << "Roulette wheel is spining now.";

				this_thread::sleep_for(chrono::seconds(1));
				cout << ".";
				this_thread::sleep_for(chrono::seconds(1));
				cout << ".";
				this_thread::sleep_for(chrono::seconds(1));
				cout << ".";
				this_thread::sleep_for(chrono::seconds(1));
				cout << ".";
				this_thread::sleep_for(chrono::seconds(1));
				cout << ".";

				spinNumber = rand() % 37;

				cout << "\nBalance is $" << balance << endl;

				if (find(red.begin(), red.end(), spinNumber) != red.end())
				{
					balance = balance + (redB * 2);
				}
				if (find(black.begin(), black.end(), spinNumber) != black.end())
				{
					balance = balance + (blackB * 2);
				}
				if (find(even.begin(), even.end(), spinNumber) != even.end())
				{
					balance = balance + (evenB * 2);
				}
				if (find(odd.begin(), odd.end(), spinNumber) != odd.end())
				{
					balance = balance + (redB * 2);
				}
				if (find(st.begin(), st.end(), spinNumber) != st.end())
				{
					balance = balance + (stB * 3);
				}
				if (find(nd.begin(), nd.end(), spinNumber) != nd.end())
				{
					balance = balance + (ndB * 3);
				}
				if (find(rd.begin(), rd.end(), spinNumber) != rd.end())
				{
					balance = balance + (rdB * 3);
				}
				if (find(row1.begin(), row1.end(), spinNumber) != row1.end())
				{
					balance = balance + (row1B * 3);
				}
				if (find(row2.begin(), row2.end(), spinNumber) != row2.end())
				{
					balance = balance + (row2B * 3);
				}
				if (find(row3.begin(), row3.end(), spinNumber) != row3.end())
				{
					balance = balance + (row3B * 3);
				}
				if (find(to18.begin(), to18.end(), spinNumber) != to18.end())
				{
					balance = balance + (to18B * 2);
				}
				if (find(to36.begin(), to36.end(), spinNumber) != to36.end())
				{
					balance = balance + (to36B * 2);
				}
				for (auto& betN : bets)
				{
					//betN.first is number and betN.second the bet on it.
					if (betN.first == spinNumber)
					{
						balance = balance + (betN.second * 36);
						break;
					}
				}

				acc.open(accName);
				acc << balance;
				acc.close();

				cout << "\nNumber is: " << spinNumber << endl;

				cout << "\nBalance is $" << balance << endl;

				cout << "\Wanna continue? (1 for yes 0 for no)" << endl;
				cin >> exitRou;

			}while(exitRou == 1);

			break;
		}
		
		case(2):
		{
			do {
			cout << "\nWelcome to blackjack!  \n" << "Aces only count as '1' !!!\n" << "Please enter your bet: ";
			cin >> bet;

			if (bet > 0 && bet <= balance) {
				balance = balance - bet;
				ofstream acc(accName);
				acc << balance;
				acc.close();
				cout << "\nThe deck is being shuffled! \n";

				cout << ".\n";
				this_thread::sleep_for(chrono::seconds(1));
				cout << ".\n";
				this_thread::sleep_for(chrono::seconds(1));
				cout << ".\n";
				this_thread::sleep_for(chrono::seconds(1));

				cout << "\nGame is starting! \n";
				houseDeck = 0;

				playerDeck = rand() % 19 + 3;
				
				cout << "\n";
				bool blackjack = 0;
				this_thread::sleep_for(chrono::seconds(2));

				houseDeck = rand() % 10 + 1;
				

				if (playerDeck == 21) {					
					blackjack = 1;
				}

				
					do {

						cout << "\nYour bet is: $" << bet << "\nYour balance is: " << balance << "\nYour hand is: " << playerDeck << "\nHouse first card hand is: " << houseDeck;
						cout << "\nH for hit\nS for Stand \nD for double \n";

					
						cin >> choice;

						if (choice == "S" || choice == "s") {
							hitCheck = 0;
						}

						else if (choice == "D" || choice == "d") {
							
							if (bet * 2 <= balance) {
								balance = balance - bet;
								bet = bet * 2;
								playerDeck = playerDeck + rand() % 10 + 1;
								hitCheck = 0;
								cout << "Your new bet is $" << bet << ". Good luck!\n";
								this_thread::sleep_for(chrono::seconds(1));
								cout << "Your hand is " << playerDeck << endl;
								this_thread::sleep_for(chrono::seconds(2));
							}
							else if (bet * 2 > balance) {
								cout << "Your balance is not enough for double...\n";
								hitCheck = 1;
							}
							
						}
						else if (choice == "H" || choice == "h") {
							playerDeck = playerDeck + rand() % 10 + 1;
							hitCheck = 1;
						}

					} while (hitCheck == 1 && playerDeck < 21);


					if (playerDeck > 21) {

						cout << "Your hand is " << playerDeck << endl << " -$" << bet << " Bust! Your balance is $" << balance;
						this_thread::sleep_for(chrono::seconds(2));
					}


					else if (playerDeck == 21) {
						cout << "You hit 21! \n";
						houseDeck = houseDeck + rand() % 10 + 1;
						cout << "House full hand is: \n" << houseDeck << endl;
						this_thread::sleep_for(chrono::seconds(1));

						while (houseDeck < 21) {
							cout << "House hand is " << houseDeck <<"\n New card is drawing...\n";
							this_thread::sleep_for(chrono::seconds(1));
							houseDeck = houseDeck + rand() % 10 + 1;
						}
						if (houseDeck == 21) {
							balance = balance + bet;
							cout << "Push! Your balance is: $" << balance;
						}
						else {
							cout << "House hand is " << houseDeck << endl;
							cout << "You won!! ";
							if (blackjack == 1) {
								cout << "with blackjack !!!!";
								balance = balance + bet;
								bet = bet * 1.5;
								balance = balance + bet;
							}
							else
							{
								balance = balance + (2 * bet);
							}
							cout << "Your hand is "<< playerDeck << endl << "+$"<< bet << endl << "Your balance is $" << balance;
						}
						ofstream acc(accName);
						acc << balance;
						acc.close();
					}

					else {
						houseDeck = houseDeck + rand() % 10 + 1;
						cout << "House full hand is: \n" << houseDeck << endl;
						this_thread::sleep_for(chrono::seconds(1));

						while (houseDeck < playerDeck) {
							cout << "House hand is " << houseDeck << "\n New card is drawing...\n";
							this_thread::sleep_for(chrono::seconds(1));
							houseDeck = houseDeck + rand() % 10 + 1;
						}
						cout <<endl<<"\nHouse hand is: " << houseDeck << endl;
						if (houseDeck == playerDeck) {
							balance = balance + bet;
							cout << "Push! Your balance is: $" << balance;
						}
						else if (houseDeck > playerDeck && houseDeck <= 21) {
							cout << "Your hand is "<< playerDeck << ". You lost... \n";
							cout << "-$" << bet << endl << "Your balance is $" << balance;
						}
						else {
							cout << "Your hand is " << playerDeck << ". You won!! \n";
							balance = balance + (2 * bet);
							cout << "+$" << bet << endl << "Your balance is $" << balance;
						}


						ofstream acc(accName);
						acc << balance;
						acc.close();


					}

	

			}
			else		
				cout << "\nSomething went wrong please try again later. \n";

				
		cout << "\nWould you like to continue? '1 for continue, 0 for stop' \n";

		cin >> blackAgain;
		}while (blackAgain == 1);
		break;
		}//blackjack

		case(3): {
			do{
			cout << "\nWelcome to slot!  \n" << "Please enter your bet: ";
			cin >> bet;
			double multiplier;
			do{
				if (bet > 0 && bet <= balance) {
					balance = balance - bet;
					ofstream acc(accName);
					acc << balance;
					acc.close();
					cout << " |X|X|X| = 4x \n |O|O|O| = 6x \n |%|%|%| = 8x \n |&|&|&| = 10x \n |$|$|$| = !!15x!! \n\n |+|+|-| = 0.5x \n\n\n\n\n";


					vector<string> slotElements = { "X", "X", "X", "X", "X", "O", "O", "O", "O", "%", "%", "%", "&", "&", "$" };

					string slotVar1 = slotElements[rand() % slotElements.size()];
					string slotVar2 = slotElements[rand() % slotElements.size()];
					string slotVar3 = slotElements[rand() % slotElements.size()];

					cout << "|";
					this_thread::sleep_for(chrono::seconds(1));//delay
					cout << slotVar1;
					this_thread::sleep_for(chrono::seconds(1));
					cout << "|" << slotVar2;
					this_thread::sleep_for(chrono::seconds(1));
					cout << "|" << slotVar3 << "| \n\n\n";
					this_thread::sleep_for(chrono::seconds(1));

					if (slotVar1 == slotVar2 && slotVar2 == slotVar3)
					{
						if (slotVar1 == "X")
						{
							multiplier = 4;
						}
						else if (slotVar1 == "O")
						{
							multiplier = 6;
						}
						else if (slotVar1 == "%")
						{
							multiplier = 8;
						}
						else if (slotVar1 == "&")
						{
							multiplier = 10;
						}
						else if (slotVar1 == "$")
						{
							multiplier = 15;
						}

						cout << "You won $" << bet * multiplier << endl;
						balance = balance + (bet * multiplier);
						cout << "Your balance is $" << balance << endl;

					}
					else if (slotVar1 == slotVar2 && slotVar1 != slotVar3)
					{

						cout << "You won half of your bet back... Keep trying! \n";
						balance = balance + (bet / 2);

					}
					else if (slotVar1 != slotVar2 && slotVar2 == slotVar3)
					{
						cout << "You won half of your bet back... Keep trying! \n";
						balance = balance + (bet / 2);


					}
					else if (slotVar1 == slotVar3 && slotVar2 != slotVar3)
					{
						cout << "You won half of your bet back... Keep trying! \n";
						balance = balance + (bet / 2);


					}

					else
					{

						cout << "you lost...\n";

					}

					acc.open(accName);
					acc << balance;
					acc.close();

				}
			
			else
				cout << "\nSomething went wrong please try again later. \n";
				
				cout << "Your balance is " << balance << endl;
				cout << "type: 0 for spin again with same bet, 1 for change bet and 2 for exit.";
				cin >> spin;
			} while (spin == 0);
			} while (spin == 1);
			break;
		}

		case(4): {
			
			int guess1, guess2, dice, diceAgain;
			cout << "Welcome to the Dice Game! Try to guess the dice (1-6)\nYou can guess 2 numbers type one then press 'space' then type other.\nIf you guess it correctly (enough one of your guesses) you will get 2.5x of your money!\n";
			
			do {
				cout << "\nEnter bet: ";
				cin >> bet;
				do {
					balance = balance - bet;

					ofstream acc(accName);
					acc << balance;
					acc.close();

					cout << "\nType your guesses: ";
					cin >> guess1 >> guess2;

					cout << "\nDice started roll! \n";
					
					cout << ".\n";
					this_thread::sleep_for(chrono::seconds(1));
					cout << ".\n";
					this_thread::sleep_for(chrono::seconds(1));


					dice = rand() % 5 + 1;

					cout << "Dice " << dice << endl;
					if (guess1 == dice || guess2 == dice)
					{
						cout << "\nYou guess it right! You won $" << bet * 2.5 << endl;
						balance = balance + 3.5 * bet;
						acc.open(accName);
						acc << balance;
						acc.close();
					}
					else
						cout << "You couldnt guess it right... \n";

					cout << "Your balance is " << balance << endl;
					cout << "Would you like to continue? 0 for yes, 1 for with diffrent bet, 2 for exit: ";
					cin >> diceAgain;

				} while (diceAgain == 0);
			} while (diceAgain == 1);

			break;
		}

		case(5): {

			cout << "\nWelcome to the Dangerous Cave game! Your duty is to avoid falling into the trap (!if you fall you will lose all your multiplier!) and win multiplier by going through the most dilemmas. (Each dilemma 0.9 multiplier)\n";
			
			int playAgain;
			
			do {
				cout << "\nEnter bet: ";
				cin >> bet;


				if (bet > 0 && bet <= balance) {
					balance = balance - bet;
					ofstream acc(accName);
					acc << balance;
					acc.close();
					cout << "\nAdvanture is starting!\n";
					this_thread::sleep_for(chrono::seconds(1));
					cout << "\n\n\n";

					int caveWay;
					double multiplier = 0;


					do {
						cout << "Right(1), Left(2), RUN!(0)\n";
						cin >> caveWay;
						if (caveWay == 1 || caveWay == 2) {
							int randomizer = rand() % 2;
							

							if (randomizer == 1) {
								multiplier = multiplier + 0.9;
								cout << "You found the right way!\n";
							}
							else {
								cout << "You fell a trap! You lost all your " << multiplier << "x multiplier! And your balance is $" << balance << endl;
								caveWay = 0;
								multiplier = 0;
							}
						}
					} while (caveWay != 0);

					balance = balance + (bet * multiplier);
					acc.open(accName);
					acc << balance;
					acc.close();

					cout << "You ran through the exit and your total multiplier is " << multiplier << "x. You won $" << (bet * multiplier) << ". And your balance is $" << balance << endl;
				}

				else
					cout << "Something went wrong, please try again later.\n";
				cout << "Would you like to try again? (1 for yes, 0 for no)\n";
				
				cin >> playAgain;

			} while (playAgain == 1);

			break;
		}

		case(6): {

			
			break;
		}

		case(7): {
			cout << "Goodbye!";
			return(1);
				break;
		}//exit
		
		default:
			cout << "\nError. Please try again later.\n";
		}//game sellection

		cout << "\nWould you like to play another game? '1 for continue, 0 for stop' \n";
		
		cin >> newGame;

	} while (newGame == 1);//game restarter

	cout << "\nThanks for playing! Your current " << accName << " balance is $" << balance << endl;

}//main

