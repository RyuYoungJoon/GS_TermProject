#pragma once
#define _CRT_SECURE_NO_WARNINGS

#ifndef PCH_H
#define PCH_H
#include <iostream>
#include <WS2tcpip.h>
#include <MSWSock.h>
#include <thread>
#include <array>
#include <string>
#include <vector>
#include <mutex>
#include <unordered_set>
#include <concurrent_priority_queue.h>
#include <queue>
#include <unordered_map>
#include <sqlext.h>  



extern "C" {
#include "include\lua.h"
#include "include\lauxlib.h"
#include "include\lualib.h"
}
#pragma comment (lib, "lua54.lib")

using namespace std;
using namespace chrono;
#pragma comment (lib, "WS2_32.LIB")
#pragma comment (lib, "MSWSock.LIB")
#pragma comment(lib,"odbc32.lib")

#define NAME_LEN 50  
#define PHONE_LEN 60


#include "2021_°¡À»_protocol.h"
#include "error.h"
#include "Client.h"
#include "enum.h"
#include "event.h"
#include "Sender.h"
#include "DB.h"

#endif