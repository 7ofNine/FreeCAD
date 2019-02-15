#include "Commands.h"

#include "QGlobalStatic"


// Utilility command 

namespace Draft2Gui {

    CmdDraftSelectPlane::CmdDraftSelectPlane(): Command("Draft_SelectPlane")
    {
        sAppModule = "Draft";
        sGroup = QT_TRANSLATE_NOOP("Draft_Gui", "Draft");
        sMenuText = QT_TRANSLATE_NOOP("Draft_Gui", "Select Plane");
        sToolTipText = QT_TRANSLATE_NOOP("Draft_Gui", "Select a working plane for geomtery creation");
        sWhatsThis = getName();
        sStatusTip = sToolTipText;
        sPixmap = "Draft_SelectPlane";
        sAccel = "W, P";
    }
    
    bool CmdDraftSelectPlane::isActive()
    {
        return hasActiveDocument();
    }


    void CmdDraftSelectPlane::activated(int)
    {
    
    }

}
