#include "AutoTract.h"
#include <iostream>
AutoTract::AutoTract(QWidget * parent , Qt::WFlags f  ): QMainWindow(parent, f)
{
  setupUi(this);
  connect(this->exitButton, SIGNAL(clicked()), this, SLOT(slotExit()));

}

void AutoTract::slotExit()
{
  qApp->exit();
}
