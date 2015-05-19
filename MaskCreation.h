#ifndef MASKCREATION_H
#define MASKCREATION_H

// General Librairies
#include <iostream>
#include <fstream>

// Qt Librairies
#include <QString>
#include <QDir>

// My specific librairies
#include "Script.h"
#include "para_Model_AutoTract.h"
#include "soft_Model_AutoTract.h"

class MaskCreation : public Script
{
   public:

   // Constructor
   MaskCreation(QString module);
   // Set
   void setOutputDirectory(QString dir);

   // Implementing Script
   void initializeScript();
   void executeMaskCreation();
   void implementRun();

   // Updating & Getting Output
   void update();

   private:
   QString m_outputDir;
};


#endif // MASKCREATION_H
