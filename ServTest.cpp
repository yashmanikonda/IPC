#include <iostream>
#include <string>
#include <Windows.h>

int main() {
    // Connect to named pipe server
    HANDLE hPipe = CreateFile(
        L"\\\\.\\pipe\\MyNamedPipe",
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL);

    if (hPipe != INVALID_HANDLE_VALUE) {
        // User input
        std::string input;
        std::cout << "Enter command: ";
        std::cin >> input;

        // Send command to server
        DWORD bytesWritten;
        WriteFile(hPipe, input.c_str(), input.size(), &bytesWritten, NULL);

        // Clean up
        CloseHandle(hPipe);
    }
    else {
        std::cerr << "Failed to connect to named pipe server" << std::endl;
        return 1;
    }

    return 0;
}
