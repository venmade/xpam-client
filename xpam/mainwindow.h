/*
Copyright (c) 2013, cen (imbacen@gmail.com)
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 
   
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QString"
#include "QMouseEvent"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void readStdout();              //starts the gproxy
    void startW3();                 //starts w3
    void startUpdate();             //starts the update
    void updateCheckFinished();     //terminates the splash screen event loop
    void cancelUpdate();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void checkUpdates();
    bool checkW3Updates();
    bool updatesEnabled;
    
private slots:
    void on_pushButtonGWG_clicked();
    void on_pushButtonGWN_clicked();
    void on_pushButtonGWD_clicked();
    void on_pushButtonBU_clicked();
    void handleCheckbox(bool checked);
    void handleCheckboxClient(bool checked);
    void initGproxyOptions();
    void initClientOptions();

    void on_pushButtonGPCL_clicked();
    void on_pushButtonGPNOTEPAD_clicked();
    void on_pushButtonClientLog_clicked();
    void on_pushButton_w3path_clicked();
    
    void on_horizontalSliderW3Version_sliderReleased();
    
    void on_pushButton_updateW3_released();

    void on_tabWidget_currentChanged(int index);

public slots:
    void gproxyReady(QString w3Exename);
    void gproxyExiting();
    void receiveLine(QString line);
    void w3Exited();

    void updateFinished(bool restartNeeded, bool ok, bool isUpToDate, bool retry, int type);
    void hideSplashScreen();
    void logUpdate(QString line);
    void modifyLastLineSlot(QString line);

private:
    Ui::MainWindow *ui;

    void lockTabs(int except);
    void unlockTabs();
    void removeLastLine();
    void status(QString status);

    bool isStartupUpdate;

    //window moving
    bool down;
    QPoint lastPos;

    //min and max
    bool ismax;
    QPoint normalpos;
    QSize normalsize;
    int lastCheckedDota=0;

    void startW3AndGproxy(QString w3Exename, QString restrictedVersion="");

    void displayW3Version();
    void diffW3Update(QString version);
    int checkDotaUpdates();

    bool updateInProgress;

protected:
    //void mousePressEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
