#include <stdio.h>
#include "main_header.h"

int main() {

    char *dataToSend = "Hi";
    char *packet = makePacketHeader("SYN", 12538, 1, 58789, dataToSend);
    printf("%s\n", packet);
    return 0;
}


/**
 * Packet header design:
 * In order
 * Flag 8 chars 0-7 , Sequence Number 16 chars 8-23, Ack Number 16 chars 24-39, Data Length 16 chars 40-55, Window 16 chars 56-71
 * Total 72 chars for packet header
 * Example header: 00000SYN0000000000012538000000000000000100000000000000020000000000058789
 */
char* makePacketHeader(char* flag, int seq, int ack, int window, char* dataToSend) {

    char packetHeader[72 + 1] = "000000000000000000000000000000000000000000000000000000000000000000000000";
    int dataLength = strlen(dataToSend);
    char resultingPacket[72 + dataLength + 1];
    //Convert sequence number, ack number, dataLength, window to string
    char seqInString[16];
    char ackInString[16];
    char dataLengthInString[16];
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
    for(int j = 56 - strlen(dataLengthInString); j < 56; j++) {
        packetHeader[j] = dataLengthInString[counter];
        counter++;
    }

    counter = 0;
    for(int j = 72 - strlen(windowInString); j < 72; j++) {
        packetHeader[j] = windowInString[counter];
        counter++;
    }

    strcpy(resultingPacket, packetHeader);
    strcat(resultingPacket, dataToSend);
    char * result = resultingPacket;
    return result;
}

void processPacketHeader() {

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
