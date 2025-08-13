
/*
~DESCRIPTION:
	- Generate from a range a random number.
	- Show a message that ask the user to enter a number in the range.
	- Check three condition and return a message corresponding.
	If was equal, congratule it and enter in the game-state of score-menu.
	else, specify to the user if it's lower or greater,
	and increase the number f try of this session.
	- When reach the game-state score-menu, if was a success ( only possibility here)
	increase he's score by one. Check the number of try
	this game and the lower register and if lower than it store it.
	Ask to enter 'Y' to replay and 'N' to exit.
	If enter 'N', break the main loop.
	If enter 'Y', call the game main-loop.
*/

#include <stdbool.h>

#include <random.h>


/*
~GAME

A) CORE ARCHITECTURE



B) MODULES

a) Win condition

When the game ask the user to guess a number.
This one should input the one equal to
the one generate at the roun start.

Until it does not found it,
or the user renounce,
it will keep asking.

The message of ask
depand on the result of the last guess.

If to low or to high specify wich.
If it's the first of the round don't specify special things.
If it's equal, congratulate and don't ask for a number but a game-mode ( mainmenu or play againm )

b) User-interface

Each moment the user enter an input or when the app start.
The iterate a main-loop that was structure in the following way.

Phases:

State-parsing:
  First it check the last user input and other app and system states that can influence the model.

Update:
  Second it update the app-state acordingly to those influences.

View ( proposition and contexte infos ):
  Third it show the user he's option of input and what the consequancies he can espect.

Input:
  Fourth it ask the user to enter an input as response to he's propositions.


*/

/*
~GAME-CORE
*/

bool game_IsInit(void);
void game_Init(void);
void game_GenerateGuess(void);

enum e_game_mode{
	E_GAME_MODE_NULL,

	E_GAME_MODE_MAINMENU,
	E_GAME_MODE_PLAY,
	E_GAME_MODE_PAUSE,
	E_GAME_MODE_SCORE,

	E_GAME_MODE_EXIT,

	E_GAME_MODE_MAX
};

#define LABEL_LEN 50

const char LABEL_GAME_MODE[E_GAME_MODE_MAX][LABEL_LEN] = {
	"E_GAME_MODE_NULL",
	
	"E_GAME_MODE_MAINMENU",
	"E_GAME_MODE_PLAY",
	"E_GAME_MODE_PAUSE",
	"E_GAME_MODE_SCORE",
	
	"E_GAME_MODE_EXIT",
};

static enum e_game_mode user_game_mode=E_GAME_MODE_NULL;

void game_Start(void){
	game_Init();
	user_game_mode=E_GAME_MODE_MAINMENU;
	
	game_GenerateGuess();
}

void game_End(void){

}

void game_View(void){

}

bool game_IsValideNewMode(enum e_game_mode _new_mode_ask){

	switch(user_game_mode){
		case E_GAME_MODE_NULL:
			/* Not request */
			break;
	
		case E_GAME_MODE_MAINMENU:
			if(E_GAME_MODE_PLAY == _new_mode_ask || E_GAME_MODE_EXIT == _new_mode_ask){
				return true;
			}
			break;
			
		case E_GAME_MODE_PLAY:
			if(E_GAME_MODE_PAUSE == _new_mode_ask || E_GAME_MODE_SCORE == _new_mode_ask){
				return true;
			}
			break;
			
		case E_GAME_MODE_PAUSE:
			if(E_GAME_MODE_PLAY == _new_mode_ask || E_GAME_MODE_MAINMENU == _new_mode_ask){
				return true;
			}
			break;
			
		case E_GAME_MODE_SCORE:
			if(E_GAME_MODE_PLAY == _new_mode_ask || E_GAME_MODE_MAINMENU == _new_mode_ask){
				return true;
			}
			break;
			
		default:
			break;
	}
	
	return false;
}

void game_Control(void){
	enum e_game_mode new_mode_ask=E_GAME_MODE_NULL;
	
	
	
	if(!game_IsValideNewMode(new_mode_ask)){
		
	}
}

/*
~MODULES
*/

static bool game_is_init=0;

/*
A) NUMBER TO GUESS
*/

#define GAME_INT_TOGUESS_MAX 100

static int game_int_toguess=0;

bool game_IsInit(void){
	return game_is_ini;
}

void game_Init(void){
	if(!game_IsInit()){
		random_SetRandMax(GAME_INT_TOGUESS_MAX);

  	game_is_ini=1;
  }
}

void game_GenerateGuess(void){
	game_int_toguess=random_stack_Pop();
}

int main(void){

	return 0;
}
