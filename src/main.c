#include <stdio.h>
#include <inttypes.h>
#include "main_header.h"


struct Packet {
    char flag[9];
    int seq;
    int ack;
    int dataLength;
    int windowNum;
    char data[1981]
};
void processPacketHeader1(char *packet1, struct Packet *clientReceiveBuffer1);
int main() {
    const char *synFlag = "SYN";
    const char *ackFlag = "ACK";
    char dataToSend[1981];
    char packetTemp[2041];

    strcpy(dataToSend, "hi");
    strcpy (packetTemp, makePacketHeader(synFlag, 12538, 1, 58789, dataToSend));
    printf("%s\n", packetTemp);

    strcpy(dataToSend, "Hihihihihihihihihihihihihihihihihi");
    strcpy (packetTemp, makePacketHeader(synFlag, 12538, 1, 58789, dataToSend));
    printf("%s\n", packetTemp);

    strcpy(dataToSend, "Hi how are you?");
    strcpy (packetTemp, makePacketHeader(ackFlag, 12540, 1, 58790, dataToSend));
    printf("%s\n", packetTemp);


    /**
     * Receiver side
     */
    struct Packet clientReceiveBuffer[255];
    processPacketHeader1(packetTemp, clientReceiveBuffer);
    return 0;
}


/**
 * Packet header design:
 * In order
 * Flag 8 chars 0-7 , Sequence Number 16 chars 8-23, Ack Number 16 chars 24-39, Data Length 5 chars 40-44, Window 16 chars 45-60
 * Total 61 chars for packet header
 * Example header: 00000SYN00000000000125380000000000000001000020000000000058789
 */
char* makePacketHeader(char* flag, int seq, int ack, int window, char* dataToSend) {

    char packetHeader[61 + 1] = "0000000000000000000000000000000000000000000000000000000000000";
    int dataLength = strlen(dataToSend);
    char resultingPacket[61 + dataLength + 1];
    //Convert sequence number, ack number, dataLength, window to string
    char seqInString[16];
    char ackInString[16];
    char dataLengthInString[5];
    char windowInString[16];

    sprintf(seqInString, "%d", seq);
    sprintf(ackInString, "%d", ack);
    sprintf(dataLengthInString, "%d", dataLength);
    sprintf(windowInString, "%d", window);

    /**
     * Process flag
     */
     int counter = 0;
     for(int j = 8 - strlen(flag); j < 8; j++) {
            packetHeader[j] = flag[counter];
            counter++;
     }

    counter = 0;
    for(int j = 24 - strlen(seqInString); j < 24; j++) {
        packetHeader[j] = seqInString[counter];
        counter++;
    }

    counter = 0;
    for(int j = 40 - strlen(ackInString); j < 40; j++) {
        packetHeader[j] = ackInString[counter];
        counter++;
    }

    counter = 0;
    for(int j = 45 - strlen(dataLengthInString); j < 45; j++) {
        packetHeader[j] = dataLengthInString[counter];
        counter++;
    }

    counter = 0;
    for(int j = 61 - strlen(windowInString); j < 61; j++) {
        packetHeader[j] = windowInString[counter];
        counter++;
    }
    packetHeader[61] = '\0';
    strcpy(resultingPacket, packetHeader);
    strcat(resultingPacket, dataToSend);
    char * result = {0};
    result = resultingPacket;
    result[61 + dataLength] = '\0';
    return result;
}

void processPacketHeader1(char *packet1, struct Packet *clientReceiveBuffer1) {
    struct Packet tempPacket1 = {0};
    char seqTemp[17];
    char ackTemp[17];
    char dataLengthTemp[6];
    char windowNumTemp[17];
    char dataTemp[1981];

    strncpy(tempPacket1.flag, packet1 + 0, 8);
    strncpy(seqTemp, packet1 + 8, 16);
    seqTemp[16] = '\0';
    strncpy(ackTemp, packet1 + 24, 16);
    ackTemp[16] = '\0';
    strncpy(dataLengthTemp, packet1 + 40, 5);
    dataLengthTemp[5] = '\0';
    strncpy(windowNumTemp, packet1 + 45, 16);
    windowNumTemp[16] = '\0';

    tempPacket1.seq = strtoumax(seqTemp, NULL, 10);
    tempPacket1.ack = strtoumax(ackTemp, NULL, 10);
    tempPacket1.dataLength = strtoumax(dataLengthTemp, NULL, 10);
    tempPacket1.windowNum = strtoumax(windowNumTemp, NULL, 10);
    if (tempPacket1.dataLength < 1981) {
        strncpy(tempPacket1.data, packet1 + 61, tempPacket1.dataLength);
    } else {
        //Throw error
    }
}

void loopThroughStringArray(char tempString3[]) {
    char* fileExpressions11[] = {"/root/Documents/client/A Tale of Two Cities.txt", "/root/Documents/client/foo.txt"}, **fff;
    fff = fileExpressions11;
    while(*fff != "") {
        printf("%s\n", *fff++);
    }
}

char* getFileNameFromFilePath(char tempString4[]) {
    char *stringToTest = strdup(tempString4);
    char *token = strtok(stringToTest, "/");
    char *tokenBefore;
    while (token != NULL) {
        tokenBefore = token;
        token=strtok(NULL, "/");
    }
    close(stringToTest);
    return tokenBefore;
}

int stringToInt(char tempString4[]) {

    int number = strtoumax(tempString4, NULL, 10);

    return number;
}

