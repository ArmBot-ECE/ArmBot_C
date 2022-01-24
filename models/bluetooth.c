//
//  bluetooth.c
//  RaspberryPi
//
//  Created by Troyan Hugo on 04/01/2022.
//  Copyright © 2022 Troyan Hugo. All rights reserved.
//



// This is where Bluetooth API must be implemented

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  
#include "bluetooth.h"
#include <wiringPi.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
//#include <bluetooth/bluetooth.h>
#include <bluetooth/sdp.h>
#include <bluetooth/sco.h>
#include <bluetooth/sdp_lib.h>
#include <bluetooth/rfcomm.h>
#include <bluetooth/l2cap.h>

/*
    Initialize bluetooth connection
*/
bool initializeBluetooth() {
	char buf[1024] = { 0 };
    int s, bytes_read = -1;
    int client = init_server();
	int port = 3;

    do {
        // read data from the client
        memset(buf, 0, sizeof(buf));
        bytes_read = read(client, buf, sizeof(buf));
        if( bytes_read > 0 ) {
            printf("received [%s]\n", buf);
        }
    } while (bytes_read > 0);

    // close connection
    printf("Closing connection.\n");
    close(client);
    close(s);
    //sdp_close( session );

    return true;
}

void getCommand() {
    // TODO Get command from bluetooth
}



sdp_session_t *register_service(uint8_t rfcomm_channel) {
	//ls -l /dev/disk/by-uuid .
	//426ad438-6e4a-a1bd-c4cf-d49c036205b8
	//2f4adfbf-32e5-44ec-9323-1d08cbe8c29e
	//00001101-0000-1000-8000-00805F9B34FB
	uint32_t svc_uuid_int[] = { 0x00001101, 0x00001000, 0x80000080, 0x5F9B34FB };
	const char *service_name = "ArmBot Bluetooth server";
	const char *svc_dsc = "An ArmBot server that interfaces with the ArmBot Android app";
	const char *service_prov = "ArmBot";

	uuid_t root_uuid, l2cap_uuid, rfcomm_uuid, svc_uuid,
	       svc_class_uuid;
	sdp_list_t  *l2cap_list = 0,
	            *rfcomm_list = 0,
	            *root_list = 0,
	            *proto_list = 0,
	            *access_proto_list = 0,
	            *svc_class_list = 0,
	            *profile_list = 0;
	sdp_data_t  *channel = 0;
	sdp_profile_desc_t profile;
	sdp_record_t record = { 0 };
	sdp_session_t *session = 0;
	

	// set the general service ID
	sdp_uuid128_create(&svc_uuid, &svc_uuid_int);
	sdp_set_service_id(&record, svc_uuid);

	char str[256] = "";
	sdp_uuid2strn(&svc_uuid, str, 256);
	printf("Registering UUID %s\n", str);

	// set the service class
	sdp_uuid16_create(&svc_class_uuid, SERIAL_PORT_SVCLASS_ID);
	svc_class_list = sdp_list_append(0, &svc_class_uuid);
	sdp_set_service_classes(&record, svc_class_list);

	// set the Bluetooth profile information
	sdp_uuid16_create(&profile.uuid, SERIAL_PORT_PROFILE_ID);
	profile.version = 0x0100;
	profile_list = sdp_list_append(0, &profile);
	sdp_set_profile_descs(&record, profile_list);

	// make the service record publicly browsable
	sdp_uuid16_create(&root_uuid, PUBLIC_BROWSE_GROUP);
	root_list = sdp_list_append(0, &root_uuid);
	sdp_set_browse_groups(&record, root_list);

	// set l2cap information
	sdp_uuid16_create(&l2cap_uuid, L2CAP_UUID);
	l2cap_list = sdp_list_append(0, &l2cap_uuid);
	proto_list = sdp_list_append(0, l2cap_list);

	// register the RFCOMM channel for RFCOMM sockets
	sdp_uuid16_create(&rfcomm_uuid, RFCOMM_UUID);
	channel = sdp_data_alloc(SDP_UINT8, &rfcomm_channel);
	rfcomm_list = sdp_list_append(0, &rfcomm_uuid);
	sdp_list_append(rfcomm_list, channel);
	sdp_list_append(proto_list, rfcomm_list);

	access_proto_list = sdp_list_append(0, proto_list);
	sdp_set_access_protos(&record, access_proto_list);

	// set the name, provider, and description
	sdp_set_info_attr(&record, service_name, service_prov, svc_dsc);

	// connect to the local SDP server, register the service record,
	// and disconnect
	session = sdp_connect(BDADDR_ANY, BDADDR_LOCAL, SDP_RETRY_IF_BUSY);
	sdp_record_register(session, &record, 0);

	// cleanup
	sdp_data_free(channel);
	sdp_list_free(l2cap_list, 0);
	sdp_list_free(rfcomm_list, 0);
	sdp_list_free(root_list, 0);
	sdp_list_free(access_proto_list, 0);
	sdp_list_free(svc_class_list, 0);
	sdp_list_free(profile_list, 0);

	return session;
}

int init_server() {
	int port = 1, result, sock, client, bytes_read, bytes_sent;
	struct sockaddr_rc loc_addr = { 0 }, rem_addr = { 0 };
	char buffer[1024] = { 0 };
	socklen_t opt = sizeof(rem_addr);

	// local bluetooth adapter
	loc_addr.rc_family = AF_BLUETOOTH;
	loc_addr.rc_bdaddr = *BDADDR_ANY;
	loc_addr.rc_channel = (uint8_t) port;

	// register service
	sdp_session_t *session = register_service(port);

	// allocate socket
	sock = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
	printf("socket() returned %d\n", sock);

	// bind socket to port 3 of the first available
	result = bind(sock, (struct sockaddr *)&loc_addr, sizeof(loc_addr));
	printf("bind() on channel %d returned %d\n", port, result);

	// put socket into listening mode
	result = listen(sock, 1);
	printf("listen() returned %d\n", result);

	//sdpRegisterL2cap(port);

	// accept one connection
	printf("calling accept()\n");
	client = accept(sock, (struct sockaddr *)&rem_addr, &opt);
	printf("accept() returned %d\n", client);

	ba2str(&rem_addr.rc_bdaddr, buffer);
	fprintf(stderr, "accepted connection from %s\n", buffer);
	memset(buffer, 0, sizeof(buffer));

	return client;
}

char *read_server(int client) {
	// read data from the client
	char input[1024] = { 0 };
	int bytes_read;
	bytes_read = read(client, input, sizeof(input));
	if (bytes_read > 0) {
		printf("received [%s]\n", input);
		return input;
	} else {
		return "";
	}
}

void write_server(int client, char *message) {
	// send data to the client
	char messageArr[1024] = { 0 };
	int bytes_sent;
	sprintf(messageArr, message);
	bytes_sent = write(client, messageArr, sizeof(messageArr));
	if (bytes_sent > 0) {
		printf("sent [%s]\n", messageArr);
	}
}











































/*
// Link to ws2_32.lib
#include <winsock2.h>
#include <ws2bth.h>
#include <BluetoothAPIs.h>
#include <stdio.h>

#define DEFAULT_BUFLEN 512

int main(int argc, char **argv)
{
    WSADATA wsd;
    SOCKET s, s2;
    SOCKADDR_BTH sab, sab2;

    // NULL_GUID
    GUID nguiD = {38d46a42-bda1-4a6e-9cd4-cfc4b8056203};
    int ilen, iResult;

    // This should be const void * type for non-char data
    char *sendbuf = "Test data from receiver...";
    int recvbuflen = DEFAULT_BUFLEN;

    // Change the type accordingly for non-char data
    char recvbuf[DEFAULT_BUFLEN] = "";

    if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0){
        printf("Unable to load Winsock! Error code is %d\n", WSAGetLastError());
        return 1;
    }
    else{
        printf("WSAStartup() is OK, Winsock lib loaded!\n");
    }
        
    s = socket (AF_BTH, SOCK_STREAM, BTHPROTO_RFCOMM);
    if (s == INVALID_SOCKET){
        printf ("Socket creation failed, error %d\n", WSAGetLastError());
        return 1;
    }
    else{
        printf ("socket() looks fine!\n");
    }

    memset (&sab, 0, sizeof(sab));
    sab.addressFamily  = AF_BTH;

    // We hardcoded it
    sab.port = 1;

    if (0 != bind(s, (SOCKADDR *) &sab, sizeof(sab))){
        printf ("bind() failed with error code %d\n", WSAGetLastError());
        closesocket (s);
        return;
    }
    else{
        printf ("bind() looks fine!\n");
    }
 
    if(listen (s, 5) == 0)
        printf("listen() is OK! Listening for connection...\n");
    else
        printf("listen() failed with error code %d\n", WSAGetLastError());

    for ( ; ; ){
        // Get information on the port assigned
        ilen = sizeof(sab2);
        s2 = accept (s, (SOCKADDR *)&sab2, &ilen);
        if (s2 == INVALID_SOCKET){
            printf ("accept() failed with error code %d\n", WSAGetLastError ());
            break;
        }
        else
            printf ("accept(), is OK buddy!\n");

        // Print the info
        printf ("Connection came from %04x%08x to channel %d\n", GET_NAP(sab2.btAddr), GET_SAP(sab2.btAddr), sab2.port);
    }

    // Receive until the peer closes the connection
    do {
        iResult = recv(s2, recvbuf, recvbuflen, 0);

        if (iResult > 0)
            printf(" %d Bytes received from sender\n", iResult);
        else if ( iResult == 0 )
            printf("Connection closed by peer!\n");
        else
            printf("recv() failed with error code %d\n", WSAGetLastError());
    } while(iResult > 0);

    // Echo back the data
    iResult = send(s2, recvbuf, recvbuflen, 0 );

    if (iResult == SOCKET_ERROR)
    {
        printf("send() failed with error code %d\n", WSAGetLastError());
        closesocket(s2);
        WSACleanup();

        return 1;
    }
    else
    {
        printf("send() is OK!\n");
        printf("Bytes Sent: %d\n", iResult);
    }

    if(closesocket(s) == 0)
        printf("closesocket() pretty fine!\n");
    if(WSACleanup () == 0)
        printf("WSACleanup() is OK!\n");
    return 0;
}*/
