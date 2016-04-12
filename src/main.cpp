#include <ros/ros.h>
#include <QApplication>
#include <QDesktopWidget>

#include "../include/master_interface.h"

void centerWindow(QMainWindow* w);

#include <stdio.h>  /* defines FILENAME_MAX */
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
 #endif



int main(int argc, char **argv) {

char cCurrentPath[FILENAME_MAX];
     if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
              {
                       return errno;
                            }

     cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */

     printf ("The current working directory is %s", cCurrentPath);


    ros::init(argc, argv, "exercise_interface");    
    QApplication app(argc, argv);
    MasterInterface mi; 
    centerWindow(&mi);
    mi.show();

    return app.exec();

    return 0;
}

// Finds the active window and places w in the center of that screen
void centerWindow(QMainWindow* w) {
    QDesktopWidget* m = QApplication::desktop();
    QRect desk_rect = m->screenGeometry(m->screenNumber(QCursor::pos()));
    int desk_x = desk_rect.width();
    int desk_y = desk_rect.height();
    int x = w->width();
    int y = w->height();
    w->move(desk_x / 2 - x / 2 + desk_rect.left(), desk_y / 2 - y / 2 + desk_rect.top());
}
