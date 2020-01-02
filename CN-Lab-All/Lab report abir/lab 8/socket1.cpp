#include<iostream>
#include<winsock2.h>
using namespace std;


int main()
{
     WSADATA WSAData;
     SOCKET server;
     SOCKADDR_IN addr;

     WSAStartup(MAKEWORD(2,0) , &WSAData);
     server= socket( AF_INET, SOCK_STREAM, 0);

     addr.sin_addr.s_addr= inet_addr("192.168.1.9");
     addr.sin_family = AF_INET;
     addr.sin_port = htons(5555);

     connect(server, (SOCKADDR *)&addr, sizeof(addr));
     cout << "Connected to server!" << endl;

     char buffer [1024]= {'h','e','l','l','o'};
     send(server,buffer,sizeof(buffer),0);
     cout<< "MESSAGE SENT!"<<endl;

     closesocket(server);
     WSACleanup();
     cout<< " SOCKET CLOSED."<<endl<<endl;

     /*SOCKET client;
     SOCKADDR_IN serverAddr, clientAddr;
     WSAStartup(MAKEWORD(2,0), &WSAData);
     server = socket(AF_INET, SOCK_STREAM, 0);

     serverAddr.sin_addr.S_addr = INADDR_ANY;
     serverAddr.sin_family = AF_INET;
     serverAddr.sin_port = htons(5555);

     bind(server, (SOCKADDR *) &serverAddr, sizeof(serverAddr));
     listen(server,0);

      */



}
