#include "../fomodinstallerdialog.h"

QString getFomodPathCaseInsensitive(const QString& baseDir,
                                    const QString& fileName) noexcept
{
  // look for the fomod folder
  for (const auto& dirEntry :
       QDirListing(baseDir, QDirListing::IteratorFlag::DirsOnly)) {
    if (dirEntry.fileName().compare(QStringLiteral("fomod"), Qt::CaseInsensitive) ==
        0) {
      // return the absolute folder path if the provided file name is empty
      if (fileName.isEmpty()) {
        return dirEntry.absoluteFilePath();
      }

      // case-insensitive file lookup
      for (const auto& fileEntry : QDirListing(dirEntry.absoluteFilePath(),
                                               QDirListing::IteratorFlag::FilesOnly)) {
        if (fileEntry.fileName().compare(fileName, Qt::CaseInsensitive) == 0) {
          return fileEntry.absoluteFilePath();
        }
      }
    }
  }

  return {};
}

QString FomodInstallerDialog::getFomodPath(const QString& fileName) const noexcept
{
  QString baseDir = QDir::tempPath() % '/' % m_FomodPath;
  return getFomodPathCaseInsensitive(baseDir, fileName);
}
