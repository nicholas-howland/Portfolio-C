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


int atPeaceWithForbiddenSnack()
{
    int msgboxID = MessageBox(
        NULL,
        (LPCWSTR)L"Have you found peace with eating the forbidden snack?\nForbidden snack is not evil just annoying",
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
    // messing around with message dialouge boxes, jokeware that will not allow the user to stop the dialouge box
    ForbddenSnack();

}
