#include <iostream>
#include <allegro5/allegro.h>

#include "Main.h"
#include "Cursor.h"

using namespace std;

int main() {
    Main editor;

    if (!editor.initialize(640, 480)) {
        cout << "Error, could not initialize editor.\n";
        return 1;
    }

    editor.run();

    return 0;
}
