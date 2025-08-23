
#include <stdio.h> /* printf */
#include <stdbool.h>

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

static int user_index=0;

static is_init=false;

bool SpwanUser(int _index);

void Init(void){
	if(false == is_init){
		SpwanUser(PLAYER_INDEX_MIN);
		int i=0;
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

void ActionOne(int _player_id){
	int player_index = _player_id;
	int old_score = players[player_index].score;
	players[player_index].score = old_score + 250;
}
void ActionTwo(int _player_id){
	int player_index = _player_id;
	int i=PLAYER_INDEX_MIN;
	int imax=ROOM;
	while(i < imax){
		int player_gaining_index = i;
		if(player_gaining_index != player_index){ int old_score = players[player_gaining_index].score; players[player_gaining_index].score = old_score + 10; }
		i++;
	}
}

void PlayerAction(struct Player _val){
	switch(_val.action_id){
		case E_ACTION_ONE:
			ActionOne(_val.id);
			break;
	
		case E_ACTION_TWO:
			ActionTwo(_val.id);
			break;
	}
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
		printf("player: id '%d'; action '%d'; score '%d'.\n", players[i].id, players[i].action_id, players[i].score );
		i++;
	}
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
