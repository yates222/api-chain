#include "labels.h"

SplitLine::SplitLine(int width, int length, const QColor color, QWidget* parent)
    : QLabel(parent)
    , w(width)
    , length(length)
    , color(color)
    , orientation(Qt::Orientation::Horizontal)
{
//    this->setFixedWidth(w);
//    QPalette p;
//    p.setColor(QPalette::Window, color);
//    this->setAutoFillBackground(true);
//    this->setPalette(p);
}

//void SplitLine::setLength(int w)
//{
//    if (orientation == Qt::Orientation::Horizontal)
//        this->setFixedWidth(length);
//    else
//        this->setFixedHeight(length);
//}

void SplitLine::setOrientation(Qt::Orientation orientation)
{
    if (orientation == Qt::Orientation::Horizontal)
    {
        this->setFixedHeight(w);
        QPalette p;
        p.setColor(QPalette::Window, color);
        this->setAutoFillBackground(true);
        this->setPalette(p);
        this->setFixedWidth(length);
    }
    else
    {
        this->setFixedWidth(w);
        QPalette p;
        p.setColor(QPalette::Window, color);
        this->setAutoFillBackground(true);
        this->setPalette(p);
        this->setFixedHeight(length);
    }
}

TitleLabel::TitleLabel(QWidget *parent, const QString& text, const QColor color)
    : QLabel(parent)
{
    // 设置字体
    QString fontPath = QString(":/resource/font/Bookman-Old-Style.ttf");
    int loadedFontID = QFontDatabase::addApplicationFont(fontPath);
    QString bookman = QFontDatabase::applicationFontFamilies (loadedFontID).at(0);

    QFont font;
    font.setFamily(bookman);
    font.setPointSize(14);
    font.setWeight(QFont::ExtraBold);
//    font.setFamily("Palatino");
    setFont(font);

    // 设置文字颜色
    QPalette p;
    p.setColor(QPalette::WindowText, color);
    setPalette(p);

    // 居中对齐
    setAlignment(Qt::AlignCenter);

    setFixedWidth(100);

    setText(text);
}
