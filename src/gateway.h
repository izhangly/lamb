
/* 
 * Lamb Gateway Platform
 * Copyright (C) 2017 typefo <typefo@qq.com>
 * Update: 2017-07-14
 */

#ifndef _LAMB_GATEWAY_H
#define _LAMB_GATEWAY_H

#include <sys/epoll.h>
#include "db.h"
#include "queue.h"

typedef struct {
    int id;
    int type;
    char host[16];
    int port;
    char username[32];
    char password[64];
    char spid[32];
    char spcode[24];
    int encoded;
    int concurrent;
} lamb_gateway_t;

typedef struct {
    int id;
    lamb_queue_t send;
    lamb_queue_t recv;
} lamb_gateway_queue_t;

int lamb_gateway_get(lamb_db_t *db, int id, lamb_gateway_t *gateway);
int lamb_gateway_get_all(lamb_db_t *db, lamb_gateway_t *gateways[], size_t size);
int lamb_gateway_queue_open(lamb_gateway_queue_t *queues[], size_t qlen, lamb_gateway_t *gateways[], size_t glen);
int lamb_gateway_epoll_add(int epfd, struct epoll_event *event, lamb_gateway_queue_t *queues[], size_t len, int type);

#endif
