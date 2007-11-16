/***************************************************************************
 *  Copyright 2007 Huy Phan  <huyphan@playxiangqi.com>                     *
 *                                                                         * 
 *  This file is part of HOXChess.                                         *
 *                                                                         *
 *  HOXChess is free software: you can redistribute it and/or modify       *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, either version 3 of the License, or      *
 *  (at your option) any later version.                                    *
 *                                                                         *
 *  HOXChess is distributed in the hope that it will be useful,            *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with HOXChess.  If not, see <http://www.gnu.org/licenses/>.      *
 ***************************************************************************/

/////////////////////////////////////////////////////////////////////////////
// Name:            hoxSocketServer.h
// Created:         10/25/2007
//
// Description:     The main (only) server socket that handles 
//                  all incoming connection.
/////////////////////////////////////////////////////////////////////////////

#ifndef __HOX_SOCKET_SERVER_H_
#define __HOX_SOCKET_SERVER_H_

#include <wx/wx.h>
#include <wx/socket.h>
#include "hoxEnums.h"
#include "hoxTypes.h"

/* Forward declarations */
class hoxServer;

//
// hoxSocketServer
//
// Perhaps we should rename it to something without the word "socket"
// in it (may be used pipe for local connections...)

class hoxSocketServer : public wxThreadHelper
{
public:
    hoxSocketServer( int        nPort,
                     hoxServer* server );
    ~hoxSocketServer();

    // Thread execution starts here
    virtual void* Entry();

public:
    /* My own API */
    void RequestShutdown() { m_shutdownRequested = true; }

private:
    void _DestroySocketServer();

private:
    int               m_nPort;       // The main server's port.
    wxSocketServer*   m_pSServer;    // The main server's socket

    hoxServer*        m_server;

    bool              m_shutdownRequested;
                /* Has a shutdown-request been received? */

};

#endif /* __HOX_SOCKET_SERVER_H_ */