#include "Pipeline.h"

Pipeline::Pipeline()
{
}

Pipeline::~Pipeline()
{

}

void Pipeline::setPipelineParameters(para_Model_AutoTract* para_m)
{
    m_para_m = para_m;
}

void Pipeline::setPipelineSoftwares(soft_Model_AutoTract* soft_m)
{
   m_soft_m = soft_m;
}
void Pipeline::setPlainTextEdit(QPlainTextEdit* plainTextEdit)
{
   m_plainTextEdit = plainTextEdit;
}

QProcess* Pipeline::getMainScriptProcess()
{
   return m_mainScriptProcess;
}

void Pipeline::initializeMainScript()
{
   m_script = "#!/usr/bin/env python\n\n";

   m_script += "import os\n";
   m_script += "import sys\n";
   m_script += "import signal\n";
   m_script += "import logging\n";
   m_script += "import subprocess\n";
   m_script += "import datetime\n";
   m_script += "import shutil\n\n";
}

void Pipeline::defineSignalHandler()
{
   m_script += "def signal_handler(signal, frame):\n";
   m_script += "\tprint '***************You pressed Ctrl+C!******************'\n";
   m_script += "\tif runningProcess.poll!=1:\n";
   m_script += "\t\trunningProcess.terminate()\n";
   m_script += "\tsys.exit(0)\n\n";

   m_script += "signal.signal(signal.SIGINT, signal_handler)\n";
   m_script += "signal.signal(signal.SIGTERM, signal_handler)\n\n";
}

void Pipeline::initializeLogging()
{
   m_script += "log = \"" + m_log_path + "\"\n";
   m_script += "logFile = open(log, \"w\") \n\n";

   m_script += "logger = logging.getLogger('AutoTract')\n";
   m_script += "logger.setLevel(logging.DEBUG)\n\n";

   m_script += "fileHandler = logging.FileHandler(log)\n";
   m_script += "fileHandler.setLevel(logging.DEBUG)\n";
   m_script += "fileFormatter = logging.Formatter('%(message)s')\n";
   m_script += "fileHandler.setFormatter(fileFormatter)\n\n";

   m_script += "consoleHandler = logging.StreamHandler()\n";
   m_script += "consoleHandler.setLevel(logging.DEBUG)\n";
   m_script += "consoleFormatter = logging.Formatter('%(message)s')\n";
   m_script += "consoleHandler.setFormatter(consoleFormatter)\n\n";

   m_script += "logger.addHandler(fileHandler)\n";
   m_script += "logger.addHandler(consoleHandler)\n\n";
}

void Pipeline::writeMainScript()
{
   initializeMainScript();

   defineSignalHandler();
   initializeLogging();

   m_script += "os.environ['ITK_GLOBAL_DEFAULT_NUMBER_OF_THREADS'] = '1' \n";

   m_script += "logger.info(sys.executable)\n";

   m_script += "start = datetime.datetime.now()\n\n";

   m_script += "end = datetime.datetime.now()\n\n";

   m_script += "elapsedTime = (end - start).seconds\n";

   m_script += "hours = elapsedTime/(60*60)\n";
   m_script += "elapsedTime -= hours*(60*60)\n\n";

   m_script += "minutes = elapsedTime/60\n";
   m_script += "elapsedTime -= minutes*60\n\n";

   m_script += "seconds = elapsedTime\n\n";

   m_script += "logger.info('Pipeline took %s hour(s), %s minute(s) and %s second(s)', hours, minutes, seconds)\n";

   QDir* processing_dir = new QDir(m_processing_path);
   m_main_path = processing_dir->filePath("main.py");

   std::ofstream* script_stream = new std::ofstream((m_main_path.toStdString()).c_str());
   *script_stream << m_script.toStdString() << std::endl;

   script_stream->close();

   chmod((m_main_path.toStdString()).c_str(), 0755);
}

void Pipeline::cleanUp()
{
}

void Pipeline::writePipeline()
{
   QDir* output_dir = new QDir(m_para_m->getpara_output_dir_lineEdit());
   QFileInfo fi(m_para_m->getpara_output_dir_lineEdit());
   QString base = fi.baseName();
   //std::cout<<base.toStdString()<<std::endl;
   m_log_path = output_dir->filePath(base + ".log");
   writeMainScript();

}

void Pipeline::runPipeline()
{
   /*QString command;
   if(!(m_parameters->getComputingSystem()).compare("local", Qt::CaseInsensitive) || !(m_parameters->getComputingSystem()).compare("killdevil interactive", Qt::CaseInsensitive))
   {
      command = m_main_path;
   }

   if(!(m_parameters->getComputingSystem()).compare("killdevil", Qt::CaseInsensitive))
   {
      command = "bsub -q day -M 4 -n 1 -R \"span[hosts=1]\" python " +  m_main_path;
   }

   QString python_path = (m_parameters->getExecutablePaths())->getExecutablePath("python");
   QString pythonDirectory_path = ((QFileInfo(python_path)).absoluteDir()).path();

   QString FSL_path = (m_parameters->getExecutablePaths())->getExecutablePath("FSL");

   QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
   env.insert("PATH", pythonDirectory_path + ":" + env.value("PATH"));
   env.insert("PYTHONPATH", "");
   env.insert("FSLDIR", FSL_path);
   env.insert("FSLOUTPUTTYPE", "NIFTI_GZ");


   m_mainScriptProcess = new QProcess;
   m_mainScripStProcess->setProcessEnvironment(env);
   m_mainScriptProcess->start(command);

   m_mainScriptProcess->waitForStarted();
   m_timer.start();

   while (!m_mainScriptProcess->waitForFinished())
   {
      sleep(1);
   }

   if(!(m_parameters->getComputingSystem()).compare("killdevil", Qt::CaseInsensitive))
   {
      bool jobRunning = true;

      QString output(m_mainScriptProcess->readAllStandardOutput());
      QRegExp regExp("(<{1})([0-9]{1,})(>{1})");
      regExp.indexIn(output);
      m_jobID = regExp.cap(2);

      std::cout<<"jobID = "<<m_jobID.toStdString()<<std::endl;

      QProcess* bjobs_process = new::QProcess();
      while(jobRunning)
      {
         bjobs_process->start("bjobs " + m_jobID);
         while (!bjobs_process->waitForFinished())
         {
            sleep(1);
         }

         QString bjobs_output(bjobs_process->readAllStandardOutput());
         if(bjobs_output.contains("DONE") || bjobs_output.contains("EXIT"))
         {
            jobRunning = false;
         }

         sleep(1);
      }
   }

   if(m_mainScriptProcess->exitCode()==0)
   {
      cleanUp();
   }*/
}

void Pipeline::stopPipeline()
{
   /*if(!(m_parameters->getComputingSystem()).compare("killdevil", Qt::CaseInsensitive))
   {
      QProcess* bkill_process = new::QProcess();
      bkill_process->start("bkill " + m_jobID);
      while (!bkill_process->waitForFinished())
      {
         sleep(1);
      }
   }

   m_mainScriptProcess->terminate();*/
}

