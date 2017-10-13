
/* 
 * Lamb Gateway Platform
 * Copyright (C) 2017 typefo <typefo@qq.com>
 * Update: 2017-07-14
 */

#ifndef _LAMB_ISMG_H
#define _LAMB_ISMG_H

#include <stdbool.h>
#include <cmpp.h>
#include "account.h"

#define LAMB_SUBMIT 1
#define LAMB_DELIVER 2
#define LAMB_REPORT 3

typedef struct {
    int id;
    char listen[16];
    int port;
    int connections;
    long long timeout;
    long long send_timeout;
    long long recv_timeout;
    char queue[64];
    char redis_host[16];
    int redis_port;
    int redis_db;
    char logfile[128];
    bool debug;
    bool daemon;
} lamb_config_t;

typedef struct {
    unsigned int sequenceId;
    unsigned long long msgId;
} lamb_confirmed_t;

typedef struct {
    cmpp_sock_t *sock;
    lamb_account_t *account;
    char *addr;
} lamb_client_t;

void lamb_event_loop(cmpp_ismg_t *cmpp);
void lamb_work_loop(lamb_client_t *client);
void *lamb_deliver_loop(void *data);
void *lamb_online_update(void *data);
bool lamb_is_login(lamb_cache_t *cache, int account);
int lamb_read_config(lamb_config_t *conf, const char *file);

#endif