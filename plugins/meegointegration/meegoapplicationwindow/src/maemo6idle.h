/****************************************************************************
**
** qutIM instant messenger
**
** Copyright (C) 2011 Evgeniy Degtyarev <degtep@gmail.com>
**
*****************************************************************************
**
** $QUTIM_BEGIN_LICENSE$
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 2 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
** See the GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see http://www.gnu.org/licenses/.
** $QUTIM_END_LICENSE$
**
****************************************************************************/

#ifndef MAEMO6IDLE_H
#define MAEMO6IDLE_H

#include <QObject>
#include <QBasicTimer>
#include <qmactivity.h>

namespace MeegoIntegration
{
using namespace MeeGo;

class Maemo6Idle : public QObject
{
	Q_OBJECT
	Q_CLASSINFO("Service", "Idle")
public:
	Maemo6Idle();
signals:
	void secondsIdle(int);

public slots:
	void activityChanged(QmActivity::Activity activity);

protected:
	void timerEvent(QTimerEvent* ev);

private:
	QmActivity::Activity m_activity;
	QBasicTimer *idle_timer;
	int idleSeconds;
	QmActivity *m_qmActivity;
};
}


#endif