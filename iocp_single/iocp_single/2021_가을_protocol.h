#pragma once



//array <Client, MAX_USER + MAX_NPC> Clients;



// ID 에 영역지정
// 0 - (MAX_USER - 1) : 플레이어
// MAX_USER  - (MAX_USER + MAX_NPC) : NPC

//#define SERVER_PORT		4000
//#define NPC_ID_START	3000
//#define NUM_NPC			3000

//constexpr int MAX_ID_LEN = 50;
//constexpr int MAX_STR_LEN = 80;
//
//constexpr int MAX_PACKET_SIZE = 255;
//constexpr auto MAX_BUF_SIZE = 1024;
////constexpr auto MAX_USER = NPC_ID_START;
//constexpr auto VIEW_RADIUS = 7;

//#define WORLD_WIDTH		800
//#define WORLD_HEIGHT	800
//
//#define MAX_STR_SIZE  100
//
////받는 입장에서는 패킷 type이 날아온다. 보내는 입장에서는 이걸 담아 보내야 알려줄 수 있다.
//#define C2S_LOGIN	1
//#define C2S_MOVE	2
//#define C2S_ATTACK  3
//#define C2S_CHAT    4
//#define C2S_LOGOUT  5
//
//#define S2C_LOGIN_OK		1
//#define S2C_LOGIN_FAIL		2
//#define S2C_MOVE			3
//#define S2C_ENTER			4
//#define S2C_LEAVE			5
//#define S2C_CHAT			6
//#define S2C_STAT_CHANGE     7
//
#define NPC_STAY 0
#define NPC_FIGHT 1

#define NPC_HOLD 0
#define NPC_RANDOM_MOVE 1

#define NPC_SPECIAL 2


enum GRID_TYPE
{
	eBLANK,
	eSTART,
	eEND,
	eBLOCKED,
	eOPEN,
	eCLOSE,
};

struct MAP
{
	GRID_TYPE type; //0-땅바닥, 3-장애물, 10-몬스터, 11-플레이어, 12-다른플레이어, 
};

const int BUFSIZE = 256;
const int RANGE = 9;

const short SERVER_PORT = 4000;


constexpr int MAX_ID_LEN = 50;
constexpr int MAX_STR_LEN = 80;

constexpr int MAX_PACKET_SIZE = 255;
constexpr auto MAX_BUF_SIZE = 1024;

const int  WORLD_HEIGHT = 800;
const int  WORLD_WIDTH = 800;
const int  MAX_NAME_SIZE = 20;
const int  MAX_CHAT_SIZE = 100;
const int  MAX_USER = 10000;
const int  MAX_NPC = 10000;
constexpr int NPC_ID_START = MAX_USER;
constexpr int NPC_ID_END = MAX_USER + MAX_NPC - 1;

const char CS_PACKET_LOGIN = 1;
const char CS_PACKET_MOVE = 2;
const char CS_PACKET_ATTACK = 3;
const char CS_PACKET_CHAT = 4;
const char CS_PACKET_TELEPORT = 5;
const char CS_PACKET_LOGOUT = 6;

const char SC_PACKET_LOGIN_OK = 1;
const char SC_PACKET_MOVE = 2;
const char SC_PACKET_PUT_OBJECT = 3;
const char SC_PACKET_REMOVE_OBJECT = 4;
const char SC_PACKET_CHAT = 5;
const char SC_PACKET_LOGIN_FAIL = 6;
const char SC_PACKET_STATUS_CHANGE = 7;
const char SC_PACKET_ATTACK = 8;
const char SC_PACKET_STATUS_MONSTER = 9;
const char SC_PACKET_TELEPORT = 10;
#pragma pack (push, 1)
struct cs_packet_login {
	unsigned char size;
	char	type;
	char	userID[MAX_NAME_SIZE];
	int		userPassWord;
	//char	name[MAX_NAME_SIZE];
};

struct cs_packet_move {
	unsigned char size;
	char	type;
	char	direction;			// 0 : up,  1: down, 2:left, 3:right
	int		move_time;
};

struct cs_packet_attack {
	unsigned char size;
	char	type;
};

struct cs_packet_chat {
	unsigned char size;
	char	type;
	char	message[MAX_CHAT_SIZE];
	int id;
};
struct cs_packet_logout {
	char	size;
	char	type;
};
struct cs_packet_teleport { 
	// 서버에서 장애물이 없는 랜덤 좌표로 텔레포트 시킨다.
	// 더미 클라이언트에서 동접 테스트용으로 사용.
	unsigned char size;
	char	type;
};

struct sc_packet_login_ok {
	unsigned char size;
	char type;
	int		id;
	short	x, y;
	short	level;
	short	hp, maxhp;
	int		exp;
};

struct sc_packet_move {
	unsigned char size;
	char type;
	int		id;
	char direction;
	short  x, y;
	int		move_time;
};
struct sc_packet_put_object {
	unsigned char size;
	char type;
	int id;
	char	name[MAX_NAME_SIZE];
	short x, y;
	char object_type;

	char npcCharacterType; // 0 - peace / 1-war
	char npcMoveType; // 0-고정 / 1 - 로밍

};
//struct sc_packet_enter {
//	char size;
//	char type;
//	int id;
//	char name[MAX_ID_LEN];
//	char o_type;
//	short x, y;
//
//	char npcCharacterType; //0-peace / 1-war
//	char npcMoveType; //0-고정 / 1-로밍
//
//};
struct sc_packet_remove_object {
	unsigned char size;
	char type;
	int id;
	bool isDie;
};

struct sc_packet_chat {
	unsigned char size;
	char type;
	int id;
	//wchar_t mess[MAX_STR_LEN];
	char mess[100];
	int chatType; //0 - 개인 / 1-시스템

};
//struct sc_packet_chat {
//	char size;
//	char type;
//	int	 id;
//	wchar_t mess[MAX_STR_LEN];
//	char mess[MAX_STR_LEN];
//	int chatType; //0-개인 / 1-시스템
//};
struct sc_packet_login_fail {
	unsigned char size;
	char type;
	int	 reason;		// 0: 중복 ID,  1:사용자 Full
};
struct sc_packet_attack {
	char size;
	char type;
	char id;
};
struct sc_packet_status_change {
	unsigned char size;
	char type;
	short	level;
	short	hp, maxhp;
	int		exp, max_exp;
	int		id;
};
struct sc_packet_teleport {
	unsigned char size;
	char type;
	int x;
	int y;

};
//struct sc_packet_stat_change {
//	char size;
//	char type;
//	int id; //내가 추가
//	short hp;
//	short level;
//	int	exp;
//};
struct sc_packet_status_monster {
	char size;
	char type;
	short c_hp;
	int id;
};
#pragma pack(pop)

//#pragma once
//
//#define SERVER_PORT		9000
//#define NPC_ID_START	3000
//#define NUM_NPC			3000
//
//constexpr int MAX_ID_LEN = 50;
//constexpr int MAX_STR_LEN = 80;
//
//constexpr int MAX_PACKET_SIZE = 255;
//constexpr auto MAX_BUF_SIZE = 1024;
//constexpr auto MAX_USER = NPC_ID_START;
//constexpr auto MAX_NPC = 3000;
//constexpr auto VIEW_RADIUS = 7;
//
//const int  MAX_NAME_SIZE = 20;
//const int  MAX_CHAT_SIZE = 100;
//
//const int RANGE = 15;
//#define WORLD_WIDTH		800
//#define WORLD_HEIGHT	800
//
//#define MAX_STR_SIZE  100
//
//받는 입장에서는 패킷 type이 날아온다. 보내는 입장에서는 이걸 담아 보내야 알려줄 수 있다.
//#define C2S_LOGIN	1
//#define C2S_MOVE	2
//#define C2S_ATTACK  3
//#define C2S_CHAT    4
//#define C2S_LOGOUT  5
//
//#define S2C_LOGIN_OK		1
//#define S2C_LOGIN_FAIL		2
//#define S2C_MOVE			3
//#define S2C_ENTER			4
//#define S2C_LEAVE			5
//#define S2C_CHAT			6
//#define S2C_STAT_CHANGE     7
//#define S2C_ATTACK			8
//
//#define NPC_PEACE 0
//#define NPC_WAR 1
//
//#define NPC_FIX 0
//#define NPC_RANDOM_MOVE 1
//
//#define NPC_SPECIAL 2
//
//enum GRID_TYPE
//{
//	eBLANK,
//	eSTART,
//	eEND,
//	eBLOCKED,
//	eOPEN,
//	eCLOSE,
//};
//
//struct MAP
//{
//	GRID_TYPE type; //0-땅바닥, 3-장애물, 10-몬스터, 11-플레이어, 12-다른플레이어, 
//};
//
//#pragma pack(push ,1)
//
//struct sc_packet_chat {
//	char size;
//	char type;
//	int	 id;
//	wchar_t mess[MAX_STR_LEN];
//	char mess[MAX_STR_LEN];
//	int chatType; //0-개인 / 1-시스템
//};
//
//struct sc_packet_login_ok {
//	char size;
//	char type;
//	int id;
//	short x, y;
//	short hp;
//	short level;
//	int	exp;
//};
//
//struct sc_packet_login_fail {
//	char size;
//	char type;
//};
//
//struct sc_packet_move {
//	char size;
//	char type;
//	int id;
//	char direction;
//	short x, y;
//	unsigned move_time;
//};
//
//
//OBJECT TYPE
//constexpr unsigned char O_PLAYER = 0;
//constexpr unsigned char O_NPC_PEACE = 1;
//constexpr unsigned char O_NPC_WAR = 2;
//
//struct sc_packet_enter {
//	char size;
//	char type;
//	int id;
//	char name[MAX_ID_LEN];
//	char o_type;
//	short x, y;
//
//	char npcCharacterType; //0-peace / 1-war
//	char npcMoveType; //0-고정 / 1-로밍
//
//};
//
//struct sc_packet_leave {
//	char size;
//	char type;
//	int id;
//};
//
//struct cs_packet_login {
//	char	size;
//	char	type;
//	char	name[MAX_ID_LEN];
//};
//
//struct sc_packet_stat_change {
//	char size;
//	char type;
//	int id; //내가 추가
//	short hp;
//	short level;
//	int	exp;
//};
//
constexpr unsigned char D_UP = 0;
constexpr unsigned char D_DOWN = 1;
constexpr unsigned char D_LEFT = 2;
constexpr unsigned char D_RIGHT = 3;
//
//struct cs_packet_move {
//	char	size;
//	char	type;
//	char	direction;
//	unsigned move_time;
//};
//
//struct cs_packet_attack {
//	char size;
//	char type;
//};
//
//struct cs_packet_chat {
//	char size;
//	char type;
//	wchar_t message[MAX_STR_LEN];
//};
//
//struct cs_packet_logout {
//	char size;
//	char type;
//};

//struct sc_packet_login_ok {
//	unsigned char size;
//	char type;
//	int		id;
//	short	x, y;
//	short	level;
//	short	hp, maxhp;
//	int		exp;
//};
//
//struct sc_packet_move {
//	unsigned char size;
//	char type;
//	int		id;
//	short  x, y;
//	int		move_time;
//};
//
//struct sc_packet_put_object {
//	unsigned char size;
//	char type;
//	int id;
//	short x, y;
//	char object_type;
//	char	name[MAX_NAME_SIZE];
//};
//
//struct sc_packet_remove_object {
//	unsigned char size;
//	char type;
//	int id;
//};
//
//struct sc_packet_chat {
//	unsigned char size;
//	char type;
//	int id;
//	char message[MAX_CHAT_SIZE];
//};
//
//struct sc_packet_login_fail {
//	unsigned char size;
//	char type;
//	int	 reason;		// 0: 중복 ID,  1:사용자 Full
//};
//struct sc_packet_attack {
//	char size;
//	char type;
//	char id;
//};
//struct sc_packet_status_change {
//	unsigned char size;
//	char type;
//	short	level;
//	short	hp, maxhp;
//	int		exp, max_exp;
//	int		id;
//};
//struct sc_packet_status_monster {
//	char size;
//	char type;
//	short c_hp;
//	int id;
//};
#pragma pack (pop)
