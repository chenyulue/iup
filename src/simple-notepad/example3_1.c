#include <stdlib.h>
#include <iup.h>

int main(int argc, char *argv[]) {
    IupOpen(&argc, &argv);

    Ihandle *multitext = IupText(NULL);
    Ihandle *vbox = IupVbox(multitext, NULL);

    // IupSetAttribute(multitext, "MULTILINE", "YES");
    IupSetAttribute(multitext, "EXPAND", "YES");

    Ihandle *dlg = IupDialog(vbox);
    IupSetAttribute(dlg, "TITLE", "Simple Notepad");
    IupSetAttribute(dlg, "SIZE", "QUARTERxQUARTER");

    IupShowXY(dlg, IUP_CENTER, IUP_CENTER);
    IupSetAttribute(dlg, "USERSIZE", NULL);

    IupMainLoop();
    IupClose();

    return EXIT_SUCCESS;
}