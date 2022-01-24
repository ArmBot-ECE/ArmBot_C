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
#include <stdlib.h>
#include <wiringPi.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/sdp.h>
#include <bluetooth/sco.h>
#include <bluetooth/sdp_lib.h>
#include <bluetooth/rfcomm.h>
#include <bluetooth/l2cap.h>

sdp_session_t *register_service(uint8_t rfcomm_channel);
int init_server();
char *read_server(int client);
void write_server(int client, char *message);

#endif /* bluetooth_h */
