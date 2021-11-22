#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>

HANDLE initCom(int comPortNumber) {
    DCB dcb;
    HANDLE hCom;
    BOOL fSuccess;
    char comPortName[20];
    sprintf(comPortName, "\\\\.\\COM%d", comPortNumber);
    hCom = CreateFileA(comPortName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hCom == INVALID_HANDLE_VALUE) {
        MessageBoxA(0, "Fout: De seriële poort kan niet geopend worden!", "Fout", MB_OK | MB_ICONEXCLAMATION);
        exit(-1);
    }
    fSuccess = GetCommState(hCom, &dcb);
    if (!fSuccess) {
        MessageBoxA(0, "Fout: De instellingen van de seriële poort kunnen niet gelezen worden!", "Fout", MB_OK | MB_ICONEXCLAMATION);
        exit(-1);
    }
    dcb.fParity = TRUE;
    dcb.BaudRate = CBR_9600;
    dcb.ByteSize = 7;
    dcb.Parity = EVENPARITY;
    dcb.StopBits = ONESTOPBIT;
    dcb.fOutxCtsFlow = FALSE;
    dcb.fOutxDsrFlow = FALSE;
    dcb.fDtrControl = DTR_CONTROL_DISABLE;
    dcb.fDsrSensitivity = FALSE;
    dcb.fOutX = FALSE;
    dcb.fInX = FALSE;
    dcb.fRtsControl = RTS_CONTROL_DISABLE;
    fSuccess = SetCommState(hCom, &dcb);
    if (!fSuccess) {
        MessageBoxA(0, "Fout: De instellingen van de seriële poort kunnen niet aangepast worden!", "Fout", MB_OK | MB_ICONEXCLAMATION);
        exit(-1);
    }
    return hCom;
}

char readCom(HANDLE hCom) {
    char inBuffer[2] = " ";
    unsigned long nBytesRead;
    while (ReadFile(hCom, &inBuffer, 1, &nBytesRead, NULL) && nBytesRead == 0);
    if (nBytesRead != 1) {
        MessageBoxA(0, "Fout: De seriële poort kan niet uitgelezen worden!", "Fout", MB_OK | MB_ICONEXCLAMATION);
        exit(-1);
    }
    return inBuffer[0];
}

void writeCom(HANDLE hCom, char c) {
    char outBuffer[2] = " ";
    unsigned long nBytesWritten;
    outBuffer[0] = c;
    WriteFile(hCom, &outBuffer, 1, &nBytesWritten, NULL);
    if (nBytesWritten != 1) {
        MessageBoxA(0, "Fout: De seriële poort kan niet beschreven worden!", "Fout", MB_OK | MB_ICONEXCLAMATION);
        exit(-1);
    }
}

void closeCom(HANDLE hCom) {
    CloseHandle(hCom);
}

int main(void) {
    FILE* outfile;
    outfile = fopen("output.txt", "w");
    char in;
    int j = 0;
    char text[50];
    printf("Er wordt nu een S verstuurd.\n");
    for(int i = 0; i < 5; i++){
        j = 0;
        HANDLE hCom;
        hCom = initCom(3);
        writeCom(hCom, 'S');
        printf("Spanning = ");
        do {
            in = readCom(hCom);
            if (in != 'Q') {
                putchar(in);
                text[j] = in;
            }else{
                text[j] = '\0';
            }
            j++;
        } while (in != 'Q');
        closeCom(hCom);
        printf(" V\n");

    if (outfile == NULL) {
        printf("File output.txt kan niet aangemaakt worden.\n");
    }
    else {
        struct tm* pt;
        time_t tijd;
        time(&tijd);
        fprintf(outfile, "%s V", text);
        fprintf(outfile,"  %s\n", ctime(&tijd));
        printf("\n\nFile output.txt is aangemaakt.\n");
    }
    Sleep(1000);
    }
    fclose(outfile);
    printf("\nEINDE.\n");
    getchar();
    return 0;
}
