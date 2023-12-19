#include <iup.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    IupOpen(&argc, &argv);

    Ihandle *label = IupLabel("Hello world from IUP");
    Ihandle *dlg = IupDialog(IupVbox(label, NULL));

    IupShowXY(dlg, IUP_CENTER, IUP_CENTER);

    IupMainLoop();

    IupClose();
    return EXIT_SUCCESS;
}