/////////////////////////////////////////////////////////////////////////////
// Name:            hoxHostPlayer.cpp
// Program's Name:  Huy's Open Xiangqi
// Created:         10/09/2007
//
// Description:     The Player.
/////////////////////////////////////////////////////////////////////////////

#include "hoxHostPlayer.h"
#include "hoxEnums.h"
#include "hoxTable.h"
#include "hoxTableMgr.h"

#include <algorithm>

// user code intercepting the event
IMPLEMENT_DYNAMIC_CLASS( hoxHostPlayer, hoxPlayer )

BEGIN_EVENT_TABLE(hoxHostPlayer, hoxPlayer)
    // Need to have a table even though it is empty.
END_EVENT_TABLE()


//-----------------------------------------------------------------------------
// hoxHostPlayer
//-----------------------------------------------------------------------------

hoxHostPlayer::hoxHostPlayer()
            : hoxPlayer( _("Unknown"), hoxPLAYER_TYPE_HOST, 1500 )
{ 
}

hoxHostPlayer::hoxHostPlayer( const wxString& name,
                              hoxPlayerType   type,
                              int             score )
            : hoxPlayer( name, type, score )
{ 
}

hoxHostPlayer::~hoxHostPlayer() 
{
}

void 
hoxHostPlayer::OnNewMove_FromTable( hoxPlayerEvent&  event )
{
    const char* FNAME = "hoxHostPlayer::OnNewMove_FromTable";
    wxLogDebug("%s: Ignore the Move since this is a HOST player.", FNAME);
}


/************************* END OF FILE ***************************************/
