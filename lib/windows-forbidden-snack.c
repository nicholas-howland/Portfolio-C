// i686-w64-mingw32-gcc -o M msgbox.c
#include <stdio.h>
#include <windows.h>

int properexit = 1;

int NoEscape()
{
    int msgboxID = MessageBox(
        NULL,
        (LPCWSTR)L"There is no escape,\n you cannot cancel a click on a forbidden snack my friend...",
        (LPCWSTR)L"Account Details",
        MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_OK
    );

    switch (msgboxID)
    {
    case IDCANCEL:
        NoEscape();
        break;
    case IDTRYAGAIN:
        ForbddenSnack();
        break;
    case IDCONTINUE:
        atPeaceWithForbiddenSnack();
        break;
    }

    return msgboxID;
}

int OkBye()
{
    int msgboxID = MessageBox(
        NULL,
        (LPCWSTR)L"You have learned a lesson, hopefully it was that not all snacks are forbidden but some are.\n dont eat forbidden snack.",
        (LPCWSTR)L"Account Details",
        MB_OK
    );

    switch (msgboxID)
    {
    case IDCANCEL:
        // TODO: add code
        break;
    case IDTRYAGAIN:
        // TODO: add code
        break;
    case IDOK:
        // TODO: add code
        break;
    }

    return msgboxID;
}

int atPeaceWithForbiddenSnack()
{
    int msgboxID = MessageBox(
        NULL,
        (LPCWSTR)L"Have you found peace with eating the forbidden snack?\nSnack will not just stop",
        (LPCWSTR)L"Account Details",
        MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_OK
    );

    switch (msgboxID)
    {
    case IDCANCEL:
        NoEscape();
        break;
    case IDTRYAGAIN:
        ForbddenSnack();
        break;
    case IDCONTINUE:
        atPeaceWithForbiddenSnack();
        break;
    }

    return msgboxID;
}

int ForbddenSnack()
{
    int msgboxID = MessageBox(
        NULL,
        (LPCWSTR)L"Forbidden Snack Eaten\nHave you learned your lesson?",
        (LPCWSTR)L"Account Details",
        MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_OK
    );

    switch (msgboxID)
    {
    case IDCANCEL:
        NoEscape();
        break;
    case IDTRYAGAIN:
        ForbddenSnack();
        break;
    case IDCONTINUE:
        atPeaceWithForbiddenSnack();
        break;
    }

    return msgboxID;
}



int main(int argc, char* argv[]) {
    // while loop to stop program from exiting while forbidden snack has not recieved the exit signal
    // what will break the exit signal? calling IT or ending the task? to simple the goal should be 
    // to call IT not just end the task
   
        ForbddenSnack();

}
