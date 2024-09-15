//* https://fontawesome.com/search?s=regular&f=classic&o=r

class GameLabsLiveIndicator extends CrashBase
{
#ifdef GAMELABS 
    protected string _eventPictogram = "question";
    protected string _eventDisplayName = "Dynamic event";
    private ref _Event _registeredInstance;

    override void EEInit()
    {
        super.EEInit();

        if (!GetGame().IsServer()) return;
        vector position = GetPosition();
        if (position[0] <= 0 && position[1] <= 0 && position[2] <= 0) return;

        Print("[DEF] Creating GameLabs event for " + GetType() + " object as \"" + _eventDisplayName + "\" (icon: " + _eventPictogram + ")");
        _registeredInstance = new _Event(_eventDisplayName, _eventPictogram, this);
        GetGameLabs().RegisterEvent(_registeredInstance);
    }

    override void EEDelete(EntityAI parent)
    {
        super.EEDelete(parent);

        if (!GetGame().IsServer()) return;
        if (!GetGameLabs()) return;
        if (_registeredInstance)
        {
            Print("[DEF] Removing GameLabs event for " + GetType());
            GetGameLabs().RemoveEvent(_registeredInstance);
        }
    }

    //*  private string GetEventPictogram()
    //*  {
    //*      if (ConfigIsExisting("eventPictogram"))
    //*      {
    //*          return ConfigGetString("eventPictogram");
    //*      }
    //*      return "question";
    //*  }
    //*  private string GetEventDisplayName()
    //*  {
    //*      if (ConfigIsExisting("displayedName"))
    //*      {
    //*          return ConfigGetString("displayedName");
    //*      }
    //*      return GetType();
    //*  }
#endif
};