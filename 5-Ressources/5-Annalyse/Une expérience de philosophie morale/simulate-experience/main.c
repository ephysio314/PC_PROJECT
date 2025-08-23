
#include <stdio.h> /* printf */
#include <stdbool.h>
#include <string.h> /* strcpy */

enum e_action{
	E_ACTION_NULL,
	
	E_ACTION_ONE,
	E_ACTION_TWO,
	
	E_ACTION_MAX
};

struct Player{
	int id;
	enum e_action action_id;
	
	int score;
};

#define ROOM 101 + 1
#define PLAYER_INDEX_MIN 1

static struct Player players[ROOM] = (struct Player[ROOM]){0};
static int room_score = 0;

static int user_index=0;

static is_init=false;

bool SpwanUser(int _index);

void Init(void){
	if(false == is_init){
		SpwanUser(PLAYER_INDEX_MIN);
		int i=PLAYER_INDEX_MIN;
		int imax=ROOM;
		while(i < imax){
			players[i].id = i;
			i++;
		}
	}
}

bool SpwanUser(int _index){
	if(PLAYER_INDEX_MIN <= _index && _index < ROOM){ 
		user_index = _index;
	}else{
		return false;
	}
	return true;
}

void ActionOne(struct Player _val){
	int score_add = 250;
	int player_index = _val.id;
	int old_score = players[player_index].score;
	players[player_index].score = old_score + score_add;

	room_score += score_add;
}
void ActionTwo(struct Player _val){
	int player_index = _val.id;
	int i=PLAYER_INDEX_MIN;
	int imax=ROOM;
	while(i < imax){
		int player_gaining_index = i;
		if(player_gaining_index != player_index){
			int score_add=10;
			int old_score = players[player_gaining_index].score;
			players[player_gaining_index].score = old_score + 10;
			room_score += score_add;
		}
		i++;
	}
}

void PlayerAction(struct Player _val){
	switch(_val.action_id){
		case E_ACTION_ONE:
			ActionOne(_val);
			break;
	
		case E_ACTION_TWO:
			ActionTwo(_val);
			break;
	}
}

static char player_action_name_buf[255]={0};

const char * PlayerActionName(enum e_action _val){
	switch(_val){
		case E_ACTION_ONE:
			strcpy(player_action_name_buf, "you gain 250");
			break;
	
		case E_ACTION_TWO:
			strcpy(player_action_name_buf, "others gain 10");
			break;
	}
	return player_action_name_buf;
}

void ContextOne(void){
	/*
		All do first action.
	*/

	enum e_action user_action = E_ACTION_ONE;
	enum e_action others_action = E_ACTION_ONE;
	
	int i=PLAYER_INDEX_MIN;
	int imax=ROOM;
	while(i < imax){
		if(user_index == i){
			players[i].action_id = user_action;
		}else{
			players[i].action_id = others_action;
		}
		i++;
	}
}

void ContextTwo(void){
	/*
		All do second action.
	*/

	enum e_action user_action = E_ACTION_TWO;
	enum e_action others_action = E_ACTION_TWO;
	
	int i=PLAYER_INDEX_MIN;
	int imax=ROOM;
	while(i < imax){
		if(user_index == i){
			players[i].action_id = user_action;
		}else{
			players[i].action_id = others_action;
		}
		i++;
	}
}

void ContextThree(void){
	/*
		User do first.
		Others do second.
	*/
	
	enum e_action user_action = E_ACTION_ONE;
	enum e_action others_action = E_ACTION_TWO;
	
	int i=PLAYER_INDEX_MIN;
	int imax=ROOM;
	while(i < imax){
		if(user_index == i){
			players[i].action_id = user_action;
		}else{
			players[i].action_id = others_action;
		}
		i++;
	}
}

void ContextFour(void){
	/*
		User do second.
		Others do first.
	*/
	
	enum e_action user_action = E_ACTION_TWO;
	enum e_action others_action = E_ACTION_ONE;
	
	int i=PLAYER_INDEX_MIN;
	int imax=ROOM;
	while(i < imax){
		if(user_index == i){
			players[i].action_id = user_action;
		}else{
			players[i].action_id = others_action;
		}
		i++;
	}
	
}

void GameStart(void){
	SpwanUser(1);
	room_score=0;
	int i=PLAYER_INDEX_MIN;
	int imax=ROOM;
	while(i < imax){
		players[i].id = i;
		players[i].score = 0;
		i++;
	}
}

void GameLoop(void){
	Init();
	int i=PLAYER_INDEX_MIN;
	int imax=ROOM;
	while(i < imax){
		PlayerAction(players[i]);
		i++;
	}
}

void GameEnd(void){
	int i=PLAYER_INDEX_MIN;
	int imax=ROOM;
	while(i < imax){
		printf("i '%d'; player: id '%d'; action '%d' that '%s'; score '%d'.\n", i, players[i].id, players[i].action_id, PlayerActionName(players[i].action_id), players[i].score );
		i++;
	}
	printf("Room score: '%d'\n", room_score);
}

void GameOne(void){
	ContextOne();
	
	GameStart();
	GameLoop();
	GameEnd();
}

void GameTwo(void){
	ContextTwo();
	
	GameStart();
	GameLoop();
	GameEnd();
}

void GameThree(void){
	ContextThree();
	
	GameStart();
	GameLoop();
	GameEnd();
}

void GameFour(void){
	ContextFour();
	
	GameStart();
	GameLoop();
	GameEnd();
}

int main(void){
	GameOne();
	GameTwo();
	GameThree();
	GameFour();
	return 0;
}
