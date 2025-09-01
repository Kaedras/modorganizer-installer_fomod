#include "../fomodinstallerdialog.h"

using namespace Qt::Literals::StringLiterals;

QString FomodInstallerDialog::getFomodPath(const QString& fileName) const noexcept
{
  QString value = QDir::tempPath() % "/"_L1 % m_FomodPath;
  if (!fileName.isEmpty()) {
    value = value % "/"_L1 % fileName;
  }

  return value;
}
