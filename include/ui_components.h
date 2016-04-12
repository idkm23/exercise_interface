#ifndef UI_ASDINTERFACE_H
#define UI_ASDINTERFACE_H

#include <QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QLCDNumber>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QComboBox>

QT_BEGIN_NAMESPACE

class UIComponents {

public:

    static const int BSPACING = 10, BWIDTH = 100, BHEIGHT = 50,
                     COL1_X = 20, COL1_Y = 70, 
                     COL2_X = 150, COL2_Y = COL1_Y,
                     COL3_X = 280, COL3_Y = COL1_Y;

    QLabel *trainingLabel, *trialLabel, *extrasLabel;
    
    QPushButton *trainingRecord, *trainingDelete, *trainingClear,
                *trialBegin, *trialPractice,
                *myoLaunch, *myoCalibrate, *naoLaunch;
    
    QComboBox *myoCount;

    void setupUi(QWidget *MasterInterface) {
    
        // Create and size window    
        
        if(MasterInterface->objectName().isEmpty()) {
            MasterInterface->setObjectName(QString("MasterInterface"));
        }

        MasterInterface->resize(410, 260);

        /***************************************/
        
        trainingLabel = new QLabel(MasterInterface);
        trainingLabel->setText(QString("<h1><u>Training</u></h1>"));
        trainingLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        trainingLabel->setStyleSheet("QLabel { margin: 10px 0 0 10px }");

        trainingRecord = new QPushButton(MasterInterface);
        trainingRecord->setObjectName(QString("trainingRecord"));
        trainingRecord->setGeometry(QRect(COL1_X, COL1_Y, BWIDTH, BHEIGHT)); 

        trainingDelete = new QPushButton(MasterInterface);
        trainingDelete->setObjectName(QString("trainingDelete"));
        trainingDelete->setGeometry(QRect(COL1_X, COL1_Y+BHEIGHT+BSPACING, BWIDTH, BHEIGHT)); 

        trainingClear = new QPushButton(MasterInterface);
        trainingClear->setObjectName(QString("trainingClear"));
        trainingClear->setGeometry(QRect(COL1_X, COL1_Y+2*(BHEIGHT+BSPACING), BWIDTH, BHEIGHT)); 

        /***************************************/
        
        trialLabel = new QLabel(MasterInterface);
        trialLabel->setText(QString("<h1><u>Trial</u></h1>"));
        trialLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        trialLabel->setStyleSheet("QLabel { margin: 10px 0 0 165px }");

        trialBegin = new QPushButton(MasterInterface);
        trialBegin->setObjectName(QString("trialBegin"));
        trialBegin->setGeometry(QRect(COL2_X, COL2_Y, BWIDTH, BHEIGHT)); 

        trialPractice = new QPushButton(MasterInterface);
        trialPractice->setObjectName(QString("trialPractice"));
        trialPractice->setGeometry(QRect(COL2_X, COL2_Y+BHEIGHT+BSPACING, BWIDTH, BHEIGHT)); 

        /***************************************/
        
        extrasLabel = new QLabel(MasterInterface);
        extrasLabel->setText(QString("<h1><u>Extras</u></h1>"));
        extrasLabel->setAlignment(Qt::AlignTop | Qt::AlignLeft);
        extrasLabel->setStyleSheet("QLabel { margin: 10px 0 0 280px }");

        myoCount = new QComboBox(MasterInterface);
        myoCount->addItem(QString("2"));
        myoCount->addItem(QString("1"));
        myoCount->setGeometry(QRect(COL3_X, COL3_Y, 35, BHEIGHT)); 

        myoLaunch = new QPushButton(MasterInterface);
        myoLaunch->setObjectName(QString("myoLaunch"));
        myoLaunch->setGeometry(QRect(COL3_X + 35, COL3_Y, BWIDTH - 35, BHEIGHT)); 

        myoCalibrate = new QPushButton(MasterInterface);
        myoCalibrate->setObjectName(QString("myoCalibrate"));
        myoCalibrate->setGeometry(QRect(COL3_X, COL3_Y+(BHEIGHT+BSPACING), BWIDTH, BHEIGHT)); 

        naoLaunch = new QPushButton(MasterInterface);
        naoLaunch->setObjectName(QString("naoLaunch"));
        naoLaunch->setGeometry(QRect(COL3_X, COL3_Y+2*(BHEIGHT+BSPACING), BWIDTH, BHEIGHT)); 

        /***************************************/
        
       // Polish it all off
        retranslateUi(MasterInterface);
        QMetaObject::connectSlotsByName(MasterInterface);
    }

    // Name window and buttons    
    void retranslateUi(QWidget *MasterInterface){
        MasterInterface->setWindowTitle(QApplication::translate("MasterInterface", "MasterInterface", 0));

        trainingLabel->adjustSize(); 
        trainingRecord->setText("train\nclassifier");
        trainingDelete->setText("delete\nlast training");
        trainingClear->setText("clear");

        trialLabel->adjustSize();
        trialBegin->setText("begin trial");
        trialPractice->setText("begin\npractice");

        extrasLabel->adjustSize();
        myoLaunch->setText("launch\nmyo");
        myoCalibrate->setText("calibrate myo");
        naoLaunch->setText("launch Nao");
   }

    int getMyoCount() {
        return myoCount->currentText().toStdString()[0] - '0';
    } 

};

QT_END_NAMESPACE

#endif
