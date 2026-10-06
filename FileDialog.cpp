#include "FileDialog.h"

#include <windows.h>
#include <commdlg.h>

std::string FileDialog::openBMP()
{
    char filename[MAX_PATH] = "";

    OPENFILENAMEA ofn;

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;

    ofn.lpstrFilter =
        "Bitmap Images (*.bmp)\0*.bmp\0"
        "All Files (*.*)\0*.*\0";

    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;

    ofn.Flags =
        OFN_PATHMUSTEXIST |
        OFN_FILEMUSTEXIST;

    ofn.lpstrDefExt = "bmp";

    if (GetOpenFileNameA(&ofn))
    {
        return filename;
    }

    return "";
}

std::string FileDialog::saveBMP()
{
    char filename[MAX_PATH] = "";

    OPENFILENAMEA ofn;

    ZeroMemory(&ofn, sizeof(ofn));

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;

    ofn.lpstrFilter =
        "Bitmap Images (*.bmp)\0*.bmp\0";

    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;

    ofn.Flags =
        OFN_PATHMUSTEXIST |
        OFN_OVERWRITEPROMPT;

    ofn.lpstrDefExt = "bmp";

    if (GetSaveFileNameA(&ofn))
    {
        return filename;
    }

    return "";
}