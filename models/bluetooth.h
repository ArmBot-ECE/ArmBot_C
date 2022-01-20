//
//  bluetooth.h
//  RaspberryPi
//
//  Created by Troyan Hugo on 05/01/2022.
//  Copyright © 2022 Troyan Hugo. All rights reserved.
//

#ifndef bluetooth_h
#define bluetooth_h

#include <stdio.h>

bool initializeBluetooth(void);
sdp_session_t *register_service(uint8_t rfcomm_channel);
int init_server();
char *read_server(int client);
void write_server(int client, char *message);

#endif /* bluetooth_h */
