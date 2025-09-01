#include "../fomodinstallerdialog.h"
#include <QDirIterator>

using namespace Qt::Literals::StringLiterals;

QString getFomodPathCaseInsensitive(const QString& baseDir,
                                    const QString& fileName) noexcept
{
  // todo: replace QDirIterator with QDirListing once Qt is upgraded to 6.8 or later

  // look for the fomod folder
  QDirIterator dirIter(baseDir);
  while (dirIter.hasNext()) {
    QFileInfo info(dirIter.nextFileInfo());
    // skip files
    if (info.isFile()) {
      continue;
    }
    if (info.fileName().compare("fomod"_L1, Qt::CaseInsensitive) == 0) {
      // return the absolute folder path if the provided file name is empty
      if (fileName.isEmpty()) {
        return info.absoluteFilePath();
      }

      // case-insensitive file lookup
      QDirIterator fileIter(baseDir);
      while (fileIter.hasNext()) {
        QFileInfo fileInfo(fileIter.nextFileInfo());
        // skip directories
        if (fileInfo.isDir()) {
          continue;
        }
        if (fileInfo.fileName().compare(fileName, Qt::CaseInsensitive) == 0) {
          return fileInfo.absoluteFilePath();
        }
      }
    }
  }

  if (fileName.isEmpty()) {
    return "fomod"_L1;
  }
  return "fomod"_L1 % "/"_L1 % fileName;
}

QString FomodInstallerDialog::getFomodPath(const QString& fileName) const noexcept
{
  QString baseDir = QDir::tempPath() % "/"_L1 % m_FomodPath;
  return getFomodPathCaseInsensitive(baseDir, fileName);
}
