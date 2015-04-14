#include "AutoTractWindow.h"
#include <QApplication>


int main( int argc , char** argv )
{
  QApplication app(argc, argv);
  
  AutoTractWindow window;
  window.show();
  
  return app.exec();
  
}
