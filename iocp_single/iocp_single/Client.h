#pragma once

#include "enum.h"
enum class STATUS;
//class Exp_Over;
class error;

class Client
{
	//unordered_map<Client, MAX_USER + MAX_NPC> Clients;

	error* errorMask;

public:
	//char name[MAX_NAME_SIZE];
	char name[20];
	//unordered_map<Client, int> Clients;
	int	   _id;
	short  x, y;
	unordered_set   <int>  viewlist;
	mutex vl;
	mutex cl;
	
	lua_State* L;

	short level;
	short hp;
	int	  exp;
	bool can_attack;
	short damage = 20;
	short maxhp;

	mutex state_lock;
	STATUS _state;
	atomic_bool	_is_active;
	int		_type;   // 1.Player   2.NPC	
	int move_count;
	bool overlap;

	char npcCharacterType;	// 0. stay 1. fight
	char npcMoveType;		// 0. hold 1. moving

	char direction;
	Exp_Over _recv_over;
	SOCKET  _socket;
	int		_prev_size;
	int		last_move_time;
public:
	Client();

	~Client();

	//void do_recv();

	//void do_send(int num_bytes, void* mess);
};

