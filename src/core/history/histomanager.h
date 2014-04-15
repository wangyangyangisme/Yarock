/****************************************************************************************
*  YAROCK                                                                               *
*  Copyright (c) 2010-2014 Sebastien amardeilh <sebastien.amardeilh+yarock@gmail.com>   *
*                                                                                       *
*  This program is free software; you can redistribute it and/or modify it under        *
*  the terms of the GNU General Public License as published by the Free Software        *
*  Foundation; either version 2 of the License, or (at your option) any later           *
*  version.                                                                             *
*                                                                                       *
*  This program is distributed in the hope that it will be useful, but WITHOUT ANY      *
*  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A      *
*  PARTICULAR PURPOSE. See the GNU General Public License for more details.             *
*                                                                                       *
*  You should have received a copy of the GNU General Public License along with         *
*  this program.  If not, see <http://www.gnu.org/licenses/>.                           *
*****************************************************************************************/


#ifndef _HISTO_MANAGER_H_
#define _HISTO_MANAGER_H_

#include <QObject>
#include <QTimer>

class EngineBase;

/*
********************************************************************************
*                                                                              *
*    Class HistoManager                                                        *
*                                                                              *
********************************************************************************
*/
class HistoManager : public QObject
{
Q_OBJECT
  static HistoManager *INSTANCE;
  public:
    HistoManager();
    static HistoManager* instance() { return INSTANCE; }
    void clearHistory();

  private slots:
    void addEntry();
    void addToDatabase();

  private:
   void checkHisto();

  private:
    EngineBase          *m_player;
    QTimer              *m_timer;
};


#endif // _HISTO_H_
