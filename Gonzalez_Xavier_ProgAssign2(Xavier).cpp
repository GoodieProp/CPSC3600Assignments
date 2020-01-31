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

// Initialized Variables
const int ROWS = 15;

const int columns = 30;
const int SEATS_PER_ROW = 30;
const int FRONT_ROW_COST = 50;
const int BACK_ROW_COST = 40;
const int DIVIDER = 7; //first 7 rows are "front"
const char seatTaken = '*';
const char seatEmpty = '#';

int main() {

    char concertSeats[ROWS][SEATS_PER_ROW];
    for(int i=0; i< ROWS; i++)
        for(int j=0; j<SEATS_PER_ROW; j++)
            concertSeats[i][j]= seatEmpty;
    int uChoice;
    int totalSales = 0;
    
    do {
        uChoice = showMenu();

        switch (uChoice) {
            case 1:
                std::cout << "Seating Chart" << std::endl;
                std::cout << "\t" << "123456789012345678901234567890" << std::endl;
	            for (int i = 0; i < ROWS; i++) {
		            std::cout << "Row " << i+1 << "\t";
		            for (int j = 0; j < SEATS_PER_ROW; j++) {
			            std::cout << concertSeats[i][j];
		            }
		            std::cout << std::endl;
	            }
	            std::cout << std::endl; 
                break;
            case 2:
				/*TO DO: code for letting user buy tickets
					-also updates total sales and seating chart
					-up to you to implement, but the following steps may help:
					Steps:
					1. Ask how many tickets user wants to buy 
					2. For each ticket they want to purchase
						-Ask user to enter row number followed by seat number
						-Validate that the rows selected are valid (not taken)
						-If seat selection is valid, update order cost and seating chart
						-Repeat until user has purchased the number of tickets they entered
				*/

                int row, col;
                char choice;

                do {
                    std::cout << "Enter the row you want to sit in: " << std::endl;
                    std::cin >> row;
                    row -= 1;
                    std::cout << "Enter the column you want to sit in: ";
                    std::cin >> col;
                    col -= 1;

                    if (concertSeats[row][col] == seatTaken) {
                        std::cout << "This seat is taken. Please select another seat.";
                        std::cout << std::endl;
                    } else {
                        row += 1;
                        col += 1;
                        if (row < 8) {
                            std::cout << FRONT_ROW_COST;
                            totalSales += FRONT_ROW_COST;
                            concertSeats[row-1][col-1] = '*';
                        } else if (row >= 8 && row <= 15) {
                            std::cout << BACK_ROW_COST;
                            totalSales += BACK_ROW_COST;
                            concertSeats[row-1][col-1] = '*';
                        }
                    }


                } while (choice == 'Y');

                break;
            case 3:
				//TO DO: code for displaying total sales
                std::cout << "Total Sales: $" << totalSales << std::endl;

                break;
            case 4:
				/*TO DO: code for displaying seat info, e.g.
					-how many seats have sold
					-how many seats available for each row
					-how many seats available for the entire auditorium
				*/
                std::cout << "Seating Chart" << std::endl;
                std::cout << "\t" << "123456789012345678901234567890" << std::endl;
	            for (int i = 0; i < ROWS; i++) {
		            std::cout << "Row " << i+1 << "\t";
		            for (int j = 0; j < SEATS_PER_ROW; j++) {
			            std::cout << concertSeats[i][j];
		            }
		            std::cout << std::endl;
	            }
	            std::cout << std::endl; 
                break;
            case 5:
				//code to quit program
                std::cout << "Thank you for using Concert Seating";
                exit(1);
            default:
                std::cout << "Invalid choice" << std::endl; //this should never happen
        }

    } while (uChoice != 5);

}

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
