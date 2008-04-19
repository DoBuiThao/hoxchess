/***************************************************************************
 *  Copyright 2007, 2008 Huy Phan  <huyphan@playxiangqi.com>               *
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
// Name:            hoxPlayerMgr.h
// Created:         10/06/2007
//
// Description:     A Player-Manager that manages a group of players.
/////////////////////////////////////////////////////////////////////////////

#ifndef __INCLUDED_HOX_PLAYER_MGR_H_
#define __INCLUDED_HOX_PLAYER_MGR_H_

#include "hoxPlayer.h"

/* Forward declarations */
class hoxSite;
class hoxMyPlayer;
class hoxChesscapePlayer;

/**
 * A Player-Manager that manages a group of players.
 */
class hoxPlayerMgr
{
public:
    hoxPlayerMgr();
    ~hoxPlayerMgr();

    hoxChesscapePlayer* CreateChesscapePlayer( const wxString& name,
                                               int             score = 1500 );

    hoxMyPlayer* CreateMyPlayer( const wxString& name,
                                 int             score = 1500 );

    hoxPlayer* CreateDummyPlayer( const wxString& name,
                                  int             score = 1500 );

    /**
     * @return NULL if not found.
     */
    hoxPlayer* FindPlayer( const wxString& playerId ) const;

    /**
     * Handle SITE-CLOSING request from Site.
     */
    void OnSiteClosing();

    /**
     * Return the number of players in the system.
     */
    int GetNumberOfPlayers() { return (int) m_players.size(); }

private:
    hoxPlayerList   m_players;  // The list of all players in the system.
};

#endif /* __INCLUDED_HOX_PLAYER_MGR_H_ */
