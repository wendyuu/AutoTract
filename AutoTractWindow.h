#ifndef AutoTractWindow_h
#define AutoTractWindow_h

#include "ui_AutoTract.h"

class AutoTractWindow :public QMainWindow, public Ui::MainWindow
{
  Q_OBJECT
  public:
    AutoTractWindow(QWidget * parent = 0, Qt::WFlags f = 0 );
  private slots:

};

#endif

