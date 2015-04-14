#ifndef AutoTractWindow_h
#define AutoTractWindow_h

#include "ui_AutoTract.h"
#include "AutoTractSave.h"
#include "AutoTractModel.h"
#include "AutoTractLoad.h"

class AutoTractWindow :public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT
public:
    AutoTractWindow( QWidget * parent = 0, Qt::WFlags f = 0 ) ;
    void SyncUiToModelStructure() ;
    void SyncModelStructureToUi() ;
public slots:
    void Save();
    void Load();


private:
    AutoTractModel m ;
    AutoTractSave s ;
    AutoTractLoad l ;

};

#endif
