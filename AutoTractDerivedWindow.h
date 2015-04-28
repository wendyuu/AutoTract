#include "AutoTractWindow.h"
#include <QFileDialog>
#include <QSignalMapper>
#include <iterator>
#include <iostream>
#include <fstream>

class AutoTractDerivedWindow :public AutoTractWindow
{
    Q_OBJECT
public:
    AutoTractDerivedWindow();
    void displayAtlases();
    void checkSelectedAtlases();
    void checkAtlases();
public slots:
    void UpdateAtlasPopulationDirectoryDisplay();
    void selectAtlas(QListWidgetItem* item);
    void selectTractsPopulationDirectory();
    void enterAtlasPopulationDirectory();
private slots:
    void SaveParaConfigFile();
    void LoadParaConfigFile();
    void SaveSoftConfigFile();
    void LoadSoftConfigFile();
    void selectExecutable(QString executable_name);
    void enterExecutable(QString executable_name);
    void resetExecutable(QString executable_name);
    void selectParameters(QString parameters_name);
    void enterParameters(QString parameters_name);
    void changeRegistrationType(int index);
    void runPipeline();

private:
    struct Executable
    {
        QPushButton* select_button;
        QLineEdit* enter_lineEdit;
        QPushButton* reset_button;
    };
    struct Parameters
    {
        QPushButton* select_button;
        QLineEdit* enter_lineEdit;
    };

    QMap<QString, Executable> m_executables_map;
    QMap<QString, QString> executables_map;
    QMap<QString, Parameters> m_parameters_map;
    QMap<QString, QString> parameters_map;
    void initializeExecutablesMap();
    void initializeParametersMap();

    QStringList m_selectedAtlases;
    QString m_atlasPopulationDirectory;
    QString m_script;

};
