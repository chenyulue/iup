#include <iup.h>
#include <stdlib.h>

int btn_exit_cb(Ihandle *self) { return IUP_CLOSE; }

int main(int argc, char **argv) {
    IupOpen(&argc, &argv);

    Ihandle *label = IupLabel("Hello world from IUP.");
    Ihandle *button = IupButton("OK", NULL);
    Ihandle *vbox = IupVbox(label, button, NULL);

    Ihandle *dlg = IupDialog(vbox);
    IupSetAttribute(dlg, "TITLE", "Hello World 4");

    IupSetCallback(button, "ACTION", (Icallback)btn_exit_cb);

    IupShowXY(dlg, IUP_CENTER, IUP_CENTER);

    IupMainLoop();

    IupClose();
    return EXIT_SUCCESS;
}