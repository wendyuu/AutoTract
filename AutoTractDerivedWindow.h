#include "AutoTractWindow.h"
#include <QFileDialog>

class AutoTractDerivedWindow :public AutoTractWindow
{
    Q_OBJECT
public:
    AutoTractDerivedWindow();
private slots:
    void SaveConfigFile();
    void LoadConfigFile();
};
