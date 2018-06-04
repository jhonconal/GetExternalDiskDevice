#ifndef GETUSBDISKWIDGET_H
#define GETUSBDISKWIDGET_H

#include <QWidget>
#include <windows.h>
#include <winbase.h>
#include <winnls.h>
#include <dbt.h>
#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QVector>
#include <QStringList>
#include <QDesktopServices>
#include <QUrl>
namespace Ui {
class GetUsbDiskWidget;
}

typedef struct USB_DISK_INFO
{
    QString DirPath;
    float TotalMemory;
    float FreeMemory;
}USB_DISK_INFO;

class GetUsbDiskWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GetUsbDiskWidget(QWidget *parent = 0);
    ~GetUsbDiskWidget();

    void Init();
    void ScanHD();
    void AddDisk(QString &DiskName);
    void DeleteDisk(QString &DiskName);
    bool SearchDisk(QString &DiskName,int &iter);
    void GetMemorySize(USB_DISK_INFO & disk);
    void AddComboBoxItem(QString &item);
    void DeleteComboBoxItem(QString &item);
    char FirstDriveFromMask (ULONG unitmask);
    USB_DISK_INFO GetCheckedDisk();

    bool winEvent(MSG *message, long *result);
protected:
    bool nativeEvent(const QByteArray & eventType, void * message, long*result);
private:
    Ui::GetUsbDiskWidget *ui;
    QVector<USB_DISK_INFO> usb_disk_info;
    USB_DISK_INFO CurrentUseDisk;
private slots:
    void on_comboBox_USB_currentIndexChanged(QString );
    void on_checkButton_clicked();
};

#endif // GETUSBDISKWIDGET_H
