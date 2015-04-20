#include "AutoTractWindow.h"
#include <QFileDialog>
#include <QSignalMapper>

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
    void selectData(QString data_name);
    void enterData(QString data_name);

private:
    struct Executable
    {
        QPushButton* select_button;
        QLineEdit* enter_lineEdit;
        QPushButton* reset_button;
    };
    struct Data
    {
        QPushButton* select_button;
        QLineEdit* enter_lineEdit;
    };

    QMap<QString, Executable> m_executables_map;
    QMap<QString, QString> executables_map;
    QMap<QString, Data> m_data_map;
    QMap<QString, QString> data_map;
    void initializeExecutablesMap();
    void initializeDataMap();

    QStringList m_selectedAtlases;
    QString m_atlasPopulationDirectory;
};
