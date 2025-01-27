#include "mywindowwithimage.h"
#include "ui_mywindowwithimage.h"

MyWindowWithImage::MyWindowWithImage(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyWindowWithImage)
{
    ui->setupUi(this);

    // Сохраним путь в переменную.
    QString absolute_path_file = "C:\\Users\\user\\Downloads\\i-love-qt.png";

    // Вызываем созданный ранее метод.
    SetPixmap(ui->lbl_pixmap, absolute_path_file);
}

MyWindowWithImage::~MyWindowWithImage()
{
    delete ui;
}

void MyWindowWithImage::SetPixmap(QLabel *label_pix, const QString& path)
{
    QPixmap pix(path);
    Q_ASSERT(!pix.isNull());

    label_pix->setPixmap(pix);
    FitToImage(label_pix);
    label_pix->show();
}

void MyWindowWithImage::FitToImage(QLabel* label)
{
    if (!label || !label->pixmap())
        return;

    const QPixmap* pixmap = label->pixmap();
    label->setFixedSize(pixmap->width(), pixmap->height());
}

void MyWindowWithImage::CenterImage(QLabel* label)
{
    if (!label || !label->pixmap())
        return;

    // Получаем размеры окна
    int windowWidth = this->width();
    int windowHeight = this->height();

    // Получаем размеры изображения
    const QPixmap* pixmap = label->pixmap();
    int imageWidth = pixmap->width();
    int imageHeight = pixmap->height();

    // Вычисляем координаты для центрирования
    int x = (windowWidth - imageWidth) / 2;
    int y = (windowHeight - imageHeight) / 2;

    // Перемещаем изображение в центр
    label->move(x, y);
}
