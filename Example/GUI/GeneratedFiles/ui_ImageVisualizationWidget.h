/********************************************************************************
** Form generated from reading UI file 'ImageVisualizationWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVISUALIZATIONWIDGET_H
#define UI_IMAGEVISUALIZATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageVisualizationWidget
{
public:
    QSpinBox *spinBoxImageId;
    QLabel *labelImage;
    QComboBox *comboBoxSet;
    QLabel *Image;

    void setupUi(QWidget *ImageVisualizationWidget)
    {
        if (ImageVisualizationWidget->objectName().isEmpty())
            ImageVisualizationWidget->setObjectName(QString::fromUtf8("ImageVisualizationWidget"));
        ImageVisualizationWidget->resize(660, 420);
        spinBoxImageId = new QSpinBox(ImageVisualizationWidget);
        spinBoxImageId->setObjectName(QString::fromUtf8("spinBoxImageId"));
        spinBoxImageId->setGeometry(QRect(10, 360, 80, 22));
        spinBoxImageId->setMaximum(9999);
        labelImage = new QLabel(ImageVisualizationWidget);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(10, 340, 80, 16));
        comboBoxSet = new QComboBox(ImageVisualizationWidget);
        comboBoxSet->addItem(QString());
        comboBoxSet->addItem(QString());
        comboBoxSet->setObjectName(QString::fromUtf8("comboBoxSet"));
        comboBoxSet->setGeometry(QRect(10, 390, 80, 22));
        Image = new QLabel(ImageVisualizationWidget);
        Image->setObjectName(QString::fromUtf8("Image"));
        Image->setGeometry(QRect(10, 10, 50, 50));
        comboBoxSet->raise();
        spinBoxImageId->raise();
        labelImage->raise();
        Image->raise();

        retranslateUi(ImageVisualizationWidget);

        QMetaObject::connectSlotsByName(ImageVisualizationWidget);
    } // setupUi

    void retranslateUi(QWidget *ImageVisualizationWidget)
    {
        ImageVisualizationWidget->setWindowTitle(QCoreApplication::translate("ImageVisualizationWidget", "ImageVisualizationWidget", nullptr));
        labelImage->setText(QCoreApplication::translate("ImageVisualizationWidget", "Label :", nullptr));
        comboBoxSet->setItemText(0, QCoreApplication::translate("ImageVisualizationWidget", "Testing", nullptr));
        comboBoxSet->setItemText(1, QCoreApplication::translate("ImageVisualizationWidget", "Training", nullptr));

        Image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ImageVisualizationWidget: public Ui_ImageVisualizationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVISUALIZATIONWIDGET_H
