#include<iostream>
#include<winsock2.h>
#include<string.h>
using namespace std;
int main()
{
    while(1)
    {

        WSADATA WSAData;
        SOCKET server;
        SOCKADDR_IN addr;

        WSAStartup(MAKEWORD(2,0), &WSAData);
        server= socket( AF_INET, SOCK_STREAM, 0);

        addr.sin_addr.s_addr= inet_addr("192.168.1.22"); /// server ip
        addr.sin_family = AF_INET;
        addr.sin_port = htons(5555);

        connect(server, (SOCKADDR *)&addr, sizeof(addr));
        cout << "Connected to server!" << endl;

        char buffer [1024]= {'k','r','i','e',' ','k','e','m','o','n',' ','a','c','i','s'};





        //string str="asi to valoi";
        string str;
        cin>>str;
        int i;
        for(i=0; i<str.size(); i++)
        {
            buffer[i]=str[i];
        }
        buffer[i]='\0';
        send(server,buffer,sizeof(buffer),0);
        //send(server,str,str.size(),0);
        cout<< "MESSAGE SENT!"<<endl;



        closesocket(server);
        WSACleanup();
        cout<< " SOCKET CLOSED."<<endl<<endl;

    }
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
