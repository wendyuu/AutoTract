#ifndef AutoTract_h
#define AutoTract_h

#include "ui_AutoTract.h"

class AutoTract :public QMainWindow, public Ui::MainWindow
{
  Q_OBJECT
  public:
    AutoTract(QWidget * parent = 0, Qt::WFlags f = 0 );
  private slots:
   void slotExit();

};

#endif

