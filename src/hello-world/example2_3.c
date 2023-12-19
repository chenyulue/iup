#include <iup.h>
#include <stdlib.h>

int btn_exit_cb(Ihandle *self) {
    IupMessage("Hello World Message", "Hello world from IUP.");
    return IUP_CLOSE;
}

int main(int argc, char *argv[]) {
    IupOpen(&argc, *argv);

    Ihandle *button = IupButton("OK", NULL);
    Ihandle *vbox = IupVbox(button, NULL);
    Ihandle *dlg = IupDialog(vbox);
    IupSetAttribute(dlg, "TITLE", "Hello World 3");

    IupSetCallback(button, "ACTION", (Icallback)btn_exit_cb);

    IupShowXY(dlg, IUP_CENTER, IUP_CENTER);

    IupMainLoop();

    IupClose();
    return EXIT_SUCCESS;
}