#include "Block.h"
#include "Board.h"
#include "Movement.h"
#include <string>
#include "Windows.h"
#include <iostream>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77



int user_input(){
    char input;

     while(1)
    {
        std::cin >> input;
        
        switch(input)
        {
            case 'u':
               return 0;
                break;
		    case 'r':
                return 1;
			    break;
		    case 'd':
			    return 2;
			    break;
		    case 'l':
                return 3;
                break;
            default:
                break;
        } 
        
    }

    /*
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD NumInputs = 0;
    DWORD InputsRead = 0;
    bool running = true;
    
    INPUT_RECORD irInput;
    
    GetNumberOfConsoleInputEvents(hInput, &NumInputs);
    
    while(running)
    {
        ReadConsoleInput(hInput, &irInput, 1, &InputsRead);
        std::cout << irInput.Event.KeyEvent.wVirtualKeyCode << std::endl;
        
        switch(irInput.Event.KeyEvent.wVirtualKeyCode)
        {
            case KEY_UP:
               return 0;
                break;
		    case KEY_RIGHT:
                return 1;
			    break;
		    case KEY_DOWN:
			    return 2;
			    break;
		    case KEY_LEFT:
                return 3;
                break;
            default:
                break;
        } 
        
    }
    return -1;
    */
}


void find_values(std::string values[], Board main_Board){
    int alternator = 0;
    std::string empty = "      ";
    for(int i = 0; i < 15; i++){
        if(main_Board.spots[i] == NULL){
            values[i] = empty;
        }
        else{
            values[i] = std::to_string(main_Board.spots[i]->value);
            while(values[i].length() != 6){
                if(alternator == 0){
                    values[i] = " " + values[i];
                    alternator = 1;
                }
                else if(alternator == 1){
                    alternator = 0;
                    values[i] = values[i] + " " ;
                }
            }
        }
    }

}

void graphics(std::string values[]){

    std::cout << "_____________________________\n";
    for(int i = 0; i < 3; i++){
        std::cout << "|      |      |      |      |\n";
        for(int j = 0; j < 4; j++){
            std::cout << "|" << values[4*i+j]; 
        }
        std::cout << "|\n";
        std::cout << "|______|______|______|______|\n";
    }
}
int turn(Board main_board){
    std::string values[16];
    find_values(values, main_board);
    graphics(values);
    
    move(user_input(),main_board);
    return 0;
}

int start(){
    Board main_board;
    int game_over = 0;
    while(game_over == 0){
        game_over = turn(main_board);
    }
    return 0;
}