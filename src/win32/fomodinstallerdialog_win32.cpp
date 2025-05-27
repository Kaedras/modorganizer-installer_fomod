#include "../fomodinstallerdialog.h"

QString FomodInstallerDialog::getFomodPath(const QString& fileName) const noexcept
{
  QString value = QDir::tempPath() % '/' % m_FomodPath;
  if (!fileName.isEmpty()) {
    value = value % '/' % fileName;
  }

  return value;
}
