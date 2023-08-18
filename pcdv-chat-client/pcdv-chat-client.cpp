#include <iostream>
#include <iostream>
#include <tchar.h>
#include <winsock2.h>
#include <ws2tcpip.h>
using namespace std;

int main()
{
    cout << "Initializing Chat Client";

    cout << "Step 1: Setting up DLL" << endl;
    SOCKET clientSocket, acceptSocket;
    int port = 55555;
    WSADATA wsaData;
    int wsaError;
    WORD wVersionRequested = MAKEWORD(2, 2);

    wsaError = WSAStartup(wVersionRequested, &wsaData);

    if (wsaError != 0)
    {
        cout << "Winsock dll not found!" << endl;
        return 0;
    }
    else
    {
        cout << "Winsock dll found!" << endl;
        cout << "Status: " << wsaData.szSystemStatus << endl;
    }

    cout << "Step 2: Setting up Client Socket" << endl;
    clientSocket = INVALID_SOCKET;
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (clientSocket == INVALID_SOCKET)
    {
        cout << "Error at socket():" << WSAGetLastError() << endl;
        WSACleanup();
        return 0;
    }
    else
    {
        cout << "socket() is OK!" << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
