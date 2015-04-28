#ifndef AutoTractWindow_h
#define AutoTractWindow_h

#include "ui_AutoTract.h"
#include "para_Save_AutoTract.h"
#include "para_Load_AutoTract.h"
#include "para_Model_AutoTract.h"
#include "soft_Save_AutoTract.h"
#include "soft_Load_AutoTract.h"
#include "soft_Model_AutoTract.h"

class AutoTractWindow :public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT
public:
    AutoTractWindow( QWidget * parent = 0, Qt::WFlags f = 0 );
    void SyncUiToModelStructure();
    void SyncModelStructureToUi();
public slots:
    void Save_Parameter_Configuration( std::string filename );
    void Load_Parameter_Configuration( std::string filename );
    void Save_Software_Configuration( std::string filename );
    void Load_Software_Configuration( std::string filename );


protected:
    para_Model_AutoTract para_m;
    para_Save_AutoTract para_s;
    para_Load_AutoTract para_l;
    soft_Model_AutoTract soft_m;
    soft_Save_AutoTract soft_s;
    soft_Load_AutoTract soft_l;
};

#endif
