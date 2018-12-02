/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** As a special exception, The Qt Company gives you certain additional
** rights. These rights are described in The Qt Company LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file. Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef DOCUMENT_H
#define DOCUMENT_H
#include <QObject>
#include <QString>
#include <QtWebChannel/QtWebChannel>
#include <qwebengineview.h>
#include "mappoints.h"
#include "math.h"
#include "serial/packet.h"
#define   PI             3.14159265358979323846
#define   EARTH_RADIUS   6378137.0

class Document : public QObject
{
    Q_OBJECT

public:
    explicit Document(QObject *parent = nullptr);
    // 向页面发送消息
    void sendMsg(QWebEnginePage* page, const QString& msg);
    void savepoints(double lng,double lat);
    void changepoints(double lng,double lat,quint8 index_point);
    double getFlatternDistance(double lat1,double lng1,double lat2,double lng2);
    void Calculated_distance(double points[30][2],quint8 nums);
    void uiclear_init();
    double getRad(double d);

    Mappoints *mappoints;

signals:
    void recvdMsg(const QString& msg1,const QString& msg2);
    void recvdMsg_newpoint(const QString& msg1,const QString& msg2,quint8 index_point);
public slots:
    // 接收到页面发送来的消息
    void onMsg(const QString& msg1,const QString& msg2);
    void onMsg_newpoint(const QString& msg1,const QString& msg2,quint8 index_point);
private:
};

#endif // DOCUMENT_H
