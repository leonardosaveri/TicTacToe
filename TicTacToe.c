#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


void print_state (int state[]);
int get_user_input();
void make_user_move(int state[]);
void check_win(int state[]);
void make_first_ai(int state[]);
void make_ai_move(int state[]);
void make_ai_move_win (int state[]);


int main(void){
	
	srand (time(NULL));

	int state[8];
	for (int i = 0; i<9; i++){
		state[i] = 0;
	}

	printf("\n\nHi and welcome to TIC TAC TOE! To play just insert the number of the place where you want to put your X. Here are the positions:\n\n");
	printf("0\t1\t2\n3\t4\t5\n6\t7\t8");
	printf("\n\nGood Luck!\n\n");


    int c = rand() % 2;
    
    if (c == 0){
    
        printf("\nThe PLAYER Begins\n");

	    print_state(state);	
	    make_user_move(state);
	    make_first_ai(state);
	    check_win(state);
	    print_state(state);

	
	    while(1){
		    make_user_move(state);
		    check_win(state);
		    make_ai_move(state);
		    check_win(state);
            print_state(state);
	    }
    } else if(c == 1) {

        printf("\nAI Begins\n");

	    print_state(state);	
        make_first_ai(state);
        print_state(state);
	    make_user_move(state);
	    check_win(state);
	    print_state(state);

	
	    while(1){
            make_ai_move(state);
            check_win(state);
            print_state(state);
            make_user_move(state);
            check_win(state);
            print_state(state);
	    }
    }
	
}

void make_ai_move(int state[]) {

    make_ai_move_win(state);
	
	int move = 0;

	if(move == 0){
	for (int i = 0; i < 3; i++){
		int sum = 0;
		for (int j = 0; j<3; j++){
			sum += state[i + 3 * j];
		}
		if (sum == 2){
			for (int h = 0; h < 3; h++){
				if (state[i + 3  * h] == 0){
					state [i + 3 * h]  = -1;
					printf("\nAI made move %d\n", (i + 3 * h));
					move++;
					break;
				}
			}
		}
	}
	}

    if (move == 0){
        int sum = 0;
        for (int i = 3; i < 6; i++){
           sum += state[i];
        } if (sum == 2){
            for (int j = 3; j < 6; j++){
                if (state[j] == 0){
                    state[j] = -1;
                    printf("\nAI made move %d\n", (j));
					move++;
					break;
                }
            }
        }

    }

	if (move == 0){
	for (int i = 0; i < 3; i = i + 3){
		int sum = 0;
		for (int j = 0; j<3; j++){
			sum += state[i + j];
		}
		if (sum == 2){
			for (int h = 0; h < 3; h++){
				if (state[i + h] == 0){
					state[i + h]  = -1;
					printf("\nAI made move %d\n", (i + h));
					move++;
					break;
				}
			}
		} 
	}
	}

	if (move == 0){
	int sum = 0;
	for (int i = 0; i < 9; i = i+4) {
		sum += state[i];
	}
	if (sum == 2) {
		for (int j = 0; j < 9; j = j+4) {
			if (state[j] == 0){
				state[j] = -1;
				printf("\nAI made move %d\n", (j));
				move++;
				break;
			}
		}
	} else if (sum == 1 || sum == -1){
		for (int i = 2; i < 8; i = i + 2){
			if (state[i] == 0){
				state[i] = -1;
				printf("\nAI made move %d\n", (i));
				move++;
				break;
			}
		}
	} 
	}

	if (move == 0){
	int sum = 0; 
	for (int i = 2; i < 8; i = i+2) {
		sum += state[i];
	}
	if (sum == 2) {
		for (int j = 2; j < 8; j = j+2) {
			if (state[j] == 0){
				state[j] = -1;
				printf("\nAI made move %d\n", (j));
				move++;
				break;
			}
		}
	} else if (sum == 1 || sum == -1){
		for (int i = 0; i < 9; i = i + 4){
			if (state[i] == 0){
				state[i] = -1;
				printf("\nAI made move %d\n", (i));
				move++;
				break;
			}
		}
	}

	if(move == 0){
		for (int i = 0; i < 9; i++){
			if (state[i] == 0){
				state[i] = -1;
				printf("\nAI made move %d\n", (i));
				move++;
				break;
			}
		}
	}

	if (move == 0){
		printf("Error: Could not find move for AI\n");
		exit(1);
	}
    
    }
}

void make_ai_move_win (int state[]){
    
    int move = 0;

	if(move == 0){
	for (int i = 0; i < 3; i++){
		int sum = 0;
		for (int j = 0; j<3; j++){
			sum += state[i + 3 * j];
		}
		if (sum == -2){
			for (int h = 0; h < 3; h++){
				if (state[i + 3  * h] == 0){
					state [i + 3 * h]  = -1;
					printf("\nAI made move %d\n", (i + 3 * h));
					move++;
					break;
				}
			}
		}
	}
	}

    if (move == 0){
        int sum = 0;
        for (int i = 3; i < 6; i++){
           sum += state[i];
        } if (sum == -2){
            for (int j = 3; j < 6; j++){
                if (state[j] == 0){
                    state[j] = -1;
                    printf("\nAI made move %d\n", (j));
					move++;
					break;
                }
            }
        }

    }

	if (move == 0){
	for (int i = 0; i < 3; i = i + 3){
		int sum = 0;
		for (int j = 0; j<3; j++){
			sum += state[i + j];
		}
		if (sum == -2){
			for (int h = 0; h < 3; h++){
				if (state[i + h] == 0){
					state[i + h]  = -1;
					printf("\nAI made move %d\n", (i + h));
					move++;
					break;
				}
			}
		} 
	}
	}

	if (move == 0){
	int sum = 0;
	for (int i = 0; i < 9; i = i+4) {
		sum += state[i];
	}
	if (sum == -2) {
		for (int j = 0; j < 9; j = j+4) {
			if (state[j] == 0){
				state[j] = -1;
				printf("\nAI made move %d\n", (j));
				move++;
				break;
			}
		}
	} 
	}

	if (move == 0){
	int sum = 0; 
	for (int i = 2; i < 8; i = i+2) {
		sum += state[i];
        break;
	}

	if (sum == 2) {
		for (int j = 2; j < 8; j = j+2) {
			if (state[j] == 0){
				state[j] = -1;
				printf("\nAI made move %d\n", (j));
				move++;
				break;
			}
		}
	} 
	}

}

void print_state(int state[]){
	printf("\nCurrent State:\n\n");
	
	for (int i = 0; i < 9; i++){
		switch(state[i]){
			case 0: printf("•\t"); break;
			case 1: printf("X\t"); break;
			case -1: printf("O\t"); break;
			default: printf("Error: unknown number in state array\n"); break;
		}
		if (i % 3 == 2){
			printf("\n");
		}
	}
}

int get_user_input(){
	printf("\nYour Move: ");
	fflush(stdout);
	int move = -1;
	int c = getchar();
	while (move < 0 || c != '\n') {
		if(c>=48 && c<=57)
			move = c - '0';
			
		c = getchar();
		if (c == EOF){
			printf("\nReceived EOF\n");
			exit(0);
		}
	}
	printf("\nReceived Move: %d\n", move);
	
	return move;
}	

void make_user_move(int state[]){
	
	while (1){
		int user_move = get_user_input();
		if(state[user_move] == 0){
			state[user_move] = 1;
			break;
		}
		else
			printf("\nThe place is already occupied\n");
	}		
}

void check_win(int state[]){
	
	for (int i = 0; i < 3; i++){
		int sum = 0;
		for (int j = 0; j < 3; j++){
			sum += state[i + 3 * j];
		}
		if (sum == 3){
            print_state(state);
			printf("\nPlayer WON!: 3 x in a column\n");
			exit(0);
		}
		if (sum == -3){
            print_state(state);
			printf("\nAI Won!: 3 o in a column\n");
			exit(0);
		}
	}
	
	for (int i = 0; i < 9; i=i+3) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += state[i + j];
		}
		if (sum == 3) {
            print_state(state);
			printf("\nPlayer WON!: 3 x in a row!\n");
			exit(0);
		}
		if (sum == -3){
            print_state(state);
			printf("\nAI Won!: 3 o in a row!\n ");
			exit(0);
		}
	}
	
	int sum = 0;
	
	for (int i = 0; i < 9; i = i+4){
		sum += state[i];
	}
	if (sum == 3){
        print_state(state);
		printf("\nPlayer WON!: 3 x in a diagonal\n");
		exit(0);
	}
	if (sum == -3){
        print_state(state);
		printf("\nAI Won!: 3 o in a diagonal\n");
		exit(0);
	}
	
	sum = 0;
	for (int i = 2; i < 8; i = i + 2){
		sum += state[i];
	}
	if(sum == 3){
        print_state(state);
		printf("\nPlayer WON!: 3 x in a diagonal\n");
			exit(0);
	}
	if (sum == -3){
        print_state(state);
			printf("\nAI Won!: 3 o in a diagonal\n");
			exit(0);
	}
	
	int free_spaces = 0;
	for (int i = 0; i < 9; i++){
		if (state[i] == 0){
			free_spaces++;
		}
	}

	if (free_spaces == 0){
        print_state(state);
		printf("\nGame ended with a DRAW: No more spaces left!\n");
        exit(0);
	}
	
}	

void make_first_ai(int state[]){
	if (state[4]  == 0){
		state[4] = -1;
		printf("\nAI makes move 4\n");
	} else {
		int move = rand() % 4;
		int place;
		switch (move){
			case 0: place = 0; break;
			case 1: place = 2; break;
			case 2: place = 6; break;
			case 3: place = 8; break;
		}
		state[place] = -1;
		printf("\nAI makes move %d\n ", place);
		}
}
