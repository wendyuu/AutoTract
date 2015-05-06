#ifndef DEF_DerivedWindow
#define DEF_DerivedWindow

#include "AutoTractWindow.h"
#include "Pipeline.h"
#include <QFileDialog>
#include <QSignalMapper>
#include <iterator>
#include <iostream>
#include <fstream>
#include <QtGui>

class AutoTractDerivedWindow :public AutoTractWindow
{
    Q_OBJECT
public:
    AutoTractDerivedWindow();
    void displayAtlases();
    void checkSelectedAtlases();
    void checkAtlases();
    /*void setSoftwareXMLPath(std::string executables);
    void setParameterXMLPath(std::string parameters);*/
public slots:
    void UpdateAtlasPopulationDirectoryDisplay();
    void selectAtlas(QListWidgetItem* item);
    void selectTractsPopulationDirectory();
    void enterAtlasPopulationDirectory();
    void selectOutputDirectory();
    void enterOutputDirectory();
    void initializePipelineLogging();
    void printPipelineLog();
    void SetLookupExecutableMap(QMap<QString, QString> lookup_executables_map);
    void SetLookupParameterMap(QMap<QString, QString> lookup_parameters_map);
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
    void runPipeline();
    void stopPipeline();
    void changeRegistrationType(int index);

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
    QMap<QString, QString> m_lookup_executables_map;
    QMap<QString, Parameters> m_parameters_map;
    QMap<QString, QString> m_lookup_parameters_map;
    QTextStream* m_log_textStream;
    MainScriptThread* m_thread;
    void initializeExecutablesMap();
    void initializeParametersMap();
    Pipeline* m_pipeline;
    QStringList m_selectedAtlases;
    QString m_atlasPopulationDirectory;
    QString m_script;
};

#endif
