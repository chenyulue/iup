#include <stdlib.h>
#include <iup.h>

int btn_exit_cb(Ihandle *self) {
    return IUP_CLOSE;
}

int main(int argc, char *argv[]) {
    IupOpen(&argc, &argv);

    Ihandle *label = IupLabel("Hello world fro IUP.");
    Ihandle *button = IupButton("OK", NULL);
    Ihandle *vbox = IupVbox(label, button, NULL);

    IupSetAttribute(vbox, "ALIGNMENT", "ARIGHT");
    IupSetAttribute(vbox, "GAP", "10");
    IupSetAttribute(vbox, "MARGIN", "10x10");

    Ihandle *dlg = IupDialog(vbox);
    IupSetAttribute(dlg, "TITLE", "Hello World 5");

    IupSetCallback(button, "ACTION", (Icallback)btn_exit_cb);

    IupShowXY(dlg, IUP_CENTER, IUP_CENTER);
    IupMainLoop();
    IupClose();

    return EXIT_SUCCESS;
}