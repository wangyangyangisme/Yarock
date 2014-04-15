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
#ifndef _SERVICE_DISCOGS_H_
#define _SERVICE_DISCOGS_H_

#include "info_service.h"
#include "info_system.h"

#include <QObject>
#include <QString>
#include <QMap>
#include <QByteArray>

/*
********************************************************************************
*                                                                              *
*    Class ServiceDiscogs                                                      *
*                                                                              *
********************************************************************************
*/
class ServiceDiscogs  : public INFO::InfoService
{
Q_OBJECT

public:
    ServiceDiscogs();
    virtual ~ServiceDiscogs();

protected slots:
    virtual void init() {};
    void getInfo( INFO::InfoRequestData requestData );
    void fetchInfo( INFO::InfoRequestData requestData );
    
private:
    void fetch_artist_releases( INFO::InfoRequestData requestData );
    void fetch_album_songs( INFO::InfoRequestData requestData );
    void fetch_album_cover( INFO::InfoRequestData requestData );
    void fetch_image_uri( INFO::InfoRequestData requestData );

private slots:
    void slot_request_error();
    void slot_parse_artist_search_response(QByteArray);
    void slot_parse_artist_release_response(QByteArray);
    void slot_parse_album_search_response(QByteArray);
    void slot_image_received(QByteArray);
    
private:
    QMap<QObject*, INFO::InfoRequestData> m_requests;
};

#endif // _SERVICE_DISCOGS_H_
