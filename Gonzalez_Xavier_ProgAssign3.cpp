/*  Xavier Gonzalez
    Applied Programming Assignment
    Concert Seating
    1/30/2020
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>

// Initialized Functions
int showMenu();
void showTotalSales();
void showSeatInfo();
void showSeatingChart(char seats[15][30]);
void bTickets(char seats[15][30]);
void Quit();

// Initialized Variables
const int ROWS = 15;
const int COLUMNS = 30;
const int SEATS_PER_ROW = 30;
const int FRONT_ROW_COST = 50;
const int BACK_ROW_COST = 40;
const char seatTaken = '*';
const char seatEmpty = '#';
int totalSales = 0;
int totalSeats = 450;
int row1 = 15, row2 = 15, row3 = 15, row4 = 15, row5 = 15;
int row6 = 15, row7 = 15, row8 = 15, row9 = 15, row10 = 15;
int row11 = 15, row12 = 15, row13 = 15, row14 = 15, row15 = 15;

int showMenu() {
    int choice;

    std::cout << "Welcome! Your choices are: \n"
                << "1 - display seating chart\n"
                << "2 - buy tickets\n"
                << "3 - show total sales\n"
                << "4 - show seating info\n"
                << "5 - quit" << std::endl;  		
		
	std::cout << "Enter choice: " << std::endl;
    std::cin >> choice;

    return choice;
}

void showTotalSales() {
    std::cout << "Total Sales: $" << totalSales << std::endl;
    std::cout << "" << std::endl;
}

void showSeatInfo() {
    std::cout << "\nNumber of seats sold: " << totalSeats << std::endl;
    std::cout << "Total Seats Available: " <<totalSeats<<std::endl;
	std::cout << "Seats Remaining per Row: "<<std::endl;
    std::cout << "Row 1: " << row1 << std::endl;
	std::cout << "Row 2: " << row2 << std::endl;
	std::cout << "Row 3: " << row3 << std::endl;
	std::cout << "Row 4: " << row4 << std::endl;
	std::cout << "Row 5: " << row5 << std::endl;
	std::cout << "Row 6: " << row6 << std::endl;
	std::cout << "Row 7: " << row7 << std::endl;
	std::cout << "Row 8: " << row8 << std::endl;
	std::cout << "Row 9: " << row9 << std::endl;
	std::cout << "Row 10: " << row10 << std::endl;
	std::cout << "Row 11: " << row11 << std::endl;
	std::cout << "Row 12: " << row12 << std::endl;
	std::cout << "Row 13: " << row13 << std::endl;
	std::cout << "Row 14: " << row14 << std::endl;
	std::cout << "Row 15: " << row15 << std::endl;
    std::cout << "" << std::endl;
}

void showSeatingChart(char seats[15][30]) {
    std::cout << "Seating Chart" << std::endl;
    std::cout << "\t" << "123456789012345678901234567890" << std::endl;
	for (int i = 0; i < ROWS; i++) {
		std::cout << "Row " << i+1 << "\t";
		for (int j = 0; j < SEATS_PER_ROW; j++) {
			std::cout << seats[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl; 
}

void bTickets(char seats[15][30]) {
    int row, col;
    int purchaseTickets;
    bool seatAvailable = false;

    std::cout << "How many tickets would you like to buy: " << std::endl;
    std::cin >> purchaseTickets;

    do {

        for (int i = 0; i < purchaseTickets; i++) {
            std::cout << "Enter the row you want to sit in: " << std::endl;
            std::cin >> row;
            if (row > 15 || row < 1) {
                std::cout << "The row you choose is invalid. Please try again." << std::endl;
                break;
            }
            row -= 1;
            std::cout << "Enter the column you want to sit in: ";
            std::cin >> col;
            if (row > 15 || row < 1) {
                std::cout << "The column you choose is invalid. Please try again." << std::endl;
                break;
            }
            col -= 1;

            if (seats[row][col] == seatEmpty) {
                seats[row][col] = seatTaken;
                seatAvailable = true;
                std::cout << "Your seat is available, and purchase!" << std::endl;
                totalSeats -= 1;
                row += 1;

                if (row < 8) {
                    std::cout << "Seat Cost: " << FRONT_ROW_COST << std::endl;
                    std::cout << "" << std::endl;
                    totalSales += FRONT_ROW_COST;
                } else if (row >= 8 && row <= 15) {
                    std::cout << "Seat Cost: " << BACK_ROW_COST << std::endl;
                    std::cout << "" << std::endl;
                    totalSales += BACK_ROW_COST;
                }

                if (row == 1) 
                    row1--;
                else if (row == 2)
                    row2--;
                else if (row == 3)
                    row3--;
                else if (row == 4)
                    row4--;
                else if (row == 5)
                    row5--;
                else if (row == 6)
                    row6--;
                else if (row == 7)
                    row7--;
                else if (row == 8)
                    row8--;
                else if (row == 9)
                    row9--;
                else if (row == 10)
                    row10--;
                else if (row == 11)
                    row11--;
                else if (row == 12)
                    row12--;
                else if (row == 13)
                    row13--;
                else if (row == 14)
                    row14--;
                else if (row == 14)
                    row15--;
                } else
                    std::cout << "Sorry, that seat is taken. Please find another seat." << std::endl;
                }
    } while (seatAvailable == false);
    seatAvailable = false;
}

void Quit() {
    std::cout << "Thank you for using Seat Charter" << std::endl;
}

int main() {

    char concertSeats[ROWS][SEATS_PER_ROW];
    for(int i=0; i< ROWS; i++)
        for(int j=0; j<SEATS_PER_ROW; j++)
            concertSeats[i][j]= seatEmpty;
    int uChoice;

    do {
        uChoice = showMenu();

        switch (uChoice) {
            case 1:
                showSeatingChart(concertSeats);
                break;
            case 2:
				bTickets(concertSeats);
                break;
            case 3:
				showTotalSales();
                break;
            case 4:
				showSeatInfo();
                break;
            case 5:
                Quit();
                exit(1);
            default:
                std::cout << "Invalid choice" << std::endl; //this should never happen
        }
    } while (uChoice != 5);
    return 0;
}