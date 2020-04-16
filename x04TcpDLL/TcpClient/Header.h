#pragma once

#ifdef TCPCLIENT_EXPORTS
#define API __declspec(dllexport)
#else
#define API __declspec(dllimport)
#endif

#define EXTERNAPI extern "C" API

