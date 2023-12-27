#include <iup.h>
#include <stdlib.h>

int exit_cb(void) { return IUP_CLOSE; }

int main(int argc, char **argv) {
    IupOpen(&argc, &argv);

    Ihandle *multitext = IupText(NULL);
    IupSetAttribute(multitext, "MULTILINE", "YES");
    IupSetAttribute(multitext, "EXPAND", "YES");

    Ihandle *item_open = IupItem("Open", NULL);
    Ihandle *item_saveas = IupItem("Save As", NULL);
    Ihandle *item_exit = IupItem("Exit", NULL);
    IupSetCallback(item_exit, "ACTION", (Icallback)exit_cb);

    Ihandle *file_menu =
        IupMenu(item_open, item_saveas, IupSeparator(), item_exit, NULL);

    Ihandle *sub1_menu = IupSubmenu("File", file_menu);

    Ihandle *menu = IupMenu(sub1_menu, NULL);

    Ihandle *vbox = IupVbox(multitext, NULL);

    Ihandle *dlg = IupDialog(vbox);
    IupSetAttributeHandle(dlg, "MENU", menu);
    IupSetAttribute(dlg, "TITLE", "Simple Notepad");
    IupSetAttribute(dlg, "SIZE", "QUARTERxQUARTER");

    IupShowXY(dlg, IUP_CENTER, IUP_CENTER);
    IupSetAttribute(dlg, "USERSIZE", NULL);

    IupMainLoop();
    IupClose();

    return EXIT_SUCCESS;
}