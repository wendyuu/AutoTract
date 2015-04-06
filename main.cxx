#include "AutoTract.h"
#include <QApplication>


int main( int argc , char** argv )
{
  QApplication app(argc, argv);
  
  AutoTract window;
  window.show();
  
  return app.exec();
  
}
