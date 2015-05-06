#ifndef REGISTRATION_H
#define REGISTRATION_H

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

class Registration : public Script
{
   public:

   // Constructor
   Registration(QString module);
   // Set
   void setRefDTIAtlas(QString refDTIAtlas);
   void setInputDTIAtlas(QString inputDTIAtlas);
   void setRegistrationType(QString registrationType);
   void setSimilarityMetric(QString similarityMetric);
   void setGaussianSigma(QString gaussianSigma);
   void setDisplacementFieldPath(QString path); //output

   // Implementing Script
   void initializeScript();
   void executeRegistration();
   void implementRun();

   // Updating & Getting Output
   void update();
   QString getDisplacementField();

   private:

   // Parameters
   QString              m_refDTIAtlas;
   QString              m_inputDTIAtlas;
   QString              m_registrationType;
   QString              m_similarityMetric;
   QString              m_gaussianSigma;
   QString              m_displacementFieldPath;
};


#endif // REGISTRATION_H
