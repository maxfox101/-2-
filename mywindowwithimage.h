#ifndef MYWINDOWWITHIMAGE_H
#define MYWINDOWWITHIMAGE_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MyWindowWithImage;
}
QT_END_NAMESPACE

class MyWindowWithImage : public QMainWindow
{
    Q_OBJECT

public:
    MyWindowWithImage(QWidget *parent = nullptr);
    ~MyWindowWithImage();

    void SetPixmap(QLabel* label_pix, const QString& path);
    void FitToImage(QLabel* label);
    void CenterImage(QLabel* label);  // Новый метод для центрирования изображения

private:
    Ui::MyWindowWithImage *ui;

};
#endif // MYWINDOWWITHIMAGE_H
