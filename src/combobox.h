#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QStyledItemDelegate>
#include <QComboBox>
#include <QLineEdit>
#include <QPainter>
#include <QEvent>
#include <QAbstractItemView>

#include "constants.h"

class NoFocusFrameDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit NoFocusFrameDelegate(QWidget *parent = nullptr);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

class BasicComboBox: public QComboBox
{
    Q_OBJECT
public:
    BasicComboBox(QWidget *parent=nullptr);
    void showPopup();
    void hidePopup();
    bool isPopup();
private:
    void paintEvent(QPaintEvent*);
    bool eventFilter(QObject *, QEvent *);
private:
    int borderRadius;
    int itemHight;
    int miniWidth;
    bool _isPopup;
    bool _forcePopup;
};

#endif // COMBOBOX_H
